################################################################################
#                                robot-concepts                                #
#                                                                              #
# Copyright (c) 2018, Individual contributors see AUTHORS.md file              #
# See AUTHORS.md - All rights reserved.                                        #
# Released under BSD License. See details in LICENSE file                      #
################################################################################

set(EXEC_NAME demo)
add_executable(${EXEC_NAME} ${EXEC_NAME}.cpp
                            example_classes.h
                            example_classes.cpp)
target_link_libraries(${EXEC_NAME} PRIVATE ${ROBOT_CONCEPTS_NAMESPACE}::core)
