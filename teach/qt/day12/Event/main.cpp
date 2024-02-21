#include "eventwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    EventWindow w;
    w.show();

    return a.exec();
}
