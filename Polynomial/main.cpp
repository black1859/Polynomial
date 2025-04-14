#include <iostream>
#include "polynomial_node.h"
#include "polynomial.h"
#include "absolute.h"

double findSol(int a, int b, double steps, Polynomial* p) {
	double approximation = absolute(p->substitute(a));
	double result = a;

	double x = a;
	while (x <= b) {
		 x += steps;
		double value = p->substitute(x);
		if (absolute(value) < approximation) {
			approximation = absolute(value);
			result = x;
		}
	}
	return result;
}

double findMin(int a, int b, double steps, Polynomial* p) {
	double approximation = absolute(p->substitute(a));
	double result = a;

	double x = a;
	while (x <= b) {
		x += steps;
		double value = p->substitute(x);
		if (absolute(value) < approximation) {
			approximation = absolute(value);
			result = x;
		}
	}
	return result;
}

int main(void) {

	Polynomial p1;
	p1.addTerm(4, 6.7);
	p1.addTerm(3, 3.2);
	p1.addTerm(2, -1);
	p1.addTerm(1, 1);
	p1.addTerm(0, -2);
	p1.print();

	double k = findSol(-10, 10, 0.00001, &p1);

	std::cout << k << " " << p1.substitute(k);

	return 0;
}