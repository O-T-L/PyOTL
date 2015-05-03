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
import unittest
import numpy
import pyotl.utility
import pyotl.optimizer.real
import pyotl.problem.real

class TestCase(unittest.TestCase):
	def setUp(self):
		self.pathData = os.path.join(os.path.dirname(__file__), 'Data')
		self.places = 4
		self.iterationList = [0, 4, 5]
	
	def tearDown(self):
		pass
	
	def testFDA_same_iteration(self):
		nObjectives = 3
		nFixedGenerations = 5
		distinctSteps = 10
		distDecisions = 10
		nDecisions = nObjectives - 1 + distDecisions
		solution = pyotl.optimizer.real.Solution()
		solution.decision_ = pyotl.utility.PyList2Vector_Real(numpy.random.random(nDecisions).tolist())
		objectiveList = []
		for _iteration in range(nFixedGenerations):
			iteration = pyotl.utility.Generation(_iteration)
			problem = pyotl.problem.real.FDA5(nObjectives, iteration, nFixedGenerations, distinctSteps, distDecisions)
			problem(solution)
			objectiveList.append(list(solution.objective_))
		for objective1, objective2 in zip(objectiveList[:-1], objectiveList[1:]):
			for i in range(nObjectives):
				self.assertEqual(objective1[i], objective2[i])
	
	def testFDA_different_iteration(self):
		nObjectives = 3
		nFixedGenerations = 5
		distinctSteps = 10
		distDecisions = 10
		nDecisions = nObjectives - 1 + distDecisions
		solution = pyotl.optimizer.real.Solution()
		solution.decision_ = pyotl.utility.PyList2Vector_Real(numpy.random.random(nDecisions).tolist())
		# Generation 0
		iteration1 = pyotl.utility.Generation(0)
		problem1 = pyotl.problem.real.FDA5(nObjectives, iteration1, nFixedGenerations, distinctSteps, distDecisions)
		problem1(solution)
		objective1 = list(solution.objective_)
		# Generation nFixedGenerations
		iteration2 = pyotl.utility.Generation(nFixedGenerations)
		problem2 = pyotl.problem.real.FDA5(nObjectives, iteration2, nFixedGenerations, distinctSteps, distDecisions)
		problem2(solution)
		objective2 = list(solution.objective_)
		# Different
		for i in range(nObjectives):
			self.assertNotEqual(objective1[i], objective2[i])
	
	def testFDA_distinct_steps(self):
		nObjectives = 3
		nFixedGenerations = 5
		distinctSteps = 10
		distDecisions = 10
		nDecisions = nObjectives - 1 + distDecisions
		solution = pyotl.optimizer.real.Solution()
		solution.decision_ = pyotl.utility.PyList2Vector_Real(numpy.random.random(nDecisions).tolist())
		objectiveList = []
		for step in range(distinctSteps):
			iteration = pyotl.utility.Generation(nFixedGenerations * step)
			problem = pyotl.problem.real.FDA5(nObjectives, iteration, nFixedGenerations, distinctSteps, distDecisions)
			problem(solution)
			objectiveList.append(list(solution.objective_))
		for objective1, objective2 in zip(objectiveList[:-1], objectiveList[1:]):
			for i in range(nObjectives):
				self.assertNotEqual(objective1[i], objective2[i])
	
	def testFDA5(self):
		nObjectives = 3
		for _iteration in self.iterationList:
			iteration = pyotl.utility.Generation(_iteration)
			problem = pyotl.problem.real.FDA5(nObjectives, iteration)
			nDecisions = len(problem.GetBoundary())
			pathData = os.path.join(self.pathData, type(problem).__name__)
			pathData = os.path.join(pathData, str(problem.GetNumberOfDistinctSteps()))
			pathData = os.path.join(pathData, str(int(iteration() / problem.GetNumberOfFixedGenerations())))
			filename = '%u_%u' % (nObjectives, nDecisions)
			ps = numpy.loadtxt(os.path.join(pathData, filename + '.ps.csv'))
			pf = numpy.loadtxt(os.path.join(pathData, filename + '.pf.csv'))
			self.assertEqual(len(ps.shape), 2)
			self.assertEqual(len(pf.shape), 2)
			self.assertEqual(ps.shape[0], pf.shape[0])
			self.assertEqual(ps.shape[1], nDecisions)
			self.assertEqual(pf.shape[1], problem.GetNumberOfObjectives())
			for decision, objective in zip(ps, pf):
				solution = pyotl.optimizer.real.Solution()
				solution.decision_ = pyotl.utility.PyList2Vector_Real(decision.tolist())
				problem(solution)
				for f1, f2 in zip(objective, solution.objective_):
					self.assertAlmostEqual(f1, f2, self.places)

if __name__ == '__main__':
	unittest.main()