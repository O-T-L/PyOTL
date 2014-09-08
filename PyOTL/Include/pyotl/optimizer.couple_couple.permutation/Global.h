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

#include <pyotl/optimizer.permutation/Global.h>

namespace pyotl
{
namespace optimizer
{
namespace couple_couple
{
namespace permutation
{
typedef pyotl::optimizer::permutation::TProblem TProblem;
typedef pyotl::crossover::permutation::TCoupleCoupleCrossover TCrossover;
typedef pyotl::optimizer::permutation::TMutation TMutation;

typedef pyotl::optimizer::permutation::TDecision TDecision;
typedef pyotl::optimizer::permutation::TSolution TSolution;
typedef pyotl::optimizer::permutation::TOptimizer TOptimizer;
}
}
}
}
