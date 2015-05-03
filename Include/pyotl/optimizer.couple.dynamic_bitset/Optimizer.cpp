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
#include "Optimizer.h"

namespace pyotl
{
namespace optimizer
{
namespace couple
{
namespace dynamic_bitset
{
BOOST_PYTHON_MODULE(PYMODULE_NAME)
{
#ifdef EXPORT_EPSILON_MOEA
	boost::python::class_<TEpsilon_MOEA, boost::python::bases<TOptimizer> >("Epsilon_MOEA", boost::python::init<TRandom &, TProblem &, const std::vector<TDecision> &, TCrossover &, TMutation &, const std::vector<TReal> &>())
		.def("GetSolutionSet", &GetSolutionSet<TEpsilon_MOEA>)
		.def("GetCrossover", &TEpsilon_MOEA::GetCrossover, boost::python::return_value_policy<boost::python::reference_existing_object>())
		.def("GetMutation", &TEpsilon_MOEA::GetMutation, boost::python::return_value_policy<boost::python::reference_existing_object>())
		.def("GetEpsilon", &TEpsilon_MOEA::GetEpsilon, boost::python::return_value_policy<boost::python::reference_existing_object>())
	;
#endif
#ifdef EXPORT_TDEA
	boost::python::class_<TTDEA, boost::python::bases<TOptimizer> >("TDEA", boost::python::init<TRandom &, TProblem &, const std::vector<TDecision> &, TCrossover &, TMutation &, const TTDEA::TBoundary &, TReal>())
		.def("GetSolutionSet", &GetSolutionSet<TTDEA>)
		.def("GetCrossover", &TTDEA::GetCrossover, boost::python::return_value_policy<boost::python::reference_existing_object>())
		.def("GetMutation", &TTDEA::GetMutation, boost::python::return_value_policy<boost::python::reference_existing_object>())
		.def("GetObjectiveBoundary", &TTDEA::GetObjectiveBoundary, boost::python::return_value_policy<boost::python::reference_existing_object>())
		.def("GetTerritorySize", &TTDEA::GetTerritorySize)
	;
#endif
}
}
}
}
}
