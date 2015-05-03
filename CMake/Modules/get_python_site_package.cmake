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

function(get_python_site_package)
	FIND_PACKAGE(PythonInterp)
	if(PYTHONINTERP_FOUND)
		if(${PYTHON_VERSION_MAJOR} STREQUAL "2")
			execute_process(COMMAND ${PYTHON_EXECUTABLE} -c "from distutils.sysconfig import get_python_lib; print get_python_lib(True)" OUTPUT_VARIABLE PYTHON_SITE_PACKAGES)
		else()
			execute_process(COMMAND ${PYTHON_EXECUTABLE} -c "import site; print(site.getsitepackages()[0])" OUTPUT_VARIABLE PYTHON_SITE_PACKAGES)
		endif()
		STRING(REGEX REPLACE "(\r?\n)+$" "" PYTHON_SITE_PACKAGES "${PYTHON_SITE_PACKAGES}")
		set(PYTHON_SITE_PACKAGES "${PYTHON_SITE_PACKAGES}" PARENT_SCOPE)
	endif()
endfunction()
