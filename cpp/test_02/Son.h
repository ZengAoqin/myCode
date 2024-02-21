#ifndef Son_H
#define Son_H
#include <string>
#include "Father.h"

using namespace std;

namespace Family
{
    class Son: public Father
    {
    public:
        Son(int age);
        void setB(int b);
        void setC(int c);
        void showB();
        void func();
        friend void showC(Son& s);
    
    private:
        int c;
    };

    void showC(Son& s);
}

#endif