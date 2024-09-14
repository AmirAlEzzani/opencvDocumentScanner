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
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QLabel>

QT_BEGIN_NAMESPACE

class Ui_confirm
{
public:
    QDialogButtonBox *buttonBox;
    QLabel *confirmImg;

    void setupUi(QDialog *confirm)
    {
        if (confirm->objectName().isEmpty())
            confirm->setObjectName("confirm");
        confirm->resize(893, 596);
        buttonBox = new QDialogButtonBox(confirm);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setGeometry(QRect(190, 470, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        confirmImg = new QLabel(confirm);
        confirmImg->setObjectName("confirmImg");
        confirmImg->setGeometry(QRect(230, 100, 521, 301));

        retranslateUi(confirm);
        QObject::connect(buttonBox, &QDialogButtonBox::rejected, confirm, qOverload<>(&QDialog::reject));
        QObject::connect(buttonBox, &QDialogButtonBox::accepted, confirm, qOverload<>(&QDialog::accept));

        QMetaObject::connectSlotsByName(confirm);
    } // setupUi

    void retranslateUi(QDialog *confirm)
    {
        confirm->setWindowTitle(QCoreApplication::translate("confirm", "Dialog", nullptr));
        confirmImg->setText(QCoreApplication::translate("confirm", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class confirm: public Ui_confirm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONFIRM_H
