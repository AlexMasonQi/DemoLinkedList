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
void freeMem(CycleList **list)
{
	//judge the list is null or not
	if (list == NULL)
	{
		printf("NULL Pointer Exception!\n");
		return -1;
	}

	CycleList *tmp = NULL;

	while ((*list) != NULL)
	{
		//if no head node
		if ((*list)->next == NULL)
		{
			break;
		}

		//if only a head
		if ((*list)->next == (*list))
		{
			free((*list));
			(*list) = NULL;
		}
		else
		{
			tmp = (*list)->next->next;
			free((*list)->next);
			(*list)->next = tmp;
		}
	}
}

//list the elements
int forEach(CycleList *list)
{
	//judge the list is null or not
	if (list == NULL)
	{
		printf("NULL Pointer Exception!\n");
		return -1;
	}

	CycleList *tmp = list;
	printf("\n===================遍历链表===================\n\n");
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

	return 0;
}

//get the length
int length(CycleList *list)
{
	//judge the list is null or not
	if (list == NULL)
	{
		printf("NULL Pointer Exception!\n");
		return -1;
	}

	int len = 1;
	CycleList *tmp = list;
	while (tmp->next != list)
	{
		len++;
		tmp = tmp->next;
	}

	return len;
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

	printf("请输入元素，按Enter键键入下一个元素，输入0结束输入\n");

	//create the head node
	CycleList *head = (CycleList *)malloc(sizeof(CycleList));
	head->prev = *list;
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
			head->prev = node;
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

int add(CycleList **list, int index,int num)
{
	//judge the list is null or not
	if (list == NULL)
	{
		printf("NULL Pointer Exception!\n");
		return -1;
	}

	CycleList *tmp = (*list);
	CycleList *temp = (*list);
	CycleList *buffer = NULL;
	
	//if the index is 0(insert before the head node)
	if (index == 0)
	{
		buffer = (*list);

		//create a new node
		CycleList *node = (CycleList *)malloc(sizeof(CycleList));
		node->data = num;
		node->prev = buffer->prev;
		node->next = buffer;
		buffer->prev = node;
		(*list) = node;

		//make the last node point to the new head node
		/*while (temp->next != buffer)
		{
			temp = temp->next;
		}*/
		node->prev->next = (*list);
	}
	else
	{
		buffer = (*list);
		int j = 0;

		//create a new node
		CycleList *node = (CycleList *)malloc(sizeof(CycleList));
		node->data = num;
		while (tmp != NULL)
		{
			if (j == index)
			{
				node->next = tmp;
				node->prev = tmp->prev;
				tmp->prev->next = node;
				tmp->prev = node;
				break;
			}
			tmp = tmp->next;
			j++;
		}
	}

	forEach((*list));

	return 0;
}

int deleteEle(CycleList **list, int index)
{
	//judge the list is null or not
	if (list == NULL)
	{
		printf("NULL Pointer Exception!\n");
		return -1;
	}

	CycleList *tmp = (*list);
	int i = 0;

	//if only a head
	if ((*list)->next == (*list))
	{
		free((*list));
		(*list) = NULL;
	}
	else
	{
		CycleList *buffer = (*list);
		CycleList *tail = (*list)->prev;
		//if delete the head node
		if (i == index)
		{
			tail->next = buffer->next;
			buffer->next->prev = tail;
			if (buffer != NULL)
			{
				free(buffer);
				buffer = NULL;
			}
			(*list) = tail->next;
		}
		else
		{
			while (buffer->next != buffer)
			{
				if (i == index)
				{
					buffer->prev->next = buffer->next;
					buffer->next->prev = buffer->prev;
					if (buffer != NULL)
					{
						free(buffer);
						buffer = NULL;
					}
					break;
				}
				buffer = buffer->next;
				i++;
			}
		}
	}

	forEach((*list));

	return 0;
}

int get(CycleList *list, int data)
{
	//judge the list is null or not
	if (list == NULL)
	{
		printf("NULL Pointer Exception!\n");
		return -1;
	}

	int index = 0;
	CycleList *tmp = list;

	while (tmp!=NULL)
	{
		if (data == tmp->data)
		{
			break;
		}
		tmp = tmp->next;
		if (tmp == list)
		{
			printf("\n没有该元素！\n");
			index = -1;
			break;
		}
		index++;
	}

	return index;
}

//init the screen
void initScreen()
{
	printf("\n=====================循环链表=======================\n");
	printf("\n请输入提示数字进行操作\n\n");
	printf("1. 初始化链表\n\n");
	printf("2. 插入元素\n\n");
	printf("3. 删除元素\n\n");
	printf("4. 返回元素索引\n\n");
	printf("5. 遍历链表\n\n");
	printf("0. 退出程序\n\n");
}

int main()
{
	initScreen();
	int option = 0;
	CycleList *list = (CycleList *)malloc(sizeof(CycleList));
	list->prev = NULL;
	list->next = NULL;
	list->data = 0;
	
	while (1)
	{
		printf("请输入操作码：");
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
				printf("\n请输入插入的位置: ");
				int index = 0;
				scanf("%d", &index);
				printf("\n请输入插入的元素: ");
				int data = 0;
				scanf("%d", &data);
				add(&list, index, data);
			}break;

			//delete
			case 3:
			{
				printf("\n请输入要删除的索引: ");
				int index = 0;
				scanf("%d", &index);
				deleteEle(&list, index);
			}break;

			//get index
			case 4:
			{
				printf("\n请输入要查找的元素: ");
				int data = 0;
				scanf("%d", &data);
				int index = get(list, data);
				if (index != -1)
				{
					printf("\n元素%d的索引为%d\n", data, index);
				}
			}break;

			//list elements
			case 5:
			{
				forEach(list);
				printf("%d\n", length(list));
			}break;

			//exit
			case 0:
			{
				//free the memory
				freeMem(&list);
				if (list != NULL)
				{
					free(list);
					list = NULL;
				}
				exit(0);
			}break;
		}
	}
	
	system("pause");
	return 0;
}