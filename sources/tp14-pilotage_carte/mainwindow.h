#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "p8055.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_actionQuitter_triggered();

    void on_pushButton1_clicked();

    void on_pushButton2_clicked();

    void on_pushButton3_clicked();

    void on_pushButton4_clicked();

    void on_pushButton5_clicked();

private:
    Ui::MainWindow *ui;
    P8055 *carte_usb;
};

#endif // MAINWINDOW_H
