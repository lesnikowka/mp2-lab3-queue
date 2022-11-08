

const size_t start_capacity = 5;
template <class T>
class TQueue {
	T* pMem;
	size_t first, last;
	//size_t capacity;
	size_t count_;
	void resize() {
		T* tmp = new T[capacity * 2];
		std::copy(pMem, pMem + capacity, tmp);
		capacity *= 2;
		delete[] pMem;
		pMem = tmp;
	}
	void printarr() {
		for (int i = 0; i < capacity; i++) {
			std::cout << pMem[i] << ", ";
		}
		std::cout << std::endl;
	}
	void recomposing() {
		T* tmp = new T[capacity * 2];
		for (int i = first; i < capacity; i++) {
			tmp[i - first] = pMem[i];
		}
		for (int i = 0; i < last; i++) {
			tmp[i + capacity - first] = pMem[i];
		}
		last = count_;
		first = 0;
		delete[] pMem;
		pMem = tmp;
		capacity *= 2;
	}
public:
	size_t capacity;
	TQueue() {
		pMem = new T[start_capacity];
		first = -1;
		last = -1;
		count_ = 0;
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
		//std::cout <<"BEFORE PUSH:" << "FIRST = " << first << " LAST = " << last << std::endl;
		//printarr();

		//last++;

		if (count_ == capacity) {
			if (last == first) recomposing();
			else resize();
			last = count_ - 1;
		}
		else if (last == capacity) { 
			last = -1;
		}
		pMem[++last] = elem;

		count_++;
		if (first == -1) first++;


		//std::cout <<"AFTER PUSH" << "FIRST = " << first << " LAST = " << last << std::endl;
		//printarr();
		//std::cout << std::endl;
	}
	const T& pop() {
		if (empty()) throw std::logic_error("queue is empty");

		int first_ = first;
		count_--;

		if (first == capacity - 1) first = 0;
		else first++;
		
		if (empty()) first = last = -1;

		return pMem[first_];
	}
	bool empty() const noexcept { return count_ == 0; }
	
	size_t count() const noexcept { return count_; }
};