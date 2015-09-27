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
#include <OTL/Crossover/Integer/SinglePointCrossover.h>
#include <OTL/Crossover/TripleCrossoverAdapter.h>
#include <OTL/Crossover/TripleTripleCrossoverAdapter.h>
#include <OTL/Crossover/TSP/OrderBasedCrossover.h>
#include <OTL/Crossover/TSP/PartiallyMappedCrossover.h>
#include <OTL/Crossover/TSP/PositionBasedCrossover.h>
#include <OTL/Crossover/XTripleCrossoverAdapter.h>
#include "Global.h"

namespace pyotl
{
namespace crossover
{
namespace index
{
typedef TCrossover::TSolution TSolution;
typedef otl::crossover::CoupleCrossoverAdapter<TReal, TDecision, TRandom &> TCoupleCrossoverAdapter;
typedef otl::crossover::CoupleCoupleCrossoverAdapter<TReal, TDecision, TRandom &> TCoupleCoupleCrossoverAdapter;
typedef otl::crossover::TripleCrossoverAdapter<TReal, TDecision, TRandom &> TTripleCrossoverAdapter;
typedef otl::crossover::TripleTripleCrossoverAdapter<TReal, TDecision, TRandom &> TTripleTripleCrossoverAdapter;
typedef otl::crossover::XTripleCrossoverAdapter<TReal, TDecision, TRandom &> TXTripleCrossoverAdapter;
typedef otl::crossover::tsp::OrderBasedCrossover<TReal, TRandom &> TOrderBasedCrossover;
typedef otl::crossover::tsp::PartiallyMappedCrossover<TReal, TRandom &> TPartiallyMappedCrossover;
typedef otl::crossover::tsp::PositionBasedCrossover<TReal, TRandom &> TPositionBasedCrossover;
typedef otl::crossover::integer::SinglePointCrossover<TReal, size_t, TRandom &> TSinglePointCrossover;
}
}
}
