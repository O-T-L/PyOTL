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
import math
import unittest
import numpy
import scipy.stats
import pyotl.utility
import pyotl.problem.community_discovery
import pyotl.problem.index
import pyotl.initial.index
import pyotl.crossover.index
import pyotl.mutation.index
import pyotl.optimizer.index
import pyotl.indicator

class TestCase(unittest.TestCase):
	def setUp(self):
		self.pathData = os.path.join(os.path.dirname(__file__), 'Data')
		self.repeat = 30
		self.graph = [
			[1, 1, 1, 1, 0, 0, 0, 0],
			[1, 1, 1, 1, 0, 0, 0, 0],
			[1, 1, 1, 1, 0, 0, 0, 0],
			[1, 1, 1, 1, 1, 1, 1, 1],
			[0, 0, 0, 1, 1, 1, 1, 0],
			[0, 0, 0, 1, 1, 1, 1, 1],
			[0, 0, 0, 1, 1, 1, 1, 1],
			[0, 0, 0, 1, 0, 1, 1, 1],
		];
	
	def tearDown(self):
		pass
	
	def testONL(self):
		random = pyotl.utility.Random(1)
		graph = pyotl.utility.PyListList2BlasSymmetricMatrix_Real(self.graph)
		metrics = [pyotl.problem.community_discovery.Q(), pyotl.problem.community_discovery.QLi()]
		_metrics = pyotl.problem.community_discovery.PyList2Vector_Metric(metrics)
		problemGen = lambda: pyotl.problem.index.ONL(graph, _metrics, random)
		problem = problemGen()
		pathProblem = os.path.join(self.pathData, type(problem).__name__, '+'.join([type(metric).__name__ for metric in metrics]))
		nDecisions = len(problem.GetBoundary())
		decisionBits = math.ceil(math.log2(nDecisions))
		decisionBits = [decisionBits] * nDecisions
		_decisionBits = pyotl.utility.PyList2Vector_size_t(decisionBits)
		_crossover = pyotl.crossover.index.SinglePointCrossover(random, 1, _decisionBits)
		crossover = pyotl.crossover.index.CoupleCoupleCrossoverAdapter(_crossover, random)
		mutation = pyotl.mutation.index.BitwiseMutation(random, 1 / float(len(problem.GetBoundary())), _decisionBits)
		pfList = []
		for _ in range(self.repeat):
			problem = problemGen()
			initial = pyotl.initial.index.PopulationUniform(random, problem.GetBoundary(), 100)
			optimizer = pyotl.optimizer.index.NSGA_II(random, problem, initial, crossover, mutation)
			while optimizer.GetProblem().GetNumberOfEvaluations() < 30000:
				optimizer()
			pf = pyotl.utility.PyListList2VectorVector_Real([list(solution.objective_) for solution in optimizer.GetSolutionSet()])
			pfList.append(pf)
		pathCrossover = os.path.join(pathProblem, type(crossover.GetCrossover()).__name__)
		pathOptimizer = os.path.join(pathCrossover, type(optimizer).__name__)
		pfTrue = pyotl.utility.PyListList2VectorVector_Real(numpy.loadtxt(os.path.join(pathProblem, 'PF.csv')).tolist())
		#GD
		indicator = pyotl.indicator.DTLZ2GD()
		metricList = [indicator(pf) for pf in pfList]
		rightList = numpy.loadtxt(os.path.join(pathOptimizer, 'GD.csv')).tolist()
		self.assertGreater(scipy.stats.ttest_ind(rightList, metricList)[1], 0.05, [numpy.mean(rightList), numpy.mean(metricList), metricList])
		#IGD
		indicator = pyotl.indicator.InvertedGenerationalDistance(pfTrue)
		metricList = [indicator(pf) for pf in pfList]
		rightList = numpy.loadtxt(os.path.join(pathOptimizer, 'IGD.csv')).tolist()
		self.assertGreater(scipy.stats.ttest_ind(rightList, metricList)[1], 0.05, [numpy.mean(rightList), numpy.mean(metricList), metricList])

if __name__ == '__main__':
	unittest.main()