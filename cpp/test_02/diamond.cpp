#include <iostream>

using namespace std;

//虚基类
class Animal
{
public:
    int num;
};

class Sheep: virtual public Animal
{

};

class Camel: virtual public Animal
{

};

class Alpaca: public Sheep, public Camel
{

};

int main()
{
    Alpaca alp;
    alp.num = 50;
    cout << "alp.num:" << alp.num << endl;
    return 0;
}