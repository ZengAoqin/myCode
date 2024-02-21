#include <iostream>
#include "Father.h"
#include "Son.h"

using namespace std;
using namespace Family;

int main() 
{
    // Father f(50);
    // f.show();

    Son s(15);

    // s.a = 20;
    // cout << "s.a:" << s.a << endl;
    
    // s.setB(66);
    // s.showB();

    // f.func();
    // s.func();
    // s.Father::func();

    s.setC(77);
    showC(s);

    return 0;
}
