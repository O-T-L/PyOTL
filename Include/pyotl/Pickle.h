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

#pragma once

#include <vector>
#include <boost/python.hpp>

namespace pyotl
{
template <typename _T>
struct VectorPickleSuite : boost::python::pickle_suite
{
	static boost::python::tuple getstate(const std::vector<_T> &v)
	{
		return boost::python::tuple(v);
	}

	static void setstate(std::vector<_T> &v, boost::python::tuple state)
	{
		v.resize(boost::python::len(state));
		for(size_t i = 0; i < v.size(); ++i)
			v[i] = boost::python::extract<_T>(state[i]);
	}
};
}
