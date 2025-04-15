#include "polynomial.h"
#include <iostream>
#include "absolute.h"
Polynomial::Polynomial(PolyNode* header) :m_head(header)
{
}

Polynomial::Polynomial()
{
	m_head = nullptr;
}

Polynomial::~Polynomial()
{
	PolyNode* current = m_head;
	while (current) {
		PolyNode* next = current->getNext();
		delete current;
		current = next;
	}
}

void Polynomial::addTerm(int expo, double coef)
{
	if (isEmpty()) {
		m_head = new PolyNode(expo, coef);
		return;
	}

	PolyNode* before = m_head;
	PolyNode* current = before->getNext();
	while (before->getNext() != nullptr)
	{
		before = before->getNext();
	}
	before->setNext(new PolyNode(expo, coef));
}

void Polynomial::delTerm(int expo)
{
	if (isEmpty()) return;
	
	if (m_head->getExponent() == expo) {
		PolyNode* temp = m_head;
		m_head = m_head->getNext();
		delete temp;
		return;
	}

	PolyNode* before = m_head;
	PolyNode* current = before->getNext(); //target is current
	while (current)
	{
		if (current->getExponent() == expo) {
			before->setNext(current->getNext());
			delete current;
			return;
		}
		before = current;
		current = before->getNext();
	}
}

PolyNode* Polynomial::searchTerm(int expo)
{
	if (isEmpty()) {
		return nullptr;
	}
	PolyNode* current = m_head;
	while (current)
	{
		if (current->getExponent() == expo) {
			return current;
		}
		current = current->getNext();
	}
	return nullptr;
}

void Polynomial::setTerm(int expo, double new_coef)
{
	if (isEmpty()) return;

	PolyNode* target = searchTerm(expo);

	if (target) {
		target->setCoefficient(new_coef);
		return;
	}
	return;
}

double Polynomial::substitute(double value)
{
	double result = 0;

	PolyNode* current = m_head;
	while (current)
	{
		result += current->substitute(value);
		current = current->getNext();
	}
	return result;
}

bool Polynomial::isEmpty() const
{
	return m_head == nullptr;
}

void Polynomial::print()
{
	if (isEmpty()) {
		std::cout << "empty\n";
		return;
	}
	PolyNode* current = m_head;
	current->print();

	while (current->getNext())
	{
		current = current->getNext();
		current->print();
	}
	std::cout << "\n";
}
