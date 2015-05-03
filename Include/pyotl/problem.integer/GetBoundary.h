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

#include <vector>
#include <list>

namespace pyotl
{
namespace problem
{
namespace integer
{
template <typename _TProblem>
std::vector<std::pair<typename _TProblem::TInteger, typename _TProblem::TInteger> > GetBoundary(const _TProblem &problem)
{
	typedef typename _TProblem::TInteger _TInteger;
	std::vector<std::pair<_TInteger, _TInteger> > boundary(problem.GetDecisionBits().size());
	for (size_t i = 0; i < boundary.size(); ++i)
	{
		boundary[i].first = 0;
		boundary[i].second = (1 << problem.GetDecisionBits()[i]) - 1;
	}
	return boundary;
}
}
}
}
