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
#include <OTL/Optimizer/MOEA-D/Weight/AdjustWeight.h>
#include <OTL/Optimizer/MOEA-D/Weight/NormalizeWeight.h>
#include <pyotl/Global.h>

namespace pyotl
{
namespace optimizer
{
namespace moea_d
{
BOOST_PYTHON_MODULE(PYMODULE_NAME)
{
	boost::python::def("AdjustWeight_Real", &otl::optimizer::moea_d::weight::AdjustWeight<TReal>);
	boost::python::def("NormalizeWeight_Real", &otl::optimizer::moea_d::weight::NormalizeWeight<TReal>);
}
}
}
}
