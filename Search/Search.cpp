#include <iostream>
#include<array>
#include "LinearSearch.cpp"
#include "BinarySearch.cpp"

using namespace std;

const int arrSize = 12;
const int startN = 1;
const int endN = 50;

void printArray(int* array, int size) {
	cout << "Array[" << to_string(size) << "] { ";
	for (int i = 0; i < size-1; i++)
		cout << array[i] << ", ";
	cout << array[size-1] << " }" << endl;
}

void fillArray(int* array, int size) {
	srand(time(0));
	for (int i = 0; i < size; i++)
		array[i] = (i != 0 ? array[i-1] : 0) + rand() % (endN - startN + 1) + startN;
}

int main()
{
	int* array = new int[arrSize];
	fillArray(array, arrSize);
	printArray(array, arrSize);

	int number;
	cout << "Enter number: ";
	cin >> number;
	cout << "-------------------Linear-------------------" << endl;
	LinearSearch linearSearch(array, arrSize);
	cout << linearSearch.getResult(number) << endl;

	cout << "-------------------Binary-------------------" << endl;
	BinarySearch binarySearch(array, arrSize);
	cout << binarySearch.getResult(number) << endl;

	delete[] array;
}