#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXSIZE 13;

//���Ա�ṹ��
typedef struct MyList
{
	int last;
	char *data[1024];
};

//����һ�������Ա�
MyList* createList()
{
	MyList *result = nullptr;
	result = (MyList *)malloc(sizeof(MyList));
	result->last = -1;

	return result;
}

//�������Ա�Ԫ�س��ֵ�λ��
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

//����
int addEle(MyList *list, char *element, int i)
{

}


int main()
{
	printf("hello.......\n");

	system("pause");
	return 0;
}