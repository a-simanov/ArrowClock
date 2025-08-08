#include "arrowclock.h"

#include <QApplication>
#include <QStyleFactory>
#include <QFile>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ArrowClock w;
    w.show();
    return a.exec();
}
