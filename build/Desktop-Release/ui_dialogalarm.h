/********************************************************************************
** Form generated from reading UI file 'dialogalarm.ui'
**
** Created by: Qt User Interface Compiler version 6.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOGALARM_H
#define UI_DIALOGALARM_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_DialogAlarm
{
public:
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QLabel *lbl_s;
    QSpinBox *sb_alarm_sec;
    QVBoxLayout *verticalLayout_2;
    QLabel *lbl_m;
    QSpinBox *sb_alarm_min;
    QVBoxLayout *verticalLayout_3;
    QLabel *lbl_h;
    QSpinBox *sb_alarm_hours;
    QDialogButtonBox *buttonBox;
    QSpacerItem *verticalSpacer;
    QPushButton *btn_change_melody;

    void setupUi(QDialog *DialogAlarm)
    {
        if (DialogAlarm->objectName().isEmpty())
            DialogAlarm->setObjectName("DialogAlarm");
        DialogAlarm->resize(400, 300);
        gridLayout = new QGridLayout(DialogAlarm);
        gridLayout->setObjectName("gridLayout");
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        lbl_s = new QLabel(DialogAlarm);
        lbl_s->setObjectName("lbl_s");

        verticalLayout->addWidget(lbl_s);

        sb_alarm_sec = new QSpinBox(DialogAlarm);
        sb_alarm_sec->setObjectName("sb_alarm_sec");
        sb_alarm_sec->setMinimum(1);
        sb_alarm_sec->setMaximum(59);

        verticalLayout->addWidget(sb_alarm_sec);


        horizontalLayout->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName("verticalLayout_2");
        lbl_m = new QLabel(DialogAlarm);
        lbl_m->setObjectName("lbl_m");

        verticalLayout_2->addWidget(lbl_m);

        sb_alarm_min = new QSpinBox(DialogAlarm);
        sb_alarm_min->setObjectName("sb_alarm_min");
        sb_alarm_min->setMinimum(1);
        sb_alarm_min->setMaximum(59);

        verticalLayout_2->addWidget(sb_alarm_min);


        horizontalLayout->addLayout(verticalLayout_2);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName("verticalLayout_3");
        lbl_h = new QLabel(DialogAlarm);
        lbl_h->setObjectName("lbl_h");

        verticalLayout_3->addWidget(lbl_h);

        sb_alarm_hours = new QSpinBox(DialogAlarm);
        sb_alarm_hours->setObjectName("sb_alarm_hours");
        sb_alarm_hours->setMinimum(1);
        sb_alarm_hours->setMaximum(12);

        verticalLayout_3->addWidget(sb_alarm_hours);


        horizontalLayout->addLayout(verticalLayout_3);


        gridLayout->addLayout(horizontalLayout, 0, 0, 1, 1);

        buttonBox = new QDialogButtonBox(DialogAlarm);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        gridLayout->addWidget(buttonBox, 3, 0, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 1, 0, 1, 1);

        btn_change_melody = new QPushButton(DialogAlarm);
        btn_change_melody->setObjectName("btn_change_melody");

        gridLayout->addWidget(btn_change_melody, 2, 0, 1, 1);


        retranslateUi(DialogAlarm);
        QObject::connect(buttonBox, &QDialogButtonBox::accepted, DialogAlarm, qOverload<>(&QDialog::accept));
        QObject::connect(buttonBox, &QDialogButtonBox::rejected, DialogAlarm, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(DialogAlarm);
    } // setupUi

    void retranslateUi(QDialog *DialogAlarm)
    {
        DialogAlarm->setWindowTitle(QCoreApplication::translate("DialogAlarm", "Dialog", nullptr));
        lbl_s->setText(QCoreApplication::translate("DialogAlarm", "\320\222\320\262\320\265\320\264\320\270\321\202\320\265 \321\201\320\265\320\272\321\203\320\275\320\264\321\213", nullptr));
        lbl_m->setText(QCoreApplication::translate("DialogAlarm", "\320\222\320\262\320\265\320\264\320\270\321\202\320\265 \320\274\320\270\320\275\321\203\321\202\321\213", nullptr));
        lbl_h->setText(QCoreApplication::translate("DialogAlarm", "\320\222\320\262\320\265\320\264\320\270\321\202\320\265 \321\207\320\260\321\201\321\213", nullptr));
        btn_change_melody->setText(QCoreApplication::translate("DialogAlarm", "\320\222\321\213\320\261\320\265\321\200\320\270\321\202\320\265 \321\201\320\270\320\263\320\275\320\260\320\273 \320\261\321\203\320\264\320\270\320\273\321\214\320\275\320\270\320\272\320\260", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DialogAlarm: public Ui_DialogAlarm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGALARM_H
