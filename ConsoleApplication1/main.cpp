#include <opencv2/core/core.hpp>        // coreモジュールのヘッダーをインクルード
#include <opencv2/highgui/highgui.hpp>  // highguiモジュールのヘッダーをインクルード
#include <opencv2/imgproc/imgproc.hpp>
#include <iostream>
#include <opencv/cv.h>
#include <opencv/cxcore.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, const char* argv[])
{
	cv::VideoCapture cap_left(0);
	cv::VideoCapture cap_right(1);
	cv::namedWindow("setting", CV_WINDOW_AUTOSIZE);
	cv::namedWindow("カメラ１", CV_WINDOW_AUTOSIZE);
	cv::namedWindow("カメラ２", CV_WINDOW_AUTOSIZE);

	IplImage* img;
	char imgfile[] = "img.png";
	img = cvLoadImage(imgfile, CV_LOAD_IMAGE_ANYCOLOR | CV_LOAD_IMAGE_ANYDEPTH);
	cvShowImage("setting", img);

	while (1)
	{
		cv::Mat cam1image;
		cv::Mat cam2image;
		cap_left >> cam1image; // カメラ１(左側のカメラの画像？)
		cap_right >> cam2image; // カメラ２(右側のカメラの画像？)
		cv::imshow("カメラ１",cam1image);
		cv::imshow("カメラ２",cam2image);
		int key = cv::waitKey(1);
		if (key == 0x1b) break; // ESCで終了
	}
}
