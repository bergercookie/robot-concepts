/* +------------------------------------------------------------------------+
   |                             robot-concepts                             |
   |                                                                        |
   | Copyright (c) 2018, Individual contributors see AUTHORS.md file        |
   | See AUTHORS.md - All rights reserved.                                  |
   | Released under BSD License. See details in LICENSE file                |
   +------------------------------------------------------------------------+ */

/**
 * @file
 * @brief Vector concept declaration
 */

#pragma once

#include <robot_concepts/core/basics.h>

#include <vector>

namespace rc
{

/**
 * A generic vector in N dimensions
 * @tparam N Type of the elements that the array holds
 */
template<typename T, Number N>
concept bool Vector = Sizeable<T> && requires (T a)
{
	{ a.norm() } -> Number;
	{ a.getAsStdVector() } -> std::vector<N>;

};


} // end of namespace rc
