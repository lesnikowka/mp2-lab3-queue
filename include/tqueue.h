

const size_t start_capacity = 10;
template <class T>
class TQueue {
	T* pMem;
	size_t first, last;
	size_t capacity;
	size_t count;
	void resize() {
		T* tmp = new T[capacity * 2];
		std::copy(pMem, pMem + capacity, tmp);
		capacity *= 2;
		delete[] pMem;
		pMem = tmp;
	}
	void recomposing() {
		T* tmp = new T[capacity * 2];
		for (int i = first; i < capacity; i++) {
			tmp[i - first] = pMem[i];
		}
		for (int i = 0; i < last; i++) {
			tmp[i + capacity - first] = pMem[i];
		}
		last = count - 1;
		first = 0;
		delete[] pMem;
		pMem = tmp;
	}
public:
	TQueue() {
		pMem = new T[start_capacity];
		first = -1;
		last = -1;
		count = 0;
		capacity = start_capacity;
	}
	~TQueue() {
		delete[] pMem;
	}
	TQueue(const TQueue& q) {
		first = q.first;
		last = q.last;
		if (capacity != q.capacity) {
			capacity = q.capacity;
			delete[] pMem;
			pMem = new T[capacity];
		}
		std::copy(q.pMem, q.pMem + capacity, pMem);
	}
	void push(const T& elem) {
		last++;

		if (count == capacity) {
			if (last == first) recomposing();
			else resize();
		}
		else if (last - 1 == capacity - 1) last = 0;
		
		if (first == -1) first++;
		pMem[last] = elem;
		count++;
	}
	const T& pop() {
		if (empty()) throw std::logic_error("queue is empty");

		int first_ = first;
		first++; count--;
		if (empty()) first = last = -1;

		return pMem[first_];
	}
	bool empty() const { return count == 0; }
};