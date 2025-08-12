# Copyright 2025 - David Brown <d.brown@bigdavedev.com>
# SPDX-License-Identifier: MIT
cmake_minimum_required (VERSION 3.31)

list (PREPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/tools/cmake)

include (InstallBuildTools)

project (
	HelloSDL
	VERSION 0.1.0
	LANGUAGES C CXX
	DESCRIPTION "Template for creating SDL applications"
	HOMEPAGE_URL "https://github.com/PterabyteGames/cpp-sdl-template.git"
)

option (YASIC_BUILD_DOCS "Generate documentation" OFF)
option (YASIC_ENABLE_TESTING "Enable running tests" ON)
option (YASIC_ENABLE_PACKAGING "Enable packaging" ON)

include (StageConfig)
include (CompilerFlagsTarget)

if (YASIC_ENABLE_TESTING)
	enable_testing ()
endif ()

if (YASIC_BUILD_DOCS)
	add_subdirectory (docs)
endif ()

add_subdirectory (external)

if (YASIC_ENABLE_CLANG_TIDY)
	set (CMAKE_CXX_CLANG_TIDY "clang-tidy")
endif ()

add_subdirectory (yasic)

if (YASIC_ENABLE_PACKAGING)
	include (InstallRequiredSystemLibraries)

	install (TARGETS yasic RUNTIME)

	get_target_property (SDL3InstallTarget SDL3::SDL3 ALIASED_TARGET)
	install (TARGETS ${SDL3InstallTarget} RUNTIME)

	install (DIRECTORY data TYPE DATA)

	set (CPACK_PACKAGE_CONTACT "David Brown <d.brown@bigdavedev.com>")
	set (CPACK_PACKAGE_EXECUTABLES "yasic" "Yasic")

	if (LINUX)
		include (package/Linux)
	elseif (WIN32)
		include (package/Windows)
	endif ()

	include (CPack)
endif ()
