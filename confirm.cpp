#include "confirm.h"
#include "ui_confirm.h"
#include <QPixmap>
confirm::confirm(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::confirm)
{
    ui->setupUi(this);
    //ui->confirmImg->setPixmap(pix);
}

confirm::~confirm()
{
    delete ui;
}

