#include "sale.h"
using namespace CLASS_S;

int main()
{
	//实例化jack rose tom三个对象
	sale jack, rose, tom;
	jack.saleFun(1200);
	rose.saleFun(3200);
	tom.saleFun(1500);
	//获取结余的产品数量
	cout << jack.numFun() << endl;
}