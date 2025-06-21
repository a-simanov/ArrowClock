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
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ArrowClock
{
public:
    QAction *action_change_time;
    QAction *action_dark_theme;
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout;
    QCheckBox *cb_set_time;
    QVBoxLayout *verticalLayout;
    QLabel *lbl_h;
    QSpinBox *sb_hours;
    QVBoxLayout *verticalLayout_2;
    QLabel *lbl_m;
    QSpinBox *sb_minutes;
    QVBoxLayout *verticalLayout_3;
    QLabel *lbl_s;
    QSpinBox *sb_seconds;
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
        action_change_time->setCheckable(true);
        action_dark_theme = new QAction(ArrowClock);
        action_dark_theme->setObjectName("action_dark_theme");
        action_dark_theme->setCheckable(true);
        centralwidget = new QWidget(ArrowClock);
        centralwidget->setObjectName("centralwidget");
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName("gridLayout");
        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(verticalSpacer, 0, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        cb_set_time = new QCheckBox(centralwidget);
        cb_set_time->setObjectName("cb_set_time");

        horizontalLayout->addWidget(cb_set_time);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        lbl_h = new QLabel(centralwidget);
        lbl_h->setObjectName("lbl_h");

        verticalLayout->addWidget(lbl_h);

        sb_hours = new QSpinBox(centralwidget);
        sb_hours->setObjectName("sb_hours");
        sb_hours->setMinimum(1);
        sb_hours->setMaximum(12);

        verticalLayout->addWidget(sb_hours);


        horizontalLayout->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName("verticalLayout_2");
        lbl_m = new QLabel(centralwidget);
        lbl_m->setObjectName("lbl_m");

        verticalLayout_2->addWidget(lbl_m);

        sb_minutes = new QSpinBox(centralwidget);
        sb_minutes->setObjectName("sb_minutes");
        sb_minutes->setMinimum(1);
        sb_minutes->setMaximum(59);

        verticalLayout_2->addWidget(sb_minutes);


        horizontalLayout->addLayout(verticalLayout_2);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName("verticalLayout_3");
        lbl_s = new QLabel(centralwidget);
        lbl_s->setObjectName("lbl_s");

        verticalLayout_3->addWidget(lbl_s);

        sb_seconds = new QSpinBox(centralwidget);
        sb_seconds->setObjectName("sb_seconds");
        sb_seconds->setMinimum(1);
        sb_seconds->setMaximum(59);

        verticalLayout_3->addWidget(sb_seconds);


        horizontalLayout->addLayout(verticalLayout_3);


        gridLayout->addLayout(horizontalLayout, 3, 0, 1, 1);

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

        retranslateUi(ArrowClock);

        QMetaObject::connectSlotsByName(ArrowClock);
    } // setupUi

    void retranslateUi(QMainWindow *ArrowClock)
    {
        ArrowClock->setWindowTitle(QCoreApplication::translate("ArrowClock", "ArrowClock", nullptr));
        action_change_time->setText(QCoreApplication::translate("ArrowClock", "\320\243\321\201\321\202\320\260\320\275\320\276\320\262\320\270\321\202\321\214 \320\262\321\200\320\265\320\274\321\217", nullptr));
        action_dark_theme->setText(QCoreApplication::translate("ArrowClock", "\320\222\321\213\320\261\321\200\320\260\321\202\321\214 \321\202\320\265\320\274\321\203", nullptr));
        cb_set_time->setText(QCoreApplication::translate("ArrowClock", "\320\243\321\201\321\202\320\260\320\275\320\276\320\262\320\270\321\202\321\214 \320\262\321\200\320\265\320\274\321\217", nullptr));
        lbl_h->setText(QCoreApplication::translate("ArrowClock", "\320\222\320\262\320\265\320\264\320\270\321\202\320\265 \321\207\320\260\321\201\321\213", nullptr));
        lbl_m->setText(QCoreApplication::translate("ArrowClock", "\320\222\320\262\320\265\320\264\320\270\321\202\320\265 \320\274\320\270\320\275\321\203\321\202\321\213", nullptr));
        lbl_s->setText(QCoreApplication::translate("ArrowClock", "\320\222\320\262\320\265\320\264\320\270\321\202\320\265 \321\201\320\265\320\272\321\203\320\275\320\264\321\213", nullptr));
        menu->setTitle(QCoreApplication::translate("ArrowClock", "\320\234\320\265\320\275\321\216", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ArrowClock: public Ui_ArrowClock {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ARROWCLOCK_H
