/*
 * =====================================================================================
 *
 *       Filename:  gaussian.cpp
 *
 *    Description:  gaussian
 *
 *        Version:  1.0
 *        Created:  2014-12-24 19:41:48
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
	cv::Mat dst_img1, dst_img2;
	cv::GaussianBlur(src_img, dst_img1, cv::Size(11,11), 10, 10);
	cv::GaussianBlur(src_img, dst_img2, cv::Size(51,3), 80, 3);
	cv::namedWindow("Blur image1", CV_WINDOW_AUTOSIZE|CV_WINDOW_FREERATIO);
	cv::namedWindow("Blur image2", CV_WINDOW_AUTOSIZE|CV_WINDOW_FREERATIO);
	cv::imshow("Blur image1", dst_img1);
	cv::imshow("Blur image2", dst_img2);
	cv::waitKey(0);
}

//end of gaussian.cpp
