

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
		last = size - 1;
		first = 0;
		delete[] pMem;
		pMem = tmp;
	}
public:
	TQueue() {
		pMem = new T[start_capacity];
		first = 0;
		last = 0;
		count = 0;
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
		
		if (size == capacity) {
			if (last == first - 1) recomposing();
			else resize();
		}
		else if (last == capacity - 1) last = -1;
		
		pMem[++last] = elem;
		size++;
	}
	const T& pop() {
		if (empty()) throw std::logic_error("queue is empty");
		first++;
		size--;
		if (empty()) first = last = 0;
	}
	bool empty() const { return size == 0; }
};