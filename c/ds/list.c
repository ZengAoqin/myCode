#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>


typedef struct list
{
    int data;
    struct list* next;
}list;

list* init()
{
    list* head = malloc(sizeof(list));
    if(NULL == head)
    {
        printf("申请head失败");
        return NULL;
    }

    head->data = 0;
    head->next = NULL;

    return head;
} 

void show(list* head)
{
    if(head->next == NULL)
    {
        printf("链表为空\n");
        return;
    }

    printf("head-");
    list* p = head->next;
    while(p != NULL)
    {
        printf("%d-", p->data);
        p = p->next;
    }
    printf("null\n");
}

void insert_tail(list *head, int data)
{
    list* temp = head;
    list* p = head->next;
    while(p != NULL)
    {
        temp = p;
        p = p->next;
    }

    list* node = malloc(sizeof(list));
    node->data = data;
    node->next = NULL;
    temp->next = node;
}

void insert_head(list* head, int data)
{
    list* node = malloc(sizeof(list));
    node->data = data;
    node->next = head->next;
    head->next = node;
}

void delete_num(list* head, int num)
{
    if(head->next == NULL)
    {
        printf("链表为空 无法删除\n");
        return;
    }

    int i = 1;
    list* p = head->next;
    list* temp = head;

    while(p != NULL && num != i)
    {
        temp = p;
        p = p->next;
        i++;
    }
    
    if(p == NULL)
    {
        printf("无效序号\n");
        return;
    }

    temp->next = p->next;
    p->data = 0;
    p->next = NULL;
}

void delete_data(list* head, int data)
{
    if(head->next == NULL)
    {
        printf("链表为空 无法删除\n");
        return;
    }

    list* p = head->next;
    list* temp = head;
    while(p != NULL && data != p->data)
    {
        temp = p;
        p = p->next;
    }

    if(p == NULL)
    {
        printf("未找到此数据\n");
        return;
    }

    temp->next = p->next;
    p->data = 0;
    p->next = NULL;
}

int find_num(list* head, int num)
{
    if(head->next == NULL)
    {
        printf("链表为空\n");
        return -1;
    }

    int i = 1;
    list* p = head->next;

    while(p != NULL && num != i)
    {
        p = p->next;
        i++;
    }
    
    if(p == NULL)
    {
        printf("无效序号\n");
        return -1;
    }

    return p->data;
}

int find_data(list* head, int data)
{
    if(head->next == NULL)
    {
        printf("链表为空");
        return -1;
    }

    int count = 1;
    list* p = head->next;
    while(p != NULL && p->data != data)
    {
        p = p->next;
        count++;
    }

    if(p == NULL)
    {
        printf("数据值不存在\n");
        return -1;
    }

    return count;
}

void update(list* head, int num, int data)
{
    if(head->next == NULL)
    {
        printf("链表为空\n");
        return;
    }

    int i = 1;
    list* p = head->next;
    while(p != NULL && num != i)
    {
        p = p->next;
        i++;
    }

    if(p == NULL)
    {
        printf("序号不存在\n");
        return;
    }

    p->data = data;
}

int main(int argc, char* argv[])
{
    list* head = init();
    show(head);
    sleep(1);

    printf("\n在链表尾插入数据后：\n");
    insert_tail(head, 10);
    insert_tail(head, 20);
    insert_tail(head, 30);
    show(head);
    sleep(1);

    printf("\n在链表头插入数据后：\n");
    insert_head(head, 3);
    insert_head(head, 2);
    insert_head(head, 1);
    show(head);
    sleep(1);

    printf("\n删除第3个数据后：\n");
    delete_num(head, 3);
    show(head);
    printf("\n删除第10个数据后：\n");
    delete_num(head, 10);
    show(head);
    printf("\n删除值为20的数据后：\n");
    delete_data(head, 20);
    show(head);
    printf("\n删除值为100的数据后：\n");
    delete_data(head, 100);
    show(head);
    sleep(1);

    printf("\n第2个数据是：");
    printf("%d\n", find_num(head, 2));
    printf("\n第5个数据是：");
    printf("%d\n", find_num(head, 5));
    printf("\n值为10数据的序号是：");
    printf("%d\n", find_data(head, 10));
    printf("\n值为100数据的序号是：");
    printf("%d\n", find_data(head, 100));
    show(head);
    sleep(1);

    printf("\n将第3个数据修改为66：\n");
    update(head, 3, 66);
    show(head);
    sleep(1);

    return 0;
}