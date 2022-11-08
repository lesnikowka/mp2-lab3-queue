

const size_t start_capacity = 10;
template <class T>
class TQueue {
	T* pMem;
	size_t first, last;
	size_t capacity;
	bool first_using;
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
		last = capacity - first + last - 1;
		first = 0;
		delete[] pMem;
		pMem = tmp;
	}
public:
	TQueue() {
		pMem = new T[start_capacity];
		first = 0;
		last = 0;
		first_using = true;
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
		if (first_using) {
			pMem[last++] = elem;
		}
		else {
			if (first == 0 && last == capacity) {
				resize();
			}
			else {
				recomposing();
			}
		}
	}
	const T& pop() {
		
	}
};