#include <iostream>
using namespace std;

//全局变量
//int age = 100;

//定义命名空间对象Student
namespace Student
{
	int age = 10;
};

using namespace Student;

//定义命名空间对象Teacher
namespace Teacher
{
	int age = 18;
};

namespace Family
{
	int age = 300;
	namespace Father
	{
		int age = 25;
	};
};

int main() //主函数
{
	cout << Student::age << endl; // 10
	cout << age << endl;			// 10
	cout << Teacher::age << endl;	// 18
	cout << Family::age << " " << Family::Father::age <<endl;
	return 0;
}