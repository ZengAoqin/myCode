#include "recvfile.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    RecvFile w;
    w.show();

    return a.exec();
}
