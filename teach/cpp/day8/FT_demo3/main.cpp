#include <iostream>

using namespace std;

template <typename T>
T Add(T a, T b)
{
    return a + b;
}

template <typename T1, typename T2>
void show(T1 no, T2 msg)
{
    cout << "À÷º¦ÁË" << no << "ºÅ:" << msg << endl;
}

int main()
{
    int no = 9527;        //Ó¢ÐÛ±àºÅ
    string msg = "Ì«Å£ÁË";        //·¢ËÍµÄÄÚÈÝ
    show(no, msg);
    return 0;
}
