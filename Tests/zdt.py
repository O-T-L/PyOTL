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

    def testZDT1(self):
        problem = pyotl.problem.real.ZDT1()
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

    def testZDT2(self):
        problem = pyotl.problem.real.ZDT2()
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

    def testZDT3(self):
        problem = pyotl.problem.real.ZDT3()
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

    def testZDT4(self):
        problem = pyotl.problem.real.ZDT4()
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

    def testZDT5(self):
        sroblem = pyotl.problem.integer.ZDT5()
        nDecisions = len(sroblem.GetDecisionBits())
        pathData = os.path.join(self.pathData, type(sroblem).__name__)
        filename = '%u' % nDecisions
        ps = numpy.loadtxt(os.path.join(pathData, filename + '.ps.csv'), dtype=int,
                           converters=dict([(nCol, lambda strData: int(strData, 2)) for nCol in range(nDecisions)]))
        pf = numpy.loadtxt(os.path.join(pathData, filename + '.pf.csv'))
        self.assertEqual(len(ps.shape), 2)
        self.assertEqual(len(pf.shape), 2)
        self.assertEqual(ps.shape[0], pf.shape[0])
        self.assertEqual(ps.shape[1], nDecisions)
        self.assertEqual(pf.shape[1], sroblem.GetNumberOfObjectives())
        for decision, objective in zip(ps, pf):
            solution = pyotl.optimizer.integer.Solution()
            solution.decision_ = pyotl.utility.PyList2Vector_Integer(decision.tolist())
            sroblem(solution)
            for f1, f2 in zip(objective, solution.objective_):
                self.assertAlmostEqual(f1, f2)

    def testZDT6(self):
        problem = pyotl.problem.real.ZDT6()
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
