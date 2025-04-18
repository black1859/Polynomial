#include "find_functions.h"

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
		value = p->substitute(x);
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