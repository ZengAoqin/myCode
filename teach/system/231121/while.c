#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main(int argc, char* argv[])
{
	pid_t pid = getpid();
	for(;;)
	{
		printf("hello world %d\n", pid);
		sleep(1);
	}
	return 0;
}