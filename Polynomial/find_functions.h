#pragma once

#include "queue.h"
#include "polynomial.h"

Queue* findSol(int a, int b, double steps, Polynomial* p);

double findMin(int a, int b, double steps, Polynomial* p);