#include <iostream>
#include "polynomial_node.h"
#include "polynomial.h"
#include "queue.h"

#define STEPS 0.00001
#define PLUS true
#define MINUS false

Queue* findSol(int a, int b, double steps, Polynomial* p) {
	double value = p->substitute(a);
	bool sign_bit = 0;
	if (value > 0) {
		sign_bit = PLUS;
	}
	else if (value < 0) {
		sign_bit = MINUS;
	}

	Queue* results = new Queue();

	double x = a;
	while (x <= b) {
		value = p->substitute(a);
		if ((value < 0) && sign_bit == PLUS) {
			results->enqueue(x);
			sign_bit = MINUS;
		}
		else if ((value > 0) && sign_bit == MINUS) {
			results->enqueue(x);
			sign_bit = PLUS;
		}
		else if (value == 0)
		{
			results->enqueue(x);
			sign_bit = not sign_bit;
		}
		 x += steps;
	}

	return results;
}

double findMin(int a, int b, double steps, Polynomial* p) {
	double approximation = p->substitute(a);
	double result_x = a;

	double x = a;
	while (x <= b) {
		x += steps;
		double value = p->substitute(x);
		if (value < approximation) {
			approximation = value;
			result_x = x;
		}
	}
	return result_x;
}

int main(void) {
	Queue* sols;

	Polynomial p1;
	p1.addTerm(4, 6.7);
	p1.addTerm(3, 3.2);
	p1.addTerm(2, -1);
	p1.addTerm(1, 1);
	p1.addTerm(0, -2);
	p1.print();

	double k = findMin(-10, 10, STEPS, &p1);
	std::cout <<"Min: x = " << k << " y = " << p1.substitute(k) << "\n";
	
	sols = findSol(-10, 10, STEPS, &p1);
	double value = sols->dequeue();

	while (value != -123456)
	{
		std::cout << value << " ";
		value = sols->dequeue();
	}

	delete(sols);
	return 0;
}