#pragma once
#include <iostream>
#include <mutex>
template <typename T>
class MyArray {
public:
	MyArray();
	MyArray(int size);
	~MyArray();
	MyArray(MyArray& other);
	MyArray& operator=(MyArray& other);
	T Get(int index) const;
	void Set(int index, T value);
	int Size() const;
	void Resize(int newSize);
	void PushBack(T value);
	T Back();
	T PopBack();
private:
	std::mutex changeStateLock;
	T * list;
	int size;
	int actualSize;
};

template<typename T>
inline MyArray<T>::MyArray()
{
	this->list = new T[20];
	size = 0;
	actualSize = 20;
}

template<typename T>
inline MyArray<T>::MyArray(int size)
{
	if (size > 20) {
		this->list = new T[size];
		actualSize = size;
	}
	else {
		this->list = new T[20];
		actualSize = 20;
	}
	
	this->size = size;
}

template<typename T>
inline MyArray<T>::~MyArray()
{
	delete[] list;
	list = nullptr;
	size = 0;
	actualSize = 0;
}

template<typename T>
inline MyArray<T>::MyArray(MyArray & other)
{
	size = other.size;
	actualSize = other.actualSize;
	list = new T[actualSize];
	for (int i = 0; i < size; i++) {
		list[i] = other.list[i];
	}
}

template<typename T>
inline MyArray<T> & MyArray<T>::operator=(MyArray & other)
{
	delete[] list;
	size = other.size;
	actualSize = other.actualSize;
	list = new T[actualSize];
	for (int i = 0; i < size; i++) {
		list[i] = other.list[i];
	}
	return *this;
}

template<typename T>
inline T MyArray<T>::Get(int index) const
{
	if (index > size) {
		return list[0];
	}
	return list[index];
}

template<typename T>
inline void MyArray<T>::Set(int index, T value)
{
	if (index > size) {
		return;
	}
	list[index] = value;
}

template<typename T>
inline int MyArray<T>::Size() const
{
	return size;
}

template<typename T>
inline void MyArray<T>::Resize(int newSize)
{
	if (newSize < actualSize) {
		size = newSize;
	}
	else {
		T* temp = new T[newSize];
		for (int i = 0; i < size; i++) {
			temp[i] = list[i];
		}
		actualSize = newSize;
		size = newSize;
		delete[] list;
		list = temp;
	}
}

template<typename T>
inline void MyArray<T>::PushBack(T value)
{
	
	if (size < actualSize) {
		list[size] = value;
		size++;
	}
	else {
	
		T* temp = new T[2 * actualSize];
		for (int i = 0; i < actualSize; i++) {
			temp[i] = list[i];
		}
		actualSize *= 2;
		delete[] list;
		list = temp;
		list[size] = value;
		size++;
	}
	
}

template<typename T>
inline T MyArray<T>::Back()
{
	if (size < 1) {
		return list[0];
	}
	return list[size - 1];
}

template<typename T>
inline T MyArray<T>::PopBack()
{
	
	if (size < 1) {
		return list[0];
	}
	size--;
	return list[size];
	
}


template<typename T>
std::ostream& operator<<(std::ostream& os, const MyArray<T>& a) {
	for (int i = 0; i < a.Size(); i++) {
		os << a.Get(i) << " ";
	}
	return os;
}
