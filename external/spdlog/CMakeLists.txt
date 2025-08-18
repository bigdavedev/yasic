# Copyright 2025 - David Brown <d.brown@bigdavedev.com>
# SPDX-License-Identifier: MIT

FetchContent_Declare (
	spdlog

	URL https://github.com/gabime/spdlog/archive/refs/tags/v1.15.3.zip

	OVERRIDE_FIND_PACKAGE
	DOWNLOAD_NO_PROGRESS TRUE
	SYSTEM
)

set (SPDLOG_FMT_EXTERNAL ON CACHE BOOL "Use fmt from external source")

FetchContent_MakeAvailable (spdlog)
