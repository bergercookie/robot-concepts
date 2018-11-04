/* +------------------------------------------------------------------------+
   |                             robot-concepts                             |
   |                                                                        |
   | Copyright (c) 2018, Individual contributors see AUTHORS.md file        |
   | See AUTHORS.md - All rights reserved.                                  |
   | Released under BSD License. See details in LICENSE file                |
   +------------------------------------------------------------------------+ */

/**
 * @file
 * @brief Toy app demoing the use of core concepts
 */

#include "example_classes.h"

#include <robot_concepts/core/Pose.h>

#include <cmath>
#include <iostream>

void printVector(rc::Vector<double>& v)
{
	for (const auto& vi: v.getAsStdVector())
	{
		std::cout << vi << ", ";
	}
	std::cout << std::endl;
}

void printRotMat(rc::RotationMatrix<double>& r)
{
	for (const auto& ri: r.getAsStdVector())
	{
		std::cout << ri << ", ";
	}
	std::cout << std::endl;
}
void printPose(rc::Pose<double>& p)
{
	printVector(p.translation());
	std::cout << std::endl;
	printRotMat(p.rotation());
}


int main(int argc, char *argv[])
{
	ExamplePose p(1.0, 2.0, M_PI);
	std::cout << "Pose:" << std::endl
						<< "=====" << std::endl;
	printPose(p);

	return 0;
}
