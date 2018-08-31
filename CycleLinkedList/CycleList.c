#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//����һ��ѭ������ṹ��
typedef struct CycleLinkedList
{
	int data;
	struct CycleLinkedList *pre;
	struct CycleLinkedList *next;
}CycleList;

//��������
void createList(CycleList **list)
{
	*list = (CycleList *)malloc(sizeof(CycleList));
	(*list)->next = NULL;
	(*list)->pre = NULL;
	(*list)->data = -1;
}

//����ڵ�
void add(CycleList *list, int ele)
{
	CycleList *head = list;
	//�ж��Ƿ���ͷ�ڵ�
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