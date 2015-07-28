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

    def tearDown(self):
        pass

    def testWFG1(self):
        nObjectives = 3
        problem = pyotl.problem.real.WFG1(nObjectives)
        nDecisions = len(problem.GetBoundary())
        nPosDecisions = problem.GetPosDecisions()
        nPosGroups = int(nPosDecisions / (nObjectives - 1))
        nDistDecisions = nDecisions - nPosDecisions
        pathData = os.path.join(self.pathData, type(problem).__name__)
        filename = '%u_%u_%u' % (nObjectives, nPosGroups, nDistDecisions)
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

    def testWFG2(self):
        nObjectives = 3
        problem = pyotl.problem.real.WFG2(nObjectives)
        nDecisions = len(problem.GetBoundary())
        nPosDecisions = problem.GetPosDecisions()
        nPosGroups = int(nPosDecisions / (nObjectives - 1))
        nDistDecisions = nDecisions - nPosDecisions
        pathData = os.path.join(self.pathData, type(problem).__name__)
        filename = '%u_%u_%u' % (nObjectives, nPosGroups, nDistDecisions)
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

    def testWFG3(self):
        nObjectives = 3
        problem = pyotl.problem.real.WFG3(nObjectives)
        nDecisions = len(problem.GetBoundary())
        nPosDecisions = problem.GetPosDecisions()
        nPosGroups = int(nPosDecisions / (nObjectives - 1))
        nDistDecisions = nDecisions - nPosDecisions
        pathData = os.path.join(self.pathData, type(problem).__name__)
        filename = '%u_%u_%u' % (nObjectives, nPosGroups, nDistDecisions)
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

    def testWFG4(self):
        nObjectives = 3
        problem = pyotl.problem.real.WFG4(nObjectives)
        nDecisions = len(problem.GetBoundary())
        nPosDecisions = problem.GetPosDecisions()
        nPosGroups = int(nPosDecisions / (nObjectives - 1))
        nDistDecisions = nDecisions - nPosDecisions
        pathData = os.path.join(self.pathData, type(problem).__name__)
        filename = '%u_%u_%u' % (nObjectives, nPosGroups, nDistDecisions)
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

    def testWFG5(self):
        nObjectives = 3
        problem = pyotl.problem.real.WFG5(nObjectives)
        nDecisions = len(problem.GetBoundary())
        nPosDecisions = problem.GetPosDecisions()
        nPosGroups = int(nPosDecisions / (nObjectives - 1))
        nDistDecisions = nDecisions - nPosDecisions
        pathData = os.path.join(self.pathData, type(problem).__name__)
        filename = '%u_%u_%u' % (nObjectives, nPosGroups, nDistDecisions)
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

    def testWFG6(self):
        nObjectives = 3
        problem = pyotl.problem.real.WFG6(nObjectives)
        nDecisions = len(problem.GetBoundary())
        nPosDecisions = problem.GetPosDecisions()
        nPosGroups = int(nPosDecisions / (nObjectives - 1))
        nDistDecisions = nDecisions - nPosDecisions
        pathData = os.path.join(self.pathData, type(problem).__name__)
        filename = '%u_%u_%u' % (nObjectives, nPosGroups, nDistDecisions)
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

    def testWFG7(self):
        nObjectives = 3
        problem = pyotl.problem.real.WFG7(nObjectives)
        nDecisions = len(problem.GetBoundary())
        nPosDecisions = problem.GetPosDecisions()
        nPosGroups = int(nPosDecisions / (nObjectives - 1))
        nDistDecisions = nDecisions - nPosDecisions
        pathData = os.path.join(self.pathData, type(problem).__name__)
        filename = '%u_%u_%u' % (nObjectives, nPosGroups, nDistDecisions)
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

    def testWFG8(self):
        nObjectives = 3
        problem = pyotl.problem.real.WFG8(nObjectives)
        nDecisions = len(problem.GetBoundary())
        nPosDecisions = problem.GetPosDecisions()
        nPosGroups = int(nPosDecisions / (nObjectives - 1))
        nDistDecisions = nDecisions - nPosDecisions
        pathData = os.path.join(self.pathData, type(problem).__name__)
        filename = '%u_%u_%u' % (nObjectives, nPosGroups, nDistDecisions)
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

    def testWFG9(self):
        nObjectives = 3
        problem = pyotl.problem.real.WFG9(nObjectives)
        nDecisions = len(problem.GetBoundary())
        nPosDecisions = problem.GetPosDecisions()
        nPosGroups = int(nPosDecisions / (nObjectives - 1))
        nDistDecisions = nDecisions - nPosDecisions
        pathData = os.path.join(self.pathData, type(problem).__name__)
        filename = '%u_%u_%u' % (nObjectives, nPosGroups, nDistDecisions)
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
