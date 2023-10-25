#pragma once
template <typename T>
class MyStack
{
private:
	T* array = nullptr;
	int capacity = 0;
	int sizeSt = 0;
public:
	MyStack(int capacity) {
		this->capacity = capacity;
		array = new T[capacity];
	}
	~MyStack() {
		delete[]array;
	}
	T top() {
		return array[sizeSt];
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
			array[sizeSt] = value;
		}
	}
	T pop() {
		if (sizeSt > 0) {
			sizeSt--;
			return array[sizeSt];
		}
		else return 0;
	}
	MyStack(MyStack<T>& st) {
		this->capacity = st.capacity;
		this->sizeSt = st.sizeSt;
		this->array = new T[capacity];
		for (int i = 0; i < sizeSt; i++) {
			array[i] = st.array[i];
		}
	}
};

