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

#include <vector>
#include <list>
#include <set>
#include <boost/python.hpp>
#include <boost/python/suite/indexing/vector_indexing_suite.hpp>
#include <boost/serialization/serialization.hpp>
#include <boost/serialization/vector.hpp>
#include <boost/serialization/utility.hpp>
#include <boost/numeric/ublas/matrix.hpp>
#include <boost/numeric/ublas/symmetric.hpp>
#include <OTL/Solution.h>
#include <pyotl/Pickle.h>
#include <pyotl/problem/Progress.h>
#include "Utility.h"

namespace pyotl
{
namespace utility
{
time_t Time(void)
{
	return std::time(0);
}

BOOST_PYTHON_MODULE(PYMODULE_NAME)
{
	typedef std::pair<TReal, TReal> TPair_Real;
	boost::python::class_<TPair_Real>("Pair_Real")
		.def_readwrite("first", &TPair_Real::first)
		.def_readwrite("second", &TPair_Real::second)
	;

	typedef std::pair<TInteger, TInteger> TPair_Integer;
	boost::python::class_<TPair_Integer>("Pair_Integer")
		.def_readwrite("first", &TPair_Integer::first)
		.def_readwrite("second", &TPair_Integer::second)
	;

	typedef std::pair<size_t, size_t> TPair_size_t;
	boost::python::class_<TPair_size_t>("Pair_size_t")
		.def_readwrite("first", &TPair_size_t::first)
		.def_readwrite("second", &TPair_size_t::second)
	;

	typedef std::vector<std::pair<TReal, TReal> > TVectorPair_Real;
	boost::python::class_<TVectorPair_Real>("VectorPair_Real")
		.def(boost::python::vector_indexing_suite<TVectorPair_Real>())
	;

	typedef std::vector<std::pair<TInteger, TInteger> > TVectorPair_Integer;
	boost::python::class_<TVectorPair_Integer>("VectorPair_Integer")
		.def(boost::python::vector_indexing_suite<TVectorPair_Integer>())
	;

	typedef std::vector<std::pair<size_t, size_t> > TVectorPair_size_t;
	boost::python::class_<TVectorPair_size_t>("VectorPair_size_t")
		.def(boost::python::vector_indexing_suite<TVectorPair_size_t>())
	;

	typedef std::vector<TReal> TVector_Real;
	boost::python::class_<TVector_Real>("Vector_Real")
		.def(boost::python::vector_indexing_suite<TVector_Real>())
		.def_pickle(VectorPickleSuite<TReal>())
	;

	typedef std::vector<TInteger> TVector_Integer;
	boost::python::class_<TVector_Integer>("Vector_Integer")
		.def(boost::python::vector_indexing_suite<TVector_Integer>())
		.def_pickle(VectorPickleSuite<TInteger>())
	;

	typedef std::vector<size_t> TVector_size_t;
	boost::python::class_<TVector_size_t>("Vector_size_t")
		.def(boost::python::vector_indexing_suite<TVector_size_t>())
		.def_pickle(VectorPickleSuite<size_t>())
	;

	typedef std::vector<bool> TVector_bool;
	boost::python::class_<TVector_bool>("Vector_bool")
		.def(boost::python::vector_indexing_suite<TVector_bool>())
		.def_pickle(VectorPickleSuite<bool>())
	;

	typedef std::set<size_t> TSet_size_t;
	boost::python::class_<TSet_size_t>("Set_size_t");

	typedef std::vector<std::vector<TReal> > TVectorVector_Real;
	boost::python::class_<TVectorVector_Real>("VectorVector_Real")
		.def(boost::python::vector_indexing_suite<TVectorVector_Real>())
	;

	typedef std::vector<std::vector<TInteger> > TVectorVector_Integer;
	boost::python::class_<TVectorVector_Integer>("VectorVector_Integer")
		.def(boost::python::vector_indexing_suite<TVectorVector_Integer>())
	;

	typedef std::vector<std::vector<size_t> > TVectorVector_size_t;
	boost::python::class_<TVectorVector_size_t>("VectorVector_size_t")
		.def(boost::python::vector_indexing_suite<TVectorVector_size_t>())
	;

	typedef std::vector<std::set<size_t> > TVectorSet_size_t;
	boost::python::class_<TVectorSet_size_t>("VectorSet_size_t")
		.def(boost::python::vector_indexing_suite<TVectorSet_size_t>())
	;

	typedef std::vector<std::vector<std::vector<size_t> > > TVectorVectorVector_size_t;
	boost::python::class_<TVectorVectorVector_size_t>("VectorVectorVector_size_t")
		.def(boost::python::vector_indexing_suite<TVectorVectorVector_size_t>())
	;

	typedef std::list<std::vector<TReal> > TListVector_Real;
	boost::python::class_<TListVector_Real>("ListVector_Real");

	typedef boost::numeric::ublas::vector<TReal> TBlasVector_Real;
	boost::python::class_<TBlasVector_Real>("BlasVector_Real");

	typedef boost::numeric::ublas::matrix<TReal> TBlasMatrix_Real;
	boost::python::class_<TBlasMatrix_Real>("BlasMatrix_Real");

	typedef boost::numeric::ublas::symmetric_matrix<TReal> TBlasSymmetricMatrix_Real;
	boost::python::class_<TBlasSymmetricMatrix_Real>("BlasSymmetricMatrix_Real");

	typedef std::vector<boost::numeric::ublas::symmetric_matrix<TReal> > TVectorBlasSymmetricMatrix_Real;
	boost::python::class_<TVectorBlasSymmetricMatrix_Real>("VectorBlasSymmetricMatrix_Real");

	boost::python::class_<TDynamicBitset>("DynamicBitset");

	typedef std::vector<TDynamicBitset> TVector_DynamicBitset;
	boost::python::class_<TVector_DynamicBitset>("Vector_DynamicBitset")
		.def(boost::python::vector_indexing_suite<TVector_DynamicBitset>())
	;

	boost::python::class_<pyotl::problem::Progress>("Progress")
		.def_readwrite("progress_", &pyotl::problem::Progress::progress_)
	;

	boost::python::class_<TRandom>("Random")
		.def(boost::python::init<TRandom::result_type>())
	;

	boost::python::def("Time", &Time);
	boost::python::def("ListVector2VectorVector_Real", &ListVector2VectorVector<TReal>);
	boost::python::def("VectorVector2ListVector_Real", &VectorVector2ListVector<TReal>);
	boost::python::def("PyTuple2Vector_Real", &PyTuple2Vector<TReal>);
	boost::python::def("PyList2Vector_Real", &PyList2Vector<TReal>);
	boost::python::def("PyTuple2Vector_Integer", &PyTuple2Vector<TInteger>);
	boost::python::def("PyList2Vector_Integer", &PyList2Vector<TInteger>);
	boost::python::def("PyTuple2Vector_size_t", &PyTuple2Vector<size_t>);
	boost::python::def("PyList2Vector_size_t", &PyList2Vector<size_t>);
	boost::python::def("PyTuple2Vector_bool", &PyTuple2Vector<bool>);
	boost::python::def("PyList2Vector_bool", &PyList2Vector<bool>);
	boost::python::def("PyListList2VectorVector_Real", &PyListList2VectorVector<TReal>);
	boost::python::def("PyList2BlasVector_Real", &PyList2BlasVector<TReal>);
	boost::python::def("PyTuple2BlasVector_Real", &PyTuple2BlasVector<TReal>);
	boost::python::def("PyListList2BlasMatrix_Real", &PyListList2BlasMatrix<TReal>);
	boost::python::def("PyListList2BlasSymmetricMatrix_Real", &PyListList2BlasSymmetricMatrix<TReal>);
	boost::python::def("PyListListList2VectorBlasSymmetricMatrix_Real", &PyListListList2VectorBlasSymmetricMatrix<TReal>);
	boost::python::def("BlasVector2PyList_Real", &BlasVector2PyList<TReal>);
	boost::python::def("BlasMatrix2PyListList_Real", &BlasMatrix2PyListList<TReal>);
	boost::python::def("BlasSymmetricMatrix2PyListList_Real", &BlasSymmetricMatrix2PyListList<TReal>);
	boost::python::def("VectorBlasMatrix2PyListListList_Real", &VectorBlasMatrix2PyListListList<TReal>);
	boost::python::def("PyList2Boundary_Real", &PyList2Boundary<TReal>);
	boost::python::def("PyList2Boundary_Integer", &PyList2Boundary<TInteger>);
	boost::python::def("ExtractParetoNondominate_Vector_Real", &ExtractParetoNondominate<TVector_Real>);
	boost::python::def("NormalBoundaryIntersection_Real", &NormalBoundaryIntersection<TReal>);
	boost::python::def("SPEA2Truncation_Real", &SPEA2Truncation<TReal>);
}
}
}
