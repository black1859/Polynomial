#include "polynomial_node.h"
#include <iostream>

PolyNode::PolyNode(int expo, double coef, PolyNode* next) : exponent(expo), coefficient(coef), m_next(next)
{
}

PolyNode::PolyNode(int expo, double coef): exponent(expo), coefficient(coef)
{
	m_next = nullptr;
}

PolyNode::~PolyNode()
{
}

PolyNode* PolyNode::getNext()
{
	return m_next;
}

int PolyNode::getExponent()
{
	return exponent;
}

double PolyNode::getCoefficient()
{
	return coefficient;
}

void PolyNode::setNext(PolyNode* other)
{
	m_next = other;
}

void PolyNode::setExponent(int e)
{
	exponent = e;
}

void PolyNode::setCoefficient(double c)
{
	coefficient = c;
}

bool PolyNode::differentiate()
{
	if (exponent) {
		coefficient *= exponent--;
		return true;
	}
	else { // case, differentiation of constant
		coefficient = 0;
		return false;
	}
}

void PolyNode::integrate()
{
	if (coefficient && exponent) {
		coefficient /= ++exponent;
		return;
	}
	exponent = 1;
	coefficient = UNKNOWN_C;
}

double PolyNode::substitute(double value)
{
	return coefficient * pow(value, exponent);
}

PolyNode PolyNode::operator+(PolyNode& other)
{
	if (this->exponent != other.getExponent()) exit(1);
	return PolyNode(this->exponent, this->coefficient + other.getCoefficient());
}

PolyNode PolyNode::operator-(PolyNode& other)
{
	if (this->exponent != other.getExponent()) exit(1);
	return PolyNode(this->exponent, this->coefficient - other.getCoefficient());
}

bool PolyNode::isZero()
{
	return coefficient == 0;
}

void PolyNode::print()
{
	if (coefficient > 0) std::cout << "+";
	std::cout << coefficient << "x^" << exponent<<" ";
}

PolyNode* PolyNode::copy()
{
	PolyNode* SelfCopy = new PolyNode(exponent, coefficient, m_next);
	return SelfCopy;
}
