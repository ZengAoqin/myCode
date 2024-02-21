#ifndef _HEAD_H
#define _HEAD_H

#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
//学号 char strID[]
//姓名 
//年龄 
//性别 char strSex[]
//成绩 float fgrade

//学生信息
typedef struct Student
{
	char strID[10]; 	//学号
	char strName[20];	//姓名 
	int age;			//年龄 
	char strSex[10];	//性别
	float fgrade;		//成绩
}Student, *pStudent;

//双向链表
typedef struct DoubleList
{
	//数据域
	Student stuInfo;	
	//指针域
	struct DoubleList* prev; //前驱指针
	struct DoubleList* next; //后继指针
}info, *INFO;

/*********双向循环链表操作*********/
//创建表头
extern INFO create_head(); 
//创建双向链表的节点
extern INFO create_node(pStudent pData);
//头部插入
extern void double_list_insert_head(INFO head, INFO node);
//尾部插入
extern void double_list_insert_tail(INFO head, INFO node);
//修改节点
extern void double_list_modify(INFO head, INFO node, pStudent pData);
//删除节点
extern void double_list_delete(INFO head, INFO node);
//查找
extern bool double_list_find(INFO head, INFO node);

/*********学生信息管理功能操作*********/
//1:添加学习信息 student_add(形参);
extern void student_add(INFO head);
//2:修改学生信息 student_update(形参);
extern void student_update(INFO head);
//3:删除学生信息 student_delete(形参);
extern void student_delete(INFO head);
//4:显示学生信息 student_display(形参);
extern void student_display(INFO head);
//5:查看学生分数排名(排序：成绩从高到低)+显示 sort_student(形参);
extern void sort_student(INFO head);
#endif