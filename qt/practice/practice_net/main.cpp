#include "netwidget.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    NetWidget w;
    w.show();

    return a.exec();
}
