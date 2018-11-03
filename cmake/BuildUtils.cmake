################################################################################
#																robot-concepts																#
#																																							#
# Copyright (c) 2018, Individual contributors see AUTHORS.md file							#
# See AUTHORS.md - All rights reserved.																				#
# Released under BSD License. See details in LICENSE file											#
################################################################################

#
# Utility methods for the various compilation procedures
#

function(add_build_options target)

	# specify standard + compile options
	target_compile_features(${target} INTERFACE c_std_11 cxx_std_17)
	target_compile_options(${target} INTERFACE -Wall -Wextra -fPIC)

	# extra flags for native arch
	if (NOT CMAKE_CROSSCOMPILING)
		check_cxx_compiler_flag("-march=native" COMPILER_SUPPORTS_FLAG)
		if(COMPILER_SUPPORTS_FLAG)
			target_compile_options(${target} INTERFACE -march=native)
		else()
			message(WARNING "Compiler in use (${CMAKE_CXX_COMPILER_ID} does not support -march=native")
		endif()

	endif()

endfunction()
