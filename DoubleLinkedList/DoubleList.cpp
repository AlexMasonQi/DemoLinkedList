#include "DoubleList.h"

DoubleList::DoubleList()
{
}

DoubleList::DoubleList(int data, string str)
{
	this->index = 0;
	this->data = data;
	this->str = str;
	this->pre = nullptr;
	this->next = nullptr;
}


DoubleList::~DoubleList()
{
}

int DoubleList::getIndex()
{
	return index;
}

void DoubleList::setIndex(int index)
{
	this->index = index;
}

int DoubleList::getData()
{
	return data;
}

void DoubleList::setData(int data)
{
	this->data = data;
}

string DoubleList::getStr()
{
	return str;
}

void DoubleList::setStr(string str)
{
	this->str = str;
}

DoubleList* DoubleList::getPre()
{
	return pre;
}

void DoubleList::setPre(DoubleList * pre)
{
	this->pre = pre;
}

DoubleList* DoubleList::getNext()
{
	return next;
}

void DoubleList::setDoubleList(DoubleList * next)
{
	this->next = next;
}

//add a node
bool addNode(DoubleList *&address, int data, string str)
{
	bool result = false;
	int index = 1;
	DoubleList *temp = nullptr;
	
	//create a new node
	DoubleList *newNode = new DoubleList;
	newNode->index = 0;
	newNode->data = data;
	newNode->str = str;
	newNode->pre = nullptr;
	newNode->next = nullptr;

	if (address != nullptr)
	{
		temp = address;
		while (temp->next != nullptr)
		{
			index++;
			temp = temp->next;
		}
		temp->next = newNode;
		temp->next->index = index;
		newNode->pre = temp;
		result = true;
	}
	else
	{
		address = newNode;
		address->index = 0;
		address->data = data;
		address->str = str;
		address->pre = nullptr;
		address->next = nullptr;
		result = true;
	}
	

	return result;
}

//get size of list
int getSize(DoubleList *address)
{
	int totalCount = 0;
	DoubleList *temp = address;
	while (temp != nullptr)
	{
		totalCount++;
		temp = temp->next;
	}

	return totalCount;
}

//traverse list
void traverseList(DoubleList *address)
{
	DoubleList *temp = address;

	while (temp != nullptr)
	{
		cout << "{index: " << temp->index << ", data: " << temp->data << ", str: " << temp->str << endl;
		temp = temp->next;
	}
}

//get node from index
DoubleList * getNode(DoubleList *address, int index)
{
	DoubleList *temp = address;
	DoubleList *result = nullptr;
	if (index > getSize(address))
	{
		cout << "Index out of bounds exception!\n" << endl;
		return nullptr;
	}
	while (temp != nullptr)
	{
		if (temp->index == index)
		{
			result = temp;
			break;
		}
		temp = temp->next;
	}

	return result;
}

//remove a node from index
bool remove(DoubleList *&head, int index)
{
	bool result = false;
	if (index > getSize(head))
	{
		cout << "Index out of bounds exception!\n" << endl;
		return result;
	}
	DoubleList *temp = head;
	DoubleList *preNode = nullptr;
	
	//if remove head
	if (index == 0)
	{
		if (temp->next != nullptr)
		{
			preNode = head;
			head = head->next;
			head->pre = nullptr;
			delete preNode;
			result = true;
		}
		else
		{
			delete head;
			result = true;
		}
	}
	else
	{
		while (temp != nullptr)
		{
			if (temp->index == index)
			{
				preNode = temp->pre;
				preNode->next = temp->next;
				temp->next->pre = preNode;
				delete temp;
				result = true;
				break;
			}
			temp = temp->next;
		}
	}

	return result;
}

//clear the list
int removeAll(DoubleList *&head)
{
	int deleteCount = 0;
	DoubleList *preNode = head;
	while (head != nullptr)
	{
		preNode = head;
		head = head->next;
		delete preNode;
		deleteCount++;
	}
	
	return deleteCount;
}
