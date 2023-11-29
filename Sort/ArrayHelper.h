#pragma once
#include <stdlib.h>
class ArrayHelper
{
private:
	int _size;
	int* _array;
	int _min = 1;
	int _max = 99;
public:
	ArrayHelper(int size) {
		_size = size;
		_array = nullptr;
	}
	ArrayHelper(int size, int min, int max) {
		_size = size;
		_min = min;
		_max = max;
		_array = nullptr;
	}
	~ArrayHelper() {
		delete[] _array;
	}
	void resize(int newSize) {
		_size = newSize;
	}
	void generate() {
		if (_array != nullptr)
			delete[] _array;
		_array = new int[_size];
		srand(0);
		for(int i = 0; i < _size; i++)
			_array[i] = rand() % (_max - _min) + _min;
	}
	int* get() {
		if (_array == nullptr)
			generate();
		return _array;
	}
	int size() {
		return _size;
	}
	int* getCopyArray() {
		if (_array == nullptr)
			generate();
		int* copyArr = new int[_size];
		for (int i = 0; i < _size; i++)
			copyArr[i] = _array[i];
		return copyArr;
	}
};