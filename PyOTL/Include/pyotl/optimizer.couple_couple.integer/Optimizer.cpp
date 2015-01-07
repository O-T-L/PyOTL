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
#include "Optimizer.h"

namespace pyotl
{
namespace optimizer
{
namespace couple_couple
{
namespace integer
{
BOOST_PYTHON_MODULE(PYMODULE_NAME)
{
#ifdef EXPORT_EPSILON_MOEA
	boost::python::class_<TEpsilon_MOEA, boost::python::bases<TOptimizer> >("Epsilon_MOEA", boost::python::init<TRandom &, TProblem &, const std::vector<TDecision> &, TCrossover &, TMutation &, const std::vector<TReal> &, const std::vector<TReal> &>())
		.def("GetSolutionSet", &GetSolutionSet<TEpsilon_MOEA>)
		.def("GetCrossover", &TEpsilon_MOEA::GetCrossover, boost::python::return_value_policy<boost::python::reference_existing_object>())
		.def("GetMutation", &TEpsilon_MOEA::GetMutation, boost::python::return_value_policy<boost::python::reference_existing_object>())
		.def("GetEpsilon", &TEpsilon_MOEA::GetEpsilon, boost::python::return_value_policy<boost::python::reference_existing_object>())
	;
#endif
#ifdef EXPORT_TDEA
	boost::python::class_<TTDEA, boost::python::bases<TOptimizer> >("TDEA", boost::python::init<TRandom &, TProblem &, const std::vector<TDecision> &, TCrossover &, TMutation &, const TTDEA::TBoundary &, TReal>())
		.def("GetSolutionSet", &GetSolutionSet<TTDEA>)
		.def("GetCrossover", &TTDEA::GetCrossover, boost::python::return_value_policy<boost::python::reference_existing_object>())
		.def("GetMutation", &TTDEA::GetMutation, boost::python::return_value_policy<boost::python::reference_existing_object>())
		.def("GetObjectiveBoundary", &TTDEA::GetObjectiveBoundary, boost::python::return_value_policy<boost::python::reference_existing_object>())
		.def("GetTerritorySize", &TTDEA::GetTerritorySize)
	;
#endif
#ifdef EXPORT_MOEA_D
	boost::python::class_<TMOEA_D_WeightedSum, boost::python::bases<TOptimizer> >("MOEA_D_WeightedSum", boost::python::init<TRandom &, TProblem &, const std::vector<TDecision> &, TCrossover &, TMutation &, std::vector<TMOEA_D_WeightedSum::TPoint> &, size_t>())
		.def("GetWeightVectors", &TMOEA_D::GetWeightVectors, boost::python::return_value_policy<boost::python::reference_existing_object>())
		.def("GetReferencePoint", &TMOEA_D::GetReferencePoint, boost::python::return_value_policy<boost::python::reference_existing_object>())
		.def("GetNeighbors", &TMOEA_D::GetNeighbors, boost::python::return_value_policy<boost::python::reference_existing_object>())
		.def("GetSolutionSet", &TMOEA_D_WeightedSum::GetSolutionSet, boost::python::return_value_policy<boost::python::reference_existing_object>())
		.def("GetCrossover", &TMOEA_D_WeightedSum::GetCrossover, boost::python::return_value_policy<boost::python::reference_existing_object>())
		.def("GetMutation", &TMOEA_D_WeightedSum::GetMutation, boost::python::return_value_policy<boost::python::reference_existing_object>())
	;

	boost::python::class_<TMOEA_D_Tchebycheff, boost::python::bases<TOptimizer> >("MOEA_D_Tchebycheff", boost::python::init<TRandom &, TProblem &, const std::vector<TDecision> &, TCrossover &, TMutation &, std::vector<TMOEA_D_Tchebycheff::TPoint> &, size_t>())
		.def("GetWeightVectors", &TMOEA_D::GetWeightVectors, boost::python::return_value_policy<boost::python::reference_existing_object>())
		.def("GetReferencePoint", &TMOEA_D::GetReferencePoint, boost::python::return_value_policy<boost::python::reference_existing_object>())
		.def("GetNeighbors", &TMOEA_D::GetNeighbors, boost::python::return_value_policy<boost::python::reference_existing_object>())
		.def("GetSolutionSet", &TMOEA_D_Tchebycheff::GetSolutionSet, boost::python::return_value_policy<boost::python::reference_existing_object>())
		.def("GetCrossover", &TMOEA_D_Tchebycheff::GetCrossover, boost::python::return_value_policy<boost::python::reference_existing_object>())
		.def("GetMutation", &TMOEA_D_Tchebycheff::GetMutation, boost::python::return_value_policy<boost::python::reference_existing_object>())
	;

	boost::python::class_<TNormMOEA_D_Tchebycheff, boost::python::bases<TOptimizer> >("NormMOEA_D_Tchebycheff", boost::python::init<TRandom &, TProblem &, const std::vector<TDecision> &, TCrossover &, TMutation &, std::vector<TNormMOEA_D_Tchebycheff::TPoint> &, size_t>())
		.def("GetWeightVectors", &TMOEA_D::GetWeightVectors, boost::python::return_value_policy<boost::python::reference_existing_object>())
		.def("GetReferencePoint", &TMOEA_D::GetReferencePoint, boost::python::return_value_policy<boost::python::reference_existing_object>())
		.def("GetNeighbors", &TMOEA_D::GetNeighbors, boost::python::return_value_policy<boost::python::reference_existing_object>())
		.def("GetSolutionSet", &TNormMOEA_D_Tchebycheff::GetSolutionSet, boost::python::return_value_policy<boost::python::reference_existing_object>())
		.def("GetCrossover", &TNormMOEA_D_Tchebycheff::GetCrossover, boost::python::return_value_policy<boost::python::reference_existing_object>())
		.def("GetMutation", &TNormMOEA_D_Tchebycheff::GetMutation, boost::python::return_value_policy<boost::python::reference_existing_object>())
	;

	boost::python::class_<TMOEA_D_PBI, boost::python::bases<TOptimizer> >("MOEA_D_PBI", boost::python::init<TRandom &, TProblem &, const std::vector<TDecision> &, TCrossover &, TMutation &, std::vector<TMOEA_D_PBI::TPoint> &, size_t, TReal>())
		.def("GetWeightVectors", &TMOEA_D::GetWeightVectors, boost::python::return_value_policy<boost::python::reference_existing_object>())
		.def("GetReferencePoint", &TMOEA_D::GetReferencePoint, boost::python::return_value_policy<boost::python::reference_existing_object>())
		.def("GetNeighbors", &TMOEA_D::GetNeighbors, boost::python::return_value_policy<boost::python::reference_existing_object>())
		.def("GetSolutionSet", &TMOEA_D_PBI::GetSolutionSet, boost::python::return_value_policy<boost::python::reference_existing_object>())
		.def("GetCrossover", &TMOEA_D_PBI::GetCrossover, boost::python::return_value_policy<boost::python::reference_existing_object>())
		.def("GetMutation", &TMOEA_D_PBI::GetMutation, boost::python::return_value_policy<boost::python::reference_existing_object>())
		.def("GetPenalty", &TMOEA_D_PBI::GetPenalty)
	;
#endif
#ifdef EXPORT_SMS_EMOA
	boost::python::class_<TSMS_EMOA, boost::python::bases<TOptimizer> >("SMS_EMOA", boost::python::init<TRandom &, TProblem &, const std::vector<TDecision> &, TCrossover &, TMutation &>())
		.def("GetSolutionSet", &TSMS_EMOA::GetSolutionSet, boost::python::return_value_policy<boost::python::reference_existing_object>())
		.def("GetCrossover", &TSMS_EMOA::GetCrossover, boost::python::return_value_policy<boost::python::reference_existing_object>())
		.def("GetMutation", &TSMS_EMOA::GetMutation, boost::python::return_value_policy<boost::python::reference_existing_object>())
	;

	boost::python::class_<TMonteCarloSMS_EMOA, boost::python::bases<TOptimizer> >("MonteCarloSMS_EMOA", boost::python::init<TRandom &, TProblem &, const std::vector<TDecision> &, TCrossover &, TMutation &, size_t>())
		.def("GetSolutionSet", &TMonteCarloSMS_EMOA::GetSolutionSet, boost::python::return_value_policy<boost::python::reference_existing_object>())
		.def("GetCrossover", &TMonteCarloSMS_EMOA::GetCrossover, boost::python::return_value_policy<boost::python::reference_existing_object>())
		.def("GetMutation", &TMonteCarloSMS_EMOA::GetMutation, boost::python::return_value_policy<boost::python::reference_existing_object>())
		.def("GetSampleSize", &TMonteCarloSMS_EMOA::GetSampleSize)
	;

	boost::python::class_<TMonteCarloHV_SMS_EMOA, boost::python::bases<TOptimizer> >("MonteCarloHV_SMS_EMOA", boost::python::init<TRandom &, TProblem &, const std::vector<TDecision> &, TCrossover &, TMutation &, size_t>())
		.def("GetSolutionSet", &TMonteCarloHV_SMS_EMOA::GetSolutionSet, boost::python::return_value_policy<boost::python::reference_existing_object>())
		.def("GetCrossover", &TMonteCarloHV_SMS_EMOA::GetCrossover, boost::python::return_value_policy<boost::python::reference_existing_object>())
		.def("GetMutation", &TMonteCarloHV_SMS_EMOA::GetMutation, boost::python::return_value_policy<boost::python::reference_existing_object>())
	;
#endif
}
}
}
}
}
