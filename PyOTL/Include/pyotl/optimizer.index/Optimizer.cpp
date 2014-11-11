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
namespace index
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
#ifdef EXPORT_NSGA_II
	boost::python::class_<TNSGA_II::TIndividual>("NSGA_II_Individual")
		.def_readonly("objective_", &TNSGA_II::TIndividual::objective_)
		.def_readonly("inequality_", &TNSGA_II::TIndividual::inequality_)
		.def_readonly("equality_", &TNSGA_II::TIndividual::equality_)
		.def_readwrite("decision_", &TNSGA_II::TIndividual::decision_)
		.def_readonly("crowdingDistance_", &TNSGA_II::TIndividual::crowdingDistance_)
	;
	boost::python::class_<TNSGA_II::TSolutionSet>("NSGA_II_Archive")
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
	boost::python::class_<TSPEA2::TIndividual>("SPEA2_Individual")
		.def_readonly("objective_", &TSPEA2::TIndividual::objective_)
		.def_readonly("inequality_", &TSPEA2::TIndividual::inequality_)
		.def_readonly("equality_", &TSPEA2::TIndividual::equality_)
		.def_readwrite("decision_", &TSPEA2::TIndividual::decision_)
		.def_readonly("rawFitness_", &TSPEA2::TIndividual::rawFitness_)
		.def_readonly("density_", &TSPEA2::TIndividual::density_)
		.def_readonly("fitness_", &TSPEA2::TIndividual::fitness_)
	;
	boost::python::class_<TSPEA2::TSolutionSet>("SPEA2_Archive")
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
	boost::python::class_<TIBEA::TIndividual>("IBEA_Individual")
		.def_readonly("objective_", &TIBEA::TIndividual::objective_)
		.def_readonly("inequality_", &TIBEA::TIndividual::inequality_)
		.def_readonly("equality_", &TIBEA::TIndividual::equality_)
		.def_readwrite("decision_", &TIBEA::TIndividual::decision_)
		.def_readonly("fitness_", &TIBEA::TIndividual::fitness_)
	;
	boost::python::class_<TIBEA::TSolutionSet>("IBEA_Archive")
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
	boost::python::class_<TCDAS::TIndividual>("CDAS_Individual")
		.def_readonly("objective_", &TCDAS::TIndividual::objective_)
		.def_readonly("inequality_", &TCDAS::TIndividual::inequality_)
		.def_readonly("equality_", &TCDAS::TIndividual::equality_)
		.def_readwrite("decision_", &TCDAS::TIndividual::decision_)
		.def_readonly("crowdingDistance_", &TCDAS::TIndividual::crowdingDistance_)
		.def_readonly("convertedObjective_", &TCDAS::TIndividual::convertedObjective_)
	;
	boost::python::class_<TCDAS::TSolutionSet>("CDAS_Archive")
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
	boost::python::class_<TEpsilon_MOEA::TIndividual>("Epsilon_MOEA_Individual")
		.def_readonly("objective_", &TEpsilon_MOEA::TIndividual::objective_)
		.def_readonly("inequality_", &TEpsilon_MOEA::TIndividual::inequality_)
		.def_readonly("equality_", &TEpsilon_MOEA::TIndividual::equality_)
		.def_readwrite("decision_", &TEpsilon_MOEA::TIndividual::decision_)
		.def_readonly("point_", &TEpsilon_MOEA::TIndividual::point_)
	;
	boost::python::class_<TEpsilon_MOEA::TSolutionSet>("Epsilon_MOEA_Archive");
	boost::python::class_<TEpsilon_MOEA::TPopulation>("Epsilon_MOEA_Population")
		.def(boost::python::vector_indexing_suite<TEpsilon_MOEA::TPopulation>())
	;
#endif
#ifdef EXPORT_TDEA
	boost::python::class_<TTDEA::TIndividual>("TDEA_Individual")
		.def_readonly("objective_", &TTDEA::TIndividual::objective_)
		.def_readonly("inequality_", &TTDEA::TIndividual::inequality_)
		.def_readonly("equality_", &TTDEA::TIndividual::equality_)
		.def_readwrite("decision_", &TTDEA::TIndividual::decision_)
		.def_readonly("scaledObjective_", &TTDEA::TIndividual::scaledObjective_)
	;
	boost::python::class_<TTDEA::TSolutionSet>("TDEA_Archive");
	boost::python::class_<TTDEA::TPopulation>("TDEA_Population")
		.def(boost::python::vector_indexing_suite<TTDEA::TPopulation>())
	;
