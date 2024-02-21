#ifndef DATA_H
#define DATA_H

#include <QMutex>

static int number = 0;
static QMutex mutex;        //互斥锁

#endif // DATA_H
