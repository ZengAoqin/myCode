#include <iostream>
using namespace std;

class Sale
{
public:
    void sale(int num)
    {
        Sale::total = Sale::total - num;
    }

    static void display()
    {
        cout << Sale::total << endl;
    }

private:
    static int total;
};

int Sale::total = 10000;

int main()
{
    Sale jack, rose, tom;
    jack.sale(1200);
    rose.sale(3200);
    tom.sale(1500);

    Sale::display();

    return 0;
}