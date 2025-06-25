#include "dialogusertrime.h"
#include "ui_dialogusertrime.h"

DialogUserTrime::DialogUserTrime(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::DialogUserTrime)
{
    ui->setupUi(this);
}

DialogUserTrime::~DialogUserTrime()
{
    delete ui;
}

void DialogUserTrime::on_sb_seconds_valueChanged(int arg1)
{
    user_sec = arg1;
}


void DialogUserTrime::on_sb_minutes_valueChanged(int arg1)
{
    user_min = arg1;
}


void DialogUserTrime::on_sb_hours_valueChanged(int arg1)
{
    user_hour = arg1;
}


void DialogUserTrime::on_buttonBox_accepted()
{
    emit uT();
}

