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

//��ʼ������
void createList(CycleList **list)
{
	CycleList *head = (CycleList *)malloc(sizeof(CycleList));
	head->pre = NULL;
	head->next = head;
	head->data = -1;
	CycleList *tmp = NULL;

	int num = -1;
	printf("\n����������:(����һ�������밴Enter��������һ����)\n");
	while (1)
	{
		scanf("%d", &num);
		if (num == 0)
			break;
		
		//�ж��Ƿ���ͷ�ڵ�
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
		//����
		forEach(head);
		*list = head;
	}
}

//��ָ��λ��ǰ����ڵ�
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