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

#include <pyotl/optimizer/Optimizer.h>
#include "Global.h"

namespace pyotl
{
namespace optimizer
{
namespace dynamic_bitset
{
typedef otl::optimizer::SGA<TReal, TDecision, TRandom &> TSGA;
typedef otl::optimizer::rwsga::RWSGA<TReal, TDecision, TRandom &> TRWSGA;
typedef otl::optimizer::nsga_ii::NSGA_II<TReal, TDecision, TRandom &> TNSGA_II;
typedef otl::optimizer::nsga_ii::ConstrainedNSGA_II<TReal, TDecision, TRandom &> TConstrainedNSGA_II;
typedef otl::optimizer::spea2::SPEA2<TReal, TDecision, TRandom &> TSPEA2;
typedef otl::optimizer::spea2_sde::SPEA2_SDE<TReal, TDecision, TRandom &> TSPEA2_SDE;
typedef otl::optimizer::ibea::IBEA<TReal, TDecision, TRandom &> TIBEA;
typedef otl::optimizer::ibea::IBEA_Epsilon<TReal, TDecision, TRandom &> TIBEA_Epsilon;
typedef otl::optimizer::ibea::IBEA_HD<TReal, TDecision, TRandom &> TIBEA_HD;
typedef otl::optimizer::cdas::CDAS<TReal, TDecision, TRandom &> TCDAS;
typedef otl::optimizer::epsilon_moea::Epsilon_MOEA<TReal, TDecision, TRandom &> TEpsilon_MOEA;
typedef otl::optimizer::tdea::TDEA<TReal, TDecision, TRandom &> TTDEA;
#ifdef EXPORT_ISNPS
typedef otl::optimizer::isnps::ISNPS<TReal, TDecision, TRandom &> TISNPS;
#endif
typedef otl::optimizer::nsga_iii::NSGA_III<TReal, TDecision, TRandom &> TNSGA_III;
typedef otl::optimizer::ar::AR<TReal, TDecision, TRandom &> TAR;
typedef otl::optimizer::ar_cd_::AR_CD_<TReal, TDecision, TRandom &> TAR_CD_;
typedef otl::optimizer::ar_dmo::AR_DMO<TReal, TDecision, TRandom &> TAR_DMO;
typedef otl::optimizer::g_nsga_ii::G_NSGA_II<TReal, TDecision, TRandom &> TG_NSGA_II;
typedef otl::optimizer::r_nsga_ii::R_NSGA_II<TReal, TDecision, TRandom &> TR_NSGA_II;
typedef otl::optimizer::hype::HypE<TReal, TDecision, TRandom &> THypE;
typedef otl::optimizer::msops::MSOPS<TReal, TDecision, TRandom &> TMSOPS;
typedef otl::optimizer::grea::GrEA<TReal, TDecision, TRandom &> TGrEA;
typedef otl::optimizer::moea_d::Individual<TReal, TDecision> TMOEA_D_Individual;
typedef std::vector<TMOEA_D_Individual> TMOEA_D_Population;
typedef pyotl::optimizer::sms_emoa::SMS_EMOA<TReal, TDecision, TRandom &> TSMS_EMOA;
}
}
}
