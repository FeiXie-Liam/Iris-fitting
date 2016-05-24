#include <opencv2/opencv.hpp>

using namespace cv;

class IrisCenterDetection
{
public:
	void ProcessEye(Mat &eyeRegion, Point2f &center);//处理眼部区域图像

	void ProcessHSV(cv::Mat& src);//图像转换到hsv空间进行图像亮度增强

	void TraverseImg(Mat Gray, Point2f& center);

	void EnhanceImg(cv::Mat &src, uchar min, uchar max);//HSV空间亮度增强

	void findAverage(Mat img, float& average);//眼部区域图像像素值均值
};