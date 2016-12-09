#include <QDebug>
#include <QTime>
#include <QString>

#include "thermoeventwin.h"
#include "ui_thermoeventwin.h"

thermoEventWin::thermoEventWin(thermostatEvent *t, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::thermoEventWin)
{
    ui->setupUi(this);
    ui->sliderTargetTemp->setValue(70);
    ui->lblTargetTemp->setText(QString::number(ui->sliderTargetTemp->value()));
    ui->btnHeat->setChecked(true);
    m_event = t;
}

thermoEventWin::~thermoEventWin()
{
    delete ui;
}

void thermoEventWin::on_btnAccept_clicked()
{
    qDebug() << ui->cboxDayOfWeek->currentText() << ui->cboxDayOfWeek->currentIndex()
             << ui->cboxHour->currentText() << ui->cboxHour->currentIndex()
             << ui->cboxMinute->currentText() << ui->cboxMinute->currentIndex();

    thermostatEvent::DayOfTheWeek days[] {
                thermostatEvent::Sunday,thermostatEvent::Monday,thermostatEvent::Tuesday,
                thermostatEvent::Wednesday,thermostatEvent::Thursday,
                thermostatEvent::Friday,thermostatEvent::Saturday};

    switch (ui->cboxDayOfWeek->currentIndex()) {
    case 0:     // All Days
    {
        qDebug() << "All week event, copy for all days";
        QList<thermostatEvent::DayOfTheWeek> allDays;
        for(int c=0; c < 7; c++)
            allDays.append(days[c]);
        m_event->deleteLater();
        fillMultipleDayEvents(allDays);
    }
        break;
    case 1:     // All Weekdays
    {
        qDebug() << "Weekday event, copy for all weekdays";
        QList<thermostatEvent::DayOfTheWeek> weekDays;
        for(int c=0; c < 5; c++)
            weekDays.append(days[c]);
        m_event->deleteLater();
        fillMultipleDayEvents(weekDays);
    }
        break;
    case 2:     // Weekend Days
    {
        qDebug() << "Weekend event, copy for all weekend days";
        QList<thermostatEvent::DayOfTheWeek> weekendDays;
        weekendDays.append(days[5]);
        weekendDays.append(days[6]);
        m_event->deleteLater();
        fillMultipleDayEvents(weekendDays);
    }
        break;

    default:
    {
        m_event->setDayOfTheWeek(days[ui->cboxDayOfWeek->currentIndex()-3]);
        if(ui->btnCool->isChecked())
            m_event->setCoolingState(thermostatEvent::Cool);
        else
            m_event->setCoolingState(thermostatEvent::Heat);
        m_event->setTargetTemp(ui->sliderTargetTemp->value());
        QString startTime = QString::number(ui->cboxHour->currentIndex())+":"+QString::number(ui->cboxMinute->currentIndex()*5);
        qDebug() << startTime;
        m_event->setStartTime(QTime::fromString(startTime, "h:m"));


        emit closing(m_event);
    }
        break;
    }
    close();
}

void thermoEventWin::on_btnCancel_clicked()
{
    m_event->deleteLater();
    close();
}

void thermoEventWin::on_btnHeat_clicked()
{
    ui->btnCool->setChecked(!ui->btnHeat->isChecked());
}

void thermoEventWin::on_btnCool_clicked()
{
    ui->btnHeat->setChecked(!ui->btnCool->isChecked());
}

void thermoEventWin::on_sliderTargetTemp_sliderMoved(int position)
{
    ui->lblTargetTemp->setText(QString::number(position));
}

void thermoEventWin::on_sliderTargetTemp_valueChanged(int value)
{
    ui->lblTargetTemp->setText(QString::number(value));
}

void thermoEventWin::fillMultipleDayEvents(QList<thermostatEvent::DayOfTheWeek> days)
{
    QListIterator<thermostatEvent::DayOfTheWeek> i(days);
    while (i.hasNext()) {
        thermostatEvent *temp = new thermostatEvent();
        temp->setDayOfTheWeek(i.next());
        if(ui->btnCool->isChecked())
            temp->setCoolingState(thermostatEvent::Cool);
        else
            temp->setCoolingState(thermostatEvent::Heat);
        temp->setTargetTemp(ui->sliderTargetTemp->value());
        QString startTime = QString::number(ui->cboxHour->currentIndex())+":"+QString::number(ui->cboxMinute->currentIndex()*5);
        qDebug() << startTime;
        temp->setStartTime(QTime::fromString(startTime, "h:m"));

        emit closing(temp);
    }

}
