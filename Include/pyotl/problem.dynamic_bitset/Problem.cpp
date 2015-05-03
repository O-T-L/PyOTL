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
#include <boost/python/stl_iterator.hpp>
#include "Problem.h"

namespace pyotl
{
namespace problem
{
namespace dynamic_bitset
{
BOOST_PYTHON_MODULE(PYMODULE_NAME)
{
	boost::python::class_<TProblem, boost::noncopyable>("Problem", boost::python::no_init)
		.def("__call__", &TProblem::operator ())
		.def("Fix", &TProblem::Fix)
		.def("GetNumberOfObjectives", &TProblem::GetNumberOfObjectives)
		.def("GetNumberOfEvaluations", &TProblem::GetNumberOfEvaluations)
	;

	boost::python::class_<TDynamicProblem, boost::noncopyable, boost::python::bases<TProblem> >("DynamicProblem", boost::python::no_init)
		.def("GetProgress", &TDynamicProblem::GetProgress)
	;

	typedef TKnapsack::TMatrix TMatrix;

	boost::python::class_<TKnapsack, boost::python::bases<TProblem> >("Knapsack", boost::python::init<const TMatrix &, const TMatrix &, const std::vector<TReal> &>())
		.def("GetPrice", &TKnapsack::GetPrice, boost::python::return_value_policy<boost::python::reference_existing_object>())
		.def("GetWeight", &TKnapsack::GetWeight, boost::python::return_value_policy<boost::python::reference_existing_object>())
		.def("GetCapacity", &TKnapsack::GetCapacity, boost::python::return_value_policy<boost::python::reference_existing_object>())
		.def("GetPacks", &TKnapsack::GetPacks)
		.def("GetNumberOfBits", &TKnapsack::GetPacks)
	;

	boost::python::class_<TGreedyRepairKnapsack, boost::python::bases<TProblem> >("GreedyRepairKnapsack", boost::python::init<const TMatrix &, const TMatrix &, const std::vector<TReal> &>())
		.def("GetPrice", &TKnapsack::GetPrice, boost::python::return_value_policy<boost::python::reference_existing_object>())
		.def("GetWeight", &TKnapsack::GetWeight, boost::python::return_value_policy<boost::python::reference_existing_object>())
		.def("GetCapacity", &TKnapsack::GetCapacity, boost::python::return_value_policy<boost::python::reference_existing_object>())
		.def("GetPacks", &TKnapsack::GetPacks)
		.def("GetNumberOfBits", &TKnapsack::GetPacks)
	;
}
}
}
}
