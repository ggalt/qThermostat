#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_btnTargetTemp_clicked()
{
    // display schedule page

}

void MainWindow::on_btnWeather_clicked()
{
    // display upcoming weather page
}
