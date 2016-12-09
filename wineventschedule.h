#ifndef WINEVENTSCHEDULE_H
#define WINEVENTSCHEDULE_H

#include <QWidget>
#include "thermoeventwin.h"
#include "thermostatevent.h"
#include "thermoeventlistmodel.h"

namespace Ui {
class winEventSchedule;
}

class winEventSchedule : public QWidget
{
    Q_OBJECT

public:
    explicit winEventSchedule(thermoEventListModel *m, QWidget *parent = 0);
    ~winEventSchedule();

private slots:
    void on_btnCancel_clicked();
    void on_btnAccept_clicked();
    void eventWinClosed(thermostatEvent *t);

private:
    Ui::winEventSchedule *ui;
    thermoEventListModel *model;
};

#endif // WINEVENTSCHEDULE_H
