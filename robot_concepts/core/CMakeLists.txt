################################################################################
#                                robot-concepts                                #
#                                                                              #
# Copyright (c) 2018, Individual contributors see AUTHORS.md file              #
# See AUTHORS.md - All rights reserved.                                        #
# Released under BSD License. See details in LICENSE file                      #
################################################################################

# TODO automate this

#
# General config
#
set(LIB_NAME core)

#
# Build it
#
add_library(${LIB_NAME} INTERFACE)
add_library(${ROBOT_CONCEPTS_NAMESPACE}::${LIB_NAME} ALIAS ${LIB_NAME})

target_include_directories(
    ${LIB_NAME} INTERFACE
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include/>
    $<INSTALL_INTERFACE:include/>
)

add_build_options(${LIB_NAME})

#
# dependencies
#

#
# tests + installation
#
# TODO
