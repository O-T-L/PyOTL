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

set(BoostPython_FOUND NO)
FIND_PACKAGE(PythonLibs)
if(PYTHONLIBS_FOUND)
	string(REPLACE "." ";" PYTHONLIBS_VERSION_LIST "${PYTHONLIBS_VERSION_STRING}")
	list(GET PYTHONLIBS_VERSION_LIST 0 PYTHONLIBS_VERSION_MAJOR)
	if(${PYTHONLIBS_VERSION_MAJOR} STREQUAL "2")
		set(Boost_PYTHON_VERSION_STRING "")
	else()
		set(Boost_PYTHON_VERSION_STRING ${PYTHONLIBS_VERSION_MAJOR})
	endif()
	FIND_PACKAGE(Boost COMPONENTS python${Boost_PYTHON_VERSION_STRING} ${BoostPython_FIND_COMPONENTS})
	if(Boost_FOUND)
		set(BoostPython_FOUND YES)
		set(BoostPython_INCLUDE_DIRS ${PYTHON_INCLUDE_DIRS} ${Boost_INCLUDE_DIR})
		set(BoostPython_LIBRARIES ${PYTHON_LIBRARIES} ${Boost_LIBRARIES})
	endif()
endif()