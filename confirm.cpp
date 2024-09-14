#include "confirm.h"
#include "ui_confirm.h"
#include <QPixmap>
#include "mainwindow.h"
confirm::confirm(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::confirm)
{
    ui->setupUi(this);
    QPixmap pix(file_name);
    ui->confirmImg->setPixmap(pix);
}

confirm::~confirm()
{
    delete ui;
}

