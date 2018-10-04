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

//获取长度
int length(CycleList *list)
{
	int len = 0;
	CycleList *tmp = list;
	while (tmp!=NULL)
	{
		len++;
		if (tmp->next == list)
		{
			break;
		}
		tmp = tmp->next;
	}

	return len;
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
	int tag = 0;
	printf("\n请输入数据:(输入一个数后请按Enter键键入下一个数)\n");
	while (1)
	{
		scanf("%d", &num);
		tag++;
		if (num == 0)
		{
			break;
		}
		
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

	if (num == 0 && tag>1)
	{
		//遍历
		forEach(head);
		*list = head;
	}
}

//在指定位置前插入节点
void add(CycleList **list, int position,int num)
{
	CycleList *head = (*list);
	CycleList *temp = head;
	CycleList *newTmp = NULL;
	int tmp = 0;
	if (head != NULL)
	{
		while (temp != NULL)
		{
			//如果在头节点前添加
			if (position == 0)
			{
				CycleList *node = (CycleList *)malloc(sizeof(CycleList));
				node->pre = NULL;
				node->data = num;
				node->next = temp;
				temp->pre = node;
				head = node;
				newTmp = head;

				//尾节点的next指向新的头节点
				while (newTmp!=NULL)
				{

				}
			}
			else
			{
				CycleList *node = (CycleList *)malloc(sizeof(CycleList));
				node->pre = NULL;
				node->data = num;
				
			}
		}
	}
}

int main()
{
	CycleList *list;
	createList(&list); 
	printf("%d\n",length(list));
	add(&list, 0, 17);
	forEach(&list);

	system("pause");
	return 0;
}