#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct LinkedList
{
	int data;
	struct LinkedList *next;
}List;

//创建链表
List *createList()
{
	
}

int main()
{
	srand(time(0));
	for (int i = 0; i < 10; i++)
	{
		int num = rand()%100;
		printf("第%d个数为: %d\n", i, num);
	}

	
	system("pause");
	return 0;
}