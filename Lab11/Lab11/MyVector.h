#pragma once
#include "DebugNewOp.h"
#include <iostream>
#include <initializer_list>

class MyVector {
private:
	int m_size;
	double* pItems;
public:
	explicit MyVector(int size = 0); // default constructor
	MyVector(const std::initializer_list<double>& list); // constructor with initialization list
	MyVector(const MyVector& otherVec); // copy constructor
	~MyVector();

	int size() const;
	double get(int index) const;
	void set(int index, double value);

	double& operator[](int index);
	const double& operator[](int index) const;

	MyVector& operator=(const MyVector& otherVec);

};

std::ostream& operator<<(std::ostream& out, const MyVector& vec);
