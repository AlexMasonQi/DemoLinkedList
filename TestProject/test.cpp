/*
	ʱ�䣺2018��9��9��
	Ŀ�ģ�ͨ��������ɶԽṹ���������������

	֪ʶ�㣺
	һ��ͨ��������ɶԽṹ���������������
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

	InputStudent(&st); //�Խṹ��������� ���뷢��st�ĵ�ַ
	OutputStudent(st); //�Խṹ��������

	system("pause");

	return 0;
}

void InputStudent(struct Student * pstu)
{
	(*pstu).age = 10;
	strcpy_s(pstu->name, "����");
	pstu->sex = 'F';

	return;
}

void OutputStudent(struct Student stu)
{
	printf("%d %s %c\n", stu.age, stu.name, stu.sex);
	//printf("%d %c\n", stu.age, stu.sex);

	return;
}