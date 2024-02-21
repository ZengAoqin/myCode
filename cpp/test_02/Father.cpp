#include <iostream>
#include "Father.h"

using namespace std;

namespace Family
{
    Father::Father(int age)
    {
        this->age = age;
    }

    void Father::show()
    {
        cout << "age:" << age << endl;
    }

    void Father::func()
    {
        cout << "father func" << endl;
    }
}
