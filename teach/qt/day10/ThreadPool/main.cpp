#include "treadpoolwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    TreadPoolWindow w;
    w.show();

    return a.exec();
}
