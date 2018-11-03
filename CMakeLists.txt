################################################################################
#                                robot-concepts                                #
#                                                                              #
# Copyright (c) 2018, Individual contributors see AUTHORS.md file              #
# See AUTHORS.md - All rights reserved.                                        #
# Released under BSD License. See details in LICENSE file                      #
################################################################################

#
# General configuration
#
cmake_minimum_required(VERSION 3.10.2) # Ubuntu 18
project(robot_concepts VERSION 0.1.0 LANGUAGES C CXX)

# Compile by default in Release
if (NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Release CACHE STRING "Type of build" FORCE)
    message(STATUS "Using default build type: ${CMAKE_BUILD_TYPE}")
    set_property(CACHE CMAKE_BUILD_TYPE PROPERTY STRINGS "Debug" "Release"
                                                         "MinSizeRel"
                                                         "RelWithDebInfo")
endif()

#
# CMake extras
#
list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake)
include(BuildUtils)
include(CheckCXXCompilerFlag)
include(GNUInstallDirs)

# Check that the compiler supports concepts - currently supported only on gcc>=6
check_cxx_compiler_flag("-fconcepts" COMPILER_SUPPORTS_CONCEPTS)
if (NOT COMPILER_SUPPORTS_CONCEPTS)
    message(FATAL_ERROR "Compiler in use (${CMAKE_CXX_COMPILER_ID}) does not support C++17 + concepts")
endif()

#
# Output directories
#
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/bin)

set(CMAKE_INSTALL_MODULES_DIR ${CMAKE_INSTALL_LIBDIR}/cmake/${PROJECT_NAME})

#
# Global cmake vars
#
message(STATUS "PROJECT_NAME: ${PROJECT_NAME}")
set(ROBOT_CONCEPTS_NAMESPACE ${PROJECT_NAME})  # target-based configuration

#
# Project subdirectories
#
add_subdirectory(cmake)
add_subdirectory(third_party)
add_subdirectory(demo)
add_subdirectory(robot_concepts)
add_subdirectory(doc)

