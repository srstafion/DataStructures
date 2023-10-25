#pragma once
template <typename T>
class DeQueue
{
private:
	T* array = nullptr;
	int capacity = 0;
	int sizeSt = 0;
public:
	DeQueue(int capacity) {
		this->capacity = capacity;
		array = new T[capacity];
	}
	~DeQueue() {
		delete[]array;
	}
	int size() {
		return sizeSt;
	}
	bool empty() {
		return !sizeSt;
	}
	void pushFront(T value) {
		if (sizeSt < capacity) {
			sizeSt++;
			array[sizeSt-1] = value;
		}
	}
	void pushBack(T value) {
		if (sizeSt > 0) {
			sizeSt++;
			for (int i = sizeSt-1; i > 0; i--) {
				array[i+1] = array[i];
			}
			array[sizeSt - 2] = array[sizeSt - 1];
			array[sizeSt - 1] = value;
		}
	}
	T popFront() {
		if (sizeSt > 0) {
			sizeSt--;
			return array[sizeSt];
		}
		else return 0;
	}
	T popBack() {
		if (sizeSt > 0) {
			sizeSt--;
			return array[0];
		}
	}
	DeQueue(DeQueue<T>& st) {
		this->capacity = st.capacity;
		this->sizeSt = st.sizeSt;
		this->array = new T[capacity];
		for (int i = 0; i < sizeSt; i++) {
			array[i] = st.array[i];
		}
	}
	T back() {
		if (sizeSt != 0) {
			return array[sizeSt-1];
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


