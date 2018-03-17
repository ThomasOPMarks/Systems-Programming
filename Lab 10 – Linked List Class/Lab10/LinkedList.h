#pragma once
#include "Node.h"


class LinkedList
{
public:
	LinkedList();
	void InsertAtHead(int v);
	void PrintList();
	void freeList();
private:
	Node * head;

private:

};


