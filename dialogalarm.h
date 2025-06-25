#ifndef DIALOGALARM_H
#define DIALOGALARM_H

#include <QDialog>
#include <QTime>

namespace Ui {
class DialogAlarm;
}

class DialogAlarm : public QDialog
{
    Q_OBJECT

public:
    explicit DialogAlarm(QWidget *parent = nullptr);
    ~DialogAlarm();
    QTime getAlarmTime () {
        return alarm_time_;
    };

signals:
    void getAlarm();

private slots:
    void on_buttonBox_accepted();

private:
    Ui::DialogAlarm *ui;
    QTime alarm_time_;
};

#endif // DIALOGALARM_H
