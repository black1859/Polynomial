#pragma once
#include "node.h"
#define NONE -123456

//FIFO first in first out
class Queue
{
public:
	Queue();
	~Queue();

	bool isEmpty();
	void enqueue(int value);
	double dequeue();

private:
	Node* m_head;
	Node* m_tail;
};

/* test this code in main
	std::cout << "\nqueue example\n[1,2,3] + 4\n";
	Queue q1;
	q1.enqueue(1);
	q1.enqueue(2);
	q1.enqueue(3);
	std::cout << q1.dequeue() << "\n";
	std::cout << q1.dequeue() << "\n";
	q1.enqueue(4);
	std::cout << q1.dequeue() << "\n";
	std::cout << q1.dequeue() << "\n";
*/