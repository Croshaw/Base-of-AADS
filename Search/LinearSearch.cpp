#include <string>
using namespace std;

class LinearSearch
{
private:
	int* array;
	int size;
	int iterations;
public:
	LinearSearch(int* array, int size)
	{
		this->array = array;
		this->size = size;
		this->iterations = 0;
	}

	int search(int element)
	{
		iterations = 0;
		for (int i = 0; i < size; i++)
		{
			iterations++;
			if (array[i] == element)
				return i;
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