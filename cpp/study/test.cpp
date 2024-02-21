#include <iostream>
#include <cstring>

using namespace std;


void func(int* num, char* name)
{
    *num = 10;
    strcpy(name, "akkdl");
}

int main(int argc, char* argv[])
{
    int a;
    char name[20];
    func(&a, name);
    cout << a << endl;
    cout << name << endl;

    return 0;
}