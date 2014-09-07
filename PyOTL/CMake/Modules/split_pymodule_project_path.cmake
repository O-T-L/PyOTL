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

function(split_pymodule_project_path PYMODULE_PROJECT_PATH)
	get_filename_component(PYMODULE_PROJECT ${PYMODULE_PROJECT_PATH} NAME)
	string(REPLACE "." ";" PYMODULE_PROJECT_LIST ${PYMODULE_PROJECT})
	list(GET PYMODULE_PROJECT_LIST -1 PYMODULE_NAME)
	list(REMOVE_AT PYMODULE_PROJECT_LIST -1)
	string(REPLACE ";" "/" PYMODULE_PATH_APPEND "${PYMODULE_PROJECT_LIST}")
	get_filename_component(PYMODULE_PATH ${PYMODULE_PROJECT_PATH} PATH)
	if (NOT ${PYMODULE_PATH_APPEND} STREQUAL "")
		set(PYMODULE_PATH "${PYMODULE_PATH}/${PYMODULE_PATH_APPEND}")
	endif()
	
	set(PYMODULE_NAME "${PYMODULE_NAME}" PARENT_SCOPE)
	set(PYMODULE_PATH "${PYMODULE_PATH}" PARENT_SCOPE)
endfunction()