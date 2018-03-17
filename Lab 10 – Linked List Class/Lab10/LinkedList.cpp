#include "LinkedList.h"
#include <stdio.h>
#include <iostream>
LinkedList::LinkedList()
{
	head = NULL;
}

void LinkedList::InsertAtHead(int v)
{
	if (!head) {
		head = new Node(v, NULL);
		
		return;
	}
	Node * insert = new Node(v, (*head).GetNext());
	(*head).SetNext(insert);
}

void LinkedList::PrintList()
{
	Node* temp = head;
	while (temp) {
		std::cout << (*temp).GetValue() << " ";
		temp = (*temp).GetNext();
	}
	std::cout << "\n";
}

void LinkedList::freeList()
{
	while (head) {
		Node* temp = head;
		head = (*head).GetNext();
		delete temp;
	}
}


