#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include <QDate>
#include <QDateTime>
#include "thermoeventlistmodel.h"
#include "wineventschedule.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_btnTargetTemp_clicked();
    void on_btnWeather_clicked();
    void tock(void);

private:
    Ui::MainWindow *ui;
    QTimer tick;
    bool showColon;

    thermoEventListModel *model;
    winEventSchedule *eventWindow;

};

#endif // MAINWINDOW_H
