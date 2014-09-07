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

#include <pyotl/optimizer.couple_couple/Optimizer.h>
#include "Global.h"

namespace pyotl
{
namespace optimizer
{
namespace couple_couple
{
namespace permutation
{
typedef otl::optimizer::epsilon_moea::couple_couple::Epsilon_MOEA<TReal, TDecision, TRandom &> TEpsilon_MOEA;
typedef otl::optimizer::tdea::couple_couple::TDEA<TReal, TDecision, TRandom &> TTDEA;
typedef otl::optimizer::moea_d::couple_couple::MOEA_D_WeightedSum<TReal, TDecision, TRandom &> TMOEA_D_WeightedSum;
typedef otl::optimizer::moea_d::couple_couple::MOEA_D_Tchebycheff<TReal, TDecision, TRandom &> TMOEA_D_Tchebycheff;
typedef otl::optimizer::moea_d::couple_couple::NormMOEA_D_Tchebycheff<TReal, TDecision, TRandom &> TNormMOEA_D_Tchebycheff;
typedef otl::optimizer::moea_d::couple_couple::MOEA_D_PBI<TReal, TDecision, TRandom &> TMOEA_D_PBI;
typedef pyotl::optimizer::sms_emoa::couple_couple::SMS_EMOA<TReal, TDecision, TRandom &> TSMS_EMOA;
typedef otl::optimizer::sms_emoa::couple_couple::MonteCarloSMS_EMOA<TReal, TDecision, TRandom &> TMonteCarloSMS_EMOA;
typedef pyotl::optimizer::sms_emoa::couple_couple::MonteCarloHV_SMS_EMOA<TReal, TDecision, TRandom &> TMonteCarloHV_SMS_EMOA;
}
}
}
}
