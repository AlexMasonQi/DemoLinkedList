#include <iostream>
#include <string>
#include "DoubleList.h"
using namespace std;

int main()
{
	DoubleList test(1, "p001");
	cout << &test << endl;
	test.addNode(10,"p002");
	
	system("pause");
	return 0;
}