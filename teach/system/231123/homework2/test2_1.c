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
	for(int i = 0; i < 10; i++)
	{
		kill(atoi(argv[1]), 2);
		printf("发送信号2 \n");
	}
	kill(atoi(argv[1]), 3);
	printf("发送信号3 \n");
	return 0;
}