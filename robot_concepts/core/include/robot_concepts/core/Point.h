/* +------------------------------------------------------------------------+
   |                             robot-concepts                             |
   |                                                                        |
   | Copyright (c) 2018, Individual contributors see AUTHORS.md file        |
   | See AUTHORS.md - All rights reserved.                                  |
   | Released under BSD License. See details in LICENSE file                |
   +------------------------------------------------------------------------+ */

/**
 * @file
 * @brief The Point concept declaration
 */

#include <robot_concepts/core/basics.h>
#include <robot_concepts/core/Matrix.h>

#include <vector>

#pragma once

namespace rc
{

/**
 * The Point concept
 * @tparam N Type of the elements that the Pose holds (e.g., double)
 */
template<typename T, Number N>
concept bool Point = Dimable<T> && requires(T a, T b)
{
	/**
	 * Get the point coordinates in std::vector<N> form
	 * @note Generalise it to return not only in an std::vector but in an
	 * arbitrary STL container.
	 */
	{ a.pos() } -> std::vector<N>&;
	{ a.posHasCovariance() } -> bool;
	{ a.posCovariance() } -> Matrix<N>&;
	{ a == b } -> bool;
	{ a != b } -> bool;
	{ a += b } -> Point<N>&;
	{ a -= b } -> Point<N>&;
	{ a + b }  -> Point<N>&;
	{ a - b }  -> Point<N>&;
};

// template<typename P, Number N>
// concept bool Point = requires(P a, P b)
// {
// };

} // end of namespace rc
