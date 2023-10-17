template <class T>
class queue {
private:
	int count;
	int capacity;
	T* arr;
	int rear;
	int front;
public:
	queue(int size = 1000)
	{
		capacity = size;
		arr = new T[capacity];
		count = 0;
		front = 0;
		rear = -1;
	}
	~queue() {
		delete[] arr;
	}

	void enqueue(T data) {
		if (isFull())
			return;
		rear = (rear + 1) % capacity;
		arr[rear] = data;
		count++;
	}

	T dequeue() {
		if (isEmpty())
			return -999999999;
		
		T x = arr[front];

		front = (front + 1) % capacity;
		count--;

		return x;
	}

	T peek() {
		return arr[front];
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