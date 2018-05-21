#include <iostream>
#include <string>
#include "DoubleList.h"
using namespace std;

int main()
{
	DoubleList *test = nullptr;
	addNode(test, 20, "p001");
	addNode(test, 21, "p002");
	addNode(test, 22, "p003");
	addNode(test, 23, "p004");

	int count = getSize(test);
	cout << "Length: " << count << endl;
	traverseList(test);

	cout << endl;
	cout << "index: " << getNode(test, 2)->getIndex() << ", data: " << getNode(test, 2)->getData() << ", str: " << getNode(test, 2)->getStr() << endl;
	cout << endl;

	/*bool tag = remove(test, 0);
	cout << boolalpha << tag << endl;
	traverseList(test);*/

	cout << endl;
	int deleteCount = removeAll(test);
	cout << deleteCount << endl;
	cout << test << endl;
	
	system("pause");
	return 0;
}