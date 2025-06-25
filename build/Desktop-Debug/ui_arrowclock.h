/********************************************************************************
** Form generated from reading UI file 'arrowclock.ui'
**
** Created by: Qt User Interface Compiler version 6.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ARROWCLOCK_H
#define UI_ARROWCLOCK_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ArrowClock
{
public:
    QAction *action_change_time;
    QAction *action_dark_theme;
    QAction *action_setAlarm;
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QSpacerItem *verticalSpacer;
    QPushButton *btn_stop_alarm;
    QStatusBar *statusbar;
    QMenuBar *menuBar;
    QMenu *menu;

    void setupUi(QMainWindow *ArrowClock)
    {
        if (ArrowClock->objectName().isEmpty())
            ArrowClock->setObjectName("ArrowClock");
        ArrowClock->resize(800, 600);
        action_change_time = new QAction(ArrowClock);
        action_change_time->setObjectName("action_change_time");
        action_change_time->setCheckable(false);
        action_dark_theme = new QAction(ArrowClock);
        action_dark_theme->setObjectName("action_dark_theme");
        action_dark_theme->setCheckable(false);
        action_setAlarm = new QAction(ArrowClock);
        action_setAlarm->setObjectName("action_setAlarm");
        centralwidget = new QWidget(ArrowClock);
        centralwidget->setObjectName("centralwidget");
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName("gridLayout");
        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 0, 0, 1, 1);

        btn_stop_alarm = new QPushButton(centralwidget);
        btn_stop_alarm->setObjectName("btn_stop_alarm");

        gridLayout->addWidget(btn_stop_alarm, 1, 0, 1, 1);

        ArrowClock->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(ArrowClock);
        statusbar->setObjectName("statusbar");
        ArrowClock->setStatusBar(statusbar);
        menuBar = new QMenuBar(ArrowClock);
        menuBar->setObjectName("menuBar");
        menuBar->setGeometry(QRect(0, 0, 800, 23));
        menu = new QMenu(menuBar);
        menu->setObjectName("menu");
        ArrowClock->setMenuBar(menuBar);

        menuBar->addAction(menu->menuAction());
        menu->addAction(action_change_time);
        menu->addAction(action_dark_theme);
        menu->addAction(action_setAlarm);

        retranslateUi(ArrowClock);

        QMetaObject::connectSlotsByName(ArrowClock);
    } // setupUi

    void retranslateUi(QMainWindow *ArrowClock)
    {
        ArrowClock->setWindowTitle(QCoreApplication::translate("ArrowClock", "ArrowClock", nullptr));
        action_change_time->setText(QCoreApplication::translate("ArrowClock", "\320\243\321\201\321\202\320\260\320\275\320\276\320\262\320\270\321\202\321\214 \320\262\321\200\320\265\320\274\321\217", nullptr));
        action_dark_theme->setText(QCoreApplication::translate("ArrowClock", "\320\222\321\213\320\261\321\200\320\260\321\202\321\214 \321\202\320\265\320\274\321\203", nullptr));
        action_setAlarm->setText(QCoreApplication::translate("ArrowClock", "\320\243\321\201\321\202\320\260\320\275\320\276\320\262\320\270\321\202\321\214 \320\261\321\203\320\264\320\270\320\273\321\214\320\275\320\270\320\272", nullptr));
        btn_stop_alarm->setText(QCoreApplication::translate("ArrowClock", "\320\236\321\201\321\202\320\260\320\275\320\276\320\262\320\270\321\202\321\214 \320\261\321\203\320\264\320\270\320\273\321\214\320\275\320\270\320\272", nullptr));
        menu->setTitle(QCoreApplication::translate("ArrowClock", "\320\234\320\265\320\275\321\216", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ArrowClock: public Ui_ArrowClock {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ARROWCLOCK_H
