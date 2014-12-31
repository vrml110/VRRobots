/*
 * =====================================================================================
 *
 *       Filename:  matrix.cpp
 *
 *    Description:  matrix
 *
 *        Version:  1.0
 *        Created:  2014-12-31 9:50:12
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  vrml1234@gmail.com
 *        Company:  vrmlstudio
 *
 * =====================================================================================
 */

#include <stdio.h>
#include <highgui.h>
#include <time.h>

#pragma comment(lib, "cv.lib")
#pragma comment(lib, "cvaux.lib")
#pragma comment(lib, "cxcore.lib")
#pragma comment(lib, "highgui.lib")
#pragma comment(lib, "ml.lib")


int main (int argc, char **argv)
{
    int i, j;
    int nrow = 3;
    int ncol = 3;
    CvMat *src, *dst, *mul;
    double det;
    CvRNG rng = cvRNG (time (NULL));
    src = cvCreateMat (nrow, ncol, CV_32FC1);
    dst = cvCreateMat (ncol, nrow, CV_32FC1);
    mul = cvCreateMat (nrow, nrow, CV_32FC1);
    printf ("src\n");
    cvmSet (src, 0, 0, 1);
    for (i = 0; i < src->rows; i++)
    {
        for (j = 0; j < src->cols; j++)
        {
            cvmSet (src, i, j, cvRandReal (&rng));
            printf ("% lf\t", cvmGet (src, i, j));
        }
        printf ("\n");
    }
    det = cvInvert (src, dst, CV_SVD);
    printf ("det(src)=%lf\n", det);
    printf ("dst\n");
    for (i = 0; i < dst->rows; i++)
    {
        for (j = 0; j < dst->cols; j++)
        {
            printf ("% lf\t", cvmGet (dst, i, j));
        }
        printf ("\n");
    }
    cvMatMul (src, dst, mul);
    printf ("mul\n");
    for (i = 0; i < mul->rows; i++)
    {
        for (j = 0; j < mul->cols; j++)
        {
            printf ("% lf\t", cvmGet (mul, i, j));
        }
        printf ("\n");
    }
    cvReleaseMat (&src);
    cvReleaseMat (&dst);
    cvReleaseMat (&mul);
    return 0;
}

//end of matrix.cpp
