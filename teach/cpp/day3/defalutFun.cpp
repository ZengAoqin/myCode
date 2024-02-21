#include <iostream>
using namespace std;

double getCircleArea(double r, double pi)
{
	cout << "获取圆的面积" << endl;
	return pi*r*r;
}

int main()
{
	double dCircleArea = getCircleArea(3.0);
	//double dCircleArea = getCircleArea(3.0, 3.14159);
	cout << "dCircleArea = " << dCircleArea << endl;
	return 0;
}




