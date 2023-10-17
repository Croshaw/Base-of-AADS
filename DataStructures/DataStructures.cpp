#include <iostream>
#include "list.cpp"
#include "queue.cpp"
#include "stack.cpp"

void listShows()
{
    list<int> nums(45);
    nums.add(543);
    nums.add(123);
    nums.add(635);
    nums.add(432);
    nums.add(321);

    for (int i = 0; i < nums.count(); i++)
        std::cout << nums.get(i)->data << " ";
    std::cout << std::endl;
    nums.get(1)->data = 666;
    for (int i = 0; i < nums.count(); i++)
        std::cout << nums.get(i)->data << " ";
}

void queueShows() {
    queue<int> nums(10);
    nums.enqueue(1);
    nums.enqueue(2);
    nums.enqueue(3);
    nums.enqueue(4);
    nums.enqueue(5);
    nums.enqueue(6);
    nums.enqueue(8);
    nums.enqueue(9);
    nums.enqueue(10);
    while (nums.size() != 0) {
        std::cout << nums.dequeue() << " ";
    }
}

void stackShows() {
    stack<int> nums(10);
    nums.push(54);
    nums.push(93);
    nums.push(857);
    nums.push(52);
    nums.push(432);
    nums.push(123);
    while (nums.size() != 0) {
        std::cout << nums.pop() << " ";
    }
}

int main()
{
    stackShows();
}
