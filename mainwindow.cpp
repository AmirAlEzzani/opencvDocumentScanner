#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "iostream"
#include "QProcess"
#include <opencv2/opencv.hpp>
#include <opencv2/imgcodecs.hpp>
#include "opencv2/highgui.hpp"
#include "opencv2/imgproc.hpp"
#include "confirm.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    qDebug() << "OpenCV Ver :" << CV_VERSION;
    qDebug() << "OpenCV Maj Ver :" << CV_VERSION_MAJOR;
    qDebug() << "OpenCV Min Ver :" << CV_VERSION_MINOR;

    cv::Mat input = cv::imread("C:/Users/Amir/Documents/qtdocscan/paper.jpg", cv::IMREAD_GRAYSCALE);
    cv::Mat Image;
    cv::resize(input, Image, cv::Size(), 0.75, 0.75);
    cv::Mat Output;
    cv::threshold(Image, Output, 100, 255, cv::THRESH_BINARY);
    std::vector<std::vector<cv::Point>> contours;
    std::vector<cv::Vec4i> hierarchy;

    cv::findContours(Output, contours, hierarchy, cv::RETR_EXTERNAL, cv::CHAIN_APPROX_SIMPLE);
    double maxArea = 0;
    int largestContourIdx = -1;
    for (size_t i = 0; i < contours.size(); i++) {
        double area = cv::contourArea(contours[i]);
        if (area > maxArea) {
            maxArea = area;
            largestContourIdx = i;
         }
    }



    cv::Mat mask = cv::Mat::zeros(Output.size(), CV_8UC3);
    cv::Mat graymask;
    if (largestContourIdx != -1) {
        cv::drawContours(mask, contours, largestContourIdx, cv::Scalar(0, 255, 255), 1);
    }
    cv::cvtColor(mask, graymask, cv::COLOR_BGR2GRAY);



    cv::Mat cornersImage = graymask.clone(); // Clone the original image to draw corners on
    std::vector<cv::Point2f> cornersList;
    cv::goodFeaturesToTrack(graymask, cornersList, 10, 0.01, 10);

    for (const auto& corner : cornersList) {
        cv::circle(cornersImage, corner, 5, cv::Scalar(255, 0, 0), -1); // Draw corners
    }


    cv::imshow("Input", Image);
    cv::imshow("graymask", graymask);
    cv::imshow("mask", mask);
    cv::imshow("corners", cornersImage);
    cv::imwrite("output.jpg", mask);
    system("C:/Users/Amir/Documents/qtdocscan/run.bat");
}




MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked() {
    using namespace std;
    using namespace cv;
    VideoCapture cap(0);
    if (!cap.isOpened()) {
    cerr << "ERROR! Unable to open camera\n";
    return;
    }

    Mat frame;
    char filename[100];
    int screenshot;
    const std::string windowName = "CAMERA 1";
    namedWindow(windowName.c_str());

    while (true) {
        cap.read(frame);

        if (frame.empty()) {
            cerr << "ERROR! blank frame grabbed\n";
            break;
        }

        imshow(windowName.c_str(), frame);

        screenshot = cv::waitKey(30);

        if (screenshot == ' ') {
            sprintf_s(filename, sizeof(filename), "./input.jpg");
            imwrite(filename, frame);
            cout << "Screenshot Taken";
            this->hide();
            confirm confirm;
            confirm.setModal(true);
            confirm.exec();
            //display input.jpg in confirmation.ui
            // Open the confirmation form with screenshot <--------------------------
        }

        if (screenshot == 27) {
            cout << "Terminating..." << endl;

            destroyWindow(windowName.c_str());
            break;
        }
    }
//convert jpg to pdf and add download button
    cap.release();
}


