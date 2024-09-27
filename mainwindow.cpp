#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "iostream"
#include "QProcess"
#include <opencv2/opencv.hpp>
#include <opencv2/imgcodecs.hpp>
#include "opencv2/highgui.hpp"
#include "confirm.h"
#include "QFileDialog"
#include "QMessageBox"
#include <windows.h>


//move image processing to the window that opens when you click "upload image" or confirm camera capture
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    qDebug() << "OpenCV Ver :" << CV_VERSION;
    qDebug() << "OpenCV Maj Ver :" << CV_VERSION_MAJOR;
    qDebug() << "OpenCV Min Ver :" << CV_VERSION_MINOR;
    remove("C:/Users/Amir/Documents/qtdocscan/build/Desktop_x86_windows_msvc2022_pe_64bit-Debug/input.jpg");
    remove("C:/Users/Amir/Documents/qtdocscan/build/Desktop_x86_windows_msvc2022_pe_64bit-Debug/output.jpg");
    remove("C:/Users/Amir/Documents/qtdocscan/build/Desktop_x86_windows_msvc2022_pe_64bit-Debug/output.txt");

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
        }

        if (screenshot == 27) {
            cout << "Terminating..." << endl;
            destroyWindow(windowName.c_str());
            break;
        }
    }

    cap.release();
}


void MainWindow::on_pushButton_2_clicked()
{


    QString sourcePath = QFileDialog::getOpenFileName(0, tr("Select Image"), ".", tr("Images (*.png *.xpm *.jpg *.jpeg *.bmp)"));
    QString destinationPath = QDir::currentPath() + "/input.jpg";  // Save the copied image to the script's directory

    if (QFile::copy(sourcePath, destinationPath)) {
        qDebug() << "Image copied successfully to: " << destinationPath;
    } else {
        qDebug() << "Failed to copy the image.";
    }
    this->hide();
    confirm confirm;
    confirm.setModal(true);
    confirm.exec();
}

