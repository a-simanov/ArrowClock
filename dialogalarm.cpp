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


void DialogAlarm::on_btn_change_melody_clicked()
{
    melody_ = QFileDialog::getOpenFileName(this, QString("Выберите мелодию"), QDir::currentPath(), "*");
    ui->btn_change_melody->setText(melody_);
}

