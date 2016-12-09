#ifndef WINEVENTSCHEDULE_H
#define WINEVENTSCHEDULE_H

#include <QWidget>

namespace Ui {
class winEventSchedule;
}

class winEventSchedule : public QWidget
{
    Q_OBJECT

public:
    explicit winEventSchedule(QWidget *parent = 0);
    ~winEventSchedule();

private slots:
    void on_btnCancel_clicked();
    void on_btnAccept_clicked();
    void eventWinClosed();

private:
    Ui::winEventSchedule *ui;
};

#endif // WINEVENTSCHEDULE_H
