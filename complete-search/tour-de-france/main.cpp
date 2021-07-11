#include <iostream>
#include <vector>
#include <iomanip>
#include <queue>

double get_maximum_spread(std::vector<int> front, std::vector<int> rear); 

int main() {
	while (true) {
		int f;
		int r;

		std::cin >> f;
		if (f == 0) {
			break;
		}
		std::cin >> r;

		std::vector<int> fs(f);
		std::vector<int> rs(r);

		// read the front teeth
		for (int fi{0}; fi < f; fi++) { 
			int tmp{0};
			std::cin >> tmp; 
			fs.at(fi) = tmp;
		}

		// read the rear teeth
		for (int ri{0}; ri < r; ri++) {
			int tmp{0};
			std::cin >> tmp;
			rs.at(ri) = tmp;
		}

		double maximum_spread = get_maximum_spread(fs, rs);

		std::cout << std::setprecision(2) << std::fixed << maximum_spread << "\n";
	}
}

double get_maximum_spread(std::vector<int> fs, std::vector<int> rs) {
	std::priority_queue<double, std::vector<double>, std::greater<double>> q;
	for (int i{0}; i < fs.size(); i++) {
		for (int j{0}; j< rs.size(); j++) {
			double drive_ratio{rs.at(j)/double(fs.at(i))};
			q.push(drive_ratio);
		}
	}
	double max{0};

	double d1{q.top()};
	q.pop();

	while(!q.empty()) {
		double d2{q.top()};
		q.pop();

		double spread{d2/d1};
		
		if (max < spread) {
			max = spread;
		}

		d1 = d2;
	}	

	return max;
}
