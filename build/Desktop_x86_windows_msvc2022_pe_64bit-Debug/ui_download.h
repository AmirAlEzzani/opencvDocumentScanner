/********************************************************************************
** Form generated from reading UI file 'download.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DOWNLOAD_H
#define UI_DOWNLOAD_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_download
{
public:
    QLabel *label;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;

    void setupUi(QDialog *download)
    {
        if (download->objectName().isEmpty())
            download->setObjectName("download");
        download->resize(961, 649);
        label = new QLabel(download);
        label->setObjectName("label");
        label->setGeometry(QRect(320, 50, 371, 341));
        pushButton = new QPushButton(download);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(250, 500, 101, 24));
        pushButton_2 = new QPushButton(download);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(410, 500, 131, 24));
        pushButton_3 = new QPushButton(download);
        pushButton_3->setObjectName("pushButton_3");
        pushButton_3->setGeometry(QRect(610, 500, 80, 24));

        retranslateUi(download);

        QMetaObject::connectSlotsByName(download);
    } // setupUi

    void retranslateUi(QDialog *download)
    {
        download->setWindowTitle(QCoreApplication::translate("download", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("download", "TextLabel", nullptr));
        pushButton->setText(QCoreApplication::translate("download", "Download Image", nullptr));
        pushButton_2->setText(QCoreApplication::translate("download", "Download transcript", nullptr));
        pushButton_3->setText(QCoreApplication::translate("download", "Exit", nullptr));
    } // retranslateUi

};

namespace Ui {
    class download: public Ui_download {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DOWNLOAD_H
