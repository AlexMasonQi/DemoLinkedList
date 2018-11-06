#define _CRT_SECURE_NO_WARNINGS
#define MAXSIZE 10
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//��ջ��˳��ṹʵ��
typedef struct ArrayStack
{
	int data[MAXSIZE];
	int top;
}Stack;

//����һ����ջ
void create(Stack **stack)
{
	//�ж�ָ���Ƿ�Ϊ��
	if (stack == NULL)
	{
		printf("Null Pointer Exception!\n");
		return -1;
	}

	//������ջ
	(*stack) = (Stack *)malloc(sizeof(Stack));
	(*stack)->top = -1;
}

//��ջ�Ƿ�Ϊ���ж�
int isEmpty(Stack *stack)
{
	//�ж�ָ���Ƿ�Ϊ��
	if (stack == NULL)
	{
		printf("Null Pointer Exception!\n");
		return -1;
	}

	if (stack->top == -1)
	{
		return 0;
	}
	else
	{
		return 1;
	}
}

//��ջ
int push(Stack *stack, int num)
{
	//�ж�ָ���Ƿ�Ϊ��
	if (stack == NULL)
	{
		printf("Null Pointer Exception!");
		return -1;
	}

	//�ж϶�ջ�Ƿ�����
	if (stack->top == MAXSIZE - 1)
	{
		printf("ջ����\n");
		return -3;
	}
	else
	{
		stack->data[++(stack->top)] = num;
	}

	return 0;
}

//��ջ
int pop(Stack *stack)
{
	//�ж�ָ���Ƿ�Ϊ��
	if (stack == NULL)
	{
		printf("Null Pointer Exception!");
		return -1;
	}

	//�ж϶�ջ�Ƿ�Ϊ��
	if (isEmpty(stack)==0)
	{
		printf("��ջ\n");
		return -2;
	}
	else
	{
		return stack->data[(stack->top)--];
	}
}

int main1()
{
	Stack *stack;
	create(&stack);

	for (int i = 0; i < MAXSIZE; i++)
	{
		push(stack, i + 1);
	}

	for (int j = MAXSIZE-1; j > -1; j--)
	{
		printf("data[%d] = %d\n", j, pop(stack));
	}

	if (stack != NULL)
	{
		free(stack);
		stack = NULL;
	}
	
	system("pause");
	return 0;
}