#include <iostream>
#include "polynomial_node.h"
#include "polynomial.h"
#include "queue.h"
#include "find_functions.h"

#define STEPS 0.00001

int main(void) {

	Polynomial p1;
	p1.addTerm(4, 6.7);
	p1.addTerm(3, 3.2);
	p1.addTerm(2, -1);
	p1.addTerm(1, 1);
	p1.addTerm(0, -2);
	p1.print();

	double k = findMin(-10, 10, STEPS, &p1);
	std::cout <<"Min: x = " << k << " y = " << p1.substitute(k) << "\n";
	//과제 1
	Queue* sols;
	sols = findSol(-10, 10, STEPS, &p1);
	double value = sols->dequeue();
	while (value != -123456)
	{
		std::cout << value << " ";
		value = sols->dequeue();
	}
	delete(sols);

	//과제 2
	std::cout << "\n\n";
	
	std::cout << "p2 = ";
	Polynomial p2;
	p2.addTerm(7, 1);
	p2.addTerm(2, 1);
	p2.print();
	std::cout << "p3 = ";
	Polynomial p3;
	p3.addTerm(9, 1);
	p3.addTerm(5, 1);
	p3.print();
	std::cout << "p4 = ";
	Polynomial p4;
	p4.addTerm(7, 1);
	p4.addTerm(2, 1);
	p4.print();
	std::cout << "p2 + p3 = ";
	p2 + p3;
	p2.print();
	std::cout << "p3 - p4 = ";
	p3 - p4;
	p3.print();

	return 0;
}