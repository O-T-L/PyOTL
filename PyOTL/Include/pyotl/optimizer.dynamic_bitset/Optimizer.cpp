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
#include "Optimizer.h"

namespace pyotl
{
namespace optimizer
{
namespace dynamic_bitset
{
BOOST_PYTHON_MODULE(PYMODULE_NAME)
{
	boost::python::class_<TSolution>("Solution")
		.def_readonly("objective_", &TSolution::objective_)
		.def_readonly("inequality_", &TSolution::inequality_)
		.def_readonly("equality_", &TSolution::equality_)
		.def_readwrite("decision_", &TSolution::decision_)
		.def("__call__", &TSolution::operator ())
	;
	boost::python::class_<std::vector<TSolution> >("SolutionSet")
		.def(boost::python::vector_indexing_suite<std::vector<TSolution> >())
	;

	boost::python::class_<TOptimizer, boost::noncopyable>("Optimizer", boost::python::no_init)
		.def("__call__", &TOptimizer::operator ())
		.def("GetProblem", &TOptimizer::GetProblem, boost::python::return_value_policy<boost::python::reference_existing_object>())
	;
#ifdef EXPORT_SGA
	boost::python::class_<TSGA, boost::python::bases<TOptimizer> >("SGA", boost::python::init<TRandom &, TProblem &, const std::vector<TDecision> &, TCrossover &, TMutation &>())
		.def("GetSolutionSet", &TSGA::GetSolutionSet, boost::python::return_value_policy<boost::python::reference_existing_object>())
		.def("GetCrossover", &TSGA::GetCrossover, boost::python::return_value_policy<boost::python::reference_existing_object>())
		.def("GetMutation", &TSGA::GetMutation, boost::python::return_value_policy<boost::python::reference_existing_object>())
	;
#endif
#ifdef EXPORT_RWSGA
	boost::python::class_<TRWSGA::TIndividual, boost::python::bases<TSolution> >("RWSGA_Individual")
		.def_readonly("fitness_", &TRWSGA::TIndividual::fitness_)
	;
	boost::python::class_<TRWSGA::TSolutionSet>("RWSGA_Population")
		.def(boost::python::vector_indexing_suite<TRWSGA::TSolutionSet>())
	;
	boost::python::class_<TRWSGA, boost::python::bases<TOptimizer> >("RWSGA", boost::python::init<TRandom &, TProblem &, const std::vector<TDecision> &, TCrossover &, TMutation &>())
		.def("GetSolutionSet", &TRWSGA::GetSolutionSet, boost::python::return_value_policy<boost::python::reference_existing_object>())
		.def("GetCrossover", &TRWSGA::GetCrossover, boost::python::return_value_policy<boost::python::reference_existing_object>())
		.def("GetMutation", &TRWSGA::GetMutation, boost::python::return_value_policy<boost::python::reference_existing_object>())
	;
#endif
#ifdef EXPORT_NSGA_II
	boost::python::class_<TNSGA_II::TIndividual, boost::python::bases<TSolution> >("NSGA_II_Individual")
		.def_readonly("crowdingDistance_", &TNSGA_II::TIndividual::crowdingDistance_)
	;
	boost::python::class_<TNSGA_II::TSolutionSet>("NSGA_II_Population")
		.def(boost::python::vector_indexing_suite<TNSGA_II::TSolutionSet>())
	;
	boost::python::class_<TNSGA_II, boost::python::bases<TOptimizer> >("NSGA_II", boost::python::init<TRandom &, TProblem &, const std::vector<TDecision> &, TCrossover &, TMutation &>())
		.def("GetSolutionSet", &TNSGA_II::GetSolutionSet, boost::python::return_value_policy<boost::python::reference_existing_object>())
		.def("GetCrossover", &TNSGA_II::GetCrossover, boost::python::return_value_policy<boost::python::reference_existing_object>())
		.def("GetMutation", &TNSGA_II::GetMutation, boost::python::return_value_policy<boost::python::reference_existing_object>())
	;
	boost::python::class_<TConstrainedNSGA_II, boost::python::bases<TOptimizer> >("ConstrainedNSGA_II", boost::python::init<TRandom &, TProblem &, const std::vector<TDecision> &, TCrossover &, TMutation &>())
		.def("GetSolutionSet", &TConstrainedNSGA_II::GetSolutionSet, boost::python::return_value_policy<boost::python::reference_existing_object>())
		.def("GetCrossover", &TConstrainedNSGA_II::GetCrossover, boost::python::return_value_policy<boost::python::reference_existing_object>())
		.def("GetMutation", &TConstrainedNSGA_II::GetMutation, boost::python::return_value_policy<boost::python::reference_existing_object>())
	;
#endif
#ifdef EXPORT_SPEA2
	boost::python::class_<TSPEA2::TIndividual, boost::python::bases<TSolution> >("SPEA2_Individual")
		.def_readonly("rawFitness_", &TSPEA2::TIndividual::rawFitness_)
		.def_readonly("density_", &TSPEA2::TIndividual::density_)
		.def_readonly("fitness_", &TSPEA2::TIndividual::fitness_)
	;
	boost::python::class_<TSPEA2::TSolutionSet>("SPEA2_Population")
		.def(boost::python::vector_indexing_suite<TSPEA2::TSolutionSet>())
	;
	boost::python::class_<TSPEA2, boost::python::bases<TOptimizer> >("SPEA2", boost::python::init<TRandom &, TProblem &, const std::vector<TDecision> &, TCrossover &, TMutation &>())
		.def("GetSolutionSet", &TSPEA2::GetSolutionSet, boost::python::return_value_policy<boost::python::reference_existing_object>())
		.def("GetCrossover", &TSPEA2::GetCrossover, boost::python::return_value_policy<boost::python::reference_existing_object>())
		.def("GetMutation", &TSPEA2::GetMutation, boost::python::return_value_policy<boost::python::reference_existing_object>())
	;
#endif
#ifdef EXPORT_SPEA2_SDE
	boost::python::class_<TSPEA2_SDE, boost::python::bases<TOptimizer> >("SPEA2_SDE", boost::python::init<TRandom &, TProblem &, const std::vector<TDecision> &, TCrossover &, TMutation &>())
		.def("GetSolutionSet", &TSPEA2_SDE::GetSolutionSet, boost::python::return_value_policy<boost::python::reference_existing_object>())
		.def("GetCrossover", &TSPEA2_SDE::GetCrossover, boost::python::return_value_policy<boost::python::reference_existing_object>())
		.def("GetMutation", &TSPEA2_SDE::GetMutation, boost::python::return_value_policy<boost::python::reference_existing_object>())
	;
#endif
#ifdef EXPORT_IBEA
	boost::python::class_<TIBEA::TIndividual, boost::python::bases<TSolution> >("IBEA_Individual")
		.def_readonly("fitness_", &TIBEA::TIndividual::fitness_)
	;
	boost::python::class_<TIBEA::TSolutionSet>("IBEA_Population")
		.def(boost::python::vector_indexing_suite<TIBEA::TSolutionSet>())
	;

	boost::python::class_<TIBEA_Epsilon, boost::python::bases<TOptimizer> >("IBEA_Epsilon", boost::python::init<TRandom &, TProblem &, const std::vector<TDecision> &, TCrossover &, TMutation &, TReal>())
		.def("GetSolutionSet", &TIBEA::GetSolutionSet, boost::python::return_value_policy<boost::python::reference_existing_object>())
		.def("GetCrossover", &TIBEA::GetCrossover, boost::python::return_value_policy<boost::python::reference_existing_object>())
		.def("GetMutation", &TIBEA::GetMutation, boost::python::return_value_policy<boost::python::reference_existing_object>())
	;

	boost::python::class_<TIBEA_HD, boost::python::bases<TOptimizer> >("IBEA_HD", boost::python::init<TRandom &, TProblem &, const std::vector<TDecision> &, TCrossover &, TMutation &, TReal>())
		.def("GetSolutionSet", &TIBEA::GetSolutionSet, boost::python::return_value_policy<boost::python::reference_existing_object>())
		.def("GetCrossover", &TIBEA::GetCrossover, boost::python::return_value_policy<boost::python::reference_existing_object>())
		.def("GetMutation", &TIBEA::GetMutation, boost::python::return_value_policy<boost::python::reference_existing_object>())
	;
#endif
#ifdef EXPORT_CDAS
	boost::python::class_<TCDAS::TIndividual, boost::python::bases<TSolution> >("CDAS_Individual")
		.def_readonly("crowdingDistance_", &TCDAS::TIndividual::crowdingDistance_)
		.def_readonly("convertedObjective_", &TCDAS::TIndividual::convertedObjective_)
	;
	boost::python::class_<TCDAS::TSolutionSet>("CDAS_Population")
		.def(boost::python::vector_indexing_suite<TCDAS::TSolutionSet>())
	;
	boost::python::class_<TCDAS, boost::python::bases<TOptimizer> >("CDAS", boost::python::init<TRandom &, TProblem &, const std::vector<TDecision> &, TCrossover &, TMutation &, const std::vector<TReal> &>())
		.def("GetSolutionSet", &TCDAS::GetSolutionSet, boost::python::return_value_policy<boost::python::reference_existing_object>())
		.def("GetCrossover", &TCDAS::GetCrossover, boost::python::return_value_policy<boost::python::reference_existing_object>())
		.def("GetMutation", &TCDAS::GetMutation, boost::python::return_value_policy<boost::python::reference_existing_object>())
		.def("GetAngle", &TCDAS::GetAngle, boost::python::return_value_policy<boost::python::reference_existing_object>())
	;
#endif
#ifdef EXPORT_EPSILON_MOEA
	boost::python::class_<TEpsilon_MOEA::TIndividual, boost::python::bases<TSolution> >("Epsilon_MOEA_Individual")
		.def_readonly("point_", &TEpsilon_MOEA::TIndividual::point_)
	;
	boost::python::class_<TEpsilon_MOEA::TSolutionSet>("Epsilon_MOEA_Archive");
	boost::python::class_<TEpsilon_MOEA::TPopulation>("Epsilon_MOEA_Population")
		.def(boost::python::vector_indexing_suite<TEpsilon_MOEA::TPopulation>())
	;
#endif
#ifdef EXPORT_TDEA
	boost::python::class_<TTDEA::TIndividual, boost::python::bases<TSolution> >("TDEA_Individual")
		.def_readonly("scaledObjective_", &TTDEA::TIndividual::scaledObjective_)
	;
	boost::python::class_<TTDEA::TSolutionSet>("TDEA_Archive");
	boost::python::class_<TTDEA::TPopulation>("TDEA_Population")
		.def(boost::python::vector_indexing_suite<TTDEA::TPopulation>())
	;
#endif
#ifdef EXPORT_ISNPS
	boost::python::class_<TISNPS::TIndividual, boost::python::bases<TSolution> >("ISNPS_Individual")
		.def_readonly("convergence_", &TISNPS::TIndividual::convergence_)
		.def_readonly("distribution_", &TISNPS::TIndividual::distribution_)
	;
	boost::python::class_<TISNPS::TSolutionSet>("ISNPS_Population")
		.def(boost::python::vector_indexing_suite<TISNPS::TSolutionSet>())
	;
	boost::python::class_<TISNPS, boost::python::bases<TOptimizer> >("ISNPS", boost::python::init<TRandom &, TProblem &, const std::vector<TDecision> &, TCrossover &, TMutation &, const boost::numeric::ublas::vector<TReal> &, TReal, TReal, TReal>())
		.def("GetSolutionSet", &TISNPS::GetSolutionSet, boost::python::return_value_policy<boost::python::reference_existing_object>())
		.def("GetCrossover", &TISNPS::GetCrossover, boost::python::return_value_policy<boost::python::reference_existing_object>())
		.def("GetMutation", &TISNPS::GetMutation, boost::python::return_value_policy<boost::python::reference_existing_object>())
		.def("GetAngle1", &TISNPS::GetAngle1)
		.def("GetAngle2", &TISNPS::GetAngle2)
		.def("GetRounds", &TISNPS::GetRounds)
	;
#endif
#ifdef EXPORT_NSGA_III
	boost::python::class_<TNSGA_III::TIndividual, boost::python::bases<TSolution> >("NSGA_III_Individual")
		.def_readonly("translatedObjective_", &TNSGA_III::TIndividual::translatedObjective_)
		.def_readonly("minDistance_", &TNSGA_III::TIndividual::minDistance_)
	;
	boost::python::class_<TNSGA_III::TSolutionSet>("NSGA_III_Population")
		.def(boost::python::vector_indexing_suite<TNSGA_III::TSolutionSet>())
	;
	boost::python::class_<TNSGA_III, boost::python::bases<TOptimizer> >("NSGA_III", boost::python::init<TRandom &, TProblem &, const std::vector<TDecision> &, TCrossover &, TMutation &, const std::vector<TNSGA_III::TPoint> &>())
		.def(boost::python::init<TRandom &, TProblem &, const std::vector<TDecision> &, TCrossover &, TMutation &, const std::vector<TNSGA_III::TPoint> &, TReal>())
		.def("GetSolutionSet", &TNSGA_III::GetSolutionSet, boost::python::return_value_policy<boost::python::reference_existing_object>())
		.def("GetCrossover", &TNSGA_III::GetCrossover, boost::python::return_value_policy<boost::python::reference_existing_object>())
		.def("GetMutation", &TNSGA_III::GetMutation, boost::python::return_value_policy<boost::python::reference_existing_object>())
		.def("GetReferenceSet", &TNSGA_III::GetReferenceSet, boost::python::return_value_policy<boost::python::reference_existing_object>())
		.def("GetEpsilon", &TNSGA_III::GetEpsilon)
	;
#endif
#ifdef EXPORT_AR
	boost::python::class_<TAR::TIndividual, boost::python::bases<TSolution> >("AR_Individual")
		.def_readonly("averageRank_", &TAR::TIndividual::averageRank_)
	;
	boost::python::class_<TAR::TSolutionSet>("AR_Population")
		.def(boost::python::vector_indexing_suite<TAR::TSolutionSet>())
	;
	boost::python::class_<TAR, boost::python::bases<TOptimizer> >("AR", boost::python::init<TRandom &, TProblem &, const std::vector<TDecision> &, TCrossover &, TMutation &>())
		.def("GetSolutionSet", &TAR::GetSolutionSet, boost::python::return_value_policy<boost::python::reference_existing_object>())
		.def("GetCrossover", &TAR::GetCrossover, boost::python::return_value_policy<boost::python::reference_existing_object>())
		.def("GetMutation", &TAR::GetMutation, boost::python::return_value_policy<boost::python::reference_existing_object>())
	;
#endif
#ifdef EXPORT_AR_CD_
	boost::python::class_<TAR_CD_::TIndividual, boost::python::bases<TSolution> >("AR_CD__Individual")
		.def_readonly("averageRank_", &TAR_CD_::TIndividual::averageRank_)
		.def_readonly("crowdingDistance_", &TAR_CD_::TIndividual::crowdingDistance_)
	;
	boost::python::class_<TAR_CD_::TSolutionSet>("AR_CD__Population")
		.def(boost::python::vector_indexing_suite<TAR_CD_::TSolutionSet>())
	;
	boost::python::class_<TAR_CD_, boost::python::bases<TOptimizer> >("AR_CD_", boost::python::init<TRandom &, TProblem &, const std::vector<TDecision> &, TCrossover &, TMutation &>())
		.def("GetSolutionSet", &TAR_CD_::GetSolutionSet, boost::python::return_value_policy<boost::python::reference_existing_object>())
		.def("GetCrossover", &TAR_CD_::GetCrossover, boost::python::return_value_policy<boost::python::reference_existing_object>())
		.def("GetMutation", &TAR_CD_::GetMutation, boost::python::return_value_policy<boost::python::reference_existing_object>())
	;
#endif
#ifdef EXPORT_AR_DMO
	boost::python::class_<TAR_DMO::TIndividual, boost::python::bases<TSolution> >("AR_DMO_Individual")
		.def_readonly("averageRank_", &TAR_DMO::TIndividual::averageRank_)
		.def_readonly("crowdingDistance_", &TAR_DMO::TIndividual::crowdingDistance_)
	;
	boost::python::class_<TAR_DMO::TSolutionSet>("AR_DMO_Population")
		.def(boost::python::vector_indexing_suite<TAR_DMO::TSolutionSet>())
	;
	boost::python::class_<TAR_DMO, boost::python::bases<TOptimizer> >("AR_DMO", boost::python::init<TRandom &, TProblem &, const std::vector<TDecision> &, TCrossover &, TMutation &, const TAR_DMO::TBoundary &>())
		.def("GetSolutionSet", &TAR_DMO::GetSolutionSet, boost::python::return_value_policy<boost::python::reference_existing_object>())
		.def("GetCrossover", &TAR_DMO::GetCrossover, boost::python::return_value_policy<boost::python::reference_existing_object>())
		.def("GetMutation", &TAR_DMO::GetMutation, boost::python::return_value_policy<boost::python::reference_existing_object>())
	;
#endif
#ifdef EXPORT_G_NSGA_II
	boost::python::class_<TG_NSGA_II, boost::python::bases<TOptimizer> >("G_NSGA_II", boost::python::init<TRandom &, TProblem &, const std::vector<TDecision> &, TCrossover &, TMutation &, const std::vector<TReal> &>())
		.def("GetSolutionSet", &TG_NSGA_II::GetSolutionSet, boost::python::return_value_policy<boost::python::reference_existing_object>())
		.def("GetCrossover", &TG_NSGA_II::GetCrossover, boost::python::return_value_policy<boost::python::reference_existing_object>())
		.def("GetMutation", &TG_NSGA_II::GetMutation, boost::python::return_value_policy<boost::python::reference_existing_object>())
		.def("GetReferencePoint", &TG_NSGA_II::GetReferencePoint, boost::python::return_value_policy<boost::python::reference_existing_object>())
	;
#endif
#ifdef EXPORT_R_NSGA_II
	boost::python::class_<TR_NSGA_II, boost::python::bases<TOptimizer> >("R_NSGA_II", boost::python::init<TRandom &, TProblem &, const std::vector<TDecision> &, TCrossover &, TMutation &, const std::vector<TReal> &, TReal>())
		.def("GetSolutionSet", &TR_NSGA_II::GetSolutionSet, boost::python::return_value_policy<boost::python::reference_existing_object>())
		.def("GetCrossover", &TR_NSGA_II::GetCrossover, boost::python::return_value_policy<boost::python::reference_existing_object>())
		.def("GetMutation", &TR_NSGA_II::GetMutation, boost::python::return_value_policy<boost::python::reference_existing_object>())
		.def("GetReferencePoint", &TR_NSGA_II::GetReferencePoint, boost::python::return_value_policy<boost::python::reference_existing_object>())
		.def("GetThreshold", &TR_NSGA_II::GetThreshold)
	;
#endif
#ifdef EXPORT_HYPE
	boost::python::class_<TMonteCarloHypE::TIndividual, boost::python::bases<TSolution> >("MonteCarloHypE_Individual");
	boost::python::class_<TMonteCarloHypE::TSolutionSet>("MonteCarloHypE_Population")
		.def(boost::python::vector_indexing_suite<TMonteCarloHypE::TSolutionSet>())
	;
	boost::python::class_<TMonteCarloHypE, boost::python::bases<TOptimizer> >("MonteCarloHypE", boost::python::init<TRandom &, TProblem &, const std::vector<TDecision> &, TCrossover &, TMutation &, size_t>())
		.def("GetSolutionSet", &TMonteCarloHypE::GetSolutionSet, boost::python::return_value_policy<boost::python::reference_existing_object>())
		.def("GetCrossover", &TMonteCarloHypE::GetCrossover, boost::python::return_value_policy<boost::python::reference_existing_object>())
		.def("GetMutation", &TMonteCarloHypE::GetMutation, boost::python::return_value_policy<boost::python::reference_existing_object>())
		.def("GetSampleSize", &TMonteCarloHypE::GetSampleSize)
	;
	boost::python::class_<TFastMonteCarloHypE, boost::python::bases<TOptimizer> >("FastMonteCarloHypE", boost::python::init<TRandom &, TProblem &, const std::vector<TDecision> &, TCrossover &, TMutation &, size_t>())
		.def("GetSolutionSet", &TMonteCarloHypE::GetSolutionSet, boost::python::return_value_policy<boost::python::reference_existing_object>())
		.def("GetCrossover", &TMonteCarloHypE::GetCrossover, boost::python::return_value_policy<boost::python::reference_existing_object>())
		.def("GetMutation", &TMonteCarloHypE::GetMutation, boost::python::return_value_policy<boost::python::reference_existing_object>())
		.def("GetSampleSize", &TMonteCarloHypE::GetSampleSize)
	;
#endif
#ifdef EXPORT_MSOPS
	boost::python::class_<TMSOPS::TIndividual, boost::python::bases<TSolution> >("MSOPS_Individual")
		.def_readonly("fitness_", &TMSOPS::TIndividual::fitness_)
	;
	boost::python::class_<TMSOPS::TSolutionSet>("MSOPS_Population")
		.def(boost::python::vector_indexing_suite<TMSOPS::TSolutionSet>())
	;
	boost::python::class_<TMSOPS, boost::python::bases<TOptimizer> >("MSOPS", boost::python::init<TRandom &, TProblem &, const std::vector<TDecision> &, TCrossover &, TMutation &, const TMSOPS::TTargets &, TReal>())
		.def("GetSolutionSet", &TMSOPS::GetSolutionSet, boost::python::return_value_policy<boost::python::reference_existing_object>())
		.def("GetCrossover", &TMSOPS::GetCrossover, boost::python::return_value_policy<boost::python::reference_existing_object>())
		.def("GetMutation", &TMSOPS::GetMutation, boost::python::return_value_policy<boost::python::reference_existing_object>())
		.def("GetTargets", &TMSOPS::GetTargets, boost::python::return_value_policy<boost::python::reference_existing_object>())
		.def("GetFactor", &TMSOPS::GetFactor)
	;
#endif
#ifdef EXPORT_GrEA
	boost::python::class_<TGrEA::TIndividual, boost::python::bases<TSolution> >("GrEA_Individual")
		.def_readonly("gr_", &TGrEA::TIndividual::gr_)
		.def_readonly("gcd_", &TGrEA::TIndividual::gcd_)
		.def_readonly("gcpd_", &TGrEA::TIndividual::gcpd_)
	;
	boost::python::class_<TGrEA::TSolutionSet>("GrEA_Population")
		.def(boost::python::vector_indexing_suite<TGrEA::TSolutionSet>())
	;
	boost::python::class_<TGrEA, boost::python::bases<TOptimizer> >("GrEA", boost::python::init<TRandom &, TProblem &, const std::vector<TDecision> &, TCrossover &, TMutation &, std::vector<size_t> &>())
		.def("GetSolutionSet", &TGrEA::GetSolutionSet, boost::python::return_value_policy<boost::python::reference_existing_object>())
		.def("GetCrossover", &TGrEA::GetCrossover, boost::python::return_value_policy<boost::python::reference_existing_object>())
		.def("GetMutation", &TGrEA::GetMutation, boost::python::return_value_policy<boost::python::reference_existing_object>())
		.def("GetDivision", &TGrEA::GetDivision, boost::python::return_value_policy<boost::python::reference_existing_object>())
	;
#endif
#ifdef EXPORT_MOEA_D
	boost::python::class_<TMOEA_D_Individual, boost::python::bases<TSolution> >("MOEA_D_Individual");
	boost::python::class_<TMOEA_D_Population>("MOEA_D_Population")
		.def(boost::python::vector_indexing_suite<TMOEA_D_Population>())
	;
#endif
#ifdef EXPORT_SMS_EMOA
	boost::python::class_<TSMS_EMOA::TIndividual, boost::python::bases<TSolution> >("SMS_EMOA_Individual");
	boost::python::class_<TSMS_EMOA::TSolutionSet>("SMS_EMOA_Population")
		.def(boost::python::vector_indexing_suite<TSMS_EMOA::TSolutionSet>())
	;
#endif
}
}
}
}
