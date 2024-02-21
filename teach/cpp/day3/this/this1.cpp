#include <iostream>
using namespace std;

class Data
{
	
public:
	void set(int a, int b);
	void getData(int& a, int& b);
	
private:
	int a;
	int b;
};

int main()
{
	Data* pData = new Data;
	pData->set(3, 15);
	int m,n;
	pData->getData(m,n);
	
	cout << "m = " << m << ",n = " << n << endl;
	
	delete pData;
	pData = NULL;
	
	return 0;
}

void Data::set(int a, int b)
{
	this->a = a;
	this->b = b;
}

void Data::getData(int& a, int& b)
{
	a = this->a;
	b = this->b;
}