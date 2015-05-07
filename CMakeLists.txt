###
# Copyright (c) 2014, 申瑞珉 (Ruimin Shen)
# All rights reserved.
# 
# Redistribution and use in source and binary forms, with or without
# modification, are permitted provided that the following conditions are met:
# 
# 1. Redistributions of source code must retain the above copyright notice, this
#	list of conditions and the following disclaimer.
# 2. Redistributions in binary form must reproduce the above copyright notice,
#	this list of conditions and the following disclaimer in the documentation
#	and/or other materials provided with the distribution.
# 
# THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
# ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
# WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
# DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR
# ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
# (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
# LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
# ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
# (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
# SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

cmake_minimum_required(VERSION 2.8)
set(CMAKE_MODULE_PATH "${CMAKE_MODULE_PATH}" "${CMAKE_SOURCE_DIR}/CMake/Modules")
include(get_python_site_package)
include(get_pyotl_module_root)
include(get_pymodule_current_library_root)
include(get_pymodule_current_install_root)
include(split_pymodule_project_path)
include(make_pymodule_library)
include(make_pymodule_install)

get_pyotl_module_root()
set(PyOTL_MODULE_ROOT "${PyOTL_MODULE_ROOT}" CACHE PATH "PyOTL_MODULE_ROOT")
unset(PyOTL_MODULE_ROOT)

FIND_PACKAGE(OTL REQUIRED)
if(OTL_FOUND)
	set(CMAKE_MODULE_PATH "${CMAKE_MODULE_PATH}" "${OTL_SOURCE_DIR}/CMake/Modules")
	include(list_projects)
	
	project(PyOTL) # special project name
	include_directories("${CMAKE_SOURCE_DIR}/Include")
	add_subdirectory("${CMAKE_SOURCE_DIR}/Include")
	
	option(BUILD_SHARED_LIBS "Build shared libraries" NO)
	
	if(NOT CMAKE_BUILD_TYPE AND NOT CMAKE_CONFIGURATION_TYPES)
		set(CMAKE_BUILD_TYPE Release CACHE STRING "Choose the type of build." FORCE)
		set_property(CACHE CMAKE_BUILD_TYPE PROPERTY STRINGS "Debug" "Release" "MinSizeRel" "RelWithDebInfo")
	endif()
endif()
