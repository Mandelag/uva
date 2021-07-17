#include <iostream>
#include <vector>
#include <stack>

bool print_solution(std::stack<int>& solution, int& sum, std::vector<int> track, int idx, int n);
void printStack(std::stack<int> some_stack);
int sumStack(std::stack<int> some_stack);

int main() {
	int counter{0};
	
	while (true) {
		int n{0};
		int track{0};

		std::istream& stream = std::cin >> n >> track;
		if (stream.eof()) {
			break;	
		}
		
		std::vector<int> t(track);
		std::stack<int> solution;

		for (int i{0}; i < track; i++) {
			int duration{0};
	
			std::cin >> duration;
			t.at(i) = duration;
		}
	
		int sum{0};
		print_solution(solution, sum, t, 0, n);
		// std::cout << "Final solution: ";
		
		printStack(solution);
		std::cout << "sum:" << sumStack(solution) << "\n";

		// print_solution(n, track, t);
		counter++;	
	}	
}

bool print_solution(std::stack<int>& solution, int& sum, std::vector<int> track, int idx, int n) { 
	// count current sum from solution
	if (idx >= track.size()) {
		return true;
	}

	solution.push(track.at(idx));
	
	if (sumStack(solution) > n) {
		return false;
	}

	for(int i{idx + 1}; i < track.size(); i++) {
		bool solutionFound{print_solution(solution, sum, track, i, n)};
		if (solutionFound) {
			// printStack(solution);
			// std::cout << "\n";
		} else {
			solution.pop();
		}
	}
	// std::cout << "\n";

	return true;	
}


void printStack(std::stack<int> some_stack) {
	if (some_stack.empty()) {
		return;
	}
	int val = some_stack.top();
	some_stack.pop();
	printStack(some_stack);
	std::cout << val << " ";
	some_stack.push(val);
}

int sumStack(std::stack<int> some_stack) {
	if (some_stack.empty()) {
		return 0;
	}
	
	int val = some_stack.top();
	some_stack.pop();

	int sum = val + sumStack(some_stack);
	
	some_stack.push(val);

	return sum;
}

