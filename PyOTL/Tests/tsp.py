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
import pyotl.optimizer.tsp
import pyotl.problem.tsp
import scipy.spatial

def make_adjacency_matrix(citiesMatrix):
	nCities = len(citiesMatrix)
	adjacencyMatrix = numpy.zeros([nCities, nCities])
	for cityIndex1, city1 in enumerate(citiesMatrix):
		for cityIndex2, city2 in enumerate(citiesMatrix[:cityIndex1]):
			adjacencyMatrix[cityIndex1][cityIndex2] = scipy.spatial.distance.euclidean(city1, city2)
			adjacencyMatrix[cityIndex2][cityIndex1] = adjacencyMatrix[cityIndex1][cityIndex2]
	return adjacencyMatrix

class TestCase(unittest.TestCase):
	def setUp(self):
		self.pathData = os.path.join(os.path.dirname(__file__), 'Data')
	
	def tearDown(self):
		pass
	
	def testMOTSP(self):
		nObjectives = 2
		nCities = 150
		pathData = os.path.join(self.pathData, 'MOTSP')
		pathCities = os.path.join(pathData, 'Cities')
		citiesMatrics = [numpy.loadtxt(os.path.join(pathCities, 'kro%c%u.csv' % (chr(ord('A') + i), nCities))) for i in range(nObjectives)]
		_adjacencyMatrics = [make_adjacency_matrix(citiesMatrix).tolist() for citiesMatrix in citiesMatrics]
		adjacencyMatrics = pyotl.problem.tsp.pylistlistlist2matrics(_adjacencyMatrics)
		problem = pyotl.problem.tsp.MOTSP(adjacencyMatrics)
		filename = '%u_%u' % (problem.GetNumberOfObjectives(), nCities)
		ps = numpy.loadtxt(os.path.join(pathData, filename + '.ps.csv'), dtype = int)
		pf = numpy.loadtxt(os.path.join(pathData, filename + '.pf.csv'))
		self.assertEqual(len(ps.shape), 2)
		self.assertEqual(len(pf.shape), 2)
		self.assertEqual(ps.shape[0], pf.shape[0])
		self.assertEqual(ps.shape[1], nCities)
		self.assertEqual(pf.shape[1], problem.GetNumberOfObjectives())
		for decision, objective in zip(ps, pf):
			solution = pyotl.optimizer.tsp.Solution()
			solution.decision_ = pyotl.utility.PyList2Vector_size_t(decision.tolist())
			problem(solution)
			for f1, f2 in zip(objective, solution.objective_):
				self.assertAlmostEqual(f1, f2)
	
	def testCorrelationMOTSP(self):
		nObjectives = 4
		nCities = 30
		pathData = os.path.join(self.pathData, 'MOTSP')
		adjacencyMatricsPath = os.path.join(os.path.join(pathData, 'AdjacencyMatrics'), '%u_%u.csv' % (nObjectives, nCities))
		_adjacencyMatrics = numpy.loadtxt(adjacencyMatricsPath)
		adjacencyMatrics = numpy.split(_adjacencyMatrics, nObjectives)
		self.assertEqual(len(adjacencyMatrics), nObjectives)
		for adjacencyMatrix in adjacencyMatrics:
			self.assertEqual(len(adjacencyMatrix.shape), 2)
			for shape in adjacencyMatrix.shape:
				self.assertEqual(shape, nCities)
		adjacencyMatrics = list(map(lambda adjacencyMatrix: adjacencyMatrix.tolist(), adjacencyMatrics))
		correlationList = [0, 1]
		for _correlation in correlationList:
			correlation = [_correlation] * (len(adjacencyMatrics) - 1)
			correlation = pyotl.utility.PyList2Vector_Real(correlation)
			_adjacencyMatrics = pyotl.problem.tsp.pylistlistlist2matrics(adjacencyMatrics)
			pyotl.problem.tsp.correlate_adjacency_matrics(correlation, _adjacencyMatrics)
			problem = pyotl.problem.tsp.MOTSP(_adjacencyMatrics)
			correlationPath = os.path.join(os.path.join(pathData, 'Correlation'), str(_correlation))
			filename = '%u_%u' % (problem.GetNumberOfObjectives(), nCities)
			ps = numpy.loadtxt(os.path.join(correlationPath, filename + '.ps.csv'), dtype = int)
			pf = numpy.loadtxt(os.path.join(correlationPath, filename + '.pf.csv'))
			self.assertEqual(len(ps.shape), 2)
			self.assertEqual(len(pf.shape), 2)
			self.assertEqual(ps.shape[0], pf.shape[0])
			self.assertEqual(ps.shape[1], nCities)
			self.assertEqual(pf.shape[1], problem.GetNumberOfObjectives())
			for decision, objective in zip(ps, pf):
				solution = pyotl.optimizer.tsp.Solution()
				solution.decision_ = pyotl.utility.PyList2Vector_size_t(decision.tolist())
				problem(solution)
				for f1, f2 in zip(objective, solution.objective_):
					self.assertAlmostEqual(f1, f2, 4, correlationPath)

if __name__ == '__main__':
	unittest.main()