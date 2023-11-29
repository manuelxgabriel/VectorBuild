#include "MyVector.h"
#include <stdexcept>


MyVector::MyVector(int size) 
	: m_size(size), pItems{ size > 0 ? new double[size] : nullptr} {
	
	if (size < 0) {
		throw std::length_error("Enter a positive number");
	}

	//Initialize all item to 0
	for (int i = 0; i < size; i++) {
		pItems[i] = 0.0;
	}
	
}

MyVector::MyVector(const std::initializer_list<double>& list)
	: MyVector(static_cast<int>(list.size())) {

	// Now initialize our array from the list
	int count = 0;
	for (auto& element : list) {
		pItems[count] = element;
		count++;
	}
}

// Copy Constructor
MyVector::MyVector(const MyVector& otherVec)
	: MyVector(otherVec.m_size) {
	for (int i = 0; i < m_size; i++) {
		pItems[i] = otherVec.pItems[i];
	}
}

MyVector::~MyVector() {
	if (pItems != nullptr) {
		delete[] pItems;
	}
}

int MyVector::size() const {
	return m_size;
}

double MyVector::get(int index) const {
	if (index >= m_size || index < 0) {
		throw std::out_of_range("out of range - get()");
	}
	return pItems[index];
}

void MyVector::set(int index, double value) {
	if (index >= m_size || index < 0) {
		throw std::out_of_range("out of range - set()");
	}
	pItems[index] = value;
}

double& MyVector::operator[](int index) {
	if (index < 0 || index >= m_size) {
		throw std::out_of_range("Index out of range");
	}
	return pItems[index];
}


const double& MyVector::operator[](int index) const {
	if (index < 0 || index >= m_size) {
		throw std::out_of_range("Index out of range");
	}
	return pItems[index];
}



std::ostream& operator<<(std::ostream& out, const MyVector& v) {
	out << "[";
	for (int i = 0; i < v.size(); i++) {
		out << v.get(i);
		if (i < v.size() - 1) {
			out << ", ";
		}
	}
	out << "]";


	return out;
}


MyVector& MyVector::operator=(const MyVector& otherVec) {
	// check for self-assignment
	if (this == &otherVec) {
		return *this;
	}

	// delete currently allocated memory
	delete[] pItems;

	// Allocate new memory for pointer (as long as size > 0)
	m_size = otherVec.m_size;
	if (m_size > 0) {
		pItems = new double[m_size];

		// Copy Values into the newly allocated memory
		for (int i = 0; i < m_size; i++) {
			pItems[i] = otherVec.pItems[i];
		}
	}
	else {
		// If size == 0
		pItems = nullptr;
	}

	return *this;
}

