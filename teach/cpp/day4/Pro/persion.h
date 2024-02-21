#include <iostream>
using namespace std;

namespace MAN
{
	class Persion
	{
		public:
		//带参数的构造函数
		Persion(int _age); 
		
		//拷贝构造函数
		//Persion(const Persion& other);
		
		//析构函数
		~Persion();
		
		//显示数据
		void display();
		
		private:
		int* age;
	};
	
	void Test(Persion p);
};