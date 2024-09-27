#include "download.h"
#include "ui_download.h"
#include <qfile.h>
download::download(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::download)
{
    ui->setupUi(this);
}

download::~download()
{
    delete ui;
}

void download::on_pushButton_clicked()
{
    QFile::copy("C:/Users/Amir/Documents/qtdocscan/build/Desktop_x86_windows_msvc2022_pe_64bit-Debug/output.jpg", "C:/Users/Amir/Downloads/output.jpg");
    QFile::copy("C:/Users/Amir/Documents/qtdocscan/output.txt", "C:/Users/Amir/Downloads/output.txt");
}

