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

#include <OTL/Indicator/GD/DTLZ1GD.h>
#include <OTL/Indicator/GD/DTLZ2GD.h>
#include <OTL/Indicator/GD/WFG3GD.h>
#include <OTL/Indicator/GD/WFG4GD.h>
#include <OTL/Indicator/GD/FrontGD.h>
#include <OTL/Indicator/IGD/InvertedGenerationalDistance.h>
#include <OTL/Indicator/Epsilon/AdditiveEpsilon.h>
#include <OTL/Indicator/Epsilon/MultiplicativeEpsilon.h>
#include <OTL/Indicator/Spacing.h>
#include <OTL/Indicator/MS/MaximumSpread.h>
#include <OTL/Indicator/MS/MaximumSpread1.h>
#include <OTL/Indicator/MS/MaximumSpread2.h>
#include <OTL/Indicator/DM/DiversityMetric.h>
#include <OTL/Indicator/R2.h>
#include "Global.h"
#include "Hypervolume/MonteCarloHV.h"
#include "Hypervolume/RecursiveHV.h"

namespace pyotl
{
namespace indicator
{
typedef otl::indicator::gd::DTLZ1GD<TReal> TDTLZ1GD;
typedef otl::indicator::gd::DTLZ2GD<TReal> TDTLZ2GD;
typedef otl::indicator::gd::WFG3GD<TReal> TWFG3GD;
typedef otl::indicator::gd::WFG4GD<TReal> TWFG4GD;
typedef otl::indicator::gd::FrontGD<TReal> TFrontGD;
typedef otl::indicator::igd::InvertedGenerationalDistance<TReal> TInvertedGenerationalDistance;
typedef otl::indicator::epsilon::Epsilon<TReal> TEpsilon;
typedef otl::indicator::epsilon::AdditiveEpsilon<TReal> TAdditiveEpsilon;
typedef otl::indicator::epsilon::MultiplicativeEpsilon<TReal> TMultiplicativeEpsilon;
typedef otl::indicator::Spacing<TReal> TSpacing;
typedef otl::indicator::ms::MaximumSpread<TReal> TMaximumSpread;
typedef otl::indicator::ms::MaximumSpread1<TReal> TMaximumSpread1;
typedef otl::indicator::ms::MaximumSpread2<TReal> TMaximumSpread2;
typedef otl::indicator::dm::DiversityMetric<TReal> TDiversityMetric;
typedef otl::indicator::R2<TReal> TR2;
typedef otl::indicator::hypervolume::Hypervolume<TReal> THypervolume;
typedef pyotl::indicator::hypervolume::RecursiveHV<TReal> TRecursiveHV;
typedef pyotl::indicator::hypervolume::MonteCarloHV<TReal, TRandom &> TMonteCarloHV;
}
}
