#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    qDebug() << "OpenCV Ver :" << CV_VERSION;
    qDebug() << "OpenCV Maj Ver :" << CV_VERSION_MAJOR;
    qDebug() << "OpenCV Min Ver :" << CV_VERSION_MINOR;

    cv::Mat Image = cv::imread("C:/Users/Amir/Documents/qtdocscan/candidate3.jpg");
    cv::imshow("test", Image);
    qDebug() << "Image Width: " << Image.cols;
    qDebug() << "Image Height: " << Image.rows;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{

}

