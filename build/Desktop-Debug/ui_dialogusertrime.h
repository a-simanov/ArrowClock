/********************************************************************************
** Form generated from reading UI file 'dialogusertrime.ui'
**
** Created by: Qt User Interface Compiler version 6.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOGUSERTRIME_H
#define UI_DIALOGUSERTRIME_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_DialogUserTrime
{
public:
    QGridLayout *gridLayout;
    QDialogButtonBox *buttonBox;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QLabel *lbl_s;
    QSpinBox *sb_seconds;
    QVBoxLayout *verticalLayout_2;
    QLabel *lbl_m;
    QSpinBox *sb_minutes;
    QVBoxLayout *verticalLayout_3;
    QLabel *lbl_h;
    QSpinBox *sb_hours;
    QSpacerItem *verticalSpacer;

    void setupUi(QDialog *DialogUserTrime)
    {
        if (DialogUserTrime->objectName().isEmpty())
            DialogUserTrime->setObjectName("DialogUserTrime");
        DialogUserTrime->resize(400, 300);
        gridLayout = new QGridLayout(DialogUserTrime);
        gridLayout->setObjectName("gridLayout");
        buttonBox = new QDialogButtonBox(DialogUserTrime);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        gridLayout->addWidget(buttonBox, 2, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        lbl_s = new QLabel(DialogUserTrime);
        lbl_s->setObjectName("lbl_s");

        verticalLayout->addWidget(lbl_s);

        sb_seconds = new QSpinBox(DialogUserTrime);
        sb_seconds->setObjectName("sb_seconds");
        sb_seconds->setMinimum(1);
        sb_seconds->setMaximum(59);

        verticalLayout->addWidget(sb_seconds);


        horizontalLayout->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName("verticalLayout_2");
        lbl_m = new QLabel(DialogUserTrime);
        lbl_m->setObjectName("lbl_m");

        verticalLayout_2->addWidget(lbl_m);

        sb_minutes = new QSpinBox(DialogUserTrime);
        sb_minutes->setObjectName("sb_minutes");
        sb_minutes->setMinimum(1);
        sb_minutes->setMaximum(59);

        verticalLayout_2->addWidget(sb_minutes);


        horizontalLayout->addLayout(verticalLayout_2);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName("verticalLayout_3");
        lbl_h = new QLabel(DialogUserTrime);
        lbl_h->setObjectName("lbl_h");

        verticalLayout_3->addWidget(lbl_h);

        sb_hours = new QSpinBox(DialogUserTrime);
        sb_hours->setObjectName("sb_hours");
        sb_hours->setMinimum(1);
        sb_hours->setMaximum(12);

        verticalLayout_3->addWidget(sb_hours);


        horizontalLayout->addLayout(verticalLayout_3);


        gridLayout->addLayout(horizontalLayout, 0, 0, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 1, 0, 1, 1);


        retranslateUi(DialogUserTrime);
        QObject::connect(buttonBox, &QDialogButtonBox::accepted, DialogUserTrime, qOverload<>(&QDialog::accept));
        QObject::connect(buttonBox, &QDialogButtonBox::rejected, DialogUserTrime, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(DialogUserTrime);
    } // setupUi

    void retranslateUi(QDialog *DialogUserTrime)
    {
        DialogUserTrime->setWindowTitle(QCoreApplication::translate("DialogUserTrime", "Dialog", nullptr));
        lbl_s->setText(QCoreApplication::translate("DialogUserTrime", "\320\222\320\262\320\265\320\264\320\270\321\202\320\265 \321\201\320\265\320\272\321\203\320\275\320\264\321\213", nullptr));
        lbl_m->setText(QCoreApplication::translate("DialogUserTrime", "\320\222\320\262\320\265\320\264\320\270\321\202\320\265 \320\274\320\270\320\275\321\203\321\202\321\213", nullptr));
        lbl_h->setText(QCoreApplication::translate("DialogUserTrime", "\320\222\320\262\320\265\320\264\320\270\321\202\320\265 \321\207\320\260\321\201\321\213", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DialogUserTrime: public Ui_DialogUserTrime {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGUSERTRIME_H
