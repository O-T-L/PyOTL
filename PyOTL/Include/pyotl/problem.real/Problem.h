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

#include <OTL/Problem/XSinX.h>
#include <OTL/Problem/Camel.h>
#include <OTL/Problem/ShafferF6.h>
#include <OTL/Problem/Shubert.h>
#include <OTL/Problem/ParetoBox.h>
#include <OTL/Problem/Water.h>
#include <OTL/Problem/Rectangle.h>
#include <OTL/Problem/RotatedRectangle.h>
#include <OTL/Problem/ZDT/ZDT1.h>
#include <OTL/Problem/ZDT/ZDT2.h>
#include <OTL/Problem/ZDT/ZDT3.h>
#include <OTL/Problem/ZDT/ZDT4.h>
#include <OTL/Problem/ZDT/ZDT6.h>
#include <OTL/Problem/UF/UF1.h>
#include <OTL/Problem/UF/UF2.h>
#include <OTL/Problem/UF/UF3.h>
#include <OTL/Problem/UF/UF4.h>
#include <OTL/Problem/UF/UF5.h>
#include <OTL/Problem/UF/UF6.h>
#include <OTL/Problem/UF/UF7.h>
#include <OTL/Problem/UF/UF8.h>
#include <OTL/Problem/UF/UF9.h>
#include <OTL/Problem/UF/UF10.h>
#include <OTL/Problem/DTLZ/DTLZ1.h>
#include <OTL/Problem/DTLZ/DTLZ2.h>
#include <OTL/Problem/DTLZ/DTLZ3.h>
#include <OTL/Problem/DTLZ/DTLZ4.h>
#include <OTL/Problem/DTLZ/DTLZ5.h>
#include <OTL/Problem/DTLZ/DTLZ6.h>
#include <OTL/Problem/DTLZ/DTLZ7.h>
#include <OTL/Problem/DTLZ/DTLZ5I.h>
#include <OTL/Problem/DTLZ/DTLZ6I.h>
#include <OTL/Problem/DTLZ/ConvexDTLZ2.h>
#include <OTL/Problem/DTLZ/ConvexDTLZ3.h>
#include <OTL/Problem/DTLZ/ConvexDTLZ4.h>
#include <OTL/Problem/DTLZ/ConvexDTLZ5.h>
#include <OTL/Problem/DTLZ/ConvexDTLZ6.h>
#include <OTL/Problem/DTLZ/ConvexDTLZ5I.h>
#include <OTL/Problem/DTLZ/ConvexDTLZ6I.h>
#include <OTL/Problem/DTLZ/ScaledDTLZ2.h>
#include <OTL/Problem/DTLZ/NegativeDTLZ2.h>
#include <OTL/Problem/WFG/WFG1.h>
#include <OTL/Problem/WFG/WFG2.h>
#include <OTL/Problem/WFG/WFG3.h>
#include <OTL/Problem/WFG/WFG4.h>
#include <OTL/Problem/WFG/WFG5.h>
#include <OTL/Problem/WFG/WFG6.h>
#include <OTL/Problem/WFG/WFG7.h>
#include <OTL/Problem/WFG/WFG8.h>
#include <OTL/Problem/WFG/WFG9.h>
#include "FDA/FDA5.h"
#include "Global.h"

