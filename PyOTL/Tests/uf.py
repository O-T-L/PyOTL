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
import pyotl.optimizer.integer
import pyotl.problem.real
import pyotl.problem.integer

class TestCase(unittest.TestCase):
	def setUp(self):
		self.pathData = os.path.join(os.path.dirname(__file__), 'Data')
	
	def tearDown(self):
		pass
	
	def testUF1(self):
		for nDistDecisions in [28, 29]:
			problem = pyotl.problem.real.UF1(nDistDecisions)
			nDecisions = len(problem.GetBoundary())
			pathData = os.path.join(self.pathData, type(problem).__name__)
			filename = '%u' % nDecisions
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
					self.assertAlmostEqual(f1, f2)
	
	def testUF2(self):
		for nDistDecisions in [28, 29]:
			problem = pyotl.problem.real.UF2(nDistDecisions)
			nDecisions = len(problem.GetBoundary())
			pathData = os.path.join(self.pathData, type(problem).__name__)
			filename = '%u' % nDecisions
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
					self.assertAlmostEqual(f1, f2)
	
	def testUF3(self):
		for nDistDecisions in [28, 29]:
			problem = pyotl.problem.real.UF3(nDistDecisions)
			nDecisions = len(problem.GetBoundary())
			pathData = os.path.join(self.pathData, type(problem).__name__)
			filename = '%u' % nDecisions
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
					self.assertAlmostEqual(f1, f2)
	
	def testUF4(self):
		for nDistDecisions in [28, 29]:
			problem = pyotl.problem.real.UF4(nDistDecisions)
			nDecisions = len(problem.GetBoundary())
			pathData = os.path.join(self.pathData, type(problem).__name__)
			filename = '%u' % nDecisions
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
					self.assertAlmostEqual(f1, f2)
	
	def testUF5(self):
		for nDistDecisions in [28, 29]:
			problem = pyotl.problem.real.UF5(nDistDecisions)
			nDecisions = len(problem.GetBoundary())
			pathData = os.path.join(self.pathData, type(problem).__name__)
			filename = '%u' % nDecisions
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
					self.assertAlmostEqual(f1, f2)
	
	def testUF6(self):
		for nDistDecisions in [28, 29]:
			problem = pyotl.problem.real.UF6(nDistDecisions)
			nDecisions = len(problem.GetBoundary())
			pathData = os.path.join(self.pathData, type(problem).__name__)
			filename = '%u' % nDecisions
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
					self.assertAlmostEqual(f1, f2)
	
	def testUF7(self):
		for nDistDecisions in [28, 29]:
			problem = pyotl.problem.real.UF7(nDistDecisions)
			nDecisions = len(problem.GetBoundary())
			pathData = os.path.join(self.pathData, type(problem).__name__)
			filename = '%u' % nDecisions
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
					self.assertAlmostEqual(f1, f2)
	
	def testUF8(self):
		for nDistDecisions in [27, 28, 29]:
			problem = pyotl.problem.real.UF8(nDistDecisions)
			nDecisions = len(problem.GetBoundary())
			pathData = os.path.join(self.pathData, type(problem).__name__)
			filename = '%u' % nDecisions
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
					self.assertAlmostEqual(f1, f2)
	
	def testUF9(self):
		for nDistDecisions in [27, 28, 29]:
			problem = pyotl.problem.real.UF9(nDistDecisions)
			nDecisions = len(problem.GetBoundary())
			pathData = os.path.join(self.pathData, type(problem).__name__)
			filename = '%u' % nDecisions
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
					self.assertAlmostEqual(f1, f2)
	
	def testUF10(self):
		for nDistDecisions in [27, 28, 29]:
			problem = pyotl.problem.real.UF10(nDistDecisions)
			nDecisions = len(problem.GetBoundary())
			pathData = os.path.join(self.pathData, type(problem).__name__)
			filename = '%u' % nDecisions
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
					self.assertAlmostEqual(f1, f2)

if __name__ == '__main__':
	unittest.main()