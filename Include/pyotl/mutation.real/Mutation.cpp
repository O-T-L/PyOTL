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
namespace real
{
BOOST_PYTHON_MODULE(PYMODULE_NAME)
{
	boost::python::class_<TMutation, boost::noncopyable>("Mutation", boost::python::no_init)
		.def("__call__", &TMutation::operator ())
	;

	boost::python::class_<TPolynomialMutation, boost::python::bases<TMutation> >("PolynomialMutation", boost::python::init<TRandom &, TReal, TPolynomialMutation::TBoundary &, TReal>())
		.def("GetProbability", &TPolynomialMutation::GetProbability)
		.def("GetDistributionIndex", &TPolynomialMutation::GetDistributionIndex)
	;
}
}
}
}
