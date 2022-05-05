#pragma once

#ifndef ARRAY_H
#define ARRAY_H

#include <iostream>
#include <string>
#include <iomanip>
#include <cstdlib>
#include "defs.h"

using namespace std;

template<class T>
class Array {

public:
	//constructor
	Array() {

		//elements = new T[MAX_ARR];
		elements = (T*)malloc(MAX_ARR * sizeof(T));
		size = 0;

	}

	T& operator[](int iter) {
		return  *(elements + iter);
	}

	const T& operator[](int iter) const {
		return  *(elements + iter);
	}

	//destructor
	~Array() {
		//free(elements);
		//elements;
		size = 0;
	}

	//other
	void add(const T& nVar) {
		if (size >= MAX_ARR)return;
		elements[size++] = nVar;
	}

	T get(int index) {
		if (index < 0 || index >= size) {
			cerr << "Array index out of bounds" << endl;
			exit(1);
		}
		return elements[index];
	}
	int getSize() {
		return size;
	}
	bool isFull() {
		return size >= MAX_ARR;
	}

private:
	int size;
	T* elements;

};
#endif

/*template<typename T>
ostream& operator<<(ostream& out, T& nTmp) {
	return out << nTmp << endl;
}*/
