#ifndef Father_H
#define Father_H

#include <iostream>

using namespace std;

namespace Family
{
    class Father
    {
    public:
        Father(int age);
        void show();
        void func();
        int a;

    protected:
        int b;
        
    private:
        int age;
    };
}

#endif