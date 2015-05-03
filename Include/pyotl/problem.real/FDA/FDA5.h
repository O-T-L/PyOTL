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

#include <OTL/Problem/FDA/FDA5.h>
#include <pyotl/problem/Progress.h>

namespace pyotl
{
namespace problem
{
namespace fda
{
template <typename _TReal>
class FDA5 : public otl::problem::fda::FDA5<_TReal>
{
public:
	typedef _TReal TReal;
	typedef otl::problem::fda::FDA5<TReal> TSuper;
	typedef typename TSuper::TDecision TDecision;
	typedef typename TSuper::TSolution TSolution;

	FDA5(const size_t nObjectives, const Progress &progress);
	FDA5(const size_t nObjectives, const Progress &progress, const size_t nFixedSteps, const size_t nDistinctSteps);
	FDA5(const size_t nObjectives, const Progress &progress, const size_t nFixedSteps, const size_t nDistinctSteps, const size_t distDecisions);
	~FDA5(void);
};

template <typename _TReal>
FDA5<_TReal>::FDA5(const size_t nObjectives, const Progress &progress)
	: TSuper(nObjectives, progress.progress_)
{
}

template <typename _TReal>
FDA5<_TReal>::FDA5(const size_t nObjectives, const Progress &progress, const size_t nFixedSteps, const size_t nDistinctSteps)
	: TSuper(nObjectives, progress.progress_, nFixedSteps, nDistinctSteps)
{
}

template <typename _TReal>
FDA5<_TReal>::FDA5(const size_t nObjectives, const Progress &progress, const size_t nFixedSteps, const size_t nDistinctSteps, const size_t distDecisions)
	: TSuper(nObjectives, progress.progress_, nFixedSteps, nDistinctSteps, distDecisions)
{
}

template <typename _TReal>
FDA5<_TReal>::~FDA5(void)
{
}
}
}
}
