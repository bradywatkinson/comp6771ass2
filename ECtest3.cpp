#include <iostream>

#include "EuclideanVector.h"

int main() {
	std::list<double> l{1.0,2.0,3.0,4.0};
	
	const cs6771::EuclideanVector e{ (l.begin())++, l.end()};
	std::cout << e << std::endl;
	std::cout << e.getNumDimensions() << std::endl;
	std::cout << e.get(1) << " " << e[2] << std::endl;
	std::cout << e.getEuclideanNorm() << std::endl;
	std::cout << e.createUnitVector() << std::endl;
	cs6771::EuclideanVector f = 6;
	std::cout << std::boolalpha << (f == e) << std::endl;
	f = cs6771::EuclideanVector{4,5.0} + e;
	std::cout << f << std::endl;
	std::cout << static_cast<std::list<double>>(e).front() << std::endl;
}