#endif
#ifdef EXPORT_ISNPS
	boost::python::class_<TISNPS::TIndividual>("ISNPS_Individual")
		.def_readonly("objective_", &TISNPS::TIndividual::objective_)
		.def_readonly("inequality_", &TISNPS::TIndividual::inequality_)
		.def_readonly("equality_", &TISNPS::TIndividual::equality_)
		.def_readwrite("decision_", &TISNPS::TIndividual::decision_)
		.def_readonly("convergence_", &TISNPS::TIndividual::convergence_)
		.def_readonly("distribution_", &TISNPS::TIndividual::distribution_)
	;
	boost::python::class_<TISNPS::TSolutionSet>("ISNPS_Archive")
		.def(boost::python::vector_indexing_suite<TISNPS::TSolutionSet>())
	;
	boost::python::class_<TISNPS, boost::python::bases<TOptimizer> >("ISNPS", boost::python::init<TRandom &, TProblem &, const std::vector<TDecision> &, TCrossover &, TMutation &, const std::vector<TReal> &, const boost::numeric::ublas::vector<TReal> &, TReal, TReal, TReal>())
		.def("GetSolutionSet", &TISNPS::GetSolutionSet, boost::python::return_value_policy<boost::python::reference_existing_object>())
		.def("GetCrossover", &TISNPS::GetCrossover, boost::python::return_value_policy<boost::python::reference_existing_object>())
		.def("GetMutation", &TISNPS::GetMutation, boost::python::return_value_policy<boost::python::reference_existing_object>())
		.def("GetAngle1", &TISNPS::GetAngle1)
		.def("GetAngle2", &TISNPS::GetAngle2)
		.def("GetRounds", &TISNPS::GetRounds)
	;
#endif
#ifdef EXPORT_NSGA_III
	boost::python::class_<TNSGA_III::TIndividual>("NSGA_III_Individual")
		.def_readonly("objective_", &TNSGA_III::TIndividual::objective_)
		.def_readonly("inequality_", &TNSGA_III::TIndividual::inequality_)
		.def_readonly("equality_", &TNSGA_III::TIndividual::equality_)
		.def_readwrite("decision_", &TNSGA_III::TIndividual::decision_)
		.def_readonly("translatedObjective_", &TNSGA_III::TIndividual::translatedObjective_)
	;
	boost::python::class_<TNSGA_III::TSolutionSet>("NSGA_III_Archive")
		.def(boost::python::vector_indexing_suite<TNSGA_III::TSolutionSet>())
	;
	boost::python::class_<TNSGA_III, boost::python::bases<TOptimizer> >("NSGA_III", boost::python::init<TRandom &, TProblem &, const std::vector<TDecision> &, TCrossover &, TMutation &, const std::vector<TNSGA_III::TPoint> &>())
		.def(boost::python::init<TRandom &, TProblem &, const std::vector<TDecision> &, TCrossover &, TMutation &, const std::vector<TNSGA_III::TPoint> &, TReal>())
		.def("GetSolutionSet", &TNSGA_III::GetSolutionSet, boost::python::return_value_policy<boost::python::reference_existing_object>())
		.def("GetCrossover", &TNSGA_III::GetCrossover, boost::python::return_value_policy<boost::python::reference_existing_object>())
		.def("GetMutation", &TNSGA_III::GetMutation, boost::python::return_value_policy<boost::python::reference_existing_object>())
		.def("GetReferenceSet", &TNSGA_III::GetReferenceSet, boost::python::return_value_policy<boost::python::reference_existing_object>())
	;
