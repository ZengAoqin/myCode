//包含蛇的头文件
#include "snake.h"
#include "time.h"
#include <stdbool.h>
#include <pthread.h>

#define BLACK 0x00000000
#define WHITE 0xFFFFFFFF
#define RED   0x00FF0000

#define MOVE_UP		1		//向上移动
#define MOVE_DOWN	2		//向下移动
#define MOVE_LEFT	3		//向左移动
#define MOVE_RIGHT	4		//向右移动


//食物
POINT food;
//蛇的移动方向
static int move_dirction = MOVE_RIGHT;
//游戏标识 true:游戏开始， false:游戏结束
bool game_flag = true;

//初始化贪吃蛇游戏界面
void game_init(LCD lcd_device, SNAKE s);

//创建食物
void create_food(LCD lcd_device, SNAKE s);

//在LCD模拟器上显示贪吃蛇
void show_snake(LCD lcd_device, SNAKE s);

//获取触摸屏坐标并更改蛇的移动方向
void* getmove(void* arg)
{
	int* ptsfd = (int*)arg;
	
	int x,y;
	int want_move = 0;
	while(game_flag)
	{
		get_abs(&x, &y, *ptsfd);
		
		if(!game_flag)
			break;
		
		//4个方向键
		if(x > 600 && x < 660 && y > 40 && y < 140)
			want_move = MOVE_UP;
		else if(x > 480 && x < 590 && y >150 && y < 210)
			want_move = MOVE_LEFT;
		else if(x > 680 && x < 790 && y > 150 && y < 210)
			want_move = MOVE_RIGHT;
		else if(x > 600 && x < 660 && y > 220 && y < 320)
			want_move = MOVE_DOWN;
		
		//判断是否需要改变方向
		switch(want_move)
		{
			case MOVE_UP: //当方向键向上，但蛇本身是向下走，那么此时方向键无效
			{
				if(move_dirction == MOVE_DOWN)
					break;
				
				move_dirction = MOVE_UP;
				break;
			}
			case MOVE_DOWN: //当方向键向下，但蛇本身是向上走，那么此时方向键无效
			{
				if(move_dirction == MOVE_UP)
					break;
				
				move_dirction = MOVE_DOWN;
				break;
			}
			case MOVE_LEFT: //当方向键向左，但蛇本身是向右走，那么此时方向键无效
			{
				if(move_dirction == MOVE_RIGHT)
					break;
				
				move_dirction = MOVE_LEFT;
				break;
			}
			case MOVE_RIGHT: //当方向键向右，但蛇本身是向左走，那么此时方向键无效
			{
				if(move_dirction == MOVE_LEFT)
					break;
				
				move_dirction = MOVE_RIGHT;
				break;
			}
			default:
			break;
		}
		
		printf("get move 方向 = %d\n", move_dirction);
	}
}

//检查蛇头和蛇身是否重合
bool check_snake_self(SNAKE s)
{
	POINT p = s->first;
	int i;
	for(i = 1; i < s->lenth-1; i++)
	{
		if(p->x == s->last->x && p->y == s->last->y)
			return true;
		
		p = p->next;
	}
	return false;
}

//蛇的移动
void snake_move(LCD lcd_device, SNAKE s)
{
	POINT n = NULL;
	printf("蛇移动\n");
	for(;;)
	{
		sleep(1); //每秒移动一次
		
		switch(move_dirction)
		{
			case MOVE_UP:
			{
				n = queue_create_node(s->last->x, s->last->y-1);
				queue_in(s, n);
				break;
			}
			case MOVE_DOWN:
			{
				n = queue_create_node(s->last->x, s->last->y+1);
				queue_in(s, n);
				break;
			}
			case MOVE_LEFT:
			{
				n = queue_create_node(s->last->x-1, s->last->y);
				queue_in(s, n);
				break;
			}
			case MOVE_RIGHT:
			{
				n = queue_create_node(s->last->x+1, s->last->y);
				queue_in(s, n);
				break;
			}
		}
		
		//判断食物和蛇头是否重合
		if(s->last->x == food->x && s->last->y == food->y)
		{
			create_food(lcd_device, s);
		}
		else
		{
			//LCD上去掉蛇尾
			show_square(lcd_device, 15+45*s->first->x, 15+45*s->first->y, 45, WHITE);
				
			//在数据上去掉蛇尾
			queue_out(s);
		}
			
		//判断是否蛇头撞到边界
		if(s->last->x == -1 || s->last->x == 10)
			break;
			
		if(s->last->y == -1 || s->last->y == 10)
			break;
			
		//判断蛇是否咬到自己
		if(check_snake_self(s))
			break;
			
		show_snake(lcd_device, s);
	}
	printf("游戏标识:%d\n", game_flag);
	game_flag = false;
}

int main(int argc, char* argv[])
{
	//初始化LCD设备
	LCD lcd_device = lcd_init();
	//初始化捕获触摸事件
	int tsfd = ts_init();
	//创建蛇
	SNAKE s = queue_init();
	
	//初始化贪吃蛇游戏界面
	game_init(lcd_device, s);
	
	//线程处理触摸事件
	pthread_t thread;
	pthread_create(&thread, NULL, getmove, &tsfd);
	//蛇移动
	snake_move(lcd_device, s);
	//蛇销毁资源
	queue_destroy(s);
	//食物的资源销毁
	free(food);
	food = NULL;
	//销毁触摸事件
	ts_destroy(tsfd);
	//销毁LCD设备
	lcd_destroy(lcd_device);
	
	return 0;
}

//检查食物和蛇身是否重合----重合返回false，失败返回true
bool check_snake_food(SNAKE s)
{
	POINT p = s->first;
	
	while(p != NULL)
	{
		if(p->x == food->x && p->y == food->y)
			return false;
		
		p = p->next;
	}
	
	return true;
}

//创建食物
void create_food(LCD lcd_device, SNAKE s)
{
	food = malloc(sizeof(point));
	if(NULL == food)
	{
		fprintf(stderr, "line[%d] malloc food failed\n", __LINE__);
		return;
	}
	
	for(;;)
	{
		food->x = rand()%10;
		food->y = rand()%10;
		
		//检查食物和蛇身是否重合
		if(check_snake_food(s))
			break;
	}
	
	show_square(lcd_device, 15+45*food->x, 15+45*food->y, 45, RED);
}

//在LCD模拟器上显示贪吃蛇
void show_snake(LCD lcd_device, SNAKE s)
{
	POINT p = s->first;
	
	while(p != NULL)
	{
		show_square(lcd_device, 15+45*p->x, 15+45*p->y, 45, BLACK);
		
		p=p->next;
	}
}

//初始化贪吃蛇游戏界面
void game_init(LCD lcd_device, SNAKE s)
{
	//显示背景
	show_square(lcd_device, 0, 0, 480, BLACK);
	printf("显示黑色区域成功\n");
	show_square(lcd_device, 15, 15, 450, WHITE);
	showBmp(480, 0, "background.bmp", lcd_device);
	
	//产生一个随机种子
	srand(time(NULL));
	
	//蛇的出生(3,3)--(4,3)--(5,3)--(6,3)
	POINT node = NULL;
	for(int i = 0; i < 4; i++)
	{
		node = queue_create_node(3+i, 3);
		queue_in(s, node);
	}
	
	//创建食物
	create_food(lcd_device, s);
	
	//显示蛇
	show_snake(lcd_device, s);
}