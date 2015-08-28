#include "EuclideanVector.h"

int main() {
	
	cs6771::EuclideanVector e1{1};

	cs6771::EuclideanVector e{1,4};
	std::cout << e << std::endl;

	const int mag = 5;
	cs6771::EuclideanVector e2{3,mag};
	std::cout << e2 << std::endl;
	
	short dim2 = 6;
	cs6771::EuclideanVector e3{dim2,6.7};
	std::cout << e2 << std::endl;
}