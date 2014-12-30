/*
 * =====================================================================================
 *
 *       Filename:  polylines.cpp
 *
 *    Description:  polylines
 *
 *        Version:  1.0
 *        Created:  2014-12-29 20:41:14
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
	cv::Size img_size(500, 500);
	cv::Mat img = cv::Mat::zeros(img_size, CV_8UC3);
	cv::RNG gen(0xffffffff);
	int npt[] = {4, 4};
	cv::Point pt1[2][4];
	const cv::Point *ppt[2] = {pt1[0], pt1[1]};
	for(int i=0; i<2; i++)
		for(int j=0; j<4; j++)
			pt1[i][j] = cv::Point(gen.uniform(0, img_size.width), gen.uniform(0, img_size.height));
	cv::polylines(img, ppt, npt, 2, true, cv::Scalar(0,0,200), 3, 4);
	for(int i=0; i<2; i++)
		for(int j=0; j<4; j++)
			pt1[i][j] = cv::Point(gen.uniform(0, img_size.width), gen.uniform(0, img_size.height));
	cv::polylines(img, ppt, npt, 2, true, cv::Scalar(0,200,0), 3, 8);
	for(int i=0; i<2; i++)
		for(int j=0; j<4; j++)
			pt1[i][j] = cv::Point(gen.uniform(0, img_size.width), gen.uniform(0, img_size.height));
	cv::polylines(img, ppt, npt, 2, false, cv::Scalar(200,0,0), 10, CV_AA);
	cv::namedWindow("drawing", CV_WINDOW_AUTOSIZE|CV_WINDOW_FREERATIO);
	cv::imshow("drawing", img);
	cv::waitKey(0);
}

//end of polylines.cpp
