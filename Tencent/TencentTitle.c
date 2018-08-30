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

//����һ��n��Ԫ�ص��������
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

//��������
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

//��ȡ������
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

//��ȡ������м�ڵ�
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

//�ͷſռ䣬��ֹ�ڴ�й©
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

//��ʼ����Ϣ��ʾ
void init()
{
	printf("\nȡ���������м�ڵ�\n\n");
	printf("��ѡ��������:\n");
	printf("1. ��������\n2. ��ʾ������\n3. ��ʾ�����м�ڵ�\n0. �˳�\n");
	printf("\n��ѡ�����:\n");
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
			printf("������: %d\n", length(list));
		}break;

		case 3:
		{
			printf("�м�ڵ�Ϊ: %d\n", getMiddleNode(list));
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