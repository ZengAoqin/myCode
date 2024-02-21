#include "mainsence.h"
#include <QApplication>

int main(int argc, char* argv[])
{
    QApplication app(argc, argv);
    MainSence w;
    w.show();

    return app.exec();
}
