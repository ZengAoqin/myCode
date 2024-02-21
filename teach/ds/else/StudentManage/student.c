#include "head.h"

//管理功能操作

//在链表找是否有相同学号
INFO isFindID(INFO head,char* strID)
{
	INFO p = head;
	INFO node = NULL;
	while(p->next != head)
	{
		if(!strcmp(p->next->stuInfo.strID, strID))
		{
			node = p->next;
			break;
		}
		p = p->next;
	}
	
	return node;
}

//1:添加学习信息
void student_add(INFO head)
{
	Student stuInfo;
	bool flag = true;
	while(flag)
	{
		printf("请输入学号\n");
		scanf("%s", stuInfo.strID);
		INFO p = isFindID(head, stuInfo.strID);
		if(p != NULL)
		{
			printf("学号已存在，请重新输入学号\n");
		}
		else
		{
			flag = false;
			break;
		}
	}
	
	printf("请输入姓名\n");
	scanf("%s", stuInfo.strName);
	
	printf("请输入年龄\n");
	scanf("%d", &stuInfo.age);
	
	printf("请输入性别\n");
	scanf("%s", stuInfo.strSex);
	
	printf("请输入成绩\n");
	scanf("%f", &stuInfo.fgrade);
	
	INFO node = create_node(&stuInfo);
	
	double_list_insert_tail(head, node);
}

//2:修改学生信息
void student_update(INFO head)
{
	//学号
	char strID[10]; 	
	printf("请输入学号\n");
	scanf("%s", strID);
	
	INFO node = isFindID(head, strID);
	if(node != NULL)
	{	
		printf("请输入姓名\n");
		scanf("%s", node->stuInfo.strName);
	
		printf("请输入年龄\n");
		scanf("%d", &node->stuInfo.age);
	
		printf("请输入性别\n");
		scanf("%s", node->stuInfo.strSex);
	
		printf("请输入成绩\n");
		scanf("%f", &node->stuInfo.fgrade);
		
		printf("修改成功\n");
	}
	else
	{
		printf("没有该学生信息\n");
	}
}

//3:删除学生信息
void student_delete(INFO head)
{
	//学号
	char strID[10]; 	
	printf("请输入学号\n");
	scanf("%s", strID);
	
	INFO node = isFindID(head, strID);
	if(node != NULL)
	{	
		double_list_delete(head, node);
		
		printf("删除成功\n");
	}
	else
	{
		printf("没有该学生信息\n");
	}
}

//4:显示学生信息 student_display(形参);
void student_display(INFO head)
{
    INFO p = head;
    if(p == NULL)
    {
        printf("不能传空指针\n");
    }
    else
    {
        p = p->next;
        while(p != head)
        {
            printf("学号:%s\t", p->stuInfo.strID);
            printf("姓名:%s\t", p->stuInfo.strName);
            printf("年龄:%d\t", p->stuInfo.age);
            printf("性别:%s\t", p->stuInfo.strSex);
            printf("成绩:%.2f\n", p->stuInfo.fgrade);
            p = p->next;
        }
    }
}

//5:查看学生分数排名(排序：成绩从高到低)+显示 sort_student(形参);
void sort_student(INFO head)
{
	if(head == NULL) return;
	if(head->next == NULL) return;
	
	INFO temp = head->next, p = NULL, q = NULL;
	
	//将链表头孤立
	head->next = head;
	head->prev = head;
	
	while(temp != head)
	{
		q = temp->next;
		//p = head;
		
		//for(p = head->prev; p != head && p->data > temp->data; p = p->prev);
		p = head->prev;
		while(p != head && p->stuInfo.fgrade < temp->stuInfo.fgrade)
		{
			p = p->prev;
		}

		
		temp->prev = p;
		temp->next = p->next;
		
		p->next->prev = temp;
		p->next = temp;
		temp = q;
	}
}



