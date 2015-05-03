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

#include <OTL/Crossover/Crossover.h>
#include <OTL/Crossover/CoupleCrossover.h>
#include <OTL/Crossover/CoupleCoupleCrossover.h>
#include <OTL/Crossover/TripleCrossover.h>
#include <OTL/Crossover/TripleTripleCrossover.h>
#include <OTL/Crossover/XTripleCrossover.h>
#include <pyotl/Global.h>

namespace pyotl
{
namespace crossover
{
namespace integer
{
typedef std::vector<TInteger> TDecision;

typedef otl::crossover::Crossover<TReal, TDecision> TCrossover;
typedef otl::crossover::CoupleCrossover<TReal, TDecision> TCoupleCrossover;
typedef otl::crossover::CoupleCoupleCrossover<TReal, TDecision> TCoupleCoupleCrossover;
typedef otl::crossover::TripleCrossover<TReal, TDecision> TTripleCrossover;
typedef otl::crossover::TripleTripleCrossover<TReal, TDecision> TTripleTripleCrossover;
typedef otl::crossover::XTripleCrossover<TReal, TDecision> TXTripleCrossover;
}
}
}
