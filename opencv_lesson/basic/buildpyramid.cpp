/*
 * =====================================================================================
 *
 *       Filename:  buildpyramid.cpp
 *
 *    Description:  buildpyramid
 *
 *        Version:  1.0
 *        Created:  2014-12-23 21:25:31
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
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>

int main(int argc, char *argv[])
{
	cv::Mat src_img = cv::imread("lena.jpg", 1);
	if(!src_img.data) return -1;
	std::vector<cv::Mat> dst_img;
	cv::buildPyramid(src_img, dst_img, 2);
	cv::namedWindow("level0", CV_WINDOW_AUTOSIZE|CV_WINDOW_FREERATIO);
	cv::namedWindow("level1", CV_WINDOW_AUTOSIZE|CV_WINDOW_FREERATIO);
	cv::namedWindow("level2", CV_WINDOW_AUTOSIZE|CV_WINDOW_FREERATIO);  
	cv::imshow("level0", dst_img[0]);
	cv::imshow("level1", dst_img[1]);
	cv::imshow("level2", dst_img[2]);
	cv::waitKey(0);
}

//end of buildpyramid.cpp
