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
#include "Crossover.h"

namespace pyotl
{
namespace crossover
{
namespace dynamic_bitset
{
BOOST_PYTHON_MODULE(PYMODULE_NAME)
{
	boost::python::class_<TCrossover, boost::noncopyable>("Crossover", boost::python::no_init)
		.def("__call__", &TCrossover::operator ())
	;

	boost::python::class_<TCoupleCrossover, boost::noncopyable>("CoupleCrossover", boost::python::no_init)
		.def("__call__", &TCoupleCrossover::operator ())
	;

	boost::python::class_<TCoupleCoupleCrossover, boost::noncopyable>("CoupleCoupleCrossover", boost::python::no_init)
		.def("__call__", &TCoupleCoupleCrossover::operator ())
	;

	boost::python::class_<TTripleCrossover, boost::noncopyable>("TripleCrossover", boost::python::no_init)
		.def("__call__", &TTripleCrossover::operator ())
	;

	boost::python::class_<TTripleTripleCrossover, boost::noncopyable>("TripleTripleCrossover", boost::python::no_init)
		.def("__call__", &TTripleTripleCrossover::operator ())
	;

	boost::python::class_<TXTripleCrossover, boost::noncopyable>("XTripleCrossover", boost::python::no_init)
		.def("__call__", &TXTripleCrossover::operator ())
	;

	boost::python::class_<TCoupleCrossoverAdapter, boost::python::bases<TCrossover> >("CoupleCrossoverAdapter", boost::python::init<TCoupleCrossoverAdapter::TCrossover &, TRandom &>())
		.def("__call__", &TCrossover::operator ())
		.def("GetCrossover", &TCoupleCrossoverAdapter::GetCrossover, boost::python::return_value_policy<boost::python::reference_existing_object>())
	;

	boost::python::class_<TCoupleCoupleCrossoverAdapter, boost::python::bases<TCrossover> >("CoupleCoupleCrossoverAdapter", boost::python::init<TCoupleCoupleCrossoverAdapter::TCrossover &, TRandom &>())
		.def("__call__", &TCrossover::operator ())
		.def("GetCrossover", &TCoupleCoupleCrossoverAdapter::GetCrossover, boost::python::return_value_policy<boost::python::reference_existing_object>())
	;

	boost::python::class_<TTripleCrossoverAdapter, boost::python::bases<TCrossover> >("TripleCrossoverAdapter", boost::python::init<TTripleCrossoverAdapter::TCrossover &, TRandom &>())
		.def("__call__", &TCrossover::operator ())
		.def("GetCrossover", &TTripleCrossoverAdapter::GetCrossover, boost::python::return_value_policy<boost::python::reference_existing_object>())
	;

	boost::python::class_<TTripleTripleCrossoverAdapter, boost::python::bases<TCrossover> >("TripleTripleCrossoverAdapter", boost::python::init<TTripleTripleCrossoverAdapter::TCrossover &, TRandom &>())
		.def("__call__", &TCrossover::operator ())
		.def("GetCrossover", &TTripleTripleCrossoverAdapter::GetCrossover, boost::python::return_value_policy<boost::python::reference_existing_object>())
	;

	boost::python::class_<TXTripleCrossoverAdapter, boost::python::bases<TCrossover> >("XTripleCrossoverAdapter", boost::python::init<TXTripleCrossoverAdapter::TCrossover &, TRandom &>())
		.def("__call__", &TCrossover::operator ())
		.def("GetCrossover", &TXTripleCrossoverAdapter::GetCrossover, boost::python::return_value_policy<boost::python::reference_existing_object>())
	;

	boost::python::class_<TBitsetSinglePointCrossover, boost::python::bases<TCoupleCoupleCrossover> >("BitsetSinglePointCrossover", boost::python::init<TRandom &, TReal>())
		.def("GetProbability", &TBitsetSinglePointCrossover::GetProbability)
	;

	boost::python::class_<TDynamicBitsetUniformCrossover, boost::python::bases<TCoupleCoupleCrossover> >("DynamicBitsetUniformCrossover", boost::python::init<TRandom &, TReal>())
		.def("GetProbability", &TBitsetSinglePointCrossover::GetProbability)
	;
}
}
}
}
