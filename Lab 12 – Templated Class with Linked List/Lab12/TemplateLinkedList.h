#pragma once
#include <iostream>

template<typename T>

class LinkedList {
public:
	LinkedList();
	~LinkedList();
	LinkedList(const LinkedList & list);
	LinkedList& operator=(const LinkedList& list);
	void InsertAtHead(T val);
	void Print();
	bool IsEmpty();
	T PeekHead();
	T RemoveHead();

private:
	struct Node
	{
		T value;
		Node* next;
	};
	Node * head;
	void helper(LinkedList list, Node* current);
	
};

template<typename T>
LinkedList<T>::LinkedList() {
	head = NULL;
}




template<typename T>
inline void LinkedList<T>::InsertAtHead(T val)
{
	if (head == NULL) {
		head = new Node{ val, NULL };
		return;
	}
	Node* newNode = new Node{ val, head };
	head = newNode;
}

template<typename T>
inline void LinkedList<T>::Print()
{
	Node* temp = head;
	for (; temp; temp = temp->next) {
		std::cout << temp->value << " ";
	}
}



template<typename T>
inline LinkedList<T>::~LinkedList()
{
	while(head) {
		Node* temp = head->next;
		delete head;
		head = temp;
	}
}



template<typename T>
inline bool LinkedList<T>::IsEmpty()
{
	return !head;
}

template<typename T>
inline T LinkedList<T>::RemoveHead()
{
	if (IsEmpty()) {
		return 0;
	}
	Node* temp = head;
	head = head->next;
	T val = temp->value;
	delete temp;
	return val;
}

template<typename T>
inline T LinkedList<T>::PeekHead()
{
	return head->value;
}


template<typename T>
inline void LinkedList<T>::helper(LinkedList list, Node * current)
{
	if (current == NULL) {
		list.InsertAtHead(current->value);
	}
	helper(list, current->next);
	list.InsertAtHead(current->value);
}

template<typename T>
inline LinkedList<T>::LinkedList(const LinkedList & list)
{
	Node* temp = list.head;
	int count = 0;
	while (temp) {
		count++;
		temp = temp->next;
	}
	
	
	for (int i = count - 1; i >= 0; i--) {
		temp = list.head;
		for (int j = 0; j < i; j++) {
			temp = temp->next;
		}
		InsertAtHead(temp->value);
	}
	
}



template<typename T>
inline LinkedList<T> & LinkedList<T>::operator=(const LinkedList<T> & list)
{
	if (&list == this) {
		return *this;
	}
	Node* tempDel = this->head;
	while (tempDel) {
		Node* delNode = tempDel;
		tempDel = tempDel->next;
		delete delNode;
	}
	Node* temp = list.head;
	int count = 0;
	while (temp) {
		count++;
		temp = temp->next;
	}


	for (int i = count - 1; i >= 0; i--) {
		temp = list.head;
		for (int j = 0; j < i; j++) {
			temp = temp->next;
		}
		InsertAtHead(temp->value);
	}
	return *this;
}