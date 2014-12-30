/*
 * =====================================================================================
 *
 *       Filename:  line.cpp
 *
 *    Description:  line
 *
 *        Version:  1.0
 *        Created:  2014-12-29 20:10:46
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
	cv::Mat img = cv::Mat::zeros(500, 500, CV_8UC3);
	cv::line(img, cv::Point(100, 100), cv::Point(400, 105), cv::Scalar(0,0,200), 3, 4);  
	cv::line(img, cv::Point(100, 200), cv::Point(400, 205), cv::Scalar(0,200,0), 5, 8);
	cv::line(img, cv::Point(100, 300), cv::Point(400, 305), cv::Scalar(200,0,0), 10, CV_AA);
	cv::circle(img, cv::Point(100,300), 100 ,cv::Scalar(0,200,0), 8, 8);
	cv::namedWindow("drawing", CV_WINDOW_AUTOSIZE|CV_WINDOW_FREERATIO);
	cv::imshow("drawing", img);
	cv::waitKey(0);
}

//end of line.cpp
