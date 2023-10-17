#include <string>
using namespace std;

class BinarySearch
{
private:
	int* array;
	int size;
	int iterations;
public:
	BinarySearch(int* array, int size)
	{
		this->array = array;
		this->size = size;
		this->iterations = 0;
	}

	int search(int element)
	{
		iterations = 0;
		int firstIndex = 0;
		int lastIndex = size - 1;
		while (firstIndex <= lastIndex) {
			iterations++;
			int middleIndex = (firstIndex+lastIndex) / 2;
			int middleElement = array[middleIndex];
			if (array[middleIndex] == element)
				return middleIndex;
			else if (array[middleIndex] < element)
				firstIndex = middleIndex + 1;
			else if (array[middleIndex] > element)
				lastIndex = middleIndex - 1;
		}
		return -1;
	}
	
	int getIterations()
	{
		return iterations;
	}

	string getResult(int element)
	{
		int index = search(element);
		return "Element " + to_string(element) + (index != -1 ? " was found at index " + to_string(index) : " not found") + "\nIterations: " + to_string(getIterations());
	}
};