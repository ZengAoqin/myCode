#include "filelist.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    FileList w;
    w.show();

    return a.exec();
}
