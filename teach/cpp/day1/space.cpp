#include <iostream>
using namespace std;

//匿名空间
//限制变量的活动范围
namespace
{
	int number = 100;
};

//int number = 120;

int main()
{
	cout << "匿名空间中的number "<< ::number << endl;
	cout << "匿名空间中的number "<< number << endl;
	//cout << "全局变量的number " << number << endl;
	return 0;
}