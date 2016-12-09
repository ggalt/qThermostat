#include "wineventschedule.h"
#include "ui_wineventschedule.h"

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
    close();
}
