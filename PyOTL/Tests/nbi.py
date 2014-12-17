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
import pyotl.utility

def ncr(n, r):
	return math.factorial(n) / math.factorial(r) / math.factorial(n - r)

class TestCase(unittest.TestCase):
	def setUp(self):
		self.dimensions = [2, 3, 4]
		self.divisions = [3, 4, 5]
	
	def testNBI(self):
		for dimension in self.dimensions:
			for division in self.divisions:
				_points = pyotl.utility.NormalBoundaryIntersection_Real(dimension, division)
				self.assertEqual(len(_points), ncr(dimension + _division - 1, _division))
		

if __name__ == '__main__':
	unittest.main()