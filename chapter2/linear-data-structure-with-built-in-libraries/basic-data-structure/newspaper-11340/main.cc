#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <algorithm>

struct char_value {
	char c;
	int v;
};

// need to learn about this solution, since the debug test case all pased 
// but still get wrong answer 
// https://github.com/Sajed49/UVa-Problem-Solutions/blob/master/newspaper.cpp
int main() {
	int n;
	
	std::cin >> n;

	for (int i{0}; i < n ; i++ ) {
		int k;
		// its tempting to use array, but array value will not be set to 0
		// and can lead to incorrect calculation :(
		std::vector<int> values(256);
		int cents{0};


		std::vector<char_value> value2;
		value2.reserve(100);


		std::cin >> k;

		for (int j{0}; j < k ; j++) {
			char c;
			int value;
			
			std::cin >> c >> value;

			values[c] = value;
			value2.push_back({c: c, v: value}); 
		}

		int lines;
		
		std::cin >> lines;
	
		//for (const char_value& v : value2) {
		//std::cout << '{' << v.c << ", " << v.v << "}" << std::endl;
		//} 	

//		for (const int i : values) {
//			std::cout << i << ", ";
//		}

		std::string _;
		std::getline(std::cin, _); 

		// for (int j{0}; j < lines; j++ ) {
			// std::string line;
			// std::getline(std::cin, line);

			// for (const char c : line) {
		// 		cents += values[c];
		// 	}
		// }
		for (int j{0}; j < lines; j++ ) {
			std::string line;
			std::getline(std::cin, line);
			for (const char_value& c : value2) {

		//		std::cout << line << std::endl;
		//		std::cout << c.c << "," << c.v << " ";
				int count;
				count = std::count(line.begin(), line.end(), c.c); 

				cents += count * c.v;
			}
		//	std::cout << std::endl;
		}

		// std::cout.precision(2);
		double dollar{ cents / 100.0};
		std::cout << std::setprecision(2) << std::fixed << dollar << '$' << std::endl;
		
	}
}
