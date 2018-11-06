#define _CRT_SECURE_NO_WARNINGS
#define MAXSIZE 10
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//¶ÑÕ»µÄË³Ðò½á¹¹ÊµÏÖ
typedef struct ArrayStack
{
	int data[MAXSIZE];
	int top;
}Stack;

//´´½¨Ò»¸ö¶ÑÕ»
void create(Stack **stack)
{
	//ÅÐ¶ÏÖ¸ÕëÊÇ·ñÎª¿Õ
	if (stack == NULL)
	{
		printf("Null Pointer Exception!\n");
		return -1;
	}

	//´´½¨¶ÑÕ»
	(*stack) = (Stack *)malloc(sizeof(Stack));
	(*stack)->top = -1;
}

//¶ÑÕ»ÊÇ·ñÎª¿ÕÅÐ¶Ï
int isEmpty(Stack *stack)
{
	//ÅÐ¶ÏÖ¸ÕëÊÇ·ñÎª¿Õ
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

//ÈëÕ»
int push(Stack *stack, int num)
{
	//ÅÐ¶ÏÖ¸ÕëÊÇ·ñÎª¿Õ
	if (stack == NULL)
	{
		printf("Null Pointer Exception!");
		return -1;
	}

	//ÅÐ¶Ï¶ÑÕ»ÊÇ·ñÂúÁË
	if (stack->top == MAXSIZE - 1)
	{
		printf("Õ»ÂúÁË\n");
		return -3;
	}
	else
	{
		stack->data[++(stack->top)] = num;
	}

	return 0;
}

//³öÕ»
int pop(Stack *stack)
{
	//ÅÐ¶ÏÖ¸ÕëÊÇ·ñÎª¿Õ
	if (stack == NULL)
	{
		printf("Null Pointer Exception!");
		return -1;
	}

	//ÅÐ¶Ï¶ÑÕ»ÊÇ·ñÎª¿Õ
	if (isEmpty(stack)==0)
	{
		printf("¿ÕÕ»\n");
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