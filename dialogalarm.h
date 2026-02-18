#ifndef DIALOGALARM_H
#define DIALOGALARM_H

#include <QDialog>
#include <QTime>
#include <QFileDialog>

namespace Ui {
class DialogAlarm;
}

class DialogAlarm : public QDialog
{
    Q_OBJECT

public:
    explicit DialogAlarm(QWidget *parent = nullptr);
    ~DialogAlarm();    

signals:
    void getAlarmTime(const QTime& alarm_time);
    void getAlarmMelody(const QString& melody);

private slots:
    void on_buttonBox_accepted();

    void on_btn_change_melody_clicked();

private:
    Ui::DialogAlarm *ui;
    QTime alarm_time_;
    QString melody_ = "qrc:/sounds/sounds/signal-elektronnogo-budilnika-33304.mp3";
};

#endif // DIALOGALARM_H
