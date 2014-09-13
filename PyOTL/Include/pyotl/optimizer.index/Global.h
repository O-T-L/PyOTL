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

#include <OTL/Optimizer/Optimizer.h>
#include <pyotl/problem.index/Global.h>
#include <pyotl/crossover.index/Global.h>
#include <pyotl/mutation.index/Global.h>

namespace pyotl
{
namespace optimizer
{
namespace index
{
typedef pyotl::problem::index::TProblem TProblem;
typedef pyotl::crossover::index::TCrossover TCrossover;
typedef pyotl::mutation::index::TMutation TMutation;

typedef std::vector<size_t> TDecision;
typedef otl::Solution<TReal, TDecision> TSolution;
typedef otl::optimizer::Optimizer<TReal, TDecision> TOptimizer;
}
}
}
