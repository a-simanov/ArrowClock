#ifndef DIALOGTHEME_H
#define DIALOGTHEME_H

#include <QDialog>

namespace Ui {
class DialogTheme;
}

class DialogTheme : public QDialog
{
    Q_OBJECT

public:
    explicit DialogTheme(QWidget *parent = nullptr);
    ~DialogTheme();
    friend class ArrowClock;
signals:
    void fW();

private slots:
    void on_buttonBox_accepted();

private:
    Ui::DialogTheme *ui;
};

#endif // DIALOGTHEME_H
