# Copyright 2025 - David Brown <d.brown@bigdavedev.com>
# SPDX-License-Identifier: MIT
set (INSTALL_GTEST OFF CACHE BOOL "Enable GTest installation target")

FetchContent_Declare (
	GTest
	URL https://github.com/google/googletest/archive/refs/tags/v1.15.2.zip
	URL_HASH MD5=eb1c5c237d13ed12bf492d3997ca6b0d # v1.15.2

	SYSTEM
	OVERRIDE_FIND_PACKAGE
	DOWNLOAD_NO_PROGRESS TRUE
)

FetchContent_MakeAvailable (GTest)
