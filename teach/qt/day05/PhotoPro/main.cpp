#include "photo.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Photo w;
    w.show();

    return a.exec();
}
