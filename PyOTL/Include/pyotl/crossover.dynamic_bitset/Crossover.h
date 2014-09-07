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

#include <OTL/Crossover/CoupleCrossoverAdapter.h>
#include <OTL/Crossover/CoupleCoupleCrossoverAdapter.h>
#include <OTL/Crossover/TripleCrossoverAdapter.h>
#include <OTL/Crossover/TripleTripleCrossoverAdapter.h>
#include <OTL/Crossover/XTripleCrossoverAdapter.h>
#include <OTL/Crossover/BitsetSinglePointCrossover.h>
#include <OTL/Crossover/DynamicBitsetUniformCrossover.h>
#include "Global.h"

namespace pyotl
{
namespace crossover
{
namespace dynamic_bitset
{
typedef TCrossover::TSolution TSolution;
typedef otl::crossover::CoupleCrossoverAdapter<TReal, TDecision, TRandom &> TCoupleCrossoverAdapter;
typedef otl::crossover::CoupleCoupleCrossoverAdapter<TReal, TDecision, TRandom &> TCoupleCoupleCrossoverAdapter;
typedef otl::crossover::TripleCrossoverAdapter<TReal, TDecision, TRandom &> TTripleCrossoverAdapter;
typedef otl::crossover::TripleTripleCrossoverAdapter<TReal, TDecision, TRandom &> TTripleTripleCrossoverAdapter;
typedef otl::crossover::XTripleCrossoverAdapter<TReal, TDecision, TRandom &> TXTripleCrossoverAdapter;
typedef otl::crossover::BitsetSinglePointCrossover<TReal, TDecision, TRandom &> TBitsetSinglePointCrossover;
typedef otl::crossover::DynamicBitsetUniformCrossover<TReal, TRandom &> TDynamicBitsetUniformCrossover;
}
}
}
