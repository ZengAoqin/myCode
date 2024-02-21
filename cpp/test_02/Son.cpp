#include "Father.h"
#include "Son.h"
#include <string>

using namespace std;

namespace Family
{
    Son::Son(int age): Father(age)
    {
        
    }

    void Son::setB(int b)
    {
        this->b = b;
    }

    void Son::setC(int c)
    {
        this->c = c;
    }

    void Son::showB()
    {
        cout << "b:" << b << endl;
    }

    void Son::func()
    {
        cout << "Son func" << endl;
    }

    void showC(Son& s)
    {
        cout << "s.c:" << s.c << endl; 
    }
}