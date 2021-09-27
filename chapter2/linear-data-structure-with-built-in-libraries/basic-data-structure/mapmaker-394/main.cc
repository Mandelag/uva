#include <map>
#include <string>
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

void printVectorMinMax(std::vector<minmax> v);

void printVector(std::vector<int>);


int main() {
	int N;
	int R;

	std::cin >> N >> R;

	std::map<std::string, cs> A;

	for ( int i{0};  i < N ; i++) {
		std::string key;
		array_data cs; 

		std::cin >> key;
		std::cin >> cs.base_address >> cs.element_size >> cs.dimensions;
		
		cs.member.resize(cs.dimensions);

		for ( int j{0} ; j < cs.dimensions ; j++) {
			std::cin >> cs.member[j].min >> cs.member[j].max;
		}

		A[key] = get_c(cs);
	}

//	for ( const auto & k : A) {
//		std::cout << k.first;
//		std::cout << " " << k.second.base_address << " " << k.second.element_size << " " << k.second.dimensions << " ";
//		printVectorMinMax(k.second.member);	
//	}	
//
//	

	for (int i{0}; i < R ; i++) {
		std::string key; 
		std::vector<int> ref;

		std::cin >> key;

		for (int j{0}; j < A[key].C.size(); j++) {
			int r;
			std::cin >> r;
			ref.push_back(r);
		}
		
		// calculate total
		int total = A[key].c0;
		for (int j{0}; j < A[key].C.size(); j++) {
			total += ref.at(j) * A[key].C.at(j);
		}

		std::cout << key << "[";
		printVector(ref);
		std::cout << "]" << " = " << total << std::endl;
	}	

}

int mainx() {
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

	std::cout << total;
	return 0;
}


cs get_c(array_data ad) {
	std::vector<int> C(ad.member.size());
	C.at(C.size()-1) = ad.element_size;
	// today i learned for loop descending for size_t will not exit if condition j-- < 0
	for (int i{ad.dimensions-2}; i >=0 ; i--){
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

void printVector(std::vector<int> v) {
	for(int i{0} ; i < v.size()-1; i++) {
		std::cout << v.at(i) << ", ";
	}
	std::cout << v.at(v.size()-1); 
}

void printVectorMinMax(std::vector<minmax> v) {
	for(minmax i : v ) {
		std::cout << i.min << ", " << i.max << "; " ;
	}
	std::cout << std::endl;
}
