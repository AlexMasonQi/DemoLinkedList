#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct LinkedList
{
	//data
	int data;
	//next pointer
	struct LinkedList *next;
	//previous pointer
	struct LinkedList *pre;
}List;

//创建一个n个元素的随机链表
void createRandomList(List **list, int n)
{
	srand(time(0));
	if (list == NULL)
	{
		printf("NULL pointer exception");
		return;
	}
	List *head = (List *)malloc(sizeof(List));
	head->pre = NULL;
	head->data = rand() % 100;
	head->next = NULL;
	List *p = head;
	
	for (int i = 0; i < n-1; i++)
	{
		List *tmp = (List *)malloc(sizeof(List));
		tmp->data = rand() % 100;
		tmp->next = NULL;
		p->next = tmp;
		tmp->pre = p;
		p = tmp;
	}
	*list = head;
}

//遍历链表
void forEach(List *list)
{
	if (list == NULL)
	{
		printf("NULL pointer exception");
		return;
	}
	List *tmp = list;
	while (tmp != NULL)
	{
		int data = tmp->data;
		printf("%d ", data);
		tmp = tmp->next;
	}
	printf("\n");
}

//获取链表长度
int length(List *list)
{
	if (list == NULL)
	{
		printf("NULL pointer exception");
		return;
	}
	int result = 0;
	List *tmp = list;
	while (tmp != NULL)
	{
		result++;
		tmp = tmp->next;
	}

	return result;
}

//获取链表的中间节点
int getMiddleNode(List *list)
{
	if (list == NULL)
	{
		printf("NULL pointer exception");
		return;
	}
	List *slow = list;
	List *fast = list;

	while (fast->next != NULL)
	{
		if (fast->next->next != NULL)
		{
			fast = fast->next->next;
			slow = slow->next;
		}
		else
		{
			fast = fast->next;
		}
	}

	return slow->data;
}

//释放空间，防止内存泄漏
void freeSpace(List *list)
{
	if (list != NULL)
	{
		free(list);
		list = NULL;
	}
	else
	{
		printf("NULL pointer exception");
		return;
	}
}

//初始化信息显示
void init()
{
	printf("\n取出单链表中间节点\n\n");
	printf("请选择操作序号:\n");
	printf("1. 创建链表\n2. 显示链表长度\n3. 显示链表中间节点\n0. 退出\n");
	printf("\n请选择操作:\n");
}

int main()
{
	List *list = (List *)malloc(sizeof(List));
	
	while (1)
	{
		init();
		int serialNumber = 0;
		scanf("%d", &serialNumber);
		switch (serialNumber)
		{
		case 1:
		{
			createRandomList(&list, 20);
			forEach(list);
		}break;

		case 2:
		{
			printf("链表长度: %d\n", length(list));
		}break;

		case 3:
		{
			printf("中间节点为: %d\n", getMiddleNode(list));
		}break;

		case 0:
		{
			exit(0);
		}break;
		}
	}
	
	system("pause");
	return 0;
}