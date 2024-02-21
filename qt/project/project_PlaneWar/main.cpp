#include <QApplication>
#include "mainscene.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    //实例化主场景对象
    MainScene w;
    w.show();

    return a.exec();
}
