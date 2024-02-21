#include "filewidget.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    FileWidget w;
    w.show();

    return a.exec();
}
