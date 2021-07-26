#include <iostream>
#include <vector>
#include <map>

struct Domino{
	int left;
	int right;
};

// https://stackoverflow.com/questions/23239646/print-function-for-class-c @holt
std::ostream& operator<< (std::ostream &out, Domino const& data) {
	out << "(" << data.left << ", " << data.right << ")";
	return out;
}

void printVectorOfDominos(std::vector<Domino> vec) {
	for (int i{0}; i < vec.size(); i++) {
		std::cout << vec.at(i) << " ";
	}
	std::cout << std::endl;
}


bool allTaken(std::vector<bool> taken) {
	for (int i{0}; i < taken.size(); i++) {
		if (!taken.at(i)) {
			return false;
		}
	}
	return true;
}


bool findSolutionRecursive(Domino first, Domino last, std::vector<Domino> dominos, 
		std::map<int, std::vector<int>> index, 
		std::vector<bool> taken, int n, int m, int pos) {
	// base case
	// 0 -> actual first [1, n] 
	// if depth already reached 
	if (pos >= n) {
		
	}	

	return true;
}


bool findSolution(int n, int m, Domino first, Domino last, std::vector<Domino> dominos) {
	// build index first
	std::map<int, std::vector<int>> index;
	for(int i{0}; i < dominos.size(); i++) {
		index[dominos.at(i).left].push_back(i);
		if (dominos.at(i).left != dominos.at(i).right) {
			index[dominos.at(i).right].push_back(i);
		}
	}

	// build taken map
	std::vector<bool> taken;
	for (int i{0}; i < dominos.size(); i++) {
		taken.push_back(false);
	}

	return findSolutionRecursive(first, last, dominos, index, taken, n, m, 0);
}

int main() {
	while (true) {
		int n{0};
		int m{0};
		std::cin >> n >> m;
			
		if (n == 0) {
			break;
		}		
		Domino first;
		Domino last;

		std::cin >> first.left >> first.right;
		std::cin >> last.left >> last.right;

		std::vector<Domino> dominos(m);
		for (int i{0}; i < m; i++) {
			Domino inbetween;
			std::cin >> inbetween.left >> inbetween.right;
			dominos.at(i) = inbetween;
		}

		std::cout << n << " " << m << " " << first << " and " << last << std::endl; 
		printVectorOfDominos(dominos);
		
		bool solution{ findSolution(n, m, first, last, dominos) };
		if (solution) {
			std::cout << "YES" << std::endl;
		} else {
			std::cout << "NO" << std::endl;
		}
	}
}
