#include <iostream>
#include <vector>

void print_solution(int n, int tracks, std::vector<int> ts);
void minimizeUnused(int n, int tracks, std::vector<int> ts);
int get_sum(std::vector<int> tracks, int start_idx);

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
		
		for (int i{0}; i < track; i++) {
			int duration{0};
	
			std::cin >> duration;
			t.at(i) = duration;
		}

		get_sum(t, 0);

		// print_solution(n, track, t);
		counter++;	
	}	
}

void print_solution(int n, int tracks, std::vector<int> ts) {
	std::vector<int> result(ts.size());

}
// 1. Result is list of indices that is an actual solution
// 2. 
//
// just print the sum of all combination!!!
int get_sum(std::vector<int> tracks, int start_idx) {
	if (start_idx == tracks.size()) {
		return 0;
	}
	for (int i{start_idx}; i < tracks.size(); i++) {
		std::cout << tracks.at(i) << " ";
		int sum_below{ get_sum(tracks, i+1) };
		std::cout << ":" << tracks.at(i) + sum_below << "\n";
	}
	return 0;
}	
