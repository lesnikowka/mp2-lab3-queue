#pragma once
#include <iostream>

template <class T>
class vector {
	T* data;
	size_t size;
	size_t capacity;

	friend std::ostream& operator<< (std::ostream& out, const vector& v) {
		out << "(";
		for (size_t i = 0; i < v.size; i++)
			out << v.data[i] << "  ";
		out << ")" << std::endl;
		return out;
	}

public:
	vector(size_t capacity = 0) {
		if (capacity < 0) throw std::logic_error("size cannot be less than 0");
		size = 0;
		this->capacity = capacity;
		data = new T[capacity];
		for (size_t i = 0; i < capacity; i++)
			data[i] = 0;
	}

	vector(const vector& v) {
		resize(v.size);
		data = new T[capacity];

		for (size_t i = 0; i < size; i++)
			data[i] = v.data[i];
	}

	 ~vector() {
		size = 0;
		capacity = 0;
		delete[] data;
	}

	void resize(size_t newSize) {

		if (capacity > newSize)
			size = newSize;

		else {
			capacity = (newSize + 1) * 2;
			T* tempdata = new T[capacity];
			for (size_t i = 0; i < capacity; i++) {
				if (i < size)
					tempdata[i] = data[i];
				else
					tempdata[i] = 0;
			}
			size = newSize;
			delete[] data;
			data = tempdata;
		}
	}

	size_t getsize() {
		return size;
	}

	void push_back(T element) {

		if (capacity < size + 1)
			resize(size + 1);
		else
			size++;
		data[size - 1] = element;

	}

	T pop_back() {
		if (size == 0) throw std::logic_error("vector is empty");

		T tmp = data[size];
		size--;
		return tmp;
	}

	vector&  operator=(const vector& v) {
		if (&v == this)
			return *this;
		
		if (capacity != v.capacity) {
			delete[] data;
			data = new T[v.capacity];
			capacity = v.capacity;
		}
		size = v.size;
		std::copy(v.data, v.data + capacity, data);

		return *this;
	}

	T erase(size_t index) {
		T tmp = data[index];
		for (size_t i = index; i < size - 1; i++)
			data[i] = data[i + 1];
		size--;
		return tmp;
	}

	void insert(T element, size_t index) {
		resize(size + 1);
		for (size_t i = size - 1; i > index; i--)
			data[i] = data[i - 1];
		data[index] = element;
	}

	const T& operator[](size_t index) const {
		return data[index];
	}

	T& operator[](size_t index) {
		return data[index];
	}
};