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

#include <algorithm>
#include <OTL/Indicator/Hypervolume/MonteCarloHV.h>

namespace pyotl
{
namespace optimizer
{
namespace sms_emoa
{
template <typename _TReal, typename _TRandom>
class MakeMonteCarloHypervolume : public otl::utility::WithRandom<_TRandom>
{
public:
	typedef _TReal TReal;
	typedef _TRandom TRandom;
	typedef otl::indicator::hypervolume::MonteCarloHV<TReal, TRandom> THypervolume;
	typedef typename THypervolume::TPoint TPoint;

	MakeMonteCarloHypervolume(TRandom random, const size_t sample);
	~MakeMonteCarloHypervolume(void);
	THypervolume operator ()(const TPoint &referencePoint);

private:
	size_t sample_;
};

template <typename _TReal, typename _TRandom>
MakeMonteCarloHypervolume<_TReal, _TRandom>::MakeMonteCarloHypervolume(TRandom random, const size_t sample)
	: otl::utility::WithRandom<TRandom>(random)
	, sample_(sample)
{
}

template <typename _TReal, typename _TRandom>
MakeMonteCarloHypervolume<_TReal, _TRandom>::~MakeMonteCarloHypervolume(void)
{
}

template <typename _TReal, typename _TRandom>
typename MakeMonteCarloHypervolume<_TReal, _TRandom>::THypervolume MakeMonteCarloHypervolume<_TReal, _TRandom>::operator ()(const TPoint &referencePoint)
{
	return THypervolume(referencePoint, this->GetRandom(), sample_);
}
}
}
}
