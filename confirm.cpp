#include "confirm.h"
#include "ui_confirm.h"
#include <QPixmap>
#include "iostream"
#include "QProcess"
#include <opencv2/opencv.hpp>
#include <opencv2/imgcodecs.hpp>
#include "opencv2/highgui.hpp"
#include "opencv2/imgproc.hpp"
#include "QFileDialog"
#include "QMessageBox"
#include <windows.h>
#include "download.h"
confirm::confirm(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::confirm)
{
    ui->setupUi(this);
    QPixmap pix("C:/Users/Amir/Documents/qtdocscan/build/Desktop_x86_windows_msvc2022_pe_64bit-Debug/input.jpg");
    ui->confirmImg->setPixmap(pix);
}

confirm::~confirm()
{
    delete ui;
}


void confirm::on_pushButton_clicked()
{
    cv::Mat input = cv::imread("C:/Users/Amir/Documents/qtdocscan/build/Desktop_x86_windows_msvc2022_pe_64bit-Debug/input.jpg", cv::IMREAD_GRAYSCALE);
    cv::Mat Image;
    cv::resize(input, Image, cv::Size(), 0.75, 0.75);
    cv::Mat Output;
    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    cv::threshold(Image, Output, 200, 255, cv::THRESH_BINARY);
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
    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    cv::goodFeaturesToTrack(graymask, cornersList, 4, 0.05, 300);

    for (const auto& corner : cornersList) {
        std::cout << "Corner: (" << corner.x << ", " << corner.y << ")" << std::endl;
        cv::circle(cornersImage, corner, 5, cv::Scalar(255, 0, 0), -1); // Draw corners
    }

    // Sort the corners to ensure they are in top-left, top-right, bottom-right, bottom-left order
    std::sort(cornersList.begin(), cornersList.end(), [](const cv::Point2f &a, const cv::Point2f &b) {
        return a.y < b.y;  // Sort based on y-coordinate first
    });

    std::vector<cv::Point2f> sortedCorners(4);
    std::vector<cv::Point2f> top(2), bottom(2);

    top[0] = cornersList[0];
    top[1] = cornersList[1];
    bottom[0] = cornersList[2];
    bottom[1] = cornersList[3];

    // Sort top and bottom by x-coordinate
    if (top[0].x < top[1].x) {
        sortedCorners[0] = top[0];  // top-left
        sortedCorners[1] = top[1];  // top-right
    } else {
        sortedCorners[0] = top[1];  // top-left
        sortedCorners[1] = top[0];  // top-right
    }

    if (bottom[0].x < bottom[1].x) {
        sortedCorners[3] = bottom[0];  // bottom-left
        sortedCorners[2] = bottom[1];  // bottom-right
    } else {
        sortedCorners[3] = bottom[1];  // bottom-left
        sortedCorners[2] = bottom[0];  // bottom-right
    }

    // Define destination points based on the bounding box of the detected corners
    std::vector<cv::Point2f> dstPoints = {
        cv::Point2f(0, 0),                      // top-left
        cv::Point2f(Image.cols - 1, 0),         // top-right
        cv::Point2f(Image.cols - 1, Image.rows - 1), // bottom-right
        cv::Point2f(0, Image.rows - 1)          // bottom-left
    };

    // Get the transformation matrix
    cv::Mat perspectiveMatrix = cv::getPerspectiveTransform(sortedCorners, dstPoints);

    // Warp the perspective
    cv::Mat warpedImage;
    cv::warpPerspective(Image, warpedImage, perspectiveMatrix, Image.size());

    // Show the warped image
    //cv::imshow("Warped Image", warpedImage);
    //cv::imshow("Input", Image);
    //cv::imshow("graymask", graymask);
    //cv::imshow("mask", mask);
    //cv::imshow("corners", cornersImage);
    cv::imwrite("output.jpg", warpedImage);

    this->hide();
    download download;
    download.setModal(true);
    download.exec();

}

