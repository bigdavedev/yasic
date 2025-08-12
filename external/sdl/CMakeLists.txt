# Copyright 2025 - David Brown <d.brown@bigdavedev.com>
# SPDX-License-Identifier: MIT
FetchContent_Declare (
	SDL3
	GIT_REPOSITORY https://github.com/libsdl-org/SDL
	GIT_TAG main
#	URL https://github.com/libsdl-org/SDL/archive/refs/heads/main.zip
	#URL_HASH MD5=c8b5efd263936b157e63bf5c1fad4bc6 # v3.2.18

	SYSTEM
	OVERRIDE_FIND_PACKAGE
	DOWNLOAD_NO_PROGRESS TRUE
)

FetchContent_MakeAvailable (SDL3)