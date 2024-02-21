#include <stdio.h>
struct Data
{
	struct Data a;
	int b;
};

int main(int argc, char* argv[])
{
	struct Data data1;
	struct Data data2;
	struct Data data3;
	data1.a = data1;
	data1.a = data3;
	return 0;
}