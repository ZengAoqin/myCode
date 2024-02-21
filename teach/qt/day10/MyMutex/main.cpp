#include "threadmutex.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ThreadMutex w;
    w.show();

    return a.exec();
}
