/*!
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
*/

#include <boost/python.hpp>
#include "Problem.h"

namespace pyotl
{
namespace problem
{
namespace real
{
BOOST_PYTHON_MODULE(PYMODULE_NAME)
{
	boost::python::class_<TProblem, boost::noncopyable>("Problem", boost::python::no_init)
		.def("__call__", &TProblem::operator ())
		.def("Fix", &TProblem::Fix)
		.def("GetNumberOfObjectives", &TProblem::GetNumberOfObjectives)
		.def("GetNumberOfEvaluations", &TProblem::GetNumberOfEvaluations)
	;

	boost::python::class_<TDynamicProblem, boost::noncopyable>("DynamicProblem", boost::python::no_init)
		.def("__call__", &TProblem::operator ())
		.def("Fix", &TProblem::Fix)
		.def("GetNumberOfObjectives", &TProblem::GetNumberOfObjectives)
		.def("GetNumberOfEvaluations", &TProblem::GetNumberOfEvaluations)
		.def("GetProgress", &TDynamicProblem::GetProgress)
	;

	boost::python::class_<TXSinX, boost::python::bases<TProblem> >("XSinX")
		.def("GetBoundary", &TXSinX::GetBoundary, boost::python::return_value_policy<boost::python::reference_existing_object>())
	;

	boost::python::class_<TCamel, boost::python::bases<TProblem> >("Camel")
		.def("GetBoundary", &TCamel::GetBoundary, boost::python::return_value_policy<boost::python::reference_existing_object>())
	;

	boost::python::class_<TShafferF6, boost::python::bases<TProblem> >("ShafferF6")
		.def("GetBoundary", &TShafferF6::GetBoundary, boost::python::return_value_policy<boost::python::reference_existing_object>())
	;

	boost::python::class_<TShubert, boost::python::bases<TProblem> >("Shubert")
		.def("GetBoundary", &TShubert::GetBoundary, boost::python::return_value_policy<boost::python::reference_existing_object>())
	;

	boost::python::class_<TParetoBox, boost::python::bases<TProblem> >("ParetoBox")
		.def("GetBoundary", &TParetoBox::GetBoundary, boost::python::return_value_policy<boost::python::reference_existing_object>())
	;

	boost::python::class_<TWater, boost::python::bases<TProblem> >("Water")
		.def("GetBoundary", &TWater::GetBoundary, boost::python::return_value_policy<boost::python::reference_existing_object>())
	;

	boost::python::class_<TRectangle, boost::python::bases<TProblem> >("Rectangle", boost::python::init<TRectangle::TBoundary &, TRectangle::TBoundary &>())
		.def("GetBoundary", &TRectangle::GetBoundary, boost::python::return_value_policy<boost::python::reference_existing_object>())
		.def("GetBoundaryOptimal", &TRectangle::GetBoundaryOptimal, boost::python::return_value_policy<boost::python::reference_existing_object>())
	;

	boost::python::class_<TRotatedRectangle, boost::python::bases<TProblem> >("RotatedRectangle", boost::python::init<TRotatedRectangle::TBoundary &, TRotatedRectangle::TBoundary &, boost::numeric::ublas::vector<TReal> &>())
		.def("GetBoundary", &TRotatedRectangle::GetBoundary, boost::python::return_value_policy<boost::python::reference_existing_object>())
		.def("GetBoundaryOptimal", &TRotatedRectangle::GetBoundaryOptimal, boost::python::return_value_policy<boost::python::reference_existing_object>())
		.def("GetAxes", &TRotatedRectangle::GetAxes, boost::python::return_value_policy<boost::python::reference_existing_object>())
		.def("Transform", &TRotatedRectangle::Transform)
	;

	boost::python::class_<TZDT1, boost::python::bases<TProblem> >("ZDT1")
		.def(boost::python::init<size_t>())
		.def("GetBoundary", &TZDT::GetBoundary, boost::python::return_value_policy<boost::python::reference_existing_object>())
	;

	boost::python::class_<TZDT2, boost::python::bases<TProblem> >("ZDT2")
		.def(boost::python::init<size_t>())
		.def("GetBoundary", &TZDT::GetBoundary, boost::python::return_value_policy<boost::python::reference_existing_object>())
	;

	boost::python::class_<TZDT3, boost::python::bases<TProblem> >("ZDT3")
		.def(boost::python::init<size_t>())
		.def("GetBoundary", &TZDT::GetBoundary, boost::python::return_value_policy<boost::python::reference_existing_object>())
	;

	boost::python::class_<TZDT4, boost::python::bases<TProblem> >("ZDT4")
		.def(boost::python::init<size_t>())
		.def("GetBoundary", &TZDT::GetBoundary, boost::python::return_value_policy<boost::python::reference_existing_object>())
	;

	boost::python::class_<TZDT6, boost::python::bases<TProblem> >("ZDT6")
		.def(boost::python::init<size_t>())
		.def("GetBoundary", &TZDT::GetBoundary, boost::python::return_value_policy<boost::python::reference_existing_object>())
	;

	boost::python::class_<TUF1, boost::python::bases<TProblem> >("UF1")
		.def(boost::python::init<size_t>())
		.def("GetBoundary", &TUF::GetBoundary, boost::python::return_value_policy<boost::python::reference_existing_object>())
	;

	boost::python::class_<TUF2, boost::python::bases<TProblem> >("UF2")
		.def(boost::python::init<size_t>())
		.def("GetBoundary", &TUF::GetBoundary, boost::python::return_value_policy<boost::python::reference_existing_object>())
	;

	boost::python::class_<TUF3, boost::python::bases<TProblem> >("UF3")
		.def(boost::python::init<size_t>())
		.def("GetBoundary", &TUF::GetBoundary, boost::python::return_value_policy<boost::python::reference_existing_object>())
	;

	boost::python::class_<TUF4, boost::python::bases<TProblem> >("UF4")
		.def(boost::python::init<size_t>())
		.def("GetBoundary", &TUF::GetBoundary, boost::python::return_value_policy<boost::python::reference_existing_object>())
	;

	boost::python::class_<TUF5, boost::python::bases<TProblem> >("UF5")
		.def(boost::python::init<size_t>())
		.def(boost::python::init<size_t, TReal, size_t>())
		.def("GetBoundary", &TUF::GetBoundary, boost::python::return_value_policy<boost::python::reference_existing_object>())
	;

	boost::python::class_<TUF6, boost::python::bases<TProblem> >("UF6")
		.def(boost::python::init<size_t>())
		.def(boost::python::init<size_t, TReal, size_t>())
		.def("GetBoundary", &TUF::GetBoundary, boost::python::return_value_policy<boost::python::reference_existing_object>())
	;

	boost::python::class_<TUF7, boost::python::bases<TProblem> >("UF7")
		.def(boost::python::init<size_t>())
		.def("GetBoundary", &TUF::GetBoundary, boost::python::return_value_policy<boost::python::reference_existing_object>())
	;

	boost::python::class_<TUF8, boost::python::bases<TProblem> >("UF8")
		.def(boost::python::init<size_t>())
		.def("GetBoundary", &TUF::GetBoundary, boost::python::return_value_policy<boost::python::reference_existing_object>())
	;

	boost::python::class_<TUF9, boost::python::bases<TProblem> >("UF9")
		.def(boost::python::init<size_t>())
		.def(boost::python::init<size_t, TReal>())
		.def("GetBoundary", &TUF::GetBoundary, boost::python::return_value_policy<boost::python::reference_existing_object>())
	;

	boost::python::class_<TUF10, boost::python::bases<TProblem> >("UF10")
		.def(boost::python::init<size_t>())
		.def("GetBoundary", &TUF::GetBoundary, boost::python::return_value_policy<boost::python::reference_existing_object>())
	;

	boost::python::class_<TDTLZ1, boost::python::bases<TProblem> >("DTLZ1", boost::python::init<size_t>())
		.def(boost::python::init<size_t, size_t>())
		.def("GetBoundary", &TDTLZ::GetBoundary, boost::python::return_value_policy<boost::python::reference_existing_object>())
	;

	boost::python::class_<TDTLZ2, boost::python::bases<TProblem> >("DTLZ2", boost::python::init<size_t>())
		.def(boost::python::init<size_t, size_t>())
		.def("GetBoundary", &TDTLZ::GetBoundary, boost::python::return_value_policy<boost::python::reference_existing_object>())
	;

	boost::python::class_<TDTLZ3, boost::python::bases<TProblem> >("DTLZ3", boost::python::init<size_t>())
		.def(boost::python::init<size_t, size_t>())
		.def("GetBoundary", &TDTLZ::GetBoundary, boost::python::return_value_policy<boost::python::reference_existing_object>())
	;

	boost::python::class_<TDTLZ4, boost::python::bases<TProblem> >("DTLZ4", boost::python::init<size_t>())
		.def(boost::python::init<size_t, size_t>())
		.def(boost::python::init<size_t, size_t, TReal>())
		.def("GetBoundary", &TDTLZ::GetBoundary, boost::python::return_value_policy<boost::python::reference_existing_object>())
		.def("GetBiasFactor", &TDTLZ4::GetBiasFactor)
	;

	boost::python::class_<TDTLZ5, boost::python::bases<TProblem> >("DTLZ5", boost::python::init<size_t>())
		.def(boost::python::init<size_t, size_t>())
		.def("GetBoundary", &TDTLZ::GetBoundary, boost::python::return_value_policy<boost::python::reference_existing_object>())
	;

	boost::python::class_<TDTLZ6, boost::python::bases<TProblem> >("DTLZ6", boost::python::init<size_t>())
		.def(boost::python::init<size_t, size_t>())
		.def("GetBoundary", &TDTLZ::GetBoundary, boost::python::return_value_policy<boost::python::reference_existing_object>())
	;

	boost::python::class_<TDTLZ7, boost::python::bases<TProblem> >("DTLZ7", boost::python::init<size_t>())
		.def(boost::python::init<size_t, size_t>())
		.def("GetBoundary", &TDTLZ::GetBoundary, boost::python::return_value_policy<boost::python::reference_existing_object>())
	;

	boost::python::class_<TDTLZ5I, boost::python::bases<TProblem> >("DTLZ5I", boost::python::init<size_t, size_t>())
		.def(boost::python::init<size_t, size_t, size_t>())
		.def("GetBoundary", &TDTLZ::GetBoundary, boost::python::return_value_policy<boost::python::reference_existing_object>())
		.def("GetManifold", &TDTLZ5I::GetManifold)
	;

	boost::python::class_<TDTLZ6I, boost::python::bases<TProblem> >("DTLZ6I", boost::python::init<size_t, size_t>())
		.def(boost::python::init<size_t, size_t, size_t>())
		.def("GetBoundary", &TDTLZ::GetBoundary, boost::python::return_value_policy<boost::python::reference_existing_object>())
		.def("GetManifold", &TDTLZ6I::GetManifold)
	;

	boost::python::class_<TConvexDTLZ2, boost::python::bases<TProblem> >("ConvexDTLZ2", boost::python::init<size_t>())
		.def(boost::python::init<size_t, size_t>())
		.def("GetBoundary", &TDTLZ::GetBoundary, boost::python::return_value_policy<boost::python::reference_existing_object>())
	;

	boost::python::class_<TConvexDTLZ3, boost::python::bases<TProblem> >("ConvexDTLZ3", boost::python::init<size_t>())
		.def(boost::python::init<size_t, size_t>())
		.def("GetBoundary", &TDTLZ::GetBoundary, boost::python::return_value_policy<boost::python::reference_existing_object>())
	;

	boost::python::class_<TConvexDTLZ4, boost::python::bases<TProblem> >("ConvexDTLZ4", boost::python::init<size_t>())
		.def(boost::python::init<size_t, size_t>())
		.def(boost::python::init<size_t, size_t, TReal>())
		.def("GetBoundary", &TDTLZ::GetBoundary, boost::python::return_value_policy<boost::python::reference_existing_object>())
	;

	boost::python::class_<TConvexDTLZ5, boost::python::bases<TProblem> >("ConvexDTLZ5", boost::python::init<size_t>())
		.def(boost::python::init<size_t, size_t>())
		.def("GetBoundary", &TDTLZ::GetBoundary, boost::python::return_value_policy<boost::python::reference_existing_object>())
	;

	boost::python::class_<TConvexDTLZ6, boost::python::bases<TProblem> >("ConvexDTLZ6", boost::python::init<size_t>())
		.def(boost::python::init<size_t, size_t>())
		.def("GetBoundary", &TDTLZ::GetBoundary, boost::python::return_value_policy<boost::python::reference_existing_object>())
	;

	boost::python::class_<TConvexDTLZ5I, boost::python::bases<TProblem> >("ConvexDTLZ5I", boost::python::init<size_t, size_t>())
		.def(boost::python::init<size_t, size_t, size_t>())
		.def("GetBoundary", &TDTLZ::GetBoundary, boost::python::return_value_policy<boost::python::reference_existing_object>())
		.def("GetManifold", &TDTLZ5I::GetManifold)
	;

	boost::python::class_<TConvexDTLZ6I, boost::python::bases<TProblem> >("ConvexDTLZ6I", boost::python::init<size_t, size_t>())
		.def(boost::python::init<size_t, size_t, size_t>())
		.def("GetBoundary", &TDTLZ::GetBoundary, boost::python::return_value_policy<boost::python::reference_existing_object>())
		.def("GetManifold", &TDTLZ6I::GetManifold)
	;

	boost::python::class_<TScaledDTLZ2, boost::python::bases<TProblem> >("ScaledDTLZ2", boost::python::init<size_t>())
		.def(boost::python::init<size_t, size_t>())
		.def("GetBoundary", &TDTLZ::GetBoundary, boost::python::return_value_policy<boost::python::reference_existing_object>())
	;

	boost::python::class_<TNegativeDTLZ2, boost::python::bases<TProblem> >("NegativeDTLZ2", boost::python::init<size_t>())
		.def(boost::python::init<size_t, size_t>())
		.def("GetBoundary", &TDTLZ::GetBoundary, boost::python::return_value_policy<boost::python::reference_existing_object>())
		.def("GetMaxDistance", &TNegativeDTLZ2::GetMaxDistance)
	;

	boost::python::class_<TWFG1, boost::python::bases<TProblem> >("WFG1", boost::python::init<size_t>())
		.def(boost::python::init<size_t, size_t, size_t>())
		.def("GetBoundary", &TWFG::GetBoundary, boost::python::return_value_policy<boost::python::reference_existing_object>())
		.def("GetPosDecisions", &TStdWFG::GetPosDecisions)
	;

	boost::python::class_<TWFG2, boost::python::bases<TProblem> >("WFG2", boost::python::init<size_t>())
		.def(boost::python::init<size_t, size_t, size_t>())
		.def("GetBoundary", &TWFG::GetBoundary, boost::python::return_value_policy<boost::python::reference_existing_object>())
		.def("GetPosDecisions", &TStdWFG::GetPosDecisions)
	;

	boost::python::class_<TWFG3, boost::python::bases<TProblem> >("WFG3", boost::python::init<size_t>())
		.def(boost::python::init<size_t, size_t, size_t>())
		.def("GetBoundary", &TWFG::GetBoundary, boost::python::return_value_policy<boost::python::reference_existing_object>())
		.def("GetPosDecisions", &TStdWFG::GetPosDecisions)
	;

	boost::python::class_<TWFG4, boost::python::bases<TProblem> >("WFG4", boost::python::init<size_t>())
		.def(boost::python::init<size_t, size_t, size_t>())
		.def("GetBoundary", &TWFG::GetBoundary, boost::python::return_value_policy<boost::python::reference_existing_object>())
		.def("GetPosDecisions", &TStdWFG::GetPosDecisions)
	;

	boost::python::class_<TWFG5, boost::python::bases<TProblem> >("WFG5", boost::python::init<size_t>())
		.def(boost::python::init<size_t, size_t, size_t>())
		.def("GetBoundary", &TWFG::GetBoundary, boost::python::return_value_policy<boost::python::reference_existing_object>())
		.def("GetPosDecisions", &TStdWFG::GetPosDecisions)
	;

	boost::python::class_<TWFG6, boost::python::bases<TProblem> >("WFG6", boost::python::init<size_t>())
		.def(boost::python::init<size_t, size_t, size_t>())
		.def("GetBoundary", &TWFG::GetBoundary, boost::python::return_value_policy<boost::python::reference_existing_object>())
		.def("GetPosDecisions", &TStdWFG::GetPosDecisions)
	;

	boost::python::class_<TWFG7, boost::python::bases<TProblem> >("WFG7", boost::python::init<size_t>())
		.def(boost::python::init<size_t, size_t, size_t>())
		.def("GetBoundary", &TWFG::GetBoundary, boost::python::return_value_policy<boost::python::reference_existing_object>())
		.def("GetPosDecisions", &TStdWFG::GetPosDecisions)
	;

	boost::python::class_<TWFG8, boost::python::bases<TProblem> >("WFG8", boost::python::init<size_t>())
		.def(boost::python::init<size_t, size_t, size_t>())
		.def("GetBoundary", &TWFG::GetBoundary, boost::python::return_value_policy<boost::python::reference_existing_object>())
		.def("GetPosDecisions", &TStdWFG::GetPosDecisions)
	;

	boost::python::class_<TWFG9, boost::python::bases<TProblem> >("WFG9", boost::python::init<size_t>())
		.def(boost::python::init<size_t, size_t, size_t>())
		.def("GetBoundary", &TWFG::GetBoundary, boost::python::return_value_policy<boost::python::reference_existing_object>())
		.def("GetPosDecisions", &TStdWFG::GetPosDecisions)
	;

	boost::python::class_<TFDA5, boost::python::bases<TProblem> >("FDA5", boost::python::init<size_t, const Progress &>())
		.def(boost::python::init<size_t, const Progress &, size_t, size_t>())
		.def(boost::python::init<size_t, const Progress &, size_t, size_t, size_t>())
		.def("GetBoundary", &TFDA::GetBoundary, boost::python::return_value_policy<boost::python::reference_existing_object>())
		.def("GetNumberOfFixedSteps", &TFDA::GetNumberOfFixedSteps)
		.def("GetNumberOfDistinctSteps", &TFDA::GetNumberOfDistinctSteps)
		.def("CalculateEnvironment", &TFDA::CalculateEnvironment)
	;
}
}
}
}
