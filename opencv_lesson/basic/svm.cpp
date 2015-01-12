/*
 * =====================================================================================
 *
 *       Filename:  svm.cpp
 *
 *    Description:  svm
 *
 *        Version:  1.0
 *        Created:  2014-12-31 9:20:19
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  vrml1234@gmail.com
 *        Company:  vrmlstudio
 *
 * =====================================================================================
 */

#include <cv.h>
#include <highgui.h>
#include <ml.h>
#include <time.h>

int main (int argc, char **argv)
{
	const int s = 1000;
	int size = 400;
	int i, j, sv_num;
	IplImage *img;
	CvSVM svm = CvSVM ();
	CvSVMParams param;
	CvTermCriteria criteria;
	CvRNG rng = cvRNG (time (NULL));
	CvPoint pts[s];
	float data[s * 2];
	int res[s];
	CvMat data_mat, res_mat;
	CvScalar rcolor;
	const float *support;
	img = cvCreateImage (cvSize (size, size), IPL_DEPTH_8U, 3);
	cvZero (img);
	for (i = 0; i < s; i++)
	{
		pts[i].x = cvRandInt (&rng) % size;
		pts[i].y = cvRandInt (&rng) % size;
		if (pts[i].y > 50 * cos (pts[i].x * CV_PI / 100) + 200)
		{
			cvLine (img, cvPoint (pts[i].x - 2, pts[i].y - 2), cvPoint (pts[i].x + 2, pts[i].y + 2), CV_RGB (255, 0, 0));
			cvLine (img, cvPoint (pts[i].x + 2, pts[i].y - 2), cvPoint (pts[i].x - 2, pts[i].y + 2), CV_RGB (255, 0, 0));
			res[i] = 1;
		}
    else
	{
		if (pts[i].x > 200)
		{
			cvLine (img, cvPoint (pts[i].x - 2, pts[i].y - 2), cvPoint (pts[i].x + 2, pts[i].y + 2), CV_RGB (0, 255, 0));
			cvLine (img, cvPoint (pts[i].x + 2, pts[i].y - 2), cvPoint (pts[i].x - 2, pts[i].y + 2), CV_RGB (0, 255, 0));
			res[i] = 2;
		}
		else
		{
			cvLine (img, cvPoint (pts[i].x - 2, pts[i].y - 2), cvPoint (pts[i].x + 2, pts[i].y + 2), CV_RGB (0, 0, 255));
			cvLine (img, cvPoint (pts[i].x + 2, pts[i].y - 2), cvPoint (pts[i].x - 2, pts[i].y + 2), CV_RGB (0, 0, 255));
			res[i] = 3;
		}
	}
}
	cvNamedWindow ("SVM", CV_WINDOW_AUTOSIZE);
	cvShowImage ("SVM", img);
	cvWaitKey (0);
	for (i = 0; i < s; i++)
	{
		data[i * 2] = float (pts[i].x) / size;
		data[i * 2 + 1] = float (pts[i].y) / size;
	}
	cvInitMatHeader (&data_mat, s, 2, CV_32FC1, data);
	cvInitMatHeader (&res_mat, s, 1, CV_32SC1, res);
	criteria = cvTermCriteria (CV_TERMCRIT_EPS, 1000, FLT_EPSILON);
	param = CvSVMParams (CvSVM::C_SVC, CvSVM::RBF, 10.0, 8.0, 1.0, 10.0, 0.5, 0.1, NULL, criteria);
	svm.train (&data_mat, &res_mat, NULL, NULL, param);
	for (i = 0; i < size; i++)
	{
		for (j = 0; j < size; j++)
		{
			CvMat m;
			float ret = 0.0;
			float a[] = { float (j) / size, float (i) / size };
			cvInitMatHeader (&m, 1, 2, CV_32FC1, a);
			ret = svm.predict (&m);
			switch ((int) ret)
			{
				case 1:
					rcolor = CV_RGB (100, 0, 0);
					break;
				case 2:
					rcolor = CV_RGB (0, 100, 0);
					break;
				case 3:
					rcolor = CV_RGB (0, 0, 100);
					break;
			}
			cvSet2D (img, i, j, rcolor);
		}
	}
	for (i = 0; i < s; i++)
	{
		CvScalar rcolor;
		switch (res[i])
		{
			case 1:
				rcolor = CV_RGB (255, 0, 0);
				break;
			case 2:
				rcolor = CV_RGB (0, 255, 0);
				break;
			case 3:
				rcolor = CV_RGB (0, 0, 255);
				break;
		}
		cvLine (img, cvPoint (pts[i].x - 2, pts[i].y - 2), cvPoint (pts[i].x + 2, pts[i].y + 2), rcolor);
		cvLine (img, cvPoint (pts[i].x + 2, pts[i].y - 2), cvPoint (pts[i].x - 2, pts[i].y + 2), rcolor);
	}
	sv_num = svm.get_support_vector_count ();
	for (i = 0; i < sv_num; i++)
	{
		support = svm.get_support_vector (i);
		cvCircle (img, cvPoint ((int) (support[0] * size), (int) (support[1] * size)), 5, CV_RGB (200, 200, 200));
	}
	cvNamedWindow ("SVM", CV_WINDOW_AUTOSIZE);
	cvShowImage ("SVM", img);
	cvWaitKey (0);
	cvDestroyWindow ("SVM");
	cvReleaseImage (&img);
	return 0;
}

//end of test_opencv.cpp
