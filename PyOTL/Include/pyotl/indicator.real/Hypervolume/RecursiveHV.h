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

#include <OTL/Indicator/Hypervolume/RecursiveHV.h>
#include <OTL/Indicator/Hypervolume/FilterAdapter.h>

namespace pyotl
{
namespace indicator
{
namespace hypervolume
{
template <typename _TReal>
class RecursiveHV : public otl::indicator::hypervolume::FilterAdapter<otl::indicator::hypervolume::RecursiveHV<_TReal> >
{
public:
	typedef _TReal TReal;
	typedef otl::indicator::hypervolume::RecursiveHV<TReal> THypervolume;
	typedef otl::indicator::hypervolume::FilterAdapter<THypervolume> TSuper;
	typedef typename TSuper::TMetric TMetric;
	typedef typename TSuper::TPoint TPoint;
	typedef typename TSuper::TFront TFront;

	RecursiveHV(const TPoint &referencePoint);
	~RecursiveHV(void);
};

template <typename _TReal>
RecursiveHV<_TReal>::RecursiveHV(const TPoint &referencePoint)
	: TSuper(THypervolume(referencePoint))
{
}

template <typename _TReal>
RecursiveHV<_TReal>::~RecursiveHV(void)
{
}
}
}
}
