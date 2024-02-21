#include <iostream>

using namespace std;
//定义单例类
class Sigleton
{
public: //公开
	//建立全局访问接口
	static Sigleton* GetInstance()
	{
		if(NULL == instance)
		{
			instance = new Sigleton;
		}
		return instance;
	}
	
	~Sigleton()
	{
		cout << "~Sigleton()" << endl;
	}
	//提供一个回收接口，将指针释放
	static void Free()
	{
		if(NULL != instance)
		{
			delete instance;
			instance = NULL;
		}
	}
	//方法二：
public:
	class Garbo
	{
		public:
		~Garbo()
		{
			if(Sigleton::instance != NULL)
			{
				delete instance;
			}
		}
	}
private: //私有
	Sigleton() //构造函数
	{
		cout << "Sigleton()" << endl;
	}
	Sigleton(const Sigleton& other); //构造函数
	/*{
		cout << "Sigleton(const Sigleton& other)" << endl;
	}
	*/
//对象的声明
	static Sigleton* instance; //对象实例一个指针
	static Garbo garbo; //类中类成员创建
};

//对象定义
Sigleton* Sigleton::instance;
Sigleton::Garbo ::garbo;

int main()
{
	Sigleton* s1 = Sigleton::GetInstance();
	Sigleton* s2 = Sigleton::GetInstance();
	cout << s1 << " " << s2 << endl;
	//Sigleton s3(s1);
	//Sigleton s3(*s1);
	return 0;
}