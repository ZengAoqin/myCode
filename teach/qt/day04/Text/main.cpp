#include "filetext.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    FileText w;
    w.show();

    return a.exec();
}
