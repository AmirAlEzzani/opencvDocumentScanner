#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "iostream"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    qDebug() << "OpenCV Ver :" << CV_VERSION;
    qDebug() << "OpenCV Maj Ver :" << CV_VERSION_MAJOR;
    qDebug() << "OpenCV Min Ver :" << CV_VERSION_MINOR;

    cv::Mat Image = cv::imread("C:/Users/Amir/Documents/qtdocscan/Untitled.png",cv::IMREAD_GRAYSCALE);
    cv::Mat Output;
    cv::threshold(Image,Output,100,255,cv::THRESH_BINARY);
    std::vector<std::vector<cv::Point>> contours;
    std::vector<cv::Vec4i> hierarchy;

    cv::findContours(Output,contours,hierarchy,cv::RETR_LIST,cv::CHAIN_APPROX_SIMPLE);
    cv::Mat mask = cv::Mat::zeros(Output.size(),CV_8UC3);
    cv::drawContours(mask,contours,0,cv::Scalar(255,255,0),4);
    std::cout<<contours[0]<<std::endl;


    cv::imshow("output", mask);
   /* cv::imwrite("Newimage.jpg", Image);
    cv::namedWindow("Image Display", cv::WINDOW_NORMAL);
    cv::imshow("image Display, Image", Image); */

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{

}

