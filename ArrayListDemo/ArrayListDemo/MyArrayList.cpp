#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXSIZE 13;

//线性表结构体
typedef struct MyList
{
	int last;
	char *data[1024];
};

//创建一个空线性表
MyList* createList()
{
	MyList *result = nullptr;
	result = (MyList *)malloc(sizeof(MyList));
	result->last = -1;

	return result;
}

//查找线性表元素出现的位置
int findEleIndex(MyList *list, char *element)
{
	int index = 0;
	while (index <= list->last && list->data[index] == element)
	{
		index++;
	}
	if (index > list->last)
	{
		return -1;
	}
	return index;
}

//插入
int addEle(MyList *list, char *element, int i)
{

}


int main()
{
	printf("hello.......\n");

	system("pause");
	return 0;
}