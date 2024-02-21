#include "persion.h"

using namespace MAN;


Persion& getPersion()
{
	static Persion p(20);
	return p;
}

int main(int argc, char* argv[])
{
	cout << "I'm main fun" << endl;
	
	//用Persion实例化p1这个对象
	Persion p1(18);
	p1.display();
	
	cout << "*********************" << endl;
	
	
	Persion p2 = p1;
	p2.display();
	
	/*
	cout << "*********************" << endl;
	Persion p3(p1);
	p3.display();
	*/
	//Test(p1);
	
	//Persion p4 = getPersion();
	return 0;
}