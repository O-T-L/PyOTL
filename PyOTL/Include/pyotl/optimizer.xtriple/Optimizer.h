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

#include <OTL/Optimizer/GDE3/GDE3.h>
#include <OTL/Optimizer/MOEA-D/XTriple/MOEA-D_WeightedSum.h>
#include <OTL/Optimizer/MOEA-D/XTriple/MOEA-D_Tchebycheff.h>
#include <OTL/Optimizer/MOEA-D/XTriple/NormMOEA-D_Tchebycheff.h>
#include <OTL/Optimizer/MOEA-D/XTriple/MOEA-D_PBI.h>
#include <OTL/Optimizer/SMS-EMOA/XTriple/MonteCarloSMS-EMOA.h>
#include <pyotl/optimizer/Switch.h>
#include <pyotl/optimizer/GetSolutionSet.h>
#include <pyotl/optimizer/SMS-EMOA/XTriple/SMS-EMOA.h>
#include <pyotl/optimizer/SMS-EMOA/XTriple/MonteCarloHV-SMS-EMOA.h>

#define EXPORT_GDE3
