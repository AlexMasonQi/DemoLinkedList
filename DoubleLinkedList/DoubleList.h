#pragma once
#include <iostream>
#include <string>
using namespace std;

class DoubleList
{
public:
	DoubleList();
	DoubleList(int data, string str);
	~DoubleList();

	int getIndex();
	void setIndex(int index);
	int getData();
	void setData(int data);
	string getStr();
	void setStr(string str);
	DoubleList* getPre();
	void setPre(DoubleList *pre);
	DoubleList* getNext();
	void setDoubleList(DoubleList *next);

public:
	//add a node
	friend bool addNode(DoubleList *&address, int data, string str);
	//get length of the list
	friend int getSize(DoubleList *address);
	//traverse the list
	friend void traverseList(DoubleList *address);
	//get a node from index
	friend DoubleList* getNode(DoubleList *address, int index);
	//delete the node from index
	friend bool remove(DoubleList *&head, int index);
	//clear the list
	friend int removeAll(DoubleList *&head);

private:
	int index;
	int data;
	string str;
	DoubleList *pre;
	DoubleList *next;
};

