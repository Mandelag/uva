#include <iostream>
#include <string>

int count_occurences(char c, std::string text, int index);

int main() {
	std::cout << count_occurences('h', "alamantap!", 0) << "\n"; 
}

int count_occurences(char c, std::string text, int index) {
	if (index >= text.size()) {
		return 0;
	}

	int count{0};
	if (c == text.at(index)) {
		count++;
	}

	return count + count_occurences(c, text, ++index);
}
