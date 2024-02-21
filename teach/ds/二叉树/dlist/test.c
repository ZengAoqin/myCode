#include "dlist.h"

int main(int argc, char* argv[])
{
	DList temp1;
	DList temp11;
	temp11.data = 33;
	temp11.prev = NULL;
	temp11.next = NULL;
	DList temp111;
	temp111.data = 333;
	temp111.prev = NULL;
	temp111.next = NULL;
	temp1.data = 3;
	temp1.prev = &temp11;
	temp1.next = &temp111;
	DList temp2;
	temp2.data = 5;
	DList temp22;
	temp22.data = 55;
	temp22.prev = NULL;
	temp22.next = NULL;
	DList temp222;
	temp222.data = 555;
	temp222.prev = NULL;
	temp222.next = NULL;
	temp2.prev = &temp22;
	temp2.next = &temp222;
	printf("data = %d\n", temp1.data);
	printf("prev = %d\n", temp1.prev->data);
	printf("next = %d\n", temp1.next->data);
	
	temp1 = temp2;
	printf("**************************\n");
	printf("data = %d\n", temp1.data);
	printf("prev = %d\n", temp1.prev->data);
	printf("next = %d\n", temp1.next->data);
	return 0;
}