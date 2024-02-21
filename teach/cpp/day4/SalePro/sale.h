#include <iostream>
using namespace std;

namespace CLASS_S
{
	class sale
	{
	public:
		void saleFun(int n); //售卖
		int numFun(); //获取数量
		
	private:
		static int num; //产品总数量
	};
};