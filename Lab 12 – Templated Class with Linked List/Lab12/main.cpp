

#include <iostream>
#include "TemplateLinkedList.h"
#include <string>
#include <stdint.h>



int main(int argc, const char * argv[])
{
	{
		//Templated Linked List with uint64_t
		LinkedList<uint64_t> list;

		
		for (int i = 0; i < 10; i++) {
			list.InsertAtHead(i);
		}
		std::cout << "List 1: ";
		list.Print();
		LinkedList<uint64_t> list2(list);
		for (int i = 0; i < 10; i++) {
			list.RemoveHead();
		}
		std::cout << "\n" << "List 1: ";
		list.Print();
		std::cout << "\n" << "List 2: ";
		list2.Print();
		list = list2;
		std::cout << "\n" << "List 1: ";
		list.Print();
	}

	LinkedList<std::string> list;

	//Here adding into a string linked list 
	for (int i = 0; i < 10; i++) {
		list.InsertAtHead(std::to_string(i+1));
	}
	std::cout << "\nList 1: ";
	list.Print();
	LinkedList<std::string> list2(list);
	for (int i = 0; i < 10; i++) {
		list.RemoveHead();
	}
	std::cout << "\n" << "List 1: ";
	list.Print();
	std::cout << "\n" << "List 2: ";
	list2.Print();
	list = list2;
	std::cout << "\n" << "List 1: ";
	list.Print();





}
