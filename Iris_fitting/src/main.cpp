#include <opencv2/opencv.hpp>
#include <iostream>
#include <sstream>
#include "IrisCenterDetection.h"

using namespace std;
using namespace cv;

void readImg(int number, Mat& img)
{
	std::stringstream strStream;
	std::string filename;
	strStream << number;
	//filename = "eye_region_highlight/eye" + strStream.str() + ".jpg";
	filename = "eye_region/eye" + strStream.str() + ".jpg";
	img = cv::imread(filename);
}

int main()
{
	Mat img;
	Point2f center;
	IrisCenterDetection irisCenterDetection;
	int count = 1;
	while (waitKey(0) != 27)
	{
		readImg(count, img);
		if (img.data != nullptr)
		{
			irisCenterDetection.ProcessEye(img, center);
			imshow("img", img);
		}
		else return -1;
		count++;
	}
	return 0;
}