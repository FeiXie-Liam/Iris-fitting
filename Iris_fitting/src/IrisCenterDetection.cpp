#include "IrisCenterDetection.h"

void IrisCenterDetection::ProcessEye(Mat &eyeRegion, Point2f& center)
{
	cv::Mat grayEye;//眼部区域灰度图
	//cv::resize(eyeRegion, eyeRegion, cv::Size(200, 150));
	cv::Mat hsv(eyeRegion.rows, eyeRegion.cols, 8, 3);//HSV空间眼部区域图像
	cv::cvtColor(eyeRegion, hsv, cv::COLOR_RGB2HSV);
	//imshow("hsv", hsv);
	//cv::imshow("eyeRegion", eyeRegion);
	ProcessHSV(hsv);
	cv::cvtColor(hsv, eyeRegion, cv::COLOR_HSV2RGB);
	cv::cvtColor(eyeRegion, grayEye, cv::COLOR_RGB2GRAY);
	TraverseImg(grayEye,center);
}

void IrisCenterDetection::ProcessHSV(cv::Mat& src)
{
	std::vector<uchar> max(3), min(3);
	std::vector<cv::Mat> hsvChannels;
	cv::split(src, hsvChannels);
	//FindMaxMin(hsvChannels[1], min[1], max[1]);
	//FindMaxMin(hsvChannels[2], min[2], max[2]);
	//EnhanceImg(hsvChannels[1], min[1], max[1]);
	EnhanceImg(hsvChannels[2], min[2], max[2]);
	cv::merge(hsvChannels, src);
}

void IrisCenterDetection::EnhanceImg(cv::Mat &src, uchar min, uchar max)
{
	for (int i = 0; i < src.rows; i++)
	{
		for (int j = 0; j < src.cols; j++)
		{
			//src.ptr<uchar>(i)[j] = (src.ptr<uchar>(i)[j]-min)/(max-min);
			if (src.ptr<uchar>(i)[j]>225) src.ptr<uchar>(i)[j] = 255;
			else	src.ptr<uchar>(i)[j] += 25 ;

		}
	}
}

void IrisCenterDetection::TraverseImg(Mat Gray, Point2f& center)
{

}

void IrisCenterDetection::findAverage(Mat img, float& average)
{
	float sum = 0;
	for (int i = 0; i < img.rows; i++)
	{
		for (int j = 0; j < img.cols; j++)
		{
			sum += img.ptr(i)[j];
		}
	}
	average = sum / (img.rows*img.cols);
}


