#include "arrowclock.h"

#include <QApplication>
#include <QStyleFactory>
#include <QFile>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    qApp->setStyle(QStyleFactory::create("Fusion"));
    //QFile styleSheetFile("C:/PRGM/Clock/Gravira.qss");
    //styleSheetFile.open(QFile::ReadOnly);
    //QString styleSheet = QLatin1String(styleSheetFile.readAll());
    //a.setStyleSheet(styleSheet);
    ArrowClock w;
    w.show();
    return a.exec();
}
