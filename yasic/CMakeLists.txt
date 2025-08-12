# Copyright 2025 - David Brown <d.brown@bigdavedev.com>
# SPDX-License-Identifier: MIT

add_executable (yasic)

target_sources (
	yasic
	
	PRIVATE
	main.cpp
)

set_target_properties (
	yasic

	PROPERTIES
	CXX_STANDARD     23
	WIN32_EXECUTABLE $<PLATFORM_ID:Windows>
)

target_link_libraries (
	yasic

	PUBLIC
	Yasic::CompilerFlags
	SDL3::SDL3
)