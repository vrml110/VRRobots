// test_cam.cpp : Defines the entry point for the console application.
//

#include <stdio.h>
#include <highgui.h>

int main( int argc, char** argv )
{ 
	int key;
	CvCapture *capture;
	IplImage *frameImage;
	char windowNameCapture[] = "Capture";
	if ( ( capture = cvCreateCameraCapture( 1 ) ) == NULL ) {
		printf( "Œ¥’“µΩ…„œÒÕ∑°£°£°£\n" );
		return -1;
	}
	
	cvNamedWindow( windowNameCapture, CV_WINDOW_AUTOSIZE );
	while ( 1 ) {
		frameImage = cvQueryFrame( capture );
		cvShowImage( windowNameCapture, frameImage );
		key = cvWaitKey( 10 );
		if( key == 'q' ){
			break;
		}
	}
	cvReleaseCapture( &capture );
	cvDestroyWindow( windowNameCapture );
	return 0;
}

//end of test_cam.cpp
