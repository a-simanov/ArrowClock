#include "dialogtheme.h"
#include "ui_dialogtheme.h"

DialogTheme::DialogTheme(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::DialogTheme)
{
    ui->setupUi(this);
}

DialogTheme::~DialogTheme()
{
    delete ui;
}

void DialogTheme::on_buttonBox_accepted()
{
    emit fW();
}

