#pragma once
#include <iostream>
using namespace std;
template <typename T>
class MyQueue
{
private:
	T* array = nullptr;
	int capacity = 0;
	int sizeSt = 0;
public:
	MyQueue(int capacity) {
		this->capacity = capacity;
		array = new T[capacity];
	}
	~MyQueue() {
		delete[]array;
	}
	int size() {
		return sizeSt;
	}
	bool empty() {
		return !sizeSt;
	}
	void push(T value) {
		if (sizeSt < capacity) {
			sizeSt++;
			array[sizeSt - 1] = value;
		}
	}
	T pop() {
		if (sizeSt > 0) {
			T el = array[0];
			for (int i = 0; i < sizeSt; i++) {
				array[i] = array[i + 1];
			}
			sizeSt--;
			return el;
		}
		else return NULL;
	}
	MyQueue(MyQueue<T>& st) {
		this->capacity = st.capacity;
		this->sizeSt = st.sizeSt;
		this->array = new T[capacity];
		for (int i = 0; i < sizeSt; i++) {
			array[i] = st.array[i];
		}
	}
	T back() {
		if (sizeSt != 0) {
			return array[sizeSt - 1];
		}
		else return NULL;
	}
	T front() {
		if (sizeSt > 0) {
			return array[0];
		}
		else return NULL;
	}
};

