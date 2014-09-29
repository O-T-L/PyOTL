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
#include <boost/python/suite/indexing/vector_indexing_suite.hpp>
#include <boost/serialization/serialization.hpp>
#include <boost/serialization/vector.hpp>
#include <pyotl/Pickle.h>
#include "Problem.h"

namespace pyotl
{
namespace problem
{
namespace community_discovery
{
BOOST_PYTHON_MODULE(PYMODULE_NAME)
{
	boost::python::class_<TMetric, boost::noncopyable>("Metric", boost::python::no_init)
		.def_readonly("maximize_", &TMetric::maximize_)
		.def("__call__", &TMetric::operator ())
	;

	boost::python::class_<TQ, boost::python::bases<TMetric> >("Q");
	boost::python::class_<TQLi, boost::python::bases<TMetric> >("QLi");
	boost::python::class_<TMinMaxCut, boost::python::bases<TMetric> >("MinMaxCut");

	typedef std::vector<TMetric *> TVector_Metric;
	boost::python::class_<TVector_Metric>("Vector_Metric")
		.def(boost::python::vector_indexing_suite<TVector_Metric>())
		.def_pickle(VectorPickleSuite<TMetric *>())
	;

	boost::python::def("PyTuple2Vector_Metric", &PyTuple2Vector<TMetric *>);
	boost::python::def("PyList2Vector_Metric", &PyList2Vector<TMetric *>);
}
}
}
}
