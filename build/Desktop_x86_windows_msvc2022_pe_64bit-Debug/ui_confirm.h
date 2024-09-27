/********************************************************************************
** Form generated from reading UI file 'confirm.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONFIRM_H
#define UI_CONFIRM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_confirm
{
public:
    QLabel *confirmImg;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QLabel *label;

    void setupUi(QDialog *confirm)
    {
        if (confirm->objectName().isEmpty())
            confirm->setObjectName("confirm");
        confirm->resize(893, 596);
        confirmImg = new QLabel(confirm);
        confirmImg->setObjectName("confirmImg");
        confirmImg->setGeometry(QRect(230, 100, 521, 301));
        pushButton = new QPushButton(confirm);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(330, 450, 80, 24));
        pushButton_2 = new QPushButton(confirm);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(560, 450, 80, 24));
        label = new QLabel(confirm);
        label->setObjectName("label");
        label->setGeometry(QRect(430, 50, 171, 41));

        retranslateUi(confirm);

        QMetaObject::connectSlotsByName(confirm);
    } // setupUi

    void retranslateUi(QDialog *confirm)
    {
        confirm->setWindowTitle(QCoreApplication::translate("confirm", "Dialog", nullptr));
        confirmImg->setText(QCoreApplication::translate("confirm", "TextLabel", nullptr));
        pushButton->setText(QCoreApplication::translate("confirm", "Use", nullptr));
        pushButton_2->setText(QCoreApplication::translate("confirm", "Retake", nullptr));
        label->setText(QCoreApplication::translate("confirm", "Use this image?", nullptr));
    } // retranslateUi

};

namespace Ui {
    class confirm: public Ui_confirm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONFIRM_H
