#include "jsontest.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    JsonTest w;
    w.show();

    return a.exec();
}
