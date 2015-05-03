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

#include <pyotl/optimizer.xtriple/Optimizer.h>
#include "Global.h"

namespace pyotl
{
namespace optimizer
{
namespace xtriple
{
namespace integer
{
typedef otl::optimizer::gde3::GDE3<TReal, TDecision, TRandom &> TGDE3;
typedef otl::optimizer::moea_d::MOEA_D<TReal, TDecision, TRandom &> TMOEA_D;
typedef otl::optimizer::moea_d::xtriple::MOEA_D_WeightedSum<TReal, TDecision, TRandom &> TMOEA_D_WeightedSum;
typedef otl::optimizer::moea_d::xtriple::MOEA_D_Tchebycheff<TReal, TDecision, TRandom &> TMOEA_D_Tchebycheff;
typedef otl::optimizer::moea_d::xtriple::NormMOEA_D_Tchebycheff<TReal, TDecision, TRandom &> TNormMOEA_D_Tchebycheff;
typedef otl::optimizer::moea_d::xtriple::MOEA_D_PBI<TReal, TDecision, TRandom &> TMOEA_D_PBI;
typedef pyotl::optimizer::sms_emoa::xtriple::SMS_EMOA<TReal, TDecision, TRandom &> TSMS_EMOA;
typedef otl::optimizer::sms_emoa::xtriple::MonteCarloSMS_EMOA<TReal, TDecision, TRandom &> TMonteCarloSMS_EMOA;
typedef pyotl::optimizer::sms_emoa::xtriple::MonteCarloHV_SMS_EMOA<TReal, TDecision, TRandom &> TMonteCarloHV_SMS_EMOA;
}
}
}
}
