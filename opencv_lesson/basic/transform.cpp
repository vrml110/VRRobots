/*
 * =====================================================================================
 *
 *       Filename:  transform.cpp
 *
 *    Description:  transform
 *
 *        Version:  1.0
 *        Created:  2014-12-23 20:57:59
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  VRer (Linux Programmer), vrml1234@gmail.com
 *        Company:  VrmlStudio.inc
 *
 * =====================================================================================
 */

#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>

int main(int argc, char *argv[])
{
	cv::Mat src_img = cv::imread("lena.jpg", 0);
	if(!src_img.data) return -1;
	cv::Mat dst_img = ~src_img;
	cv::namedWindow("src image", CV_WINDOW_AUTOSIZE|CV_WINDOW_FREERATIO);
	cv::namedWindow("dst image", CV_WINDOW_AUTOSIZE|CV_WINDOW_FREERATIO);
	cv::imshow("src image", src_img);
	cv::imshow("dst image", dst_img);
	cv::waitKey(0);
}

//end of transform.cpp
