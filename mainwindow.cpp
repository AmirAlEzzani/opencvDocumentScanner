#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QMessageBox>
#include <QPixmap>
#include <QImage>
#include <QVector>
#include <QQueue>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    QString file_name = QFileDialog::getOpenFileName(this, tr("Open File"), QDir::homePath(), tr("Images (*.png *.xpm *.jpg)"));

    if (!file_name.isEmpty()) {
        QMessageBox::information(this, "...", file_name);
        QImage img(file_name);
        QPixmap pix = QPixmap::fromImage(img);

        int w = ui->label_pic->width();
        int h = ui->label_pic->height();

        ui->label_pic->setPixmap(pix.scaled(w, h, Qt::KeepAspectRatio));
    }
}

void MainWindow::start_Camera()
{
    M_Camera->start();
}

void MainWindow::stop_camera()
{
    M_Camera->stop();

}
