#include "ts.h"

//触摸屏的初始化
int ts_init()
{
	int tsfd = open(INPUT_EVENT, O_RDWR);
	if(tsfd == -1)
	{
		fprintf(stderr, "line[%d] open error\n", __LINE__);
	}
	return tsfd;
}

//触摸屏的销毁
void ts_destroy(int fd)
{
	if(close(fd) == -1)
	{
		fprintf(stderr, "line[%d] close error\n", __LINE__);
	}
}

//获取按下的坐标
void get_abs(int* x,int* y, int fd)
{
	*x = 0;
	*y = 0;
	//读取设备文件数据到结构体
	struct input_event in;
	
	for(;;)
	{
		//通过读取函数获取
		read(fd, &in, sizeof(struct input_event));
		//分析事件
		if(in.type == EV_ABS && in.code == ABS_X) //事件绝对位移
		{
			*x = in.value; //获取触摸x坐标
		}
		
		if(in.type == EV_ABS && in.code == ABS_Y) //事件绝对位移
		{
			*y = in.value; //获取触摸y坐标
			if(*x > 0)
			{
				//打印坐标
				printf("坐标(%d,%d)\n", *x, *y);
				break;
			}
		}
	}
}