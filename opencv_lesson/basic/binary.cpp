/*
 * =====================================================================================
 *
 *       Filename:  binary.cpp
 *
 *    Description:  binary
 *
 *        Version:  1.0
 *        Created:  2014-12-24 19:08:34
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  VRer (Linux Programmer), vrml1234@gmail.com
 *        Company:  VrmlStudio.inc
 *
 * =====================================================================================
 */

#include	<opencv2/core/core.hpp>
#include	<opencv2/imgproc/imgproc.hpp>
#include	<opencv2/highgui/highgui.hpp>
#include    "function.h"

using namespace std;

int main(int argc, char *argv[])
{
	CFunction function;
	cv::Mat gray_img = cv::imread("lena.jpg", 0);
	if(!gray_img.data) return -1;
	cv::Mat bin_img, bininv_img, trunc_img, tozero_img, tozeroinv_img;
	cv::threshold(gray_img, bin_img, 0, 255, cv::THRESH_BINARY|cv::THRESH_OTSU);
	cv::threshold(gray_img, bininv_img, 0, 255, cv::THRESH_BINARY_INV|cv::THRESH_OTSU);
	cv::threshold(gray_img, trunc_img, 0, 255, cv::THRESH_TRUNC|cv::THRESH_OTSU);
	cv::threshold(gray_img, tozero_img, 0, 255, cv::THRESH_TOZERO|cv::THRESH_OTSU);
	cv::threshold(gray_img, tozeroinv_img, 0, 255, cv::THRESH_TOZERO_INV|cv::THRESH_OTSU);
	cv::Mat adaptive_img;
	cv::adaptiveThreshold(gray_img, adaptive_img, 255, cv::ADAPTIVE_THRESH_GAUSSIAN_C, cv::THRESH_BINARY, 7, 8);
	cv::namedWindow("Binary", CV_WINDOW_AUTOSIZE|CV_WINDOW_FREERATIO);
	cv::namedWindow("Binary Inv", CV_WINDOW_AUTOSIZE|CV_WINDOW_FREERATIO);
	cv::namedWindow("Trunc", CV_WINDOW_AUTOSIZE|CV_WINDOW_FREERATIO);
	cv::namedWindow("ToZero", CV_WINDOW_AUTOSIZE|CV_WINDOW_FREERATIO);
	cv::namedWindow("ToZero Inv", CV_WINDOW_AUTOSIZE|CV_WINDOW_FREERATIO);
	cv::namedWindow("Adaptive", CV_WINDOW_AUTOSIZE|CV_WINDOW_FREERATIO);
	cv::imshow("Binary", bin_img);
	cv::imshow("Binary Inv", bininv_img);
	cv::imshow("Trunc", trunc_img);
	cv::imshow("ToZero", tozero_img);
	cv::imshow("ToZero Inv", tozeroinv_img);
	cv::imshow("Adaptive", adaptive_img);
	cv::waitKey(0);
	cout<<"sum is "<<function.sum(100)<<endl;
}

//end of binary.cpp
