#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    carte_usb = new P8055(0);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionQuitter_triggered()
{
    this->close();
}

void MainWindow::on_pushButton1_clicked()
{

}

void MainWindow::on_pushButton2_clicked()
{

}

void MainWindow::on_pushButton3_clicked()
{

}

void MainWindow::on_pushButton4_clicked()
{

}

void MainWindow::on_pushButton5_clicked()
{

}
