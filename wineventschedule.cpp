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
