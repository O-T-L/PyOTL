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
#include <OTL/Initial/Integer/Uniform.h>
#include <pyotl/Global.h>
#include "Initial.h"

namespace pyotl
{
namespace initial
{
namespace integer
{
BOOST_PYTHON_MODULE(PYMODULE_NAME)
{
	boost::python::def("Uniform", &otl::initial::integer::Uniform<TRandom, TInteger>);
	boost::python::def("BatchUniform", &otl::initial::integer::BatchUniform<TRandom, TInteger>);
}
}
}
}
