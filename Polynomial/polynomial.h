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

	//정렬이 되어있는 형태 및 겹치는 항이 없음을 가정
	void operator+(Polynomial& other);
	void operator-(Polynomial& other);

	PolyNode* getHead();
	void setTerm(int expo, double new_coef);

	double substitute(double value);

	bool isEmpty() const;
	void print();
private:
	PolyNode* m_head;
};

