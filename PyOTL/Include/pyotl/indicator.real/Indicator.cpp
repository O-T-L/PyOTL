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
#include "Indicator.h"

namespace pyotl
{
namespace indicator
{
BOOST_PYTHON_MODULE(PYMODULE_NAME)
{
	boost::python::class_<TIndicator, boost::noncopyable>("Indicator", boost::python::no_init)
		.def("__call__", static_cast<TIndicator::TMetric (TIndicator::*)(const std::vector<TIndicator::TPoint> &)>(&TIndicator::operator ()))
	;

	boost::python::class_<TDTLZ2GD, boost::python::bases<TIndicator> >("DTLZ2GD")
		.enable_pickling()
	;

	boost::python::class_<TWFG4GD, boost::python::bases<TIndicator> >("WFG4GD")
		.enable_pickling()
	;

	boost::python::class_<TFrontGD, boost::python::bases<TIndicator> >("FrontGD", boost::python::init<std::vector<TFrontGD::TPoint> &>())
		.def("GetFront", &TFrontGD::GetFront, boost::python::return_value_policy<boost::python::reference_existing_object>())
	;

	boost::python::class_<TInvertedGenerationalDistance, boost::python::bases<TIndicator> >("InvertedGenerationalDistance", boost::python::init<std::vector<TInvertedGenerationalDistance::TPoint> &>())
		.def("GetFront", &TInvertedGenerationalDistance::GetFront, boost::python::return_value_policy<boost::python::reference_existing_object>())
	;

	boost::python::class_<TAdditiveEpsilon, boost::python::bases<TIndicator> >("AdditiveEpsilon", boost::python::init<std::vector<TEpsilon::TPoint> &>())
		.def("GetFront", &TEpsilon::GetFront, boost::python::return_value_policy<boost::python::reference_existing_object>())
	;

	boost::python::class_<TMultiplicativeEpsilon, boost::python::bases<TIndicator> >("MultiplicativeEpsilon", boost::python::init<std::vector<TEpsilon::TPoint> &>())
		.def("GetFront", &TEpsilon::GetFront, boost::python::return_value_policy<boost::python::reference_existing_object>())
	;

	boost::python::class_<TSpacing, boost::python::bases<TIndicator> >("Spacing")
		.enable_pickling()
	;

	boost::python::class_<TMaximumSpread, boost::python::bases<TIndicator> >("MaximumSpread")
		.enable_pickling()
	;

	boost::python::class_<TMaximumSpread1, boost::python::bases<TIndicator> >("MaximumSpread1", boost::python::init<TMaximumSpread1::TBoundary &>())
		.def("GetBoundary", &TMaximumSpread1::GetBoundary, boost::python::return_value_policy<boost::python::reference_existing_object>())
	;

	boost::python::class_<TMaximumSpread2, boost::python::bases<TIndicator> >("MaximumSpread2", boost::python::init<TMaximumSpread2::TBoundary &>())
		.def("GetBoundary", &TMaximumSpread2::GetBoundary, boost::python::return_value_policy<boost::python::reference_existing_object>())
	;

	boost::python::class_<TDiversityMetric, boost::python::bases<TIndicator> >("DiversityMetric", boost::python::init<TDiversityMetric::TBoundary &, std::vector<size_t> &, std::vector<TDiversityMetric::TPoint> &>())
		.def("GetBoundary", &TDiversityMetric::GetBoundary, boost::python::return_value_policy<boost::python::reference_existing_object>())
		.def("GetDivision", &TDiversityMetric::GetDivision, boost::python::return_value_policy<boost::python::reference_existing_object>())
		.def("GetFront", &TDiversityMetric::GetFront, boost::python::return_value_policy<boost::python::reference_existing_object>())
	;

	boost::python::class_<TR2, boost::python::bases<TIndicator> >("R2", boost::python::init<TR2::TPoint &, std::vector<TR2::TPoint> &>())
		.def("GetReferencePoint", &TR2::GetReferencePoint, boost::python::return_value_policy<boost::python::reference_existing_object>())
		.def("GetWeightVectors", &TR2::GetWeightVectors, boost::python::return_value_policy<boost::python::reference_existing_object>())
	;

	boost::python::class_<TMonteCarloHV, boost::python::bases<TIndicator> >("MonteCarloHV", boost::python::init<TMonteCarloHV::TPoint &, TRandom &, size_t>())
		.def("GetReferencePoint", &THypervolume::GetReferencePoint, boost::python::return_value_policy<boost::python::reference_existing_object>())
	;

	boost::python::class_<TRecursiveHV, boost::python::bases<TIndicator> >("RecursiveHV", boost::python::init<TRecursiveHV::TPoint &>())
		.def("GetReferencePoint", &THypervolume::GetReferencePoint, boost::python::return_value_policy<boost::python::reference_existing_object>())
	;
}
}
}
