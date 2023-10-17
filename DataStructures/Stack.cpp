template <class T>
class stack {
private:
	int count;
	int capacity;
	T* arr;
public:
	stack(int size)
	{
		capacity = size;
		arr = new T[capacity];
		count = 0;
	}
	~stack() {
		delete[] arr;
	}

	void push(T data) {
		if (isFull())
			return;
		arr[count] = data;
		count++;
	}

	T pop() {
		if (isEmpty())
			return -9999999;
		count--;
		return arr[count];
	}

	T peek() {
		if (isEmpty())
			return -9999999;
		return arr[count-1];
	}

	bool isEmpty() {
		return count == 0;
	}

	bool isFull() {
		return count == capacity;
	}

	int size() {
		return count;
	}
};