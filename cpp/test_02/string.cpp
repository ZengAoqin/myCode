#include <iostream>
#include <string>

using namespace std;

int main()
{
    string s1 = "hello world";
    string s2 = " everybody";
    string s3;

    s3 = s1;
    cout << "s3:" << s3 << endl;

    s3 = s1 + s2;
    cout << "s3:" << s3 << endl;

    cout << "len(s3):" << s3.size() << endl;

    return 0;
}