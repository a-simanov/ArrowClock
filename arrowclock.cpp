#include "arrowclock.h"
#include "ui_arrowclock.h"

#include <QPaintEvent>
#include <QTimerEvent>
#include <QTime>
#include <QStyleFactory>
#include <QDebug>

ArrowClock::ArrowClock(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::ArrowClock)
{    
    ui->setupUi(this);
    ui->menuBar->hide();
    ui->btn_stop_alarm->hide();
    ui->lbl_alarm->hide();
    this->setContextMenuPolicy(Qt::CustomContextMenu);
    connect(this, &QMainWindow::customContextMenuRequested,
            this, &ArrowClock::slotMenuRequested);
    seconds_timer.start(1000);
    connect(&seconds_timer, &QTimer::timeout, this, &ArrowClock::startTicTack);
    connect(&seconds_timer, &QTimer::timeout, this, &ArrowClock::setTime);
    connect(&alarm_timer_, &QTimer::timeout, this, &ArrowClock::timerAlarm);
    connect(ui->action_change_time, &QAction::triggered, this, &ArrowClock::showHideChangeTime);
    connect(ui->action_dark_theme, &QAction::triggered, this, &ArrowClock::dialogTheme);
    connect(ui->action_setAlarm, &QAction::triggered, this, &ArrowClock::dialogAlarm);
    connect(&theme_, &DialogTheme::fW, this, &ArrowClock::changeTheme);
    connect(&user_time_, &DialogUserTrime::uT, this, &ArrowClock::changeTime);
    connect(&alarm_, &DialogAlarm::getAlarm, this, &ArrowClock::setAlarm);
    theme_.hide();
    user_time_.hide();
    setLightTheme ();
    player_.setAudioOutput(&audio_output_);
    audio_output_.setVolume(1.f);
}

ArrowClock::~ArrowClock()
{
    delete ui;
}

void ArrowClock::paintEvent (QPaintEvent *event) {
    QPainter painter(this);
    QPen pen_second(QColorConstants::Svg::lightpink);
    QPen pen_minute(QColorConstants::Svg::lightskyblue);
    QPen pen_hour(QColorConstants::Svg::lightgreen);
    if(theme_.ui->rb_light->isChecked()) {
        setLightTheme();
        pen_second = QColorConstants::Svg::darkorange;
        pen_minute = QColorConstants::Svg::darkblue;
        pen_hour = QColorConstants::Svg::darkgreen;

    } else if (theme_.ui->rb_dark->isChecked()){
        setDarkTheme();
        pen_second = QColorConstants::Svg::lightpink;
        pen_minute = QColorConstants::Svg::lightskyblue;
        pen_hour = QColorConstants::Svg::lightgreen;

    };
    pen_minute.setWidth(3);
    pen_second.setWidth(2);
    pen_hour.setWidth(4);
    painter.setPen(pen_second);
    Point2D center_ {width()/2.0, height()/2.0};
    double center_x = width()/2;
    double center_y = height()/2;
    if(is_user_time_) {
        DrawSecondsArrow (painter, center_, getSecondsAngle(now_), LENGTH_SECOND_ARROW);
    } else {
        DrawSecondsArrow (painter, center_, getSecondsAngle(), LENGTH_SECOND_ARROW);
    }
    painter.setPen(pen_minute);
    if(is_user_time_) {
        DrawMinutesArrow(painter, center_, getMinutesAngle(now_), LENGTH_MINUTE_ARROW);
    } else {
        DrawMinutesArrow(painter, center_, getMinutesAngle(), LENGTH_MINUTE_ARROW);
    }
    painter.setPen(pen_hour);
    if(is_user_time_) {
        DrawHourArrow(painter, center_, getHourAngle(now_), LENGTH_HOUR_ARROW);
    } else {
        DrawHourArrow(painter, center_, getHourAngle(), LENGTH_HOUR_ARROW);
    }
    drawClockFace (painter, center_);
    drawNumbers(painter, center_x, center_y);
};

void ArrowClock::drawClockFace (QPainter& painter, Point2D center) {
    for (int i = 1; i <= 12; i++) {
        if (theme_.ui->rb_light->isChecked()) {
            painter.setPen(Qt::black);
            DrawDial(painter, center, (90.0 + 30.0 * i), 150.0);
            painter.setPen(Qt::lightGray);
            DrawDial(painter, center, (90.0 + 30.0 * i), 130.0);
        } else {
            painter.setPen(Qt::lightGray);
            DrawDial(painter, center, (90.0 + 30.0 * i), 150.0);
            painter.setPen(QColor(53, 53, 53));
            DrawDial(painter, center, (90.0 + 30.0 * i), 130.0);
        }
    }
}

void  ArrowClock::drawNumbers (QPainter& painter, double x , double y) {
    painter.setPen(numbers_color);
    font.setPixelSize(20);
    font.setBold(true);
    painter.setFont(font);
    painter.drawText(QPointF{x - 10.0 , y - 160}, QString("12"));
    painter.drawText(QPointF{x + 160 , y + 6.0}, QString("3"));
    painter.drawText(QPointF{x - 5.0 , y + 170.0}, QString("6"));
    painter.drawText(QPointF{x - 170 , y + 6.0}, QString("9"));
}

double ArrowClock::getSecondsAngle (QTime now) {
    double seconds = now.second();
    return (-STEP_SECOND_ARROW * seconds) + 90;
}

double ArrowClock::getMinutesAngle (QTime now) {
    double minutes = now.minute();
    return (-STEP_SECOND_ARROW * minutes) + 90;
}

