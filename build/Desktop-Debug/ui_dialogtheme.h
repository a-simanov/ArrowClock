/********************************************************************************
** Form generated from reading UI file 'dialogtheme.ui'
**
** Created by: Qt User Interface Compiler version 6.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOGTHEME_H
#define UI_DIALOGTHEME_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_DialogTheme
{
public:
    QGridLayout *gridLayout;
    QGroupBox *gb_theme;
    QVBoxLayout *verticalLayout_4;
    QRadioButton *rb_dark;
    QRadioButton *rb_light;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *DialogTheme)
    {
        if (DialogTheme->objectName().isEmpty())
            DialogTheme->setObjectName("DialogTheme");
        DialogTheme->resize(400, 300);
        gridLayout = new QGridLayout(DialogTheme);
        gridLayout->setObjectName("gridLayout");
        gb_theme = new QGroupBox(DialogTheme);
        gb_theme->setObjectName("gb_theme");
        gb_theme->setMinimumSize(QSize(0, 50));
        verticalLayout_4 = new QVBoxLayout(gb_theme);
        verticalLayout_4->setObjectName("verticalLayout_4");
        rb_dark = new QRadioButton(gb_theme);
        rb_dark->setObjectName("rb_dark");

        verticalLayout_4->addWidget(rb_dark);

        rb_light = new QRadioButton(gb_theme);
        rb_light->setObjectName("rb_light");
        rb_light->setChecked(true);

        verticalLayout_4->addWidget(rb_light);


        gridLayout->addWidget(gb_theme, 0, 0, 1, 1);

        buttonBox = new QDialogButtonBox(DialogTheme);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        gridLayout->addWidget(buttonBox, 1, 0, 1, 1);


        retranslateUi(DialogTheme);
        QObject::connect(buttonBox, &QDialogButtonBox::accepted, DialogTheme, qOverload<>(&QDialog::accept));
        QObject::connect(buttonBox, &QDialogButtonBox::rejected, DialogTheme, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(DialogTheme);
    } // setupUi

    void retranslateUi(QDialog *DialogTheme)
    {
        DialogTheme->setWindowTitle(QCoreApplication::translate("DialogTheme", "Dialog", nullptr));
        gb_theme->setTitle(QCoreApplication::translate("DialogTheme", "GroupBox", nullptr));
        rb_dark->setText(QCoreApplication::translate("DialogTheme", "\320\242\320\265\320\274\320\275\321\213\320\271", nullptr));
        rb_light->setText(QCoreApplication::translate("DialogTheme", "\320\241\320\262\320\265\321\202\320\273\321\213\320\271", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DialogTheme: public Ui_DialogTheme {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGTHEME_H
