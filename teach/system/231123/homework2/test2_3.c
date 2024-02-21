#include <sys/types.h>
#include <sys/ipc.h>
#include <stdio.h>
#include <sys/msg.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>

int main(int argc, char** argv)
{
	for(int i = 2; i < 4; i++)
	{
		kill(atoi(argv[1]), i);
		printf("发送信号%d \n", i);
	}
	return 0;
}