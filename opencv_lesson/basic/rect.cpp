/*
 * =====================================================================================
 *
 *       Filename:  rect.cpp
 *
 *    Description:  rect
 *
 *        Version:  1.0
 *        Created:  2014-12-29 20:19:49
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  VRer (Linux Programmer), vrml1234@gmail.com
 *        Company:  VrmlStudio.inc
 *
 * =====================================================================================
 */

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>

int main(int argc, char *argv[])
{
	cv::Mat img = cv::Mat::zeros(500, 500, CV_32F);
	cv::rectangle(img, cv::Point(200,50), cv::Point(300, 150), cv::Scalar(0,0,200), 3, 4);
	cv::rectangle(img, cv::Point(200,200), cv::Point(300, 300), cv::Scalar(0,200,0), 5, 8);
	cv::rectangle(img, cv::Point(200,350), cv::Point(300, 450), cv::Scalar(200,0,0), -1, CV_AA);
	cv::namedWindow("drawing", CV_WINDOW_AUTOSIZE|CV_WINDOW_FREERATIO);
	cv::imshow("drawing", img);
	cv::waitKey(0);
}

//end of rect.cpp
