#include <iostream>

using namespace std;

class Data
{
public:
    Data(int a, float b): a(a), b(b)
    {
        cout << "Data(int, int)" << endl;
    }
    ~Data()
    {
        cout << "~Data()" << endl;
    }

    void show()
    {
        cout << "Data::show()" << endl;
    }


    //º¯Êý
    virtual void info();

    virtual void info1() {}
    virtual int info2() {}
    virtual float info3() {}
    virtual double info4() {}
    virtual long info5() {}
private:
    int a;
    float b;
};

void Data::info()
{
    cout << "Data::info()" << endl;
}

int main()
{
    Data data(10, 3.14);
    cout << sizeof(data) << endl;
    //data.info();
    return 0;
}
