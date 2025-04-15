#pragma once

#define UNKNOWN_C -123456

class PolyNode
{
public:
	PolyNode(int expo, double coef, PolyNode* next);
	PolyNode(int expo, double coef);
	~PolyNode();

	PolyNode* getNext();
	int getExponent();
	double getCoefficient();
	void setNext(PolyNode* other);
	void setExponent(int e);
	void setCoefficient(double c);

	bool differentiate(); // return fasle when coef == 0
	void integrate();
	double substitute(double value);

	bool isZero();
	void print();
	PolyNode* copy();
private:
	PolyNode* m_next;
	int exponent;
	double coefficient;
};