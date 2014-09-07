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
import pyotl.optimizer.dynamic_bitset
import pyotl.problem.dynamic_bitset

class TestCase(unittest.TestCase):
	def setUp(self):
		self.pathData = os.path.join(os.path.dirname(__file__), 'Data')
	
	def tearDown(self):
		pass
	
	def testKnapsack(self):
		nObjectives = 5
		nPacks = 500
		pathData = os.path.join(os.path.join(self.pathData, 'Knapsack'), '%u_%u' % (nObjectives, nPacks))
		priceMatrix = numpy.loadtxt(os.path.join(pathData, 'Price.csv'))
		weightMatrix = numpy.loadtxt(os.path.join(pathData, 'Weight.csv'))
		capacity = numpy.loadtxt(os.path.join(pathData, 'Capacity.csv'))
		assert(len(priceMatrix.shape) == len(weightMatrix.shape) == 2)
		assert(len(capacity.shape) == 1)
		assert(priceMatrix.shape[0] == weightMatrix.shape[0] == nObjectives)
		assert(priceMatrix.shape[1] == weightMatrix.shape[1] == nPacks)
		priceMatrix = pyotl.problem.dynamic_bitset.pylistlist2matrix(priceMatrix.tolist())
		weightMatrix = pyotl.problem.dynamic_bitset.pylistlist2matrix(weightMatrix.tolist())
		capacity = pyotl.utility.PyList2Vector_Real(capacity.tolist())
		problem = pyotl.problem.dynamic_bitset.Knapsack(priceMatrix, weightMatrix, capacity)

if __name__ == '__main__':
	unittest.main()