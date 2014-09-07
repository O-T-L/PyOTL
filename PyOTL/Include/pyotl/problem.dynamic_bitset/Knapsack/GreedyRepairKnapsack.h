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

#include <OTL/Problem/Knapsack/Knapsack.h>
#include <OTL/Problem/Knapsack/GreedyRepairAdapter.h>

namespace pyotl
{
namespace problem
{
namespace knapsack
{
template <typename _TReal>
class GreedyRepairKnapsack : public otl::problem::knapsack::GreedyRepairAdapter<otl::problem::knapsack::Knapsack<_TReal> >
{
public:
	typedef _TReal TReal;
	typedef otl::problem::knapsack::Knapsack<TReal> TKnapsack;
	typedef otl::problem::knapsack::GreedyRepairAdapter<TKnapsack> TSuper;
	typedef typename TKnapsack::TMatrix TMatrix;

	GreedyRepairKnapsack(const TMatrix &priceMatrix, const TMatrix &weightMatrix, const std::vector<TReal> &capacity);
	~GreedyRepairKnapsack(void);
};

template <typename _TReal>
GreedyRepairKnapsack<_TReal>::GreedyRepairKnapsack(const TMatrix &priceMatrix, const TMatrix &weightMatrix, const std::vector<TReal> &capacity)
	: TSuper(TKnapsack(priceMatrix, weightMatrix, capacity))
{
}

template <typename _TReal>
GreedyRepairKnapsack<_TReal>::~GreedyRepairKnapsack(void)
{
}
}
}
}
