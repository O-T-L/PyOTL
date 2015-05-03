# Copyright (C) 2014, 申瑞珉 (Ruimin Shen)
# 
# This program is free software: you can redistribute it and/or modify
# it under the terms of the GNU Lesser General Public License as published by
# the Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.
# 
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
# 
# You should have received a copy of the GNU General Public License
# along with this program.  If not, see <http://www.gnu.org/licenses/>.

set(OTL_BINARY_DIR "$ENV{OTL_BINARY_DIR}" CACHE PATH "OTL_BINARY_DIR")
if(EXISTS "${OTL_BINARY_DIR}/CMakeCache.txt")
	load_cache(${OTL_BINARY_DIR} READ_WITH_PREFIX OTL_ OptimizationTemplateLibrary_SOURCE_DIR)
	set(OTL_SOURCE_DIR "${OTL_OptimizationTemplateLibrary_SOURCE_DIR}")
	set(OTL_INCLUDE_DIR "${OTL_SOURCE_DIR}/Include")
	if(NOT ${OTL_FIND_COMPONENTS} STREQUAL "")
		find_library(OTL_LIBRARIES
			NAMES ${OTL_FIND_COMPONENTS}
			PATHS "${OTL_BINARY_DIR}/lib${LIB_SUFFIX}" "${CMAKE_INSTALL_PREFIX}/lib${LIB_SUFFIX}"
			PATH_SUFFIXES ${CMAKE_CONFIGURATION_TYPES}
		)
	endif()
	set(OTL_FOUND YES)
else()
	set(OTL_FOUND NO)
	message(WARNING "The OTL was not found, ${OTL_BINARY_DIR} is not valid")
endif()
