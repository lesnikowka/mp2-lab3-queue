#include <algorithm>

const int start_capacity = 5;
template <class T>
class TQueue {
	T* pMem;
	int first, last;
	int capacity, count_;

	void resize() {
		T* tmp = new T[capacity * 2];
		std::copy(pMem, pMem + capacity, tmp);

		capacity *= 2;

		delete[] pMem;
		pMem = tmp;
	}

	void recomposing() {
		T* tmp = new T[capacity * 2];

		for (int i = first; i < capacity; i++) 
			tmp[i - first] = pMem[i];
		
		for (int i = 0; i < last; i++) 
			tmp[i + capacity - first] = pMem[i];
		
		last = count_; first = 0; capacity *= 2;

		delete[] pMem;
		pMem = tmp;
	}
public:

	TQueue() {
		pMem = new T[start_capacity];

		first = -1; last = -1; count_ = 0;
		capacity = start_capacity;
	}

	~TQueue() {
		delete[] pMem;
	}

	TQueue(const TQueue<T>& q) {
		first = q.first; last = q.last; count_ = q.count_;
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

		if (count_ == capacity) {
			if (last == first) recomposing();
			else resize();
			last = count_ - 1;
		}

		else if (last == capacity)  
			last = -1;
		
		pMem[++last] = elem;

		count_++;
		if (first == -1) first = 0;
	}

	const T& pop() {
		if (empty()) throw "queue is empty";

		int first_ = first;
		count_--;

		if (first == capacity - 1) first = 0;
		else first++;
		
		if (empty()) first = last = -1;

		return pMem[first_];
	}

	bool empty() const noexcept { return count_ == 0; }
	
	int count() const noexcept { return count_; }
};