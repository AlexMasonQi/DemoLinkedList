#define _CRT_SECURE_NO_WARNINGS
#define MAXSIZE 10

#include <stdio.h>
#include <stdlib.h>

//定义线性表结构体
typedef struct LinearTable
{
	int index;
	int arr[MAXSIZE];
}MyLinear;

//建立空表
MyLinear *createLinear()
{
	MyLinear *result = (MyLinear *)malloc(sizeof(MyLinear));
	result->index = -1;
	
	return result;
}

//插入元素
void add(int ele, int i, MyLinear *linear)
{
	//检测表是否已满
	if (linear->index == MAXSIZE - 1)
	{
		printf("该表已满\n");
		return;
	}

	if (i == 0 && linear->index == -1)
	{
		linear->arr[i] = ele;
		linear->index++;
		return;
	}
	else
	{
		//检测下标是否越界
		if (i < 0 || i > linear->index+2)
		{
			printf("下标越界\n");
			return;
		}
	}

	//插入操作
	for (int j = linear->index; j >= i - 1; j--)
	{
		linear->arr[j + 1] = linear->arr[j];
	}
	linear->arr[i - 1] = ele;
	linear->index++;
}

//删除元素
void deleteEle(int i, MyLinear *linear)
{
	//检测下标是否越界
	if (i < 0 || i > linear->index)
	{
		printf("下标越界\n");
		return;
	}

	//检测表是否为空
	if (linear->index == -1)
	{
		printf("该表是空的\n");
		return;
	}

	//删除操作
	for (int j = i; j < linear->index; j++)
	{
		linear->arr[j] = linear->arr[j + 1];
	}
	linear->index--;
}

//查找某元素第一次出现的位置
int findEleFirstIndex(int ele, MyLinear *linear)
{
	int result = 0;
	while (result <= linear->index && linear->arr[result] != ele)
	{
		result++;
	}
	if (result > linear->index)
	{
		printf("没有找到相应元素\n");
		return -1;
	}

	return result;
}

//查找某个位置的元素
int findEle(int i, MyLinear *linear)
{
	//检测下标是否越界
	if (i < 0 || i > linear->index)
	{
		printf("无此元素\n");
		return;
	}
	else
	{
		return linear->arr[i];
	}
}

//获得线性表长度
int length(MyLinear *linear)
{
	return linear->index + 1;
}

int main()
{
	MyLinear *test = createLinear();
	add(1, 0, test);
	add(2, 1, test);
	add(3, 2, test);
	add(4, 3, test);
	add(5, 4, test);
	add(9, 5, test);

	for (int i = 0; i < length(test); i++)
	{
		printf("arr[%d] = %d\n", i, findEle(i, test));
	}

	deleteEle(3, test);
	printf("\n");

	for (int i = 0; i < length(test); i++)
	{
		printf("arr[%d] = %d\n", i, findEle(i, test));
	}

	system("pause");
	return 0;
}