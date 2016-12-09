#include <QByteArray>
#include "thermoeventwin.h"
#include "ui_thermoeventwin.h"

thermoEventWin::thermoEventWin(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::thermoEventWin)
{
    ui->setupUi(this);
    ui->sliderTargetTemp->setValue(70);
    ui->lblTargetTemp->setText(QString::number(ui->sliderTargetTemp->value()));
    ui->btnHeat->setChecked(true);
}

thermoEventWin::~thermoEventWin()
{
    delete ui;
}

void thermoEventWin::on_btnAccept_clicked()
{
    close();
    emit closing();
}

void thermoEventWin::on_btnCancel_clicked()
{
    close();
    emit closing();
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
