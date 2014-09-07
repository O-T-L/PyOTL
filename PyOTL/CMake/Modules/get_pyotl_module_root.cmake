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

function(get_pyotl_module_root)
	if("$ENV{PyOTL_MODULE_ROOT}" STREQUAL "")
		FIND_PACKAGE(PythonInterp)
		if(PYTHONINTERP_FOUND)
			execute_process(COMMAND ${PYTHON_EXECUTABLE} -m site --user-site OUTPUT_VARIABLE PYTHON_USER_SITE_PACKAGE)
			STRING(REGEX REPLACE "(\r?\n)+$" "" PYTHON_USER_SITE_PACKAGE "${PYTHON_USER_SITE_PACKAGE}")
			set(PyOTL_MODULE_ROOT "${PYTHON_USER_SITE_PACKAGE}" PARENT_SCOPE)
		endif()
	else()
		set(PyOTL_MODULE_ROOT "$ENV{PyOTL_MODULE_ROOT}" PARENT_SCOPE)
	endif()
endfunction()