#ifndef DIALOGUSERTRIME_H
#define DIALOGUSERTRIME_H

#include <QDialog>

namespace Ui {
class DialogUserTrime;
}

class DialogUserTrime : public QDialog
{
    Q_OBJECT

public:
    explicit DialogUserTrime(QWidget *parent = nullptr);
    ~DialogUserTrime();
    friend class ArrowClock;
signals:
    void uT();

private slots:
    void on_sb_seconds_valueChanged(int arg1);

    void on_sb_minutes_valueChanged(int arg1);

    void on_sb_hours_valueChanged(int arg1);

    void on_buttonBox_accepted();

private:
    Ui::DialogUserTrime *ui;
    int user_sec = 1;
    int user_min = 1;
    int user_hour = 0;
};

#endif // DIALOGUSERTRIME_H
