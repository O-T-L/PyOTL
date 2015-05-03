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

#include <pyotl/Global.h>
#include <pyotl/problem/Progress.h>
#include <OTL/Problem/Problem.h>
#include <OTL/Problem/DynamicProblem.h>

namespace pyotl
{
namespace problem
{
namespace index
{
typedef std::vector<size_t> TDecision;

typedef otl::problem::Problem<TReal, TDecision> TProblem;
typedef otl::problem::DynamicProblem<TReal, TDecision> TDynamicProblem;
}
}
}
