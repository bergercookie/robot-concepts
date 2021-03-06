/* +------------------------------------------------------------------------+
   |                             robot-concepts                             |
   |                                                                        |
   | Copyright (c) 2018, Individual contributors see AUTHORS.md file        |
   | See AUTHORS.md - All rights reserved.                                  |
   | Released under BSD License. See details in LICENSE file                |
   +------------------------------------------------------------------------+ */

/**
 * @file
 * @brief Pose concept declaration
 */

#pragma once

#include <robot_concepts/core/basics.h>
#include <robot_concepts/core/Vector.h>
#include <robot_concepts/core/RotationMatrix.h>

namespace rc
{

/**
 * A generic Pose
 * @tparam N Type of the elements that the Pose holds (e.g., double)
 */
template<typename T, Number N>
concept bool Pose = Dimable<T> && requires (T a)
{
	/**
	 * Specify whether the Pose has Covariance information
	 */
	{ a.isPDF() } -> bool;
	/**
	 * Translation part of Pose
	 */
	{ a.translation() } -> Vector<N>&;
	/**
	 * Rotation part of Pose - in Matrix form
	 */
	{ a.rotation() } -> RotationMatrix<N>&;

};


} // end of namespace rc
