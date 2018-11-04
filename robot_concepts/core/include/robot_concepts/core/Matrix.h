/* +------------------------------------------------------------------------+
   |                             robot-concepts                             |
   |                                                                        |
   | Copyright (c) 2018, Individual contributors see AUTHORS.md file        |
   | See AUTHORS.md - All rights reserved.                                  |
   | Released under BSD License. See details in LICENSE file                |
   +------------------------------------------------------------------------+ */

/**
 * @file
 * @brief Matrix concept declaration
 */

#pragma once

#include <robot_concepts/core/basics.h>

#include <cstddef>
#include <vector>

namespace rc
{

/**
 * A 2D Matrix concept
 */
template<typename T, Number N>
concept bool Matrix = Sizeable<T> && requires (T a)
{
	/** Return num of rows of matrix */
	{ a.rows() } -> std::size_t;
	/** Return num of columns of matrix */
	{ a.cols() } -> std::size_t;
	/** Return total number of elements of matrix*/
	{ a.size() } -> std::size_t;
	/**
	 * Get a flat std::vector with the contents of the matrix
	 * The contents should be laid out row-per-row
	 * @todo Generalise this
	 */
	{ a.getAsStdVector() } -> std::vector<N>;
};


} // end of namespace rc
