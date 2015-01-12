/*
 * =====================================================================================
 *
 *       Filename:  rotate.cpp
 *
 *    Description:  rotate
 *
 *        Version:  1.0
 *        Created:  2015-1-12 19:17:37
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  VRer (Linux Programmer), vrml1234@gmail.com
 *        Company:  VrmlStudio.inc
 *
 * =====================================================================================
 */

#include	<cv.h>
#include	<highgui.h>

#pragma comment(lib,"cv.lib")
#pragma comment(lib,"cxcore.lib")
#pragma comment(lib,"highgui.lib")
#pragma comment(lib,"ml.lib")
#pragma comment(lib,"cvcam.lib")

int main (int argc, char **argv)
{
	double angle = -45.0, scale = 1.0;
	IplImage *src_img = 0, *dst_img = 0;
	CvMat *map_matrix;
	CvPoint2D32f center;
	CvPoint pt1, pt2;
	CvRect rect;
	if (argc >= 2)
		src_img = cvLoadImage (argv[1], CV_LOAD_IMAGE_ANYDEPTH | CV_LOAD_IMAGE_ANYCOLOR);
	if (src_img == 0)
		return -1;
	rect.x = (int) (src_img->width * 0.25);
	rect.y = (int) (src_img->height * 0.25);
	rect.width = (int) (src_img->width * 0.5);
	rect.height = (int) (src_img->height * 0.5);
	cvSetImageROI (src_img, rect);
	dst_img = cvCloneImage (src_img);
	map_matrix = cvCreateMat (2, 3, CV_32FC1);
	center = cvPoint2D32f (src_img->width * 0.25, src_img->height * 0.25);
	cv2DRotationMatrix (center, angle, scale, map_matrix);
	cvWarpAffine (src_img, dst_img, map_matrix, CV_INTER_LINEAR + CV_WARP_FILL_OUTLIERS, cvScalarAll (255));
	cvResetImageROI (src_img);
	cvResetImageROI (dst_img);
	pt1 = cvPoint (rect.x, rect.y);
	pt2 = cvPoint (rect.x + rect.width, rect.y + rect.height);
	cvRectangle (src_img, pt1, pt2, CV_RGB (255, 0, 255), 2, 8, 0);
	cvNamedWindow ("src", CV_WINDOW_AUTOSIZE);
	cvNamedWindow ("dst", CV_WINDOW_AUTOSIZE);
	cvShowImage ("src", src_img);
	cvShowImage ("dst", dst_img);
	cvWaitKey (0);
	cvDestroyWindow ("src");
	cvDestroyWindow ("dst");
	cvReleaseImage (&src_img);
	cvReleaseImage (&dst_img);
	cvReleaseMat (&map_matrix);
	return 1;
}

//end of rotate.cpp
