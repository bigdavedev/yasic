# Copyright 2025 - David Brown <d.brown@bigdavedev.com>
# SPDX-License-Identifier: MIT
add_library (yasic_logging)
add_library (Yasic::Logging ALIAS yasic_logging)

target_sources (
	yasic_logging

	PUBLIC
	FILE_SET yasic_logging_headers
	TYPE HEADERS
	BASE_DIRS ${CMAKE_CURRENT_SOURCE_DIR}/include
	FILES
	include/yasic/logging/log_service.h
	include/yasic/logging/null_log_service.h
	include/yasic/logging/spdlog_service.h

	PRIVATE
	source/yasic/logging/spdlog_service.cpp
)

target_link_libraries (
	yasic_logging

	PUBLIC
	Yasic::CompilerFlags
	Yasic::Service

	fmt::fmt
	spdlog::spdlog
)
