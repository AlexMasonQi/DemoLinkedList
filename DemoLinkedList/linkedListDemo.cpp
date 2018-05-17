#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//linked list object
typedef struct Demo
{
	int index;
	int data;
	char *str;
	Demo *next;
};

//add a node
//1: successful, -1: failed
int addNode(int dataNum, char *strData, Demo *head)
{
	int result = -1;
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
		newNode->index++;
		temp = head;
		while (temp->next != nullptr)
		{
			temp = temp->next;
		}
		temp->next = newNode;
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
		printf("Demo:{Integer data: %d, String data: %s\n", temp->data, temp->str);
		while (temp->next != nullptr)
		{
			temp = temp->next;
			printf("Demo:{Integer data: %d, String data: %s\n", temp->data, temp->str);
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
		printf("No head node found!\n");
		totalCount = 0;
	}

	return totalCount;
}

//delete a node
//1: delete successful, -1: delete failed
int deleteNode(Demo *head,int index)
{
	Demo *pre = nullptr;
	Demo *after = nullptr;
	Demo *temp = nullptr;
	int result = -1;
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
			free(temp);
		}
		else
		{
			pre = head;
			head = head->next;
			free(pre);
		}
	}
	else
	{
		if (getSize(head) > 0)
		{
			temp = head;
			pre = head;
			after = head;
			while (temp->next != nullptr)
			{
				temp = temp->next;

			}
		}
	}
}

int main()
{
	int p[] = { 10,20,30 };
	for (auto c : p)
	{
		printf("%d ", c);
	}
	
	system("pause");
	return 0;
}