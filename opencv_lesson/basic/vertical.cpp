/*
 * =====================================================================================
 *
 *       Filename:  vertical.cpp
 *
 *    Description:  vertical
 *
 *        Version:  1.0
 *        Created:  2014-12-24 19:03:43
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
	cv::Mat src_img = cv::imread("lena.jpg", 1);
	if(!src_img.data) return -1;
	cv::Mat v_img, h_img, b_img;
	cv::flip(src_img, v_img, 0);
	cv::flip(src_img, h_img, 1);
	cv::flip(src_img, b_img, -1);
	cv::namedWindow("vertical flip image", CV_WINDOW_AUTOSIZE|CV_WINDOW_FREERATIO);
	cv::namedWindow("horizontal flip image", CV_WINDOW_AUTOSIZE|CV_WINDOW_FREERATIO);
	cv::namedWindow("both flip image", CV_WINDOW_AUTOSIZE|CV_WINDOW_FREERATIO);
	cv::imshow("vertical flip image", v_img);
	cv::imshow("horizontal flip image", h_img);
	cv::imshow("both flip image", b_img);
	cv::waitKey(0);
}

//end of vertical.cpp
