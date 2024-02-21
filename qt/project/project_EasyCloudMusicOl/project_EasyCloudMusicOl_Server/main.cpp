#include "musicserver.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    MusicServer w;
    w.show();

    return a.exec();
}
