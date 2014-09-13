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
#include <set>
#include <boost/numeric/ublas/symmetric.hpp>
#include <boost/python.hpp>
#include <boost/python/stl_iterator.hpp>
#include <boost/function.hpp>
#include <OTL/Problem/CommunityDiscovery/Metric/Metric.h>
#include <OTL/Problem/CommunityDiscovery/Metric/Q.h>
#include <OTL/Problem/CommunityDiscovery/Metric/QLi.h>
#include "Global.h"

namespace pyotl
{
namespace problem
{
namespace community_discovery
{
typedef boost::numeric::ublas::symmetric_matrix<TReal> TMatrix;
typedef otl::problem::community_discovery::metric::Metric<TMatrix> TMetric;
typedef otl::problem::community_discovery::metric::Q<TMatrix> TQ;
typedef otl::problem::community_discovery::metric::QLi<TMatrix> TQLi;

template <typename _T>
std::vector<_T> PyTuple2Vector(boost::python::tuple tuple)
{
	typedef boost::python::stl_input_iterator<_T> _TIterator;
	return std::vector<_T>(_TIterator(tuple), _TIterator());
}

template <typename _T>
std::vector<_T> PyList2Vector(boost::python::list list)
{
	typedef boost::python::stl_input_iterator<_T> _TIterator;
	return std::vector<_T>(_TIterator(list), _TIterator());
}
}
}
}
