#pragma once
#include "polynomial_node.h"

class Polynomial
{
public:
	Polynomial(PolyNode* header);
	Polynomial();

	~Polynomial();

	void addTerm(int expo, double coef);
	void delTerm(int expo);
	PolyNode* searchTerm(int expo);

	
	void setTerm(int expo, double new_coef);

	void differentiate();
	void integrate();
	double substitute(double value);

	bool isEmpty() const;
	void print();
private:
	PolyNode* m_head;
};

