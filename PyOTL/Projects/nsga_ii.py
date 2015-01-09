"""
Copyright (C) 2014, 申瑞珉 (Ruimin Shen)

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU Lesser General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
"""

import os
import timeit
import numpy
import pyotl.utility
import pyotl.problem.real
import pyotl.initial.real
import pyotl.crossover.real
import pyotl.mutation.real
import pyotl.optimizer.real

def run_nsga_ii(problem, nEvaluations):
	random = pyotl.utility.Random()
	_crossover = pyotl.crossover.real.SimulatedBinaryCrossover(random, 1, problem.GetBoundary(), 20)
	crossover = pyotl.crossover.real.CoupleCoupleCrossoverAdapter(_crossover, random)
	mutation = pyotl.mutation.real.PolynomialMutation(random, 1 / float(len(problem.GetBoundary())), problem.GetBoundary(), 20)
	initial = pyotl.initial.real.PopulationUniform(random, problem.GetBoundary(), 100)
	optimizer = pyotl.optimizer.real.NSGA_II(random, problem, initial, crossover, mutation)
	while optimizer.GetProblem().GetNumberOfEvaluations() < nEvaluations:
		optimizer()

def main():
	for repeat in range(30):
		for nObjectives in [2, 3]:
			problems = [
				pyotl.problem.real.DTLZ1(nObjectives),
				pyotl.problem.real.DTLZ2(nObjectives),
				pyotl.problem.real.DTLZ3(nObjectives),
				pyotl.problem.real.DTLZ4(nObjectives),
				pyotl.problem.real.DTLZ7(nObjectives),
			]
			nEvaluationsList = [100000, 30000, 100000, 30000, 30000]
			for problem, nEvaluations in zip(problems, nEvaluationsList):
				timer = timeit.Timer(lambda: run_nsga_ii(problem, nEvaluations))
				duration = timer.timeit(1)
				print(duration)
				path = os.path.join(os.path.expanduser('~'), 'NSGA-II', type(problem).__name__, str(nObjectives))
				try:
					os.makedirs(path, exist_ok = True)
				except:
					pass
				f = open(os.path.join(path, '%u.duration' % repeat), 'w')
				f.write(str(duration))
				f.close()

if __name__ == '__main__':
	main()