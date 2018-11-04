/* +------------------------------------------------------------------------+
   |                             robot-concepts                             |
   |                                                                        |
   | Copyright (c) 2018, Individual contributors see AUTHORS.md file        |
   | See AUTHORS.md - All rights reserved.                                  |
   | Released under BSD License. See details in LICENSE file                |
   +------------------------------------------------------------------------+ */

#pragma once

#include <cmath>
#include <cstddef>
#include <robot_concepts/core/Pose.h>

/**
 * A simple 2D rotation matrix implentation
 */
class ExampleVector
{
public:
	ExampleVector(double x, double y)
		: x(x),
		  y(y) {  }
	/** L2 norm */
	double norm()
	{
		return sqrt(x*x + y*y);
	}

	std::vector<double> getAsStdVector()
	{
		return std::vector<double>{x, y};
	}

	constexpr std::size_t size() { return 2; }

private:
	double x;
	double y;
};


/**
 * A simple 2D rotation matrix implentation
 */
class ExampleRotMat
{
public:
	/** Constructor accepting an angle in radians */
	ExampleRotMat(double theta)
		: theta(theta) {}
	constexpr std::size_t rows() { return _rows; }
	constexpr std::size_t cols() { return _rows; }
	constexpr std::size_t size() { return _rows * _rows; }

	std::vector<double> getAsStdVector() {
		return std::vector{cos(theta), -sin(theta), sin(theta), cos(theta)};
	};

private:
	static constexpr std::size_t _rows = 2;
	double theta;

};

/**
 * A simple pose implentation
 */
class ExamplePose
{
public:
	ExamplePose(double x, double y, double theta)
		: v(x, y),
		  r(theta) { }
	constexpr bool isPDF() { return false; }
	constexpr std::size_t dims() { return 2; }

	rc::Vector<double>& translation() { return v; }
	rc::RotationMatrix<double>& rotation() { return r; }

private:
	ExampleVector v;
	ExampleRotMat r;
};


