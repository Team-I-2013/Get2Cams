#include <opencv2/core/core.hpp>        // core���W���[���̃w�b�_�[���C���N���[�h
#include <opencv2/highgui/highgui.hpp>  // highgui���W���[���̃w�b�_�[���C���N���[�h
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
	cv::namedWindow("�J�����P", CV_WINDOW_AUTOSIZE);
	cv::namedWindow("�J�����Q", CV_WINDOW_AUTOSIZE);

	IplImage* img;
	char imgfile[] = "img.png";
	img = cvLoadImage(imgfile, CV_LOAD_IMAGE_ANYCOLOR | CV_LOAD_IMAGE_ANYDEPTH);
	cvShowImage("setting", img);

	while (1)
	{
		cv::Mat cam1image;
		cv::Mat cam2image;
		cap_left >> cam1image; // �J�����P(�����̃J�����̉摜�H)
		cap_right >> cam2image; // �J�����Q(�E���̃J�����̉摜�H)
		cv::imshow("�J�����P",cam1image);
		cv::imshow("�J�����Q",cam2image);
		int key = cv::waitKey(1);
		if (key == 0x1b) break; // ESC�ŏI��
	}
}
