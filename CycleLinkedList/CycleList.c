#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//定义一个循环链表结构体
typedef struct CycleLinkedList
{
	int data;
	struct CycleLinkedList *pre;
	struct CycleLinkedList *next;
}CycleList;

//创建链表
void createList(CycleList **list)
{
	*list = (CycleList *)malloc(sizeof(CycleList));
	(*list)->next = NULL;
	(*list)->pre = NULL;
	(*list)->data = -1;
}

//插入节点
void add(CycleList *list, int ele)
{
	CycleList *head = list;
	//判断是否是头节点
	if (head->next == NULL && head->pre == NULL)
	{
		head->data = ele;
	}
	else
	{
		CycleList *node = (CycleList *)malloc(sizeof(CycleList));
		node->pre = NULL;
		node->data = ele;
		node->next = NULL;
	}
}

int main()
{
	CycleList *cycleList;
	createList(&cycleList);

	printf("%d",cycleList->data);
	
	system("pause");
	return 0;
}