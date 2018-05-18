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
	return 0;
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

DoubleList& DoubleList::getPre()
{
	return *pre;
}

void DoubleList::setPre(unique_ptr<DoubleList> & pre)
{
	this->pre = move(pre);
}

DoubleList& DoubleList::getNext()
{
	return *next;
}

void DoubleList::setDoubleList(unique_ptr<DoubleList> & next)
{
	this->next = move(next);
}

bool DoubleList::addNode(int data, string str)
{
	bool result = false;
	unique_ptr<DoubleList> node(new DoubleList(data,str));
	if (node == nullptr)
	{
		cout << "error creating node!\n" << endl;
		return result;
	}
	node->pre = nullptr;
	node->next = nullptr;

	DoubleList preNode = *this;
	DoubleList temp = *this;
	int index = 1;

	while (temp->next != nullptr)
	{
		temp = temp->next;
		index++;
	}
	temp->next = node;
	node->pre = temp;
	temp->next->index = index;
	result = true;

	return result;
}

int DoubleList::getSize()
{
	int totalCount = 0;
	DoubleList *temp = this;
	while (temp != nullptr)
	{
		totalCount++;
		temp = temp->next;
	}

	return totalCount;
}

void DoubleList::traverseList()
{
	DoubleList *temp = this;

	while (temp != nullptr)
	{
		cout << "{index: " + temp->index << ", data: " + temp->data << ", str: " << temp->str << endl;
		temp = temp->next;
	}
}

DoubleList * DoubleList::getNode(int index)
{
	DoubleList *temp = this;
	DoubleList *result = nullptr;
	if (index > this->getSize())
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

DoubleList *DoubleList::remove(int index)
{
	if (index > this->getSize())
	{
		cout << "Index out of bounds exception!\n" << endl;
		return nullptr;
	}
	DoubleList *temp = this;
	unique_ptr<DoubleList> preNode(new DoubleList);
	
	//if remove head
	if (index == 0)
	{
		if (this->next = nullptr)
		{
		}
	}

	return nullptr;
}

void DoubleList::removeAll()
{
}
