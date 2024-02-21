#include <iostream>
#include <string.h>

using namespace std;

//定义超人类
class SuperMan
{
public:
	//无参构造
	SuperMan() {}
	void output(ostream& out)
	{
		out << "姓名:" << m_name << "\t" << "编号:" << m_num << endl;
	}
	void input(istream& in)
	{
		cout << "请输入英雄的姓名和编号：" << endl;
		in >> m_name >> m_num;
	}
private:
	string m_name;		//姓名
	int m_num;			//编号
};

//输入重载
istream& operator>>(istream& in, SuperMan& m)
{
	m.input(in);
	return in;
}
//输出重载
ostream& operator<<(ostream& out, SuperMan& m)
{
	m.output(out);
	return out;
}

/*
这里需要重载输入>>和重载<<
重载方式有两种
1)直接使用友元函数重载
2)间接调用类的成员函数进行重载
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
