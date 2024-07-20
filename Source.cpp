#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <iostream>
using namespace cv;
using namespace std;
int main()
{
    Mat img = cv::imread("C:/Users/Amir/source/repos/docScannerGUI/docScannerGUI/IMG_9730.jpg");
    namedWindow("First OpenCV Application", WINDOW_AUTOSIZE);
    imshow("First OpenCV Application", img);
    moveWindow("First OpenCV Application", 0, 45);
    waitKey(0);
    destroyAllWindows();
    return 0;
}