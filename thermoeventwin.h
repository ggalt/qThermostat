#ifndef THERMOEVENTWIN_H
#define THERMOEVENTWIN_H

#include <QWidget>

#include "thermostatevent.h"

namespace Ui {
class thermoEventWin;
}

class thermoEventWin : public QWidget
{
    Q_OBJECT

public:
    explicit thermoEventWin(thermostatEvent *t, QWidget *parent = 0);
    ~thermoEventWin();

signals:
    void closing(thermostatEvent *);

private slots:
    void on_btnAccept_clicked();

    void on_btnCancel_clicked();

    void on_btnHeat_clicked();

    void on_btnCool_clicked();

    void on_sliderTargetTemp_sliderMoved(int position);

    void on_sliderTargetTemp_valueChanged(int value);

private:
    void fillMultipleDayEvents(QList<thermostatEvent::DayOfTheWeek> alldays);

private:
    Ui::thermoEventWin *ui;
    thermostatEvent *m_event;
};

#endif // THERMOEVENTWIN_H
