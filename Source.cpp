#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <iostream>
using namespace cv;
using namespace std;
int main()
{
    Mat image = imread("C:/Users/Amir/source/repos/docScannerGUI/docScannerGUI/IMG_9730.jpg",0);
    namedWindow("test", 0);
    imshow("test", image);
    waitKey(0);
}