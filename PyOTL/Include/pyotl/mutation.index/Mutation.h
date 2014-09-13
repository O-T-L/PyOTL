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

#include <OTL/Mutation/DisplacementMutation.h>
#include <OTL/Mutation/ExchangeMutation.h>
#include <OTL/Mutation/InsertionMutation.h>
#include <OTL/Mutation/InversionMutation.h>
#include <OTL/Mutation/SpreadMutation.h>
#include <OTL/Mutation/BitwiseMutation.h>
#include "Global.h"

namespace pyotl
{
namespace mutation
{
namespace index
{
typedef otl::mutation::DisplacementMutation<TReal, TRandom &> TDisplacementMutation;
typedef otl::mutation::ExchangeMutation<TReal, TRandom &> TExchangeMutation;
typedef otl::mutation::InsertionMutation<TReal, TRandom &> TInsertionMutation;
typedef otl::mutation::InversionMutation<TReal, TRandom &> TInversionMutation;
typedef otl::mutation::SpreadMutation<TReal, TRandom &> TSpreadMutation;
typedef otl::mutation::BitwiseMutation<TReal, size_t, TRandom &> TBitwiseMutation;
}
}
}
