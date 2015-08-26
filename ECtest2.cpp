#include <iostream>
#include <vector>
#include <list>
#include <array>

#include "EuclideanVector.h"

int main() {
	
	cs6771::EuclideanVector a{2};	// use a constructor
	

	std::list<double> l {1,2,3};
	cs6771::EuclideanVector b{l.begin(),l.end()};
	
	/*
	std::vector<double> v2 {4,5,6,7};
	cs6771::EuclideanVector c{v2.begin(),v2.end()};
	
	std::array<double,5> a1 {{5,4,3,2,1}};
	cs6771::EuclideanVector d{a1.begin(),a1.end()};
	
	std::array<double,5> a2 {{9,0,8,6,7}};
	cs6771::EuclideanVector e{a2.begin(),a2.end()};
	
	// use the copy constructor
	cs6771::EuclideanVector f{e};	

	
	std::cout << a.getNumDimensions() << ": " << a << std::endl;
	std::cout << "D1:" << b.get(1) << " " << b << std::endl;
	std::cout << c << " Euclidean Norm = " << c.getEuclideanNorm() << std::endl;
	std::cout << d << " Unit Vector: " << d.createUnitVector() << " L = " << d.createUnitVector().getEuclideanNorm() << std::endl;
	std::cout << e << std::endl;
	std::cout << f << std::endl;
	
	// test the move constructor
	cs6771::EuclideanVector g = std::move(f);
	std::cout << g << std::endl;
	
	// try operator overloading
	e += d;
	std::cout << e << std::endl;
	
	cs6771::EuclideanVector h = e - g;
	std::cout << h << std::endl;
	
	// test scalar multiplication
	h *= 2;
	std::cout << h << std::endl;
	
	cs6771::EuclideanVector j = b / 2;
	std::cout << j << std::endl;
	
	std::cout << "dot product = " << j * b << std::endl;
	
	if (g == (e - d)) std::cout << "true" << std::endl;
	if (j != b ) std::cout << "false" << std::endl;
	
	j[0] = 1;
	std::cout << j << std::endl;
	
	// type cast from EuclideanVector to a std::vector
	std::vector<double> vj = j;
	
	// type cast from EuclideanVector to a std::vector
	std::list<double> lj = j;
	
	for (auto d : lj) {
		std::cout << d << std::endl;
	}
	*/
}