#endif
#ifdef EXPORT_AR
	boost::python::class_<TAR::TIndividual>("AR_Individual")
		.def_readonly("objective_", &TAR::TIndividual::objective_)
		.def_readonly("inequality_", &TAR::TIndividual::inequality_)
		.def_readonly("equality_", &TAR::TIndividual::equality_)
		.def_readwrite("decision_", &TAR::TIndividual::decision_)
		.def_readonly("averageRank_", &TAR::TIndividual::averageRank_)
	;
	boost::python::class_<TAR::TSolutionSet>("AR_Archive")
		.def(boost::python::vector_indexing_suite<TAR::TSolutionSet>())
	;
	boost::python::class_<TAR, boost::python::bases<TOptimizer> >("AR", boost::python::init<TRandom &, TProblem &, const std::vector<TDecision> &, TCrossover &, TMutation &>())
		.def("GetSolutionSet", &TAR::GetSolutionSet, boost::python::return_value_policy<boost::python::reference_existing_object>())
		.def("GetCrossover", &TAR::GetCrossover, boost::python::return_value_policy<boost::python::reference_existing_object>())
		.def("GetMutation", &TAR::GetMutation, boost::python::return_value_policy<boost::python::reference_existing_object>())
	;
#endif
#ifdef EXPORT_AR_CD_
	boost::python::class_<TAR_CD_::TIndividual>("AR_CD__Individual")
		.def_readonly("objective_", &TAR_CD_::TIndividual::objective_)
		.def_readonly("inequality_", &TAR_CD_::TIndividual::inequality_)
		.def_readonly("equality_", &TAR_CD_::TIndividual::equality_)
		.def_readwrite("decision_", &TAR_CD_::TIndividual::decision_)
		.def_readonly("averageRank_", &TAR_CD_::TIndividual::averageRank_)
		.def_readonly("crowdingDistance_", &TAR_CD_::TIndividual::crowdingDistance_)
	;
	boost::python::class_<TAR_CD_::TSolutionSet>("AR_CD__Archive")
		.def(boost::python::vector_indexing_suite<TAR_CD_::TSolutionSet>())
	;
	boost::python::class_<TAR_CD_, boost::python::bases<TOptimizer> >("AR_CD_", boost::python::init<TRandom &, TProblem &, const std::vector<TDecision> &, TCrossover &, TMutation &>())
		.def("GetSolutionSet", &TAR_CD_::GetSolutionSet, boost::python::return_value_policy<boost::python::reference_existing_object>())
		.def("GetCrossover", &TAR_CD_::GetCrossover, boost::python::return_value_policy<boost::python::reference_existing_object>())
		.def("GetMutation", &TAR_CD_::GetMutation, boost::python::return_value_policy<boost::python::reference_existing_object>())
	;
#endif
#ifdef EXPORT_AR_DMO
	boost::python::class_<TAR_DMO::TIndividual>("AR_DMO_Individual")
		.def_readonly("objective_", &TAR_DMO::TIndividual::objective_)
		.def_readonly("inequality_", &TAR_DMO::TIndividual::inequality_)
		.def_readonly("equality_", &TAR_DMO::TIndividual::equality_)
		.def_readwrite("decision_", &TAR_DMO::TIndividual::decision_)
		.def_readonly("averageRank_", &TAR_DMO::TIndividual::averageRank_)
		.def_readonly("crowdingDistance_", &TAR_DMO::TIndividual::crowdingDistance_)
	;
	boost::python::class_<TAR_DMO::TSolutionSet>("AR_DMO_Archive")
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
	boost::python::class_<THypE::TIndividual>("HypE_Individual")
		.def_readonly("objective_", &THypE::TIndividual::objective_)
		.def_readonly("inequality_", &THypE::TIndividual::inequality_)
		.def_readonly("equality_", &THypE::TIndividual::equality_)
		.def_readwrite("decision_", &THypE::TIndividual::decision_)
		.def_readonly("fitness_", &THypE::TIndividual::fitness_)
	;
	boost::python::class_<THypE::TSolutionSet>("HypE_Archive")
		.def(boost::python::vector_indexing_suite<THypE::TSolutionSet>())
	;
	boost::python::class_<THypE, boost::python::bases<TOptimizer> >("HypE", boost::python::init<TRandom &, TProblem &, const std::vector<TDecision> &, TCrossover &, TMutation &, size_t>())
		.def("GetSolutionSet", &THypE::GetSolutionSet, boost::python::return_value_policy<boost::python::reference_existing_object>())
		.def("GetCrossover", &THypE::GetCrossover, boost::python::return_value_policy<boost::python::reference_existing_object>())
		.def("GetMutation", &THypE::GetMutation, boost::python::return_value_policy<boost::python::reference_existing_object>())
	;
