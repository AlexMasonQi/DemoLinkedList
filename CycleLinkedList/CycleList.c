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

//��ȡ����
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

//��ʼ������
void createList(CycleList **list)
{
	CycleList *head = (CycleList *)malloc(sizeof(CycleList));
	head->pre = NULL;
	head->next = head;
	head->data = -1;
	CycleList *tmp = NULL;

	int num = -1;
	int tag = 0;
	printf("\n����������:(����һ�������밴Enter��������һ����)\n");
	while (1)
	{
		scanf("%d", &num);
		tag++;
		if (num == 0)
		{
			break;
		}
		
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

	if (num == 0 && tag>1)
	{
		//����
		forEach(head);
		*list = head;
	}
}

//��ָ��λ��ǰ����ڵ�
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
			//�����ͷ�ڵ�ǰ���
			if (position == 0)
			{
				CycleList *node = (CycleList *)malloc(sizeof(CycleList));
				node->pre = NULL;
				node->data = num;
				node->next = temp;
				temp->pre = node;
				head = node;
				newTmp = head;

				//β�ڵ��nextָ���µ�ͷ�ڵ�
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