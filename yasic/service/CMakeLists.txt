# Copyright 2025 - David Brown <d.brown@bigdavedev.com>
# SPDX-License-Identifier: MIT
add_library (yasic_service INTERFACE)
add_library (Yasic::Service ALIAS yasic_service)

target_sources (
	yasic_service

	INTERFACE
	FILE_SET yasic_service_headers
	TYPE HEADERS
	BASE_DIRS ${CMAKE_CURRENT_SOURCE_DIR}/include
	FILES
	include/yasic/service/service.h
	include/yasic/service/service_locator.h
)

if (YASIC_ENABLE_TESTING)
	add_subdirectory (tests)
endif ()