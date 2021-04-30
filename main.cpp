#include "walldisplay.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QCoreApplication::setOrganizationName("port4949");
    QCoreApplication::setOrganizationDomain("port4949.net");
    QCoreApplication::setApplicationName("wall-display");

    WallDisplay w;
    w.showFullScreen();

    return a.exec();
}
