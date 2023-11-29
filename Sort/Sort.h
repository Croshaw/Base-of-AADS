#pragma once
#include <chrono>
class Sort
{
public:
	virtual void sort(int* array, int size) = 0;
	virtual int getComparisonsCount() = 0;
	virtual int getSwapCount() = 0;
	virtual long getDuration() = 0;
	void swap(int* array, int fIndex, int sIndex) {
		int temp = array[fIndex];
		array[fIndex] = array[sIndex];
		array[sIndex] = temp;
	}
};

