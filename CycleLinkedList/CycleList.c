#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//define a struct
typedef struct CycleLinkedList
{
	int data;
	struct CycleLinkedList *prev;
	struct CycleLinkedList *next;
}CycleList;

//free memory
void freeMem(CycleList *list)
{
	if (list != NULL)
	{
		free(list);
		list = NULL;
	}
}

//list the elements
void forEach(CycleList *list)
{
	CycleList *tmp = list;
	printf("\n===================��������===================\n\n");
	while (tmp != NULL)
	{
		printf("%d ", tmp->data);
		if (tmp->next == list)
		{
			break;
		}
		else
		{
			tmp = tmp->next;
		}
	}
	printf("\n");
}

//init linkedlist
int initList(CycleList **list)
{
	CycleList *tmp = NULL;
	int data = 0;

	//judge the list is null or not
	if (list == NULL)
	{
		printf("NULL Pointer Exception!\n");
		return -1;
	}

	printf("������Ԫ�أ���Enter��������һ��Ԫ�أ�����0��������\n");

	//create the head node
	CycleList *head = (CycleList *)malloc(sizeof(CycleList));
	head->prev = NULL;
	head->data = -1;
	head->next = *list;

	while (1)
	{
		scanf("%d", &data);
		if (data == 0)
		{
			break;
		}
		if (head->data == -1)
		{
			head->data = data;
			tmp = head;
		}
		else
		{
			//create a new node
			CycleList *node = (CycleList *)malloc(sizeof(CycleList));
			node->data = data;
			node->prev = tmp;
			node->next = head;
			tmp->next = node;
			tmp = node;
		}
	}
	if (data == 0)
	{
		//list the elements
		forEach(head);
		*list = head;
	}

	return 0;
}

int add(CycleList **list, int num)
{
	

	return 0;
}

//init the screen
void initScreen()
{
	printf("\n=====================ѭ������=======================\n");
	printf("\n��������ʾ���ֽ��в���\n\n");
	printf("1. ��ʼ������\n\n");
	printf("2. ����Ԫ��\n\n");
	printf("3. ɾ��Ԫ��\n\n");
	printf("4. ����Ԫ������\n\n");
	printf("5. ��������\n\n");
	printf("0. �˳�����\n\n");
}

int main()
{
	initScreen();
	int option = 0;
	CycleList *list = (CycleList *)malloc(sizeof(CycleList));
	
	while (1)
	{
		printf("����������룺");
		scanf("%d", &option);

		switch (option)
		{
			//init
			case 1:
			{
				initList(&list);
			}break;

			//add
			case 2:
			{

			}break;

			//delete
			case 3:
			{

			}break;

			//get index
			case 4:
			{

			}break;

			//list elements
			case 5:
			{
				forEach(list);
			}break;

			//exit
			case 0:
			{
				exit(0);
			}break;
		}
	}

	freeMem(list);
	
	system("pause");
	return 0;
}