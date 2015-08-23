#include <vector>
#include <list>
#include <array>

#include "EuclideanVector.h"

int main (void) {

	std::list<double> l;
	l.push_back(5.0);		
	l.push_back(6.5);
	l.push_back(7.0);
	EuclideanVector c(l.begin(),l.end());	

	std::cout << c << std::endl;

	// std::array<double,2> a;
	// a.fill(5.0);
	// cs6771::EuclideanVector d(a.begin(),a.end());
	return 0;
}