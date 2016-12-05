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

private:
    Ui::winEventSchedule *ui;
};

#endif // WINEVENTSCHEDULE_H
