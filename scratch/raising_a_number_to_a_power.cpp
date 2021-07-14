#include <iostream>

double exponential(int n, int m);

int main() {
	// basically we wants to n power of m in iterative way
	
	std::cout << std::fixed << exponential(2, -2) << "\n";
}

double exponential(int n, int m) {
	// base case
	if (n == 0) {
		return 0;
	}
	if (m == 0) {
		return 1;
	} else if (m == 1) {
		return n;
	} else if (m == -1) {
		return  double(1)/n;
	}

	// recursive case
	double e{exponential(n, m/2)};
	
	if (m % 2 == 0) {
		return e * e;
	}
	
	return e * e * n;
	
}
