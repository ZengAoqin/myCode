#include <signal.h>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main(int argc, char* argv[])
{
	kill(atoi(argv[1]), 10);
	kill(atoi(argv[1]), 12);
	return 0;
}