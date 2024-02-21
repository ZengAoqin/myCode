#include <iostream>
using namespace std;

//定义一个类
class Data
{
public:
	//自定义无参构造函数
	Data();
	
	//参数列表赋值方式
	Data(int id, int age);
	
	Data(int id, int age, char);
	
	//自定义析构函数
	~Data();
	
private:
	int id, age;
};