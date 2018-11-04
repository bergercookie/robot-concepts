/* +------------------------------------------------------------------------+
   |                             robot-concepts                             |
   |                                                                        |
   | Copyright (c) 2018, Individual contributors see AUTHORS.md file        |
   | See AUTHORS.md - All rights reserved.                                  |
   | Released under BSD License. See details in LICENSE file                |
   +------------------------------------------------------------------------+ */

/**
 * @file
 * @brief Rotation Matrix concept declaration
 */

#pragma once

#include <robot_concepts/core/Matrix.h>

namespace rc
{

/**
 * A generic rotation matrix in N dimensions
 */
template<typename T, Number N>
concept bool RotationMatrix = Matrix<T, N> && true;

} // end of namespace rc
