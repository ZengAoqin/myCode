#include <iostream>

using namespace std;
/*
��ϴ��麯��������������࣬ͨ������ָ����㲻ͬͼ�ε����
*/
class Area //������ ����
{
public:
    Area()
    {
        cout << "Area()" << endl;
    }
    virtual ~Area()
    {
        cout << "~Area()" << endl;
    }
    //���麯�� �������
    virtual double sum() = 0;
};

void print(Area* sp)
{
    cout << sp->sum() << endl;
}

//�����
const double PI = 3.1415926535;

class Cricle : public Area
{
public:
    Cricle(int r): r(r)
    {
        cout << "Cricle(int)" << endl;
    }
    ~Cricle()
    {
        cout << "~Cricle()" << endl;
    }
    double sum()
    {
        return PI * r * r;
    }
private:
    int r; //�뾶
};

//������
class Triangle : public Area
{
public:
    Triangle(int low, int high): low(low), high(high)
    {
        cout << "Triangle(int, int)" << endl;
    }
    ~Triangle()
    {
        cout << "~Triangle()" << endl;
    }
    double sum()
    {
        return low * high / 2;
    }
private:
    int low, high;
};

//����
class Square : public Area
{
public:
    Square(int width, int length) : width(width), length(length)
    {
        cout << "Square(int, int)" << endl;
    }
    ~Square()
    {
        cout << "~Square()" << endl;
    }
    double sum()
    {
        return width * length;
    }
private:
    int width, length;
};

//���������
class User
{
public:
    User(Area* sp) //���캯����ʼ��
    {
        this->sp = sp;
    }
    void ContexSum()
    {
        cout << this->sp->sum() << endl;
        delete this->sp;
    }
private:
    Area* sp;
};

int main()
{
    print(new Cricle(10));
    print(new Triangle(15, 10));
    print(new Square(12, 12));

    Area* p = new Square(24, 24);
    cout << p->sum() << endl;

    //�����
    User user(new Cricle(10));
    user.ContexSum();

    User* q = new User(new Triangle(13, 13));
    q->ContexSum();
    return 0;
}
