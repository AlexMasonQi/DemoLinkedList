#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//linked list object
typedef struct Demo
{
	int index;
	int data;
	const char *str;
	Demo *next;
};

int getSize(Demo *head);

//add a node
//1: successful, -1: failed
int addNode(int dataNum, const char *strData, Demo *&head)
{
	int result = -1;
	int index = 1;
	Demo* temp = nullptr;

	//create a new space on the RAM
	Demo *newNode = (Demo *)malloc(sizeof(Demo));
	if (newNode != nullptr)
	{
		printf("create a node successfully!\n");
		newNode->data = dataNum;
		newNode->str = strData;
		newNode->next = nullptr;
	}
	else
	{
		printf("Error: create a node failed!\n");
		result = -1;
	}

	//if head is not exist
	if (head == nullptr)
	{
		newNode->index = 0;
		head = newNode;
		result = 1;
	}
	else
	{
		temp = head;
		while (temp->next != nullptr)
		{
			temp = temp->next;
			index++;
		}
		temp->next = newNode;
		temp->next->index = index;
		result = 1;
	}

	return result;
}

//traverse linked list
void traverseList(Demo *head)
{
	Demo *temp = nullptr;
	if (head != nullptr)
	{
		temp = head;
		printf("Demo:{index: %d, Integer data: %d, String data: %s\n", temp->index, temp->data, temp->str);
		while (temp->next != nullptr)
		{
			temp = temp->next;
			printf("Demo:{index: %d, Integer data: %d, String data: %s\n", temp->index, temp->data, temp->str);
		}
		printf("Traverse complete!\n");
	}
	else
	{
		printf("No head node found!\n");
	}
}

//get the list size
int getSize(Demo *head)
{
	Demo *temp = nullptr;
	int totalCount = 0;
	if (head != nullptr)
	{
		totalCount = 1;
		temp = head;
		while (temp->next != nullptr)
		{
			temp = temp->next;
			totalCount++;
		}
	}
	else
	{
		totalCount = 0;
	}

	return totalCount;
}

//copy a piece of memory
int copyNode(Demo *&dest, Demo *&src, int length)
{
	int result = -1;

	if (dest == nullptr || src == nullptr)
	{
		printf("Memory space can not be null!");
		return result;
	}
	dest->data = src->data;
	dest->index = src->index;
	dest->str = src->str;
	dest->next = src->next;

	return result;
}

//delete a node
Demo* deleteNode(Demo *&head,int index)
{
	Demo *pre = nullptr;
	Demo *after = nullptr;
	Demo *temp = nullptr;
	Demo *result = new Demo[sizeof(Demo)];
	if (head == nullptr)
	{
		printf("No head node found!\n");
		return result;
	}
	
	//if delete head node
	if (index == 0)
	{
		temp = head;
		//if only a head node
		if (temp->next == nullptr)
		{
			copyNode(result,temp,sizeof(temp));
			free(temp);
			temp = nullptr;
		}
		else
		{
			pre = head;
			head = head->next;
			copyNode(result, pre, sizeof(pre));
			free(pre);
			pre = nullptr;
		}
	}
	else
	{
		if (getSize(head) > 0)
		{
			if (index > getSize(head))
			{
				printf("Exception: Out of index!\n");
				return result;
			}
			temp = head;
			pre = head;
			after = head;
			while (temp->next != nullptr)
			{
				temp = temp->next;
				if (temp->index == index)
				{
					pre->next = temp->next;
					copyNode(result, temp, sizeof(temp));
					free(temp);
					temp = nullptr;
					break;
				}
				pre = temp;
			}
		}
	}

	return result;
}

//get a node from index
Demo *getNode(Demo *head, int index)
{
	Demo *result = nullptr;
	Demo *temp = nullptr;

	if (head == nullptr)
	{
		printf("No head node found!\n");
		return nullptr;
	}

	temp = head;
	while (temp != nullptr)
	{
		if (index == temp->index)
		{
			result = temp;
			break;
		}
		temp = temp->next;
	}

	return result;
}

int main()
{
	Demo *head = nullptr;
	const char *strArray[] = { "p001","p002","p003", "p004" };
	addNode(10, strArray[0], head);
	addNode(11, strArray[1], head);
	addNode(12, strArray[2], head);
	addNode(13, strArray[3], head);

	traverseList(head);
	printf("The length is: %d\n", getSize(head));
	
	Demo *pre = deleteNode(head, 2);
	printf("Deleted Demo:{index: %d, Integer data: %d, String data: %s\n", pre->index, pre->data, pre->str);

	traverseList(head);
	printf("The length is: %d\n", getSize(head));
	
	system("pause");
	return 0;
}