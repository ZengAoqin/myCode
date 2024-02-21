#include "easycloud.h"
#include "cloudlogin.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    CloudLogin cloudLoginWindow;
    cloudLoginWindow.show();

    return a.exec();
}
