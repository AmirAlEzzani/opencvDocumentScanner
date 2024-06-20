#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

using namespace cv;
using namespace std;

void main() {
	string path = "resources/paper.jpg";
	Mat img = imread(path);
	imshow("Image", img);
	waitKey(0);
}