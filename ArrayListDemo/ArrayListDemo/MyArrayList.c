#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>


//线性表结构体
typedef struct MyList
{
	int last;
	char *data[13];
}MyList;

//创建一个空线性表
MyList* createList()
{
	MyList *result = NULL;
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
	//判断线性表是否满了
	if (list->last == 12)
	{
		printf("该表已满\n");
		return -1;
	}

	//判断插入位置索引是否越界 
	if (i<0 || i>list->last + 2)
	{
		printf("索引已越界\n");
		return -1;
	}

	//插入元素
	for (int j = list->last; j >= i - 1; j--)
	{
		//移位
		list->data[j + 1] = list->data[j];
	}
	list->data[i - 1] = element;
	list->last++;
	return 1;
}

//删除
int deleteEle(MyList *list, int index)
{
	//判断删除的位置索引是否越界 
	if (index<0 || index>list->last + 2)
	{
		printf("索引已越界\n");
		return -1;
	}

	for (int i = index; i < (list->last)+1; i++)
	{
		//移位
		list->data[i] = list->data[i + 1];
	}
	list->last--;

	return 1;
}

//线性表长度
int length(MyList *list)
{
	return list->last + 1;
}

//根据索引index返回相应元素
char *getEle(MyList *list, int index)
{
	return list->data[index];
}

void freeSpace(MyList *list)
{
	if (list != NULL)
	{
		free(list);
		list = NULL;
	}
}

int main()
{
	MyList *list = createList();
	char *strArr[13] = { "p001","p002","p003","p004","p005","p006","p007","p008","p009","p010","p011","p012","p013"};
	list->data = strArr;

	for (int i = 0; i < 13; i++)
	{
		printf("%s\n", list->data[i]);
	}

	system("pause");
	return 0;
}