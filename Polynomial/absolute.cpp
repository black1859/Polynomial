#include "absolute.h"

double absolute(double value) {
	if (value < 0) return -1 * value;
	return value;
}
