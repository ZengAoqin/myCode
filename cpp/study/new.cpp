#include <iostream>

using namespace std;


int main(int argc, char* argv[])
{
    int* num = new int(10);
    cout << "num=" << num << endl;
    cout << "*num=" << *num << endl;

    char* c = new char('a');
    cout << "c=" << c << endl;
    cout << "*c=" << *c << endl;

    int* array = new int[3];
    array[0] = 10;
    cout << "array=" << array << endl;
    cout << "*array=" << *array << endl;

    char* charArray = new char[3];
    charArray[1] = 'a';
    cout << "array=" << charArray[1] << endl;

    delete num;
    delete c;
    delete[] array, charArray;
}