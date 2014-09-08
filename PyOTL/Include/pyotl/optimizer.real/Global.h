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
#include <pyotl/problem.real/Global.h>
#include <pyotl/crossover.real/Global.h>
#include <pyotl/mutation.real/Global.h>

namespace pyotl
{
namespace optimizer
{
namespace real
{
typedef pyotl::problem::real::TProblem TProblem;
typedef pyotl::crossover::real::TCrossover TCrossover;
typedef pyotl::mutation::real::TMutation TMutation;

typedef std::vector<TReal> TDecision;
typedef otl::Solution<TReal, TDecision> TSolution;
typedef otl::optimizer::Optimizer<TReal, TDecision> TOptimizer;
}
}
}
