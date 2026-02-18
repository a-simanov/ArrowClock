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
    connect(&alarm_, &DialogAlarm::getAlarmTime, this, &ArrowClock::setAlarm);
    connect(&alarm_, &DialogAlarm::getAlarmMelody, this, &ArrowClock::SetMelody);
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
    double size = 0.75 * std::min(width()/2, height()/2);

    bool is_dark = theme_.ui->rb_dark->isChecked();

    if(!is_dark) {
        setLightTheme();
        color_ = QColor(Qt::darkGray);
    } else {
        setDarkTheme();
        color_ = QColor(Qt::lightGray);
    };

    QPen pen_second(color_);
    QPen pen_minute(color_);
    QPen pen_hour(color_);
    pen_minute.setWidth(3);
    pen_second.setWidth(2);
    pen_hour.setWidth(4);

    painter.setPen(pen_second);
    Point2D center {width()/2.0, height()/2.0};
    if(is_user_time_) {
        DrawSecondsArrow (painter, center, getSecondsAngle(now_), size * 0.75);
    } else {
        DrawSecondsArrow (painter, center, getSecondsAngle(), size * 0.75);
    }

    painter.setPen(pen_minute);
    if(is_user_time_) {
        DrawMinutesArrow(painter, center, getMinutesAngle(now_), size * 0.9);
    } else {
        DrawMinutesArrow(painter, center, getMinutesAngle(), size * 0.9);
    }

    painter.setPen(pen_hour);
    if(is_user_time_) {
        DrawHourArrow(painter, center, getHourAngle(now_), size * 0.6);
    } else {
        DrawHourArrow(painter, center, getHourAngle(), size * 0.6);
    }
    drawClockFace(painter, size);
    drawNumbers(painter, size);
};

void ArrowClock::drawClockFace (QPainter& painter, double size) {
    painter.translate(width()/2, height()/2);
    painter.setPen(color_);
    for (int i = 0 ;i < 60; ++i) {
        if (i % 5 == 0) {
            painter.drawLine(0, size, 0, 0.9 * size);
        } else {
            painter.drawLine(0, size, 0, 0.95 * size);
        }
        painter.rotate(6.0);
    }
}

void  ArrowClock::drawNumbers (QPainter& painter, double size) {
    painter.setPen(numbers_color);
    font.setPixelSize(20);
    font.setBold(true);
    painter.setFont(font);
    painter.drawText(QPointF{-10.0, -size * 1.05}, QString("12"));
    painter.drawText(QPointF{size * 1.05 , 6.0}, QString("3"));
    painter.drawText(QPointF{-6.0 , size * 1.1}, QString("6"));
    painter.drawText(QPointF{-size * 1.1 , 6.0}, QString("9"));
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
    ui->lbl_alarm->setStyleSheet("color: black");
    QPalette lightPalette;
    lightPalette.setColor(QPalette::Window, Qt::lightGray);
    lightPalette.setColor(QPalette::WindowText, Qt::black);
    lightPalette.setColor(QPalette::Base, QColorConstants::Svg::darkgray);
    lightPalette.setColor(QPalette::AlternateBase, QColorConstants::Svg::darkgray);
    lightPalette.setColor(QPalette::ToolTipBase, Qt::black);
    lightPalette.setColor(QPalette::ToolTipText, Qt::black);
    lightPalette.setColor(QPalette::Text, Qt::black);
    lightPalette.setColor(QPalette::Button, QColorConstants::Svg::darkgray);
    lightPalette.setColor(QPalette::ButtonText, Qt::black);
    lightPalette.setColor(QPalette::BrightText, Qt::red);
    lightPalette.setColor(QPalette::Link, QColorConstants::Svg::darkgray);
    lightPalette.setColor(QPalette::Highlight, QColorConstants::Svg::darkgray);
    lightPalette.setColor(QPalette::HighlightedText, Qt::white);
    numbers_color = Qt::black;
    qApp->setPalette(lightPalette);
    theme_.setPalette(lightPalette);
    user_time_.setPalette(lightPalette);
    alarm_.setPalette(lightPalette);
}

void ArrowClock::setDarkTheme () {
    ui->lbl_alarm->setStyleSheet("color: white");
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
    theme_.setPalette(darkPalette);
    user_time_.setPalette(darkPalette);
    alarm_.setPalette(darkPalette);
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

void ArrowClock::setAlarm (const QTime& time) {
    QTime alarm_time = time;
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
    ui->lbl_alarm->setText(QString("Будильник установлен на: %1:%2:%3").arg(alarm_time.hour(), 2, 10, QChar('0')).arg(alarm_time.minute(), 2, 10, QChar('0')).arg(alarm_time.second(), 2, 10, QChar('0')));
    ui->lbl_alarm->setAlignment(Qt::AlignCenter);
    if(theme_.ui->rb_light->isChecked()) {
        ui->lbl_alarm->setStyleSheet("color: black");
    } else {
        ui->lbl_alarm->setStyleSheet("color: while");
    }    
}

void ArrowClock::SetMelody (const QString& melody) {
    player_.setSource(melody);
}

void ArrowClock::timerAlarm() {
    player_.play();
    ui->btn_stop_alarm->show();
    ui->lbl_alarm->hide();
}


void ArrowClock::on_btn_stop_alarm_clicked()
{
    player_.stop();
    ui->btn_stop_alarm->hide();
}

