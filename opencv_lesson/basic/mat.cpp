/*
 * =====================================================================================
 *
 *       Filename:  mat.cpp
 *
 *    Description:  mat
 *
 *        Version:  1.0
 *        Created:  2014-12-23 21:31:13
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  VRer (Linux Programmer), vrml1234@gmail.com
 *        Company:  VrmlStudio.inc
 *
 * =====================================================================================
 */

#include <iostream>
#include <opencv2/core/core.hpp>

int main(int argc, char *argv[])
{
	cv::Mat m = (cv::Mat_<double>(3,3) << 1, 0, 0, 0, 1, 0, 0, 0, 1);
	double angle = 45, a = std::cos(angle*CV_PI/180), b = std::sin(angle*CV_PI/180);
	cv::Mat r = (cv::Mat_<double>(2,2) << a, -b, b, a);
	std::cout << "m=" << m << std::endl << std::endl;
	std::cout << "r=" << r << std::endl;
}

//end of mat.cpp
