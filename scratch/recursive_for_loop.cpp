// https://sites.fas.harvard.edu/~cscie119/lectures/recursion.pdf
// 
#include <iostream>

void for_loop(int n1, int n2); 
void mystery(int n);

int main() {
	for_loop(0, 100);	
	mystery(10);
}

void for_loop(int n1, int n2) {
	if (n1 == n2) {
		std::cout << n2 << "\n";
		return;
	} 

	std::cout << n1 << ", ";
	for_loop(n1 + 1, n2);
}


void mystery(int n) {
	if (n <= 0) {
		return;
	}
	std::cout << n << ", ";
	mystery(n - 1);
	std::cout << n << ", ";
}


