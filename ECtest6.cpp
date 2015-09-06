#include "EuclideanVector.h"
#include <string>

int main() {
	
	cs6771::EuclideanVector e{2,4};
	std::cout << e << std::endl;

	float scalar = 2;
	cs6771::EuclideanVector f =  scalar * e;
	std::cout << f << std::endl;

	// cs6771::EuclideanVector g = e * f;
	double g = e * f;
	std::cout << g << std::endl;	

	cs6771::EuclideanVector h = e - f;
	std::cout << h << std::endl;	


	cs6771::EuclideanVector i1{2,0.0001};
	cs6771::EuclideanVector i2{2,0.0002};
	i2 = i2/2;
	std::cout << (i1 == i2)<<i1<<i2 << std::endl;

	cs6771::EuclideanVector j{2,4};
	std::cout << j.getEuclideanNorm() << std::endl;

	j += e;
	std::cout << j.getEuclideanNorm() << std::endl;
}