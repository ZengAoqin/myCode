#include "threadtime.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ThreadTime w;
    w.show();

    return a.exec();
}
