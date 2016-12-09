#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "wineventschedule.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    tick.setInterval(500);
    connect(&tick, SIGNAL(timeout()),
            this, SLOT(tock()));
    tick.start();
    showColon = true;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_btnTargetTemp_clicked()
{
    // display schedule page
    winEventSchedule *sch = new winEventSchedule(this);
    sch->show();
}

void MainWindow::on_btnWeather_clicked()
{
    // display upcoming weather page
}

void MainWindow::tock(void)
{
    QDateTime now = QDateTime::currentDateTime();
    ui->lblDate->setText(now.toString("MMM dd yyyy"));
    if(showColon)
        ui->lblTime->setText(now.toString("h:mm A"));
    else
        ui->lblTime->setText(now.toString("h mm A"));
    showColon = !showColon;

}
