#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

int main() {
	cv::Mat img = cv::imread("./IMG_9730.jpg", cv::IMREAD_GRAYSCALE);
	cv::imshow("Window", img);
	cv::waitKey(0);
	return 0;
}