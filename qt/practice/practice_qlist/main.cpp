#include "listuser.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ListUser w;
    w.show();

    return a.exec();
}
