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
#include "Mutation.h"

namespace pyotl
{
namespace mutation
{
namespace index
{
BOOST_PYTHON_MODULE(PYMODULE_NAME)
{
	boost::python::class_<TMutation, boost::noncopyable>("Mutation", boost::python::no_init)
		.def("__call__", &TMutation::operator ())
	;

	boost::python::class_<TDisplacementMutation, boost::python::bases<TMutation> >("DisplacementMutation", boost::python::init<TRandom &, TReal>())
		.def("GetProbability", &TDisplacementMutation::GetProbability)
	;

	boost::python::class_<TExchangeMutation, boost::python::bases<TMutation> >("ExchangeMutation", boost::python::init<TRandom &, TReal>())
		.def("GetProbability", &TExchangeMutation::GetProbability)
	;

	boost::python::class_<TInsertionMutation, boost::python::bases<TMutation> >("InsertionMutation", boost::python::init<TRandom &, TReal>())
		.def("GetProbability", &TInsertionMutation::GetProbability)
	;

	boost::python::class_<TInversionMutation, boost::python::bases<TMutation> >("InversionMutation", boost::python::init<TRandom &, TReal>())
		.def("GetProbability", &TInversionMutation::GetProbability)
	;

	boost::python::class_<TSpreadMutation, boost::python::bases<TMutation> >("SpreadMutation", boost::python::init<TRandom &, TReal>())
		.def("GetProbability", &TSpreadMutation::GetProbability)
	;

	boost::python::class_<TBitwiseMutation, boost::python::bases<TMutation> >("BitwiseMutation", boost::python::init<TRandom &, TReal, std::vector<size_t> &>())
		.def("GetProbability", &TBitwiseMutation::GetProbability)
		.def("GetDecisionBits", &TBitwiseMutation::GetDecisionBits, boost::python::return_value_policy<boost::python::reference_existing_object>())
	;
}
}
}
}
