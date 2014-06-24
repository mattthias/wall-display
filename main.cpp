#include "walldisplay.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QCoreApplication::setOrganizationName("endocode");
    QCoreApplication::setOrganizationDomain("endocode.com");
    QCoreApplication::setApplicationName("wall-display");

    WallDisplay w;
    w.showFullScreen();

    return a.exec();
}
