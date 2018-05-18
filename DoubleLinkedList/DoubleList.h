#pragma once
#include <iostream>
#include <string>
#include <memory>
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
	DoubleList& getPre();
	void setPre(unique_ptr<DoubleList> &pre);
	DoubleList& getNext();
	void setDoubleList(unique_ptr<DoubleList> &next);

public:
	//add a node
	bool addNode(int data, string str);
	//get length of the list
	int getSize();
	//traverse the list
	void traverseList();
	//get a node from index
	DoubleList& getNode(int index);
	//delete the node from index
	DoubleList& remove(int index);
	//clear the list
	void removeAll();

private:
	int index;
	int data;
	string str;
	unique_ptr<DoubleList> pre;
	unique_ptr<DoubleList> next;
};

