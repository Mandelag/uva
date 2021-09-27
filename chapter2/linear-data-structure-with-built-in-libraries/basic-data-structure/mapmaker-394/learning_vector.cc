#include <iostream>
#include <vector>

int main() {
	std::vector<int> V(0);
	V.resize(100);
	V.resize(60);
	std::cout << V.size() << " " << V.at(50) << " " << V.capacity() << std::endl;
}
