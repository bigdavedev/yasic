# Copyright 2025 - David Brown <d.brown@bigdavedev.com>
# SPDX-License-Identifier: MIT
set (CMAKE_C_COMPILER clang-cl.exe)
set (CMAKE_CXX_COMPILER clang++-cl.exe)

set (
	YASIC_COMPILER_FLAGS_LIST
	-Weverything
	-Wno-c++98-compat-pedantic
	-Wno-c++20-compat
	-Wno-padded
	-Wno-exit-time-destructors
)
