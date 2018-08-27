#define _CRT_SECURE_NO_WARNINGS
#define MAXSIZE 10

#include <stdio.h>
#include <stdlib.h>

//�������Ա�ṹ��
typedef struct LinearTable
{
	int index;
	int arr[MAXSIZE];
}MyLinear;

//�����ձ�
MyLinear *createLinear()
{
	MyLinear *result = (MyLinear *)malloc(sizeof(MyLinear));
	result->index = -1;
	
	return result;
}

//����Ԫ��
void add(int ele, int i, MyLinear *linear)
{
	//�����Ƿ�����
	if (linear->index == MAXSIZE - 1)
	{
		printf("�ñ�����\n");
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
		//����±��Ƿ�Խ��
		if (i < 0 || i > linear->index+2)
		{
			printf("�±�Խ��\n");
			return;
		}
	}

	//�������
	for (int j = linear->index; j >= i - 1; j--)
	{
		linear->arr[j + 1] = linear->arr[j];
	}
	linear->arr[i - 1] = ele;
	linear->index++;
}

//ɾ��Ԫ��
void deleteEle(int i, MyLinear *linear)
{
	//����±��Ƿ�Խ��
	if (i < 0 || i > linear->index)
	{
		printf("�±�Խ��\n");
		return;
	}

	//�����Ƿ�Ϊ��
	if (linear->index == -1)
	{
		printf("�ñ��ǿյ�\n");
		return;
	}

	//ɾ������
	for (int j = i; j < linear->index; j++)
	{
		linear->arr[j] = linear->arr[j + 1];
	}
	linear->index--;
}

//����ĳԪ�ص�һ�γ��ֵ�λ��
int findEleFirstIndex(int ele, MyLinear *linear)
{
	int result = 0;
	while (result <= linear->index && linear->arr[result] != ele)
	{
		result++;
	}
	if (result > linear->index)
	{
		printf("û���ҵ���ӦԪ��\n");
		return -1;
	}

	return result;
}

//����ĳ��λ�õ�Ԫ��
int findEle(int i, MyLinear *linear)
{
	//����±��Ƿ�Խ��
	if (i < 0 || i > linear->index)
	{
		printf("�޴�Ԫ��\n");
		return;
	}
	else
	{
		return linear->arr[i];
	}
}

//������Ա���
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