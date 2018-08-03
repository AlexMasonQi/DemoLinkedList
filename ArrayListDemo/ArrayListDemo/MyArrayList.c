#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>


//���Ա�ṹ��
typedef struct MyList
{
	int last;
	char *data[13];
}MyList;

//����һ�������Ա�
MyList* createList()
{
	MyList *result = NULL;
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
	//�ж����Ա��Ƿ�����
	if (list->last == 12)
	{
		printf("�ñ�����\n");
		return -1;
	}

	//�жϲ���λ�������Ƿ�Խ�� 
	if (i<0 || i>list->last + 2)
	{
		printf("������Խ��\n");
		return -1;
	}

	//����Ԫ��
	for (int j = list->last; j >= i - 1; j--)
	{
		//��λ
		list->data[j + 1] = list->data[j];
	}
	list->data[i - 1] = element;
	list->last++;
	return 1;
}

//ɾ��
int deleteEle(MyList *list, int index)
{
	//�ж�ɾ����λ�������Ƿ�Խ�� 
	if (index<0 || index>list->last + 2)
	{
		printf("������Խ��\n");
		return -1;
	}

	for (int i = index; i < (list->last)+1; i++)
	{
		//��λ
		list->data[i] = list->data[i + 1];
	}
	list->last--;

	return 1;
}

//���Ա���
int length(MyList *list)
{
	return list->last + 1;
}

//��������index������ӦԪ��
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