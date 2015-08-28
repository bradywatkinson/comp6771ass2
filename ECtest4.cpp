#include "EuclideanVector.h"

int main() {
	
	cs6771::EuclideanVector a_rval{1};
	
	unsigned int ui = 2;
	cs6771::EuclideanVector a2{ui};
	
	const int ci = 3;
	cs6771::EuclideanVector a3{ci};
	
	const unsigned int cui = 4;
	cs6771::EuclideanVector a4{cui};
	
	short unsigned si = 5;
	cs6771::EuclideanVector a5{si};
	
	std::list<int> l {1,2,4};
	cs6771::EuclideanVector b{l.begin(),l.end()};
	
	std::vector<unsigned int> v2 {4,5,6,7};
	cs6771::EuclideanVector c{v2.begin(),v2.begin()+3};
	
	std::vector<double> a1 {5,4,3.1,2,1.0};
	cs6771::EuclideanVector d{a1.begin(),a1.end()};
	
	std::cout <<"mark" <<std::endl;
	
	cs6771::EuclideanVector e{1,4};
	
	std::cout << e << std::endl;

	const int mag = 5;
	cs6771::EuclideanVector e2{ci,mag};
	
	std::cout << e2 << std::endl;

	cs6771::EuclideanVector e3{ui,4.9};
	
	double d1 = 3.14;
	cs6771::EuclideanVector e4{cui,d1};

	std::cout << e4 << std::endl;
	
}