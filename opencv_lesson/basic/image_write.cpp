/*
 * =====================================================================================
 *
 *       Filename:  image_write.cpp
 *
 *    Description:  image_write
 *
 *        Version:  1.0
 *        Created:  2014-12-29 19:43:10
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  VRer (Linux Programmer), vrml1234@gmail.com
 *        Company:  VrmlStudio.inc
 *
 * =====================================================================================
 */

#include <iostream>
#include <opencv2/highgui/highgui.hpp>

int main(int argc, char *argv[])
{
	const std::string base = "lena";
	std::vector<std::string> files;
	files.push_back(base + ".bmp");
	files.push_back(base + ".png");
    cv::Mat src_img = cv::imread("lena.jpg", 1);
	if(!src_img.data) return -1; 
	std::vector<std::string>::iterator it = files.begin();
	for(;it!=files.end(); ++it)
	{
		if(cv::imwrite(*it, src_img))
			std::cout << "imwrite:" << *it << " ... success" << std::endl;
		else
			std::cout << "imwrite:" << *it << " ... failure" << std::endl;
	}
	return 0;
}

//end of image_write
