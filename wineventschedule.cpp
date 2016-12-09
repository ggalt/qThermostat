#include "wineventschedule.h"
#include "ui_wineventschedule.h"
#include "thermoeventwin.h"

winEventSchedule::winEventSchedule(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::winEventSchedule)
{
    ui->setupUi(this);
}

winEventSchedule::~winEventSchedule()
{
    delete ui;
}

void winEventSchedule::on_btnCancel_clicked()
{
    close();
}

void winEventSchedule::on_btnAccept_clicked()
{
    thermoEventWin *event = new thermoEventWin(this);
    connect(event, SIGNAL(closing()), this, SLOT(eventWinClosed()));
    event->show();
//    this->hide();
}

void winEventSchedule::eventWinClosed()
{
//    this->show();
}
