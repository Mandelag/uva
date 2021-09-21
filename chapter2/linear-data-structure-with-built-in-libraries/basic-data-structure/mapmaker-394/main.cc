#include <iostream>
#include <string>
#include <vector>

struct minmax {
	int min;
	int max;
};


struct array_data {
	std::string name;
	int base_address;
	int element_size;
	int dimensions;
	std::vector<minmax> member;
};

struct cs {
	int c0;
	std::vector<int> C;
};

cs get_c(array_data);

int main() {
	array_data x = {
		name: "KEENAN", 
		base_address: 2000,
		element_size: 4,
		dimensions: 3,
		member: {
			{min: 1, max: 4},
			{min: 0, max: 5},
			{min: 5, max: 10},
		},
	};

	std::vector<int> input = {2, 0, 6};

	cs result = get_c(x);
	int total = result.c0;
	for(int i{0}; i < input.size(); i++) {
		total += input.at(i) * result.C.at(i); 
	}	
	std::cout << result.c0 << "  uhuyy  " << total << std::endl;
}

cs get_c(array_data ad) {
	std::vector<int> C(ad.member.size());
	C.at(C.size()-1) = ad.element_size;
	for (size_t i{C.size()-2}; i>0 ; i--) {
		C.at(i) = C.at(i+1) * (ad.member.at(i+1).max - ad.member.at(i+1).min + 1);
	}
	int c0{ad.base_address};
	for (size_t i{0}; i < C.size(); i++) {
		c0 -= C.at(i) * ad.member.at(i).min;
	}
	return {
		c0: c0,
		C: C,
	};

}


