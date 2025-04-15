#pragma once

class Node
{
public:
	Node(double v, Node* next);
	Node(double v);

	Node* getNext();
	double getValue();
	void setNext(Node* other);

	~Node();	//Nothing
private:
	double m_value;
	Node* m_next;
};
