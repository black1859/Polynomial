#include "node.h"

Node::Node(double v, Node* next) : m_value(v), m_next(next) 
{

}

Node::Node(double v) : m_value(v)
{
	m_next = nullptr;
}

Node* Node::getNext()
{
	return m_next;
}

double Node::getValue()
{
	return m_value;
}

void Node::setNext(Node* other)
{
	m_next = other;
}

Node::~Node()
{
}
