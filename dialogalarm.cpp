#include "dialogalarm.h"
#include "ui_dialogalarm.h"

DialogAlarm::DialogAlarm(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::DialogAlarm)
{
    ui->setupUi(this);
}

DialogAlarm::~DialogAlarm()
{
    delete ui;
}

void DialogAlarm::on_buttonBox_accepted()
{
    alarm_time_.setHMS(ui->sb_alarm_hours->value(), ui->sb_alarm_min->value(), ui->sb_alarm_sec->value());
    emit getAlarm();
}

