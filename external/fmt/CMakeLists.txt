# Copyright 2025 - David Brown <d.brown@bigdavedev.com>
# SPDX-License-Identifier: MIT

FetchContent_Declare (
	fmt

	URL https://github.com/fmtlib/fmt/archive/refs/tags/11.2.0.zip

	OVERRIDE_FIND_PACKAGE
	DOWNLOAD_NO_PROGRESS TRUE
	SYSTEM
)

FetchContent_MakeAvailable (fmt)
