#include <opencv2/opencv.hpp>

using namespace cv;

class IrisCenterDetection
{
public:
	void ProcessEye(Mat &eyeRegion, Point2f &center);//�����۲�����ͼ��

	void ProcessHSV(cv::Mat& src);//ͼ��ת����hsv�ռ����ͼ��������ǿ

	void TraverseImg(Mat Gray, Point2f& center);

	void EnhanceImg(cv::Mat &src, uchar min, uchar max);//HSV�ռ�������ǿ

	void findAverage(Mat img, float& average);//�۲�����ͼ������ֵ��ֵ
};