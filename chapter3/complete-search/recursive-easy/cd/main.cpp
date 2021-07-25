#include <iostream>
#include <vector>
#include <deque>


void find_solution(std::deque<int>& tmp, std::deque<int>& result, std::vector<int> track, int idx, int n); 
void printDeque(std::deque<int>& deque);
int sumDeque(std::deque<int>& deque);
void copyDeque(std::deque<int>& origin, std::deque<int>& destination);

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
		std::deque<int> tmp(track);
		std::deque<int> result(track);



		for (int i{0}; i < track; i++) {
			int duration{0};
	
			std::cin >> duration;
			t.at(i) = duration;
		}
	

		find_solution(tmp, result, t, 0, n);

		// std::cout << "Final solution: ";
		
		printDeque(result);
		std::cout << "sum:" << sumDeque(result) << "\n";

		// print_solution(n, track, t);
		counter++;	
	}	
}

void find_solution(std::deque<int>& tmp, std::deque<int>& result, std::vector<int> track, int idx, int n) {
	int sum_tmp{ sumDeque(tmp) };
	
	if (sum_tmp > n) {
		return;
	}	

	
	int sum_result { sumDeque(result) };
	
	if (idx >= track.size()) {
		int delta_tmp = n - sum_tmp;
		int delta_result = n - sum_result;
		if (delta_tmp < delta_result) {
			copyDeque(tmp, result);
		}
		// printDeque(tmp);
		// std::cout << "hm\n";
		return;
	}


	find_solution(tmp, result, track, idx+1, n);
	if (sum_tmp + track.at(idx) <= n) {
		tmp.push_front(track.at(idx));
		find_solution(tmp, result, track, idx+1, n);
		tmp.pop_front();
	}

}


void printDeque(std::deque<int>& stack) {
	for (int i{0}; i< stack.size(); i++) {
		std::cout << stack.at(i) << " ";
	}
}

int sumDeque(std::deque<int>& stack) {
	int sum{0};
	
	for (int i{0}; i < stack.size(); i++) {
		sum += stack.at(i);
	}

	return sum;
}

void copyDeque(std::deque<int>& origin, std::deque<int>& dest) {
	dest.clear();
	dest.resize(0);
	for (int i{0}; i < origin.size(); i++) {
		if (origin.at(i) == 0) {
			continue;
		}
		dest.push_front(origin.at(i));
	}
}

