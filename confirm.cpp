#include "confirm.h"
#include "ui_confirm.h"
#include <QPixmap>
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