#endif
#ifdef EXPORT_MSOPS
	boost::python::class_<TMSOPS::TIndividual>("MSOPS_Individual")
		.def_readonly("objective_", &TMSOPS::TIndividual::objective_)
		.def_readonly("inequality_", &TMSOPS::TIndividual::inequality_)
		.def_readonly("equality_", &TMSOPS::TIndividual::equality_)
		.def_readwrite("decision_", &TMSOPS::TIndividual::decision_)
		.def_readonly("fitness_", &TMSOPS::TIndividual::fitness_)
	;
	boost::python::class_<TMSOPS::TSolutionSet>("MSOPS_Archive")
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
	boost::python::class_<TGrEA::TIndividual>("GrEA_Individual")
		.def_readonly("objective_", &TGrEA::TIndividual::objective_)
		.def_readonly("inequality_", &TGrEA::TIndividual::inequality_)
		.def_readonly("equality_", &TGrEA::TIndividual::equality_)
		.def_readwrite("decision_", &TGrEA::TIndividual::decision_)
		.def_readonly("gr_", &TGrEA::TIndividual::gr_)
		.def_readonly("gcd_", &TGrEA::TIndividual::gcd_)
		.def_readonly("gcpd_", &TGrEA::TIndividual::gcpd_)
	;
	boost::python::class_<TGrEA::TSolutionSet>("GrEA_Archive")
		.def(boost::python::vector_indexing_suite<TGrEA::TSolutionSet>())
	;
	boost::python::class_<TGrEA, boost::python::bases<TOptimizer> >("GrEA", boost::python::init<TRandom &, TProblem &, const std::vector<TDecision> &, TCrossover &, TMutation &, std::vector<size_t> &>())
		.def("GetSolutionSet", &TGrEA::GetSolutionSet, boost::python::return_value_policy<boost::python::reference_existing_object>())
		.def("GetCrossover", &TGrEA::GetCrossover, boost::python::return_value_policy<boost::python::reference_existing_object>())
		.def("GetMutation", &TGrEA::GetMutation, boost::python::return_value_policy<boost::python::reference_existing_object>())
		.def("GetDividion", &TGrEA::GetDividion, boost::python::return_value_policy<boost::python::reference_existing_object>())
	;
#endif
#ifdef EXPORT_MOEA_D
	boost::python::class_<TMOEA_D_Individual>("MOEA_D_Individual")
		.def_readonly("objective_", &TMOEA_D_Individual::objective_)
		.def_readonly("inequality_", &TMOEA_D_Individual::inequality_)
		.def_readonly("equality_", &TMOEA_D_Individual::equality_)
		.def_readwrite("decision_", &TMOEA_D_Individual::decision_)
	;
	boost::python::class_<TMOEA_D_Archive>("MOEA_D_Archive")
		.def(boost::python::vector_indexing_suite<TMOEA_D_Archive>())
	;
#endif
#ifdef EXPORT_SMS_EMOA
	boost::python::class_<TSMS_EMOA::TIndividual>("SMS_EMOA_Individual")
		.def_readonly("objective_", &TSMS_EMOA::TIndividual::objective_)
		.def_readonly("inequality_", &TSMS_EMOA::TIndividual::inequality_)
		.def_readonly("equality_", &TSMS_EMOA::TIndividual::equality_)
		.def_readwrite("decision_", &TSMS_EMOA::TIndividual::decision_)
		.def_readonly("hvContribution_", &TSMS_EMOA::TIndividual::hvContribution_)
	;
	boost::python::class_<TSMS_EMOA::TSolutionSet>("SMS_EMOA_Archive")
		.def(boost::python::vector_indexing_suite<TSMS_EMOA::TSolutionSet>())
	;
#endif
}
}
}
}
