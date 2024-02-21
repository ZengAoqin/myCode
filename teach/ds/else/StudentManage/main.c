#include "head.h"

//菜单
void menu()
{
	printf("*******************学生信息管理系统*******************\n");
	printf("*******************1:添加学习信息*******************\n");
	printf("*******************2:修改学生信息*******************\n");
	printf("*******************3:删除学生信息*******************\n");
	printf("*******************4:显示学生信息*******************\n");
	printf("*******************5:查看学生分数排名*******************\n");
	printf("*******************0:退出*******************\n");
}

int main(int argc, char* argv[])
{
	INFO head = create_head();
	
	int num,ret;
	bool flag = true;
	while(flag)
	{
		menu(); //启动菜单
		printf("请输入选项\n");
		ret = scanf("%d", &num);
		if(ret != 1) //清空缓冲区
		{
			while(getchar() != '\n');
			//continue;
		}
		
		switch(num)
		{
			case 1: //添加学习信息
			{
				student_add(head);
				break;
			}
			case 2: //修改学生信息
			{
				student_update(head);
				break;
			}
			case 3: //删除学生信息
			{
				student_delete(head);
				break;
			}
			case 4: //显示学生信息
			{
				student_display(head);
				break;
			}
			case 5: //查看学生分数排名
			{
				sort_student(head);
				student_display(head);
				break;
			}
			case 0: //退出
			{
				flag = false;
				break;
			}
			default:
			{
				printf("没有这个选项值\n");
				break;
			}
		}
		
		
	}
	return 0;
}