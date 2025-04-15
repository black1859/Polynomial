#include "queue.h"

Queue::Queue(): m_head(nullptr), m_tail(nullptr)
{
}

Queue::~Queue()
{
	Node* current = m_head;
	while (current) {
		Node* next = current->getNext();
		delete current;
		current = next;
	}
}

bool Queue::isEmpty()
{
	return m_head == nullptr;
}

void Queue::enqueue(double value)
{
	if (isEmpty()) {
		m_head = new Node(value);
		m_tail = m_head;
		return;
	}

	m_tail->setNext(new Node(value));
	m_tail = m_tail->getNext();
}

double Queue::dequeue()
{
	if (isEmpty()) {
		return NONE;
	}
	Node* current = m_head;
	m_head = m_head->getNext();

	double value = current->getValue();
	delete current;
	return value;
}
