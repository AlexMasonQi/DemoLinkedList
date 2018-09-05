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

//遍历链表
void forEach(CycleList *list)
{
	CycleList *tmp = list;

	while (tmp != NULL)
	{
		printf("%d ", tmp->data);
		if (tmp->next == list)
			break;
		else
			tmp = tmp->next;
	}
	printf("\n");
}

//初始化链表
void createList(CycleList **list)
{
	CycleList *head = (CycleList *)malloc(sizeof(CycleList));
	head->pre = NULL;
	head->next = head;
	head->data = -1;
	CycleList *tmp = NULL;

	int num = -1;
	printf("\n请输入数据:(输入一个数后请按Enter键键入下一个数)\n");
	while (1)
	{
		scanf("%d", &num);
		if (num == 0)
			break;
		
		//判断是否是头节点
		if (head->data == -1)
		{
			head->data = num;
			tmp = head;
		}
		else
		{
			CycleList *node = (CycleList *)malloc(sizeof(CycleList));
			tmp->next = node;
			node->data = num;
			node->pre = tmp;
			node->next = head;
			tmp = node;
		}
	}

	if (num == 0)
	{
		//遍历
		forEach(head);
		*list = head;
	}
}

//在指定位置前插入节点
void add(CycleList **list, int position)
{
	CycleList *head = (*list);
	while (head != NULL)
	{

	}
}

int main()
{
	CycleList *list;
	createList(&list);

	forEach(list);

	system("pause");
	return 0;
}