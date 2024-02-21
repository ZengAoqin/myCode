#include <iostream>

using namespace std;

class Pet
{
public:
    Pet()
    {
        cout << "Pet 构造" << endl;
    }

    virtual void talk() = 0;

    //虚析构
    // virtual ~Pet()
    // {
    //     cout << "Pet 析构" << endl;
    // }
    
    //纯虚析构
    virtual ~Pet() = 0;
};

Pet::~Pet()
{
    cout << "Pet 纯虚析构" << endl;
}

class Dog: public Pet
{
public:
    Dog(int age)
    {
        cout << "子类Dog 构造" << endl;
        this->age = new int;
        *(this->age) = age;
    }

    void talk()
    {
        cout << "Dog bark, age:" << *age << endl;
    }

    ~Dog()
    {
        cout << "子类Dog 析构" << endl;
        if(age != NULL)
        {
            delete age;
            age == NULL;
        }
    }

private:
    int* age;
};

int main()
{
    // Dog dog(15);
    // Pet& p = dog;
    // p.talk();

    Pet* pp = new Dog(20);
    pp->talk();

    delete pp;
    pp = NULL;

    return 0;
}