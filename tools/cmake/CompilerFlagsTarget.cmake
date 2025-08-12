# Copyright 2025 - David Brown <d.brown@bigdavedev.com>
# SPDX-License-Identifier: MIT
macro (yasic_create_compiler_flags_target)
	add_library (yasic_compiler_flags INTERFACE)
	add_library (Yasic::CompilerFlags ALIAS yasic_compiler_flags)

	foreach (flag IN LISTS YASIC_COMPILER_FLAGS_LIST)
		target_compile_options (yasic_compiler_flags INTERFACE ${flag})
	endforeach ()

	target_compile_features (yasic_compiler_flags INTERFACE cxx_std_23)
endmacro ()

macro (yasic_try_enable_ipo)
	include (CheckIPOSupported)

	check_ipo_supported(RESULT result OUTPUT output)
	if (result)
		set (CMAKE_INTERPROCEDURAL_OPTIMIZATION_RELEASE TRUE)
		set (CMAKE_INTERPROCEDURAL_OPTIMIZATION_RELWITHDEBINFO TRUE)
		set (CMAKE_INTERPROCEDURAL_OPTIMIZATION_MINSIZEREL TRUE)
	else ()
		message (WARNING "IPO is not supported: ${output}")
	endif ()
endmacro ()

yasic_create_compiler_flags_target ()
