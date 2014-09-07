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
import pyotl.indicator

def readline(path):
	f = open(path)
	s = f.readline()
	f.close()
	return s

class TestCase(unittest.TestCase):
	def setUp(self):
		self.pathData = os.path.join(os.path.dirname(__file__), 'Data')
	
	def tearDown(self):
		pass
	
	def testDiversitymetric(self):
		nObjectives = 3
		problemNameList = ['DTLZ1', 'DTLZ2', 'DTLZ7']
		for problemName in problemNameList:
			pathData = os.path.join(os.path.join(self.pathData, problemName), str(nObjectives))
			boundary = numpy.loadtxt(os.path.join(pathData, 'Boundary.csv'))
			boundary = pyotl.utility.PyList2Boundary_Real(boundary.tolist())
			_division = numpy.loadtxt(os.path.join(pathData, 'Division.csv'), dtype = int)
			division = pyotl.utility.PyList2Vector_size_t(_division.tolist())
			pfTrue = numpy.loadtxt(os.path.join(pathData, 'PF_100.csv'))
			pfTrue = pyotl.utility.PyListList2VectorVector_Real(pfTrue.tolist())
			indicator = pyotl.indicator.DiversityMetric(boundary, division, pfTrue)
			pf = numpy.loadtxt(os.path.join(pathData, 'Front.csv'))
			pf = pyotl.utility.PyListList2VectorVector_Real(pf.tolist())
			metric = indicator(pf)
			self.assertAlmostEqual(float(readline(os.path.join(pathData, 'DM'))), metric)
	
	def testDTLZ1GD(self):
		nObjectives = 3
		pathData = os.path.join(os.path.join(self.pathData, 'DTLZ1'), str(nObjectives))
		indicator = pyotl.indicator.DTLZ1GD()
		pfMatrix = numpy.loadtxt(os.path.join(pathData, 'Front.csv'))
		pf = pyotl.utility.PyListList2VectorVector_Real(pfMatrix.tolist())
		metric = indicator(pf)
		self.assertAlmostEqual(float(readline(os.path.join(pathData, 'GD'))), metric)
	
	def testDTLZ2GD(self):
		nObjectives = 3
		pathData = os.path.join(os.path.join(self.pathData, 'DTLZ2'), str(nObjectives))
		indicator = pyotl.indicator.DTLZ2GD()
		pfMatrix = numpy.loadtxt(os.path.join(pathData, 'Front.csv'))
		pf = pyotl.utility.PyListList2VectorVector_Real(pfMatrix.tolist())
		metric = indicator(pf)
		self.assertAlmostEqual(float(readline(os.path.join(pathData, 'GD'))), metric)
	
	def testDTLZ7GD(self):
		nObjectives = 3
		pathData = os.path.join(os.path.join(self.pathData, 'DTLZ7'), str(nObjectives))
		pf = numpy.loadtxt(os.path.join(pathData, 'PF.csv'))
		pf = pyotl.utility.PyListList2VectorVector_Real(pf.tolist())
		indicator = pyotl.indicator.FrontGD(pf)
		pfMatrix = numpy.loadtxt(os.path.join(pathData, 'Front.csv'))
		pf = pyotl.utility.PyListList2VectorVector_Real(pfMatrix.tolist())
		metric = indicator(pf)
		self.assertAlmostEqual(float(readline(os.path.join(pathData, 'GD'))), metric)
	
	def testInvertedGenerationalDistance(self):
		nObjectives = 3
		problemNameList = ['DTLZ1', 'DTLZ2', 'DTLZ7']
		for problemName in problemNameList:
			pathData = os.path.join(os.path.join(self.pathData, problemName), str(nObjectives))
			pfTrue = numpy.loadtxt(os.path.join(pathData, 'PF.csv'))
			pfTrue = pyotl.utility.PyListList2VectorVector_Real(pfTrue.tolist())
			indicator = pyotl.indicator.InvertedGenerationalDistance(pfTrue)
			pf = numpy.loadtxt(os.path.join(pathData, 'Front.csv'))
			pf = pyotl.utility.PyListList2VectorVector_Real(pf.tolist())
			metric = indicator(pf)
			self.assertAlmostEqual(float(readline(os.path.join(pathData, 'IGD'))), metric)

if __name__ == '__main__':
	unittest.main()