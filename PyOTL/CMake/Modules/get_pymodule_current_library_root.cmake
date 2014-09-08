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

function(get_pymodule_current_library_root)
	file(RELATIVE_PATH PYMODULE_RELATIVE_PATH "${CMAKE_SOURCE_DIR}/Include" "${CMAKE_CURRENT_SOURCE_DIR}")
	set(PYMODULE_CURRENT_LIBRARY_ROOT "${PyOTL_MODULE_ROOT}/${PYMODULE_RELATIVE_PATH}")
	get_filename_component(PYMODULE_CURRENT_LIBRARY_ROOT "${PYMODULE_CURRENT_LIBRARY_ROOT}" ABSOLUTE)
	set(PYMODULE_CURRENT_LIBRARY_ROOT "${PYMODULE_CURRENT_LIBRARY_ROOT}" PARENT_SCOPE)
endfunction()