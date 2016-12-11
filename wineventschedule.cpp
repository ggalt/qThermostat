#include <QDebug>
#include <QStyledItemDelegate>
#include <QVariant>

#include "wineventschedule.h"
#include "ui_wineventschedule.h"
#include "thermostatevent.h"

winEventSchedule::winEventSchedule(thermoEventListModel *m, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::winEventSchedule)
{
    model = m;
    ui->setupUi(this);
    ui->lstViewSunday->setModel(model);
    ui->lstViewSunday->setItemDelegate(new QStyledItemDelegate);
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
    thermoEventWin *event = new thermoEventWin(new thermostatEvent(this), this);
    connect(event, SIGNAL(closing(thermostatEvent *)), this, SLOT(eventWinClosed(thermostatEvent *)));
    event->show();
//    this->hide();
}

void winEventSchedule::eventWinClosed(thermostatEvent *temp)
{
    QVariant q = QVariant::fromValue(temp->startTime());

    qDebug() << "Insert" << temp->dayOfTheWeek() << temp->startTime() << temp->targetTemp() << temp->coolingState();
    qDebug() << "Time type is:" << q.typeName() << "DayOfTheWeek type is:" << QVariant::fromValue(temp->dayOfTheWeek()).typeName()
             << "Cooling is:" << QVariant::fromValue(temp->coolingState()).typeName() << "Fanstate:" << QVariant::fromValue(temp->fanState()).typeName()
             << "Switchstate:" << QVariant::fromValue(temp->switchState()).typeName();
    model->addEvent(temp);
//    this->show();
}
