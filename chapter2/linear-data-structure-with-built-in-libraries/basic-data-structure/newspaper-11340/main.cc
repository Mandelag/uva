#include <iostream>
#include <vector>
#include <string>

int main() {
	int n;
	
	std::cin >> n;

	for (int i{0}; i < n ; i++ ) {
		int k;
		// its tempting to use array, but array value will not be set to 0
		// and can lead to incorrect calculation :(
		std::vector<int> values(256);
		int cents{0};

		std::cin >> k;

		for (int j{0}; j < k ; j++) {
			char c;
			int value;
			
			std::cin >> c >> value;

			values[c] = value;
		}

		int lines;
		
		std::cin >> lines;
		

		std::string _;
		std::getline(std::cin, _); 

		for (int j{0}; j < lines; j++ ) {
			std::string line;
			std::getline(std::cin, line);

			for (const char& c : line) {
				cents += values[c];
			}
		}

		std::cout.precision(2);
		float dollar{ cents / (float) 100};
		std::cout << std::fixed << dollar << "$" << std::endl;
		
	}
}