double ArrowClock::getHourAngle (QTime now) {
    double hours = now.hour();
    return (-STEP_HOUR_ARROW * hours) + 90;
}

void ArrowClock::setTime () {
    now_ = now_.addSecs(1);
}

void ArrowClock::DrawSecondsArrow(QPainter& painter, Point2D center, double angle, double length) {
    Vector2D lay = RotateVector(Vector2D{length, 0}, angle);
    Point2D end = Add(center, lay);
    painter.drawLine(QPointF(center.x, center.y), QPointF(end.x, end.y));
}

void ArrowClock::DrawMinutesArrow(QPainter& painter, Point2D center, double angle, double length) {
    Vector2D lay = RotateVector(Vector2D{length, 0}, angle);
    Point2D end = Add(center, lay);
    painter.drawLine(QPointF(center.x, center.y), QPointF(end.x, end.y));
}

void ArrowClock::DrawHourArrow(QPainter& painter, Point2D center, double angle, double length) {
    Vector2D lay = RotateVector(Vector2D{length, 0}, angle);
    Point2D end = Add(center, lay);
    painter.drawLine(QPointF(center.x, center.y), QPointF(end.x, end.y));
}

void ArrowClock::DrawDial(QPainter& painter, Point2D center, double angle, double length) {
    Vector2D lay = RotateVector(Vector2D{length, 0}, angle);
    Point2D end = Add(center, lay);
    painter.drawLine(QPointF(center.x, center.y), QPointF(end.x, end.y));
}

void ArrowClock::showHideChangeTime() {
    user_time_.show();
}

void ArrowClock::dialogTheme () {
    theme_.show();
}

void ArrowClock::slotMenuRequested(QPoint pos) {
    ui->menu->popup(this->mapToGlobal(pos));
}

void ArrowClock::startTicTack (){
    repaint();
}

void ArrowClock::setLightTheme () {
    QPalette lightPalette;
    lightPalette.setColor(QPalette::Window, Qt::lightGray);
    lightPalette.setColor(QPalette::WindowText, Qt::black);
    lightPalette.setColor(QPalette::Base, QColorConstants::Svg::lightcoral);
    lightPalette.setColor(QPalette::AlternateBase, QColorConstants::Svg::lightskyblue);
    lightPalette.setColor(QPalette::ToolTipBase, Qt::black);
    lightPalette.setColor(QPalette::ToolTipText, Qt::black);
    lightPalette.setColor(QPalette::Text, Qt::black);
    lightPalette.setColor(QPalette::Button, QColorConstants::Svg::lightcoral);
    lightPalette.setColor(QPalette::ButtonText, Qt::black);
    lightPalette.setColor(QPalette::BrightText, Qt::red);
    lightPalette.setColor(QPalette::Link, QColorConstants::Svg::lightcoral);
    lightPalette.setColor(QPalette::Highlight, QColorConstants::Svg::lightcoral);
    lightPalette.setColor(QPalette::HighlightedText, Qt::white);
    numbers_color = Qt::black;
    qApp->setPalette(lightPalette);
}

void ArrowClock::setDarkTheme () {
    QPalette darkPalette;
    darkPalette.setColor(QPalette::Window, QColor(53, 53, 53));
    darkPalette.setColor(QPalette::WindowText, Qt::white);
    darkPalette.setColor(QPalette::Base, QColor(25, 25, 25));
    darkPalette.setColor(QPalette::AlternateBase, QColor(53, 53, 53));
    darkPalette.setColor(QPalette::ToolTipBase, Qt::white);
    darkPalette.setColor(QPalette::ToolTipText, Qt::white);
    darkPalette.setColor(QPalette::Text, Qt::white);
    darkPalette.setColor(QPalette::Button, QColor(53, 53, 53));
    darkPalette.setColor(QPalette::ButtonText, Qt::white);
    darkPalette.setColor(QPalette::BrightText, Qt::red);
    darkPalette.setColor(QPalette::Link, QColor(42, 130, 218));
    darkPalette.setColor(QPalette::Highlight, QColor(42, 130, 218));
    darkPalette.setColor(QPalette::HighlightedText, Qt::black);
    numbers_color = Qt::lightGray;
    qApp->setPalette(darkPalette);
}

void ArrowClock::changeTheme () {
    if (theme_.ui->rb_dark->isChecked()) {
        setDarkTheme();
    } else {
        setLightTheme ();
    }
}

void ArrowClock::changeTime () {
    now_.setHMS(user_time_.user_hour, user_time_.user_min, user_time_.user_sec);
    is_user_time_ = true;
}

void ArrowClock::dialogAlarm() {
    alarm_.show();
}

void ArrowClock::setAlarm () {
    QTime alarm_time = alarm_.getAlarmTime();
    QTime now;
    if (QTime::currentTime().hour() > 12) {
        now = QTime::currentTime().addSecs(-60 * 60 * 12);
    } else {
        now = QTime::currentTime();
    }
    auto elapsed = now.secsTo(alarm_time);
    alarm_timer_.start(elapsed * 1000);
    alarm_timer_.setSingleShot(true);

    ui->lbl_alarm->show();
    ui->lbl_alarm->setText(QString("%1:%2:%3").arg(alarm_time.hour()).arg(alarm_time.minute()).arg(alarm_time.second()));
}

void ArrowClock::timerAlarm() {
    player_.setSource(alarm_.getMelody());
    player_.play();
    ui->btn_stop_alarm->show();
}


void ArrowClock::on_btn_stop_alarm_clicked()
{
    player_.stop();
    ui->btn_stop_alarm->hide();
}

