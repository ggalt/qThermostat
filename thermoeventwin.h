#ifndef THERMOEVENTWIN_H
#define THERMOEVENTWIN_H

#include <QWidget>

namespace Ui {
class thermoEventWin;
}

class thermoEventWin : public QWidget
{
    Q_OBJECT

public:
    explicit thermoEventWin(QWidget *parent = 0);
    ~thermoEventWin();

signals:
    void closing();

private slots:
    void on_btnAccept_clicked();

    void on_btnCancel_clicked();

    void on_btnHeat_clicked();

    void on_btnCool_clicked();

    void on_sliderTargetTemp_sliderMoved(int position);

    void on_sliderTargetTemp_valueChanged(int value);

private:
    Ui::thermoEventWin *ui;
};

#endif // THERMOEVENTWIN_H
