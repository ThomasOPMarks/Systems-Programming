#pragma once

#include <iostream>
#include <mutex>
using std::cout;
template <typename T>
class SharedQueue {
public:
	SharedQueue();
	~SharedQueue();

	/*
	These declarations mean that we do NOT get the automatically
	defined copy/copy-assign functions.  If you try to call one
	by copying the queue, you'll get a compiler error.

	This is a common technique for things that are uncopyable (like std::thread and std::mutex, for example).

	We really DO want a destructor, so cheating at the
	rule of 3 here makes sense here.
	*/
	SharedQueue(const SharedQueue<T>&) = delete;
	SharedQueue<T>& operator=(const SharedQueue<T>&) = delete;


	//Return true if the queue is empty
	bool IsEmpty() const;

	//Enqueue the next item at the tail of the queue.
	void Add(T value);

	//Dequeue the next queue element and store it in "item" variable.  The function returns false if the queue is empty and no item can be retrieved.
	bool Remove(T &item);
	void Print();
private:
	std::mutex queueLock;
	struct QueueItem {
		T value;
		QueueItem *next;
	};
	QueueItem* head;
	QueueItem* tail;
	//Fill in the The private data members.
};

//Fill in the function definitions


template<typename T>
inline SharedQueue<T>::SharedQueue()
{
	head = NULL;
	tail = NULL;
	//Print("Constructor ");
}

template<typename T>
inline SharedQueue<T>::~SharedQueue()
{
	QueueItem* temp;
	while (head) {
		temp = head;
		head = head->next;
		delete temp;
	}
	//Print("Deconstructor ");
}

template<typename T>
inline bool SharedQueue<T>::IsEmpty() const
{
	return !head;

}

template<typename T>
inline void SharedQueue<T>::Add(T value)
{
	QueueItem* newNode = new QueueItem();
	newNode->value = value;
	newNode->next = NULL;
	queueLock.lock();
	if (head) {
		tail->next = newNode;
		tail = tail->next;
	}
	else {
		head = new QueueItem();
		tail = head;
		head->value = value;
		tail->next = NULL;
	}
	queueLock.unlock();
	//Print("Add ");
}

template<typename T>
inline bool SharedQueue<T>::Remove(T & item)
{
	queueLock.lock();
	if (!head) {
		queueLock.unlock();
		return false;
	}
	QueueItem a = *head;
	QueueItem* temp = head;
	head = head->next;
	queueLock.unlock();
	delete temp;
	item = a.value;

	//Print("Remove ");
	return true;
}

template<typename T>
inline void SharedQueue<T>::Print()
{


	queueLock.lock();
	std::cout << "Printing: ";
	QueueItem* temp = head;
	while (temp)
	{
		std::cout << head->value << " ";
		temp = temp->next;
	}
	queueLock.unlock();
	std::cout << std::endl;
}
