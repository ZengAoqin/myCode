#include <iostream>

using namespace std;

template <class T1, class T2>
class Man
{
public:
    Man() {}
    Man(T1 a, T2 b)
    {
        this->a = a;
        this->b = b;
    }

    void show();

    T1 a;
    T2 b;
};

template <class T1, class T2>
void Man<T1, T2>::show()
{
    cout << "a:" << a << endl;
    cout << "b:" << b << endl;
}

int main()
{
    Man<int, string> m1(25, "JACK");
    m1.show();

    Man<int, string>* m2 = new Man<int, string>(18, "ROSE");
    m2->show();
    delete m2;

    return 0;
}
