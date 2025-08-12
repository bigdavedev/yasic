# Copyright 2025 - David Brown <d.brown@bigdavedev.com>
# SPDX-License-Identifier: MIT
add_executable (yasic_service_tests)

target_sources (
	yasic_service_tests

	PRIVATE
	service_locator_test.cpp
)

target_link_libraries (
	yasic_service_tests

	PRIVATE
	Yasic::Service
	Yasic::CompilerFlags
	gtest
	gtest_main
)

add_test (
	NAME YasicServiceTests
	COMMAND yasic_service_tests
)