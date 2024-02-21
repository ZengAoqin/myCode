#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main()
{
    int randomNumber = time(NULL);
	// int randomNumber = 10 + rand() % (99 - 10 + 1);
    printf("%d\n", randomNumber);
}