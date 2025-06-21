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
    theme_.hide();
    this->setContextMenuPolicy(Qt::CustomContextMenu);
    connect(this, &QMainWindow::customContextMenuRequested,
            this, &ArrowClock::slotMenuRequested);
    seconds_timer.start(1000);
    connect(&seconds_timer, &QTimer::timeout, this, &ArrowClock::startTicTack);
    connect(&seconds_timer, &QTimer::timeout, this, &ArrowClock::setTime);
    connect(ui->action_change_time, &QAction::triggered, this, &ArrowClock::showHideChangeTime);
    connect(ui->action_dark_theme, &QAction::triggered, this, &ArrowClock::dialogTheme);
    connect(&theme_, &DialogTheme::fW, this, &ArrowClock::changeTheme);
    showHideChangeTime();
    setLightTheme ();
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
    if(ui->cb_set_time->isChecked()) {
        DrawSecondsArrow (painter, center_, getSecondsAngle(now_), LENGTH_SECOND_ARROW);
    } else {
        DrawSecondsArrow (painter, center_, getSecondsAngle(), LENGTH_SECOND_ARROW);
    }
    painter.setPen(pen_minute);
    if(ui->cb_set_time->isChecked()) {
        DrawMinutesArrow(painter, center_, getMinutesAngle(now_), LENGTH_MINUTE_ARROW);
    } else {
        DrawMinutesArrow(painter, center_, getMinutesAngle(), LENGTH_MINUTE_ARROW);
    }
    painter.setPen(pen_hour);
    if(ui->cb_set_time->isChecked()) {
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
    if (ui->action_change_time->isChecked()) {
        ui->sb_seconds->show();
        ui->sb_minutes->show();
        ui->sb_hours->show();
        ui->lbl_h->show();
        ui->lbl_m->show();
        ui->lbl_s->show();
        ui->cb_set_time->show();
    } else {
        ui->sb_seconds->hide();
        ui->sb_minutes->hide();
        ui->sb_hours->hide();
        ui->lbl_h->hide();
        ui->lbl_m->hide();
        ui->lbl_s->hide();
        ui->cb_set_time->hide();
    }
}

void ArrowClock::dialogTheme () {
    if (ui->action_dark_theme->isChecked()) {
        theme_.show();
    } else {
        theme_.hide();
    }
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
        ui->action_dark_theme->setChecked(false);
    } else {
        setLightTheme ();
        ui->action_dark_theme->setChecked(false);
    }
}

void ArrowClock::on_sb_hours_valueChanged(int arg1)
{
    user_hour = arg1;
    now_.setHMS(user_hour, user_min, user_sec);
}


void ArrowClock::on_sb_minutes_valueChanged(int arg1)
{
    user_min = arg1;
    now_.setHMS(user_hour, user_min, user_sec);
}


void ArrowClock::on_sb_seconds_valueChanged(int arg1)
{
    user_sec = arg1;
    now_.setHMS(user_hour, user_min, user_sec);
}


