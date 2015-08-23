
#include <iostream>
#include <vector>
#include <list>
#include <array>

#include "EuclideanVector.h"

using namespace cs6771;

EuclideanVector::EuclideanVector(unsigned int dimension) :
	dimension_{dimension}
{
	std::cout << "EuclideanVector(1)" << std::endl;
}

EuclideanVector::EuclideanVector(unsigned int dimension, double magnitude) :
	dimension_{dimension}
{
	std::vector<double> v (dimension, magnitude);
	magnitude_ = std::move(v);
	std::cout << "EuclideanVector(3)" << std::endl;
}


//Iterator Initialisers

/*
EuclideanVector::EuclideanVector(std::vector<double>::iterator begin, std::vector<double>::iterator end) :
	magnitude_{begin,end},
	dimension_{magnitude_.size}
{ }
*/
EuclideanVector::EuclideanVector(std::vector<double>::iterator begin, std::vector<double>::iterator end)
{
	magnitude_ = std::vector<double>(begin,end);
	dimension_ = magnitude_.size();	
}

EuclideanVector::EuclideanVector(std::list<double>::iterator begin, std::list<double>::iterator end)
{
	//std::vector<double> v (begin, end);
	//magnitude_ = std::move(v);
	magnitude_ = std::vector<double>(begin,end);
	dimension_ = magnitude_.size();	
}
/*

EuclideanVector::EuclideanVector(std::array<double,int>::iterator begin, std::array<double,int>::iterator end)
{
	std::vector<double> v (begin, end);
	magnitude_ = std::move(v);
	dimension_ = magnitude_.size();	
}
*/
/*
template <typename T>
EuclideanVector::EuclideanVector(T begin, T end)
{
	//std::vector<double> v (begin, end);
	// magnitude_ = std::move(v);
	// dimension_ = magnitude_.size();	
	std::cout << "EuclideanVector(4)" << std::endl;
}*/

//copy constructor
EuclideanVector::EuclideanVector(const EuclideanVector &ev) :
	dimension_{ev.dimension_},
	magnitude_{ev.magnitude_}
{ }
//move constructor
EuclideanVector::EuclideanVector(EuclideanVector &&ev) :
	dimension_{std::move(ev.dimension_)},
	magnitude_{std::move(ev.magnitude_)}
{ }

//Destructor
EuclideanVector::~EuclideanVector()
{
	std::cout << "deleting a EuclideanVector" << std::endl;
}

//=copy Operator
EuclideanVector& EuclideanVector::operator=(const EuclideanVector &ev)
{
	if (this != &ev) {
		dimension_ = ev.dimension_;
		magnitude_ = ev.magnitude_;
	}
	std::cout << "in copy operator" << std::endl;
	return *this;
}
//=move Operator
EuclideanVector& EuclideanVector::operator=(EuclideanVector &&ev)
{
	if (this != &ev) {
		dimension_ = std::move(ev.dimension_);
		magnitude_ = std::move(ev.magnitude_);
	}
	std::cout << "in move operator" << std::endl;
	return *this;
}

//---Member Functions---

unsigned int EuclideanVector::getNumDimensions () const
{
	return dimension_;
}

std::vector<double> EuclideanVector::getMagnitude () const
{
	return magnitude_;
}

std::ostream& operator<<(std::ostream &os, const EuclideanVector &v)
{
	os << "[";
	for (std::vector<double>::const_iterator it=v.getMagnitude().begin();it!=v.getMagnitude().end();++it) {
		os << *it << " ";
	}
	os << "]";
	return os;
}








