#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include <QDate>
#include <QDateTime>

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
};

#endif // MAINWINDOW_H
