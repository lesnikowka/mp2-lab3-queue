#include <algorithm>
#pragma once

const int start_capacity = 5;
template <class T>
class TQueue {
	T* pMem;
	int first, last, capacity;

	void recomposing() {
		T* tmp = new T[capacity * 2];

		for (int i = first; i < count(); i++) 
			tmp[i - first] = pMem[i];
		if (first == last + 1) {
			for (int i = 0; i <= last; i++)
				tmp[i + capacity - first] = pMem[i];
			last = count() - 1;
			first = 0;
		}
		capacity *= 2;

		delete[] pMem;
		pMem = tmp;
	}
public:

	TQueue() {
		pMem = new T[start_capacity];

		first = -1; last = -1;
		capacity = start_capacity;
	}

	~TQueue() {
		delete[] pMem;
	}

	TQueue(const TQueue<T>& q) {
		first = q.first; last = q.last;
		capacity = q.capacity;

		pMem = new T[capacity];

		std::copy(q.pMem, q.pMem + capacity, pMem);
	}

	TQueue<T>& operator=(const TQueue<T> q) {
		if (this != &q) {
			first = q.first; last = q.last;

			if (capacity != q.capacity) {
				delete[] pMem;
				capacity = q.capacity;
				pMem = new T[capacity];
			}

			std::copy(q.pMem, q.pMem + capacity, pMem);
		}

		return *this;
	}

	void push(const T& elem) {
		if (count() == capacity) recomposing();

		pMem[++last] = elem;
		first += int(first == -1);
		
	}

	T pop() {
		if (empty()) throw "queue is empty";

		int firstEl = first;

		if (first == last) first = last = -1;
		else if(first == capacity - 1) first = 0;
		else first++;

		return pMem[firstEl];

	}

	bool empty() const noexcept { return first == -1; }
	
	int count() const noexcept { 
		if (empty()) return 0;
		else if (last >= first) return last - first + 1;
		else return capacity - first + last + 1;
	}
};