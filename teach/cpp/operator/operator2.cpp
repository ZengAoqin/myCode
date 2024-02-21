#include <iostream>
#include <string.h>

using namespace std;

//定义超人类
class SuperMan
{
	//输入重载
	friend istream& operator>>(istream& in, SuperMan& m)
	{
		cout << "请输入英雄的姓名和编号：" << endl;
		in >> m.m_name >> m.m_num;
		return in;
	}
	//输出重载
	friend ostream& operator<<(ostream& out, SuperMan& m)
	{
		out << "姓名:" << m.m_name << "\t" << "编号:" << m.m_num << endl;
		return out;
	}
public:
	//无参构造
	SuperMan() {}
private:
	string m_name;		//姓名
	int m_num;			//编号
};

/*
这里需要重载输入>>和重载<<
重载方式有两种
1)直接使用友元函数重载
*/

int main()
{
	//实例化一个超人对象m
	SuperMan m;
	//int i;
	cin >> m;
	cout << m;
	return 0;
}