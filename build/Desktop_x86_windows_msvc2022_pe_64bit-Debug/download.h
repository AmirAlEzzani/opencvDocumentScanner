#ifndef DOWNLOAD_H
#define DOWNLOAD_H

#include <QDialog>

namespace Ui {
class download;
}

class download : public QDialog
{
    Q_OBJECT

public:
    explicit download(QWidget *parent = nullptr);
    ~download();

private slots:
    void on_pushButton_clicked();

private:
    Ui::download *ui;
};

#endif // DOWNLOAD_H
