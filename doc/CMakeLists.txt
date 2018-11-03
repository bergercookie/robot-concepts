################################################################################
#                                robot-concepts                                #
#                                                                              #
# Copyright (c) 2018, Individual contributors see AUTHORS.md file              #
# See AUTHORS.md - All rights reserved.                                        #
# Released under BSD License. See details in LICENSE file                      #
################################################################################

find_package(Doxygen)

if (NOT DOXYGEN_FOUND)
    return()
endif()

# We've got doxygen, build docs...
# TODO
