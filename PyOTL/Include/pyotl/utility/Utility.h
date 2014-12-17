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

#include <cassert>
#include <vector>
#include <utility>
#include <boost/python.hpp>
#include <boost/python/stl_iterator.hpp>
#include <boost/numeric/ublas/matrix.hpp>
#include <boost/numeric/ublas/matrix_proxy.hpp>
#include <OTL/Utility/Relation/Pareto.h>
#include <OTL/Utility/Nondominate.h>
#include <OTL/Utility/Weight/NormalBoundaryIntersection.h>
#include <OTL/Optimizer/SPEA2/Truncation.h>
#include <OTL/Utility/Weight/BoundaryNBI.h>
#include <pyotl/Global.h>

namespace pyotl
{
namespace utility
{
template <typename _T>
std::vector<std::vector<_T> > ListVector2VectorVector(const std::list<std::vector<_T> > &listvector)
{
	std::vector<std::vector<_T> > vectorvector(listvector.size());
	size_t index = 0;
	for (auto i = listvector.begin(); i != listvector.end(); ++i)
	{
		vectorvector[index] = *i;
		++index;
	}
	return vectorvector;
}

template <typename _T>
std::list<std::vector<_T> > VectorVector2ListVector(const std::vector<std::vector<_T> > &vectorvector)
{
	std::list<std::vector<_T> > listvector;
	for (size_t i = 0; i < vectorvector.size(); ++i)
		listvector.push_back(vectorvector[i]);
	return listvector;
}

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

template <typename _T>
std::vector<std::vector<_T> > PyListList2VectorVector(boost::python::list listlist)
{
	std::vector<std::vector<_T> > vectorvector(boost::python::len(listlist));
	for (size_t i = 0; i < vectorvector.size(); ++i)
	{
		typedef boost::python::stl_input_iterator<_T> _TIterator;
		vectorvector[i].assign(_TIterator(listlist[i]), _TIterator());
	}
	return vectorvector;
}

template <typename _T>
boost::numeric::ublas::vector<_T> PyTuple2BlasVector(boost::python::tuple tuple)
{
	boost::numeric::ublas::vector<_T> vector(boost::python::len(tuple));
	for (size_t i = 0; i < vector.size(); ++i)
		vector[i] = boost::python::extract<_T>(tuple[i]);
	return vector;
}

template <typename _T>
boost::numeric::ublas::vector<_T> PyList2BlasVector(boost::python::list list)
{
	boost::numeric::ublas::vector<_T> vector(boost::python::len(list));
	for (size_t i = 0; i < vector.size(); ++i)
		vector[i] = boost::python::extract<_T>(list[i]);
	return vector;
}

template <typename _T>
boost::numeric::ublas::matrix<_T> PyListList2BlasMatrix(boost::python::list listlist)
{
	boost::numeric::ublas::matrix<_T> matrix(boost::python::len(listlist), boost::python::len(boost::python::extract<boost::python::list>(listlist[0])));
	for (size_t i = 0; i < matrix.size1(); ++i)
	{
		boost::python::list row = boost::python::extract<boost::python::list>(listlist[i]);
		for (size_t j = 0; j < matrix.size2(); ++j)
			matrix(i, j) = boost::python::extract<_T>(row[j]);
	}
	return matrix;
}

template <typename _T>
boost::numeric::ublas::symmetric_matrix<_T> PyListList2BlasSymmetricMatrix(boost::python::list listlist)
{
	boost::numeric::ublas::symmetric_matrix<_T> matrix(boost::python::len(listlist), boost::python::len(boost::python::extract<boost::python::list>(listlist[0])));
	for (size_t i = 0; i < matrix.size1(); ++i)
	{
		boost::python::list row = boost::python::extract<boost::python::list>(listlist[i]);
		for (size_t j = 0; j <= i; ++j)
			matrix(i, j) = boost::python::extract<_T>(row[j]);
	}
	return matrix;
}

template <typename _T>
std::vector<boost::numeric::ublas::symmetric_matrix<_T> > PyListListList2VectorBlasSymmetricMatrix(boost::python::list listlistlist)
{
	std::vector<boost::numeric::ublas::symmetric_matrix<_T> > matrics(boost::python::len(listlistlist));
	for (size_t i = 0; i < matrics.size(); ++i)
	{
		boost::python::list listlist = boost::python::extract<boost::python::list>(listlistlist[i]);
		matrics[i] = PyListList2BlasSymmetricMatrix<_T>(listlist);
	}
	return matrics;
}

template <typename _T>
boost::python::list BlasVector2PyList(const boost::numeric::ublas::vector<_T> &vector)
{
	boost::python::list list;
	for (size_t i = 0; i < vector.size(); ++i)
		list.append(vector[i]);
	return list;
}

template <typename _T>
boost::python::list BlasMatrix2PyListList(const boost::numeric::ublas::matrix<_T> &matrix)
{
	boost::python::list list;
	for (size_t i = 0; i < matrix.size1(); ++i)
	{
		boost::python::list _list;
		for (size_t j = 0; j < matrix.size2(); ++j)
			_list.append(matrix(i, j));
		list.append(_list);
	}
	return list;
}

template <typename _T>
boost::python::list BlasSymmetricMatrix2PyListList(const boost::numeric::ublas::symmetric_matrix<_T> &matrix)
{
	boost::python::list listlist;
	for (size_t i = 0; i < matrix.size1(); ++i)
	{
		boost::python::list row;
		for (size_t j = 0; j <= i; ++j)
			row.append(matrix(i, j));
		listlist.append(row);
	}
	return listlist;
}

template <typename _T>
boost::python::list VectorBlasMatrix2PyListListList(const std::vector<boost::numeric::ublas::symmetric_matrix<_T> > &matrics)
{
	boost::python::list listlistlist;
	for (size_t i = 0; i < matrics.size(); ++i)
		listlistlist.append(BlasSymmetricMatrix2PyListList(matrics[i]));
	return listlistlist;
}

template <typename _T>
std::vector<std::pair<_T, _T> > PyList2Boundary(boost::python::list listlist)
{
	typedef std::pair<_T, _T> TMinMax;
	typedef std::vector<TMinMax> TBoundary;
	assert(boost::python::len(listlist) > 0);
	TBoundary boundary(boost::python::len(listlist));
	for (size_t i = 0; i < boundary.size(); ++i)
	{
		boost::python::list list = boost::python::extract<boost::python::list>(listlist[i]);
		assert(boost::python::len(list) == 2);
		boundary[i].first = boost::python::extract<_T>(list[0]);
		boundary[i].second = boost::python::extract<_T>(list[1]);
		assert(boundary[i].first <= boundary[i].second);
	}
	return boundary;
}

template <typename _TIndividual>
std::list<_TIndividual> ExtractParetoNondominate(std::list<_TIndividual> &population)
{
	typedef typename _TIndividual::value_type _TReal;
	return otl::utility::ExtractNondominate(population, &otl::utility::relation::Dominate<_TReal>);
}

template <typename _TReal>
std::vector<std::vector<_TReal> > NormalBoundaryIntersection(const size_t dimension, const size_t division)
{
	const auto points = otl::utility::weight::NormalBoundaryIntersection<_TReal>(dimension, division);
	return std::vector<std::vector<_TReal> >(points.begin(), points.end());
}

template <typename _TReal>
std::vector<std::vector<_TReal> > BoundaryNBI(const size_t dimension, const size_t division)
{
	const auto points = otl::utility::weight::BoundaryNBI<_TReal>(dimension, division);
	return std::vector<std::vector<_TReal> >(points.begin(), points.end());
}

template <typename _TReal>
_TReal _Distance(const std::vector<_TReal> *point1, const std::vector<_TReal> *point2)
{
	return sqrt(std::inner_product(point1->begin(), point1->end(), point2->begin(), (_TReal)0
		, std::plus<_TReal>()
		, [](_TReal x, _TReal y)->_TReal{_TReal t = x - y;return t * t;}
	));
}

template <typename _TReal>
void SPEA2Truncation(size_t size, std::list<std::vector<_TReal> > &points)
{
	struct _TPoint : public std::vector<_TReal>
	{
		size_t index_;
	};
	std::list<_TPoint> population;
	std::list<_TPoint *> _population;
	for (auto i = points.begin(); i != points.end(); ++i)
	{
		population.push_back(_TPoint());
		static_cast<std::vector<_TReal> &>(population.back()) = *i;
		_population.push_back(&population.back());
	}
	if (_population.size() > size)
		otl::optimizer::spea2::Truncation<_TReal>(_population.size() - size, _population, &_Distance<_TReal>);
	points.clear();
	for (auto i = _population.begin(); i != _population.end(); ++i)
		points.push_back(static_cast<std::vector<_TReal> &>(**i));
}
}
}
