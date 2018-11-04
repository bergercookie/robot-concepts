/* +------------------------------------------------------------------------+
   |                             robot-concepts                             |
   |                                                                        |
   | Copyright (c) 2018, Individual contributors see AUTHORS.md file        |
   | See AUTHORS.md - All rights reserved.                                  |
   | Released under BSD License. See details in LICENSE file                |
   +------------------------------------------------------------------------+ */

/**
 * @file
 * @brief Basic concepts used across the core lib
 */

#pragma once

///@todo needs gcc8 for -std=c++2a - consider going directly for that
// #include <concepts>
#include <type_traits> // is_same_v

#include <cstddef>

namespace rc
{

/**
 * Primitive Number concept
 * For now this is either an int, float or double just to make life easier
 */
template<typename T>
concept bool Number = std::is_same_v<T, int> ||
											std::is_same_v<T, float> ||
											std::is_same_v<T, double>;


/**
 * Dimensions concept
 * @sa Sizeable
 */
template<typename T>
concept bool Dimable = requires(T a)
{
	/**
	 * Number of dimensions of the object at hand
	 */
	{ a.dims() } -> std::size_t;
};

/**
 * Size concept
 * This is rather similar to the Dimable object but with different semantics
 * @sa Dimable
 */
template<typename T>
concept bool Sizeable = requires(T a)
{
	/**
	 * Get the size of the object at hand
	 */
	{ a.size() } -> std::size_t;
};


} // end of namespace rc
