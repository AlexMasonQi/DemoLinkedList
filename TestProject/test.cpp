/*
	时间：2018年9月9日
	目的：通过函数完成对结构体变量的输入和输出

	知识点：
	一：通过函数完成对结构体变量的输入和输出
*/

# include <stdio.h>
# include <stdlib.h>
# include <string.h>

struct Student
{
	int age;
	char sex;
	char name[100];
};

void InputStudent(struct Student *);
void OutputStudent(struct Student);

int main()
{
	struct Student st;

	InputStudent(&st); //对结构体变量输入 必须发送st的地址
	OutputStudent(st); //对结构体变量输出

	system("pause");

	return 0;
}

void InputStudent(struct Student * pstu)
{
	(*pstu).age = 10;
	strcpy_s(pstu->name, "张三");
	pstu->sex = 'F';

	return;
}

void OutputStudent(struct Student stu)
{
	printf("%d %s %c\n", stu.age, stu.name, stu.sex);
	//printf("%d %c\n", stu.age, stu.sex);

	return;
}