namespace pyotl
{
namespace problem
{
namespace real
{
typedef otl::problem::XSinX<TReal> TXSinX;
typedef otl::problem::Camel<TReal> TCamel;
typedef otl::problem::ShafferF6<TReal> TShafferF6;
typedef otl::problem::Shubert<TReal> TShubert;
typedef otl::problem::ParetoBox<TReal> TParetoBox;
typedef otl::problem::Water<TReal> TWater;
typedef otl::problem::Rectangle<TReal> TRectangle;
typedef otl::problem::RotatedRectangle<TReal> TRotatedRectangle;

typedef otl::problem::zdt::ZDT<TReal> TZDT;
typedef otl::problem::zdt::ZDT1<TReal> TZDT1;
typedef otl::problem::zdt::ZDT2<TReal> TZDT2;
typedef otl::problem::zdt::ZDT3<TReal> TZDT3;
typedef otl::problem::zdt::ZDT4<TReal> TZDT4;
typedef otl::problem::zdt::ZDT6<TReal> TZDT6;

typedef otl::problem::uf::UF<TReal> TUF;
typedef otl::problem::uf::UF1<TReal> TUF1;
typedef otl::problem::uf::UF2<TReal> TUF2;
typedef otl::problem::uf::UF3<TReal> TUF3;
typedef otl::problem::uf::UF4<TReal> TUF4;
typedef otl::problem::uf::UF5<TReal> TUF5;
typedef otl::problem::uf::UF6<TReal> TUF6;
typedef otl::problem::uf::UF7<TReal> TUF7;
typedef otl::problem::uf::UF8<TReal> TUF8;
typedef otl::problem::uf::UF9<TReal> TUF9;
typedef otl::problem::uf::UF10<TReal> TUF10;

typedef otl::problem::dtlz::DTLZ<TReal> TDTLZ;
typedef otl::problem::dtlz::DTLZ1<TReal> TDTLZ1;
typedef otl::problem::dtlz::DTLZ2<TReal> TDTLZ2;
typedef otl::problem::dtlz::DTLZ3<TReal> TDTLZ3;
typedef otl::problem::dtlz::DTLZ4<TReal> TDTLZ4;
typedef otl::problem::dtlz::DTLZ5<TReal> TDTLZ5;
typedef otl::problem::dtlz::DTLZ6<TReal> TDTLZ6;
typedef otl::problem::dtlz::DTLZ7<TReal> TDTLZ7;
typedef otl::problem::dtlz::DTLZ5I<TReal> TDTLZ5I;
typedef otl::problem::dtlz::DTLZ6I<TReal> TDTLZ6I;
typedef otl::problem::dtlz::ConvexDTLZ2<TReal> TConvexDTLZ2;
typedef otl::problem::dtlz::ConvexDTLZ3<TReal> TConvexDTLZ3;
typedef otl::problem::dtlz::ConvexDTLZ4<TReal> TConvexDTLZ4;
typedef otl::problem::dtlz::ConvexDTLZ5<TReal> TConvexDTLZ5;
typedef otl::problem::dtlz::ConvexDTLZ6<TReal> TConvexDTLZ6;
typedef otl::problem::dtlz::ConvexDTLZ5I<TReal> TConvexDTLZ5I;
typedef otl::problem::dtlz::ConvexDTLZ6I<TReal> TConvexDTLZ6I;
typedef otl::problem::dtlz::ScaledDTLZ2<TReal> TScaledDTLZ2;
typedef otl::problem::dtlz::NegativeDTLZ2<TReal> TNegativeDTLZ2;

typedef otl::problem::wfg::WFG<TReal> TWFG;
typedef otl::problem::wfg::StdWFG<TReal> TStdWFG;
typedef otl::problem::wfg::WFG1<TReal> TWFG1;
typedef otl::problem::wfg::WFG2<TReal> TWFG2;
typedef otl::problem::wfg::WFG3<TReal> TWFG3;
typedef otl::problem::wfg::WFG4<TReal> TWFG4;
typedef otl::problem::wfg::WFG5<TReal> TWFG5;
typedef otl::problem::wfg::WFG6<TReal> TWFG6;
typedef otl::problem::wfg::WFG7<TReal> TWFG7;
typedef otl::problem::wfg::WFG8<TReal> TWFG8;
typedef otl::problem::wfg::WFG9<TReal> TWFG9;

typedef otl::problem::fda::FDA<TReal> TFDA;
typedef fda::FDA5<TReal> TFDA5;
}
}
}
