/*
 * =====================================================================================
 *
 *       Filename:  kmeans.c
 *
 *    Description:  kmeans
 *
 *        Version:  1.0
 *        Created:  2014-12-31 15:11:12
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
 
#define MAX_CLUSTERS (10) /* number of cluster */
 
int main(int argc, char** argv)
{
  int i, size;
  IplImage *src_img = 0, *dst_img = 0;
  CvMat tmp_header;
  CvMat *clusters, *points, *tmp;
  CvMat *count = cvCreateMat( MAX_CLUSTERS, 1, CV_32SC1);
  CvMat *centers = cvCreateMat( MAX_CLUSTERS, 3, CV_32FC1);
  const char *imagename;
 
  // (1)load a specified file as a 3-channel color image
  imagename = argc > 1 ? argv[1] : "lena.jpg";
  src_img = cvLoadImage(imagename, CV_LOAD_IMAGE_COLOR);
  if(src_img == 0)
    return -1;
 
  size = src_img->width * src_img->height;
  dst_img  = cvCloneImage(src_img);
  clusters = cvCreateMat(size, 1, CV_32SC1 );
  points   = cvCreateMat(size, 1, CV_32FC3 );
 
  // (2)reshape the image to be a 1 column matrix 
#if 0
  tmp = cvCreateMat(size, 1, CV_8UC3);
  tmp = cvReshape(src_img, &tmp_header, 0, size);
  cvConvert(tmp, points);
  cvReleaseMat(&tmp);
#else
  for(i=0; i<size; i++) {
    points->data.fl[i*3+0] = (uchar)src_img->imageData[i*3+0];
    points->data.fl[i*3+1] = (uchar)src_img->imageData[i*3+1];
    points->data.fl[i*3+2] = (uchar)src_img->imageData[i*3+2];
  }
#endif
 
  // (3)run k-means clustering algorithm to segment pixels in RGB color space
  cvKMeans2( points, MAX_CLUSTERS, clusters,
         cvTermCriteria( CV_TERMCRIT_EPS+CV_TERMCRIT_ITER, 10, 1.0 ),
         1, 0, 0, centers, 0);
 
  // (4)make a each centroid represent all pixels in the cluster
  for(i=0; i<size; i++) {
    int idx = clusters->data.i[i];
    dst_img->imageData[i*3+0] = (char)centers->data.fl[idx*3+0];
    dst_img->imageData[i*3+1] = (char)centers->data.fl[idx*3+1];
    dst_img->imageData[i*3+2] = (char)centers->data.fl[idx*3+2];
  }
 
  // (5)show source and destination image, and quit when any key pressed
  cvNamedWindow( "src", CV_WINDOW_AUTOSIZE);
  cvShowImage( "src", src_img );
  cvNamedWindow( "low-color", CV_WINDOW_AUTOSIZE);
  cvShowImage( "low-color", dst_img );
  cvWaitKey(0);
 
  cvDestroyWindow("src");
  cvDestroyWindow("low-color");
  cvReleaseImage(&src_img);
  cvReleaseImage(&dst_img);
  cvReleaseMat(&clusters);
  cvReleaseMat(&points);
  cvReleaseMat(¡éers);
  cvReleaseMat(&count);
 
  return 0;
}

/* end of kmeans.c */
