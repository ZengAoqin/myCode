#include <iostream>

using namespace std;

class Pet
{
public:
    virtual void talk()
    {
        cout << "Pet talk" << endl;
    }
};

class Dog: public Pet
{
public:
    void talk()
    {
        cout << "Dog bark" << endl;
    }
};

int main()
{
    Dog dog;
    Pet& p = dog;
    p.talk();

    Pet* pp = new Dog;
    pp->talk();

    delete pp;
    pp = NULL;

    return 0;
}