#include "sale.h"
using namespace CLASS_S;

int sale::num = 10000; //产品总数量

//售卖
void sale::saleFun(int n) 
{
	this->num -= n;
}

//获取产品数量
int sale::numFun()
{
	return this->num;
}