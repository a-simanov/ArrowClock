#ifndef ARROWCLOCK_H
#define ARROWCLOCK_H

#include "dialogtheme.h"
#include "ui_dialogtheme.h"
#include "dialogusertrime.h"
#include "dialogalarm.h"

#include <QMainWindow>
#include <QPainter>
#include <QTimer>
#include <QFile>
#include <QTime>
#include <QMediaPlayer>
#include <QAudioOutput>
#include <algorithm>

QT_BEGIN_NAMESPACE
namespace Ui {
class ArrowClock;
}
QT_END_NAMESPACE

const double STEP_SECOND_ARROW = 6.0;
const double STEP_HOUR_ARROW = 30.0;


struct Vector2D {
    double x;
    double y;
};

struct Point2D {
    double x;
    double y;
};

inline Vector2D RotateVector(Vector2D src, double angle) {
    double a_rad = angle / 180. * M_PI;
    double sin_v = std::sin(a_rad);
    double cos_v = std::cos(a_rad);
    return Vector2D{
        src.x * cos_v + src.y * sin_v, - src.x * sin_v + src.y * cos_v
    };
}

inline Vector2D Add(Vector2D l, Vector2D r) {
    return Vector2D{l.x + r.x, l.y + r.y};
}

inline Point2D Add(Point2D l, Vector2D r) {
    return Point2D{l.x + r.x, l.y + r.y};
}

class ArrowClock : public QMainWindow
{
    Q_OBJECT

public:
    ArrowClock(QWidget *parent = nullptr);

    ~ArrowClock();

    friend class DialogTheme;

    void startTicTack ();
private:
    QTimer seconds_timer{this};
    QFont font;    
    QColor numbers_color = Qt::black;
    int user_sec = 1;
    int user_min = 1;
    int user_hour = 0;
    QTime now_;
    DialogTheme theme_;
    bool is_user_time_ = false;
    DialogUserTrime user_time_;
    DialogAlarm alarm_;
    QTimer alarm_timer_{this};
    QMediaPlayer player_{this};
    QAudioOutput audio_output_{this};
    QString melody_;
    QColor color_ = QColor(Qt::darkGray);

private:
    Ui::ArrowClock *ui;
    void paintEvent(QPaintEvent *event) override;
    double getSecondsAngle(QTime now = QTime::currentTime());
    double getMinutesAngle(QTime now = QTime::currentTime());
    double getHourAngle(QTime now = QTime::currentTime());
    void setTime ();
    void DrawSecondsArrow(QPainter& painter, Point2D center, double angle, double length);
    void DrawMinutesArrow(QPainter& painter, Point2D center, double angle, double length);
    void DrawHourArrow(QPainter& painter, Point2D center, double angle, double length);
    void drawNumbers (QPainter& painter, double size);
    void drawClockFace (QPainter& painter, double size);
    void setLightTheme ();
    void setDarkTheme ();
    void changeTheme ();
    void changeTime ();
    void dialogAlarm();
    void setAlarm ();
    void timerAlarm();

private slots:
    void showHideChangeTime();
    void slotMenuRequested(QPoint pos);
    void dialogTheme ();
    void on_btn_stop_alarm_clicked();    
};
#endif // ARROWCLOCK_H
