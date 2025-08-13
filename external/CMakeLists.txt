# Copyright 2025 - David Brown <d.brown@bigdavedev.com>
# SPDX-License-Identifier: MIT
include (FetchContent)

if (YASIC_ENABLE_TESTING)
	add_subdirectory (googletest)
endif ()

add_subdirectory (fmt)
add_subdirectory (spdlog)

add_subdirectory (sdl)
