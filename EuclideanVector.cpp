
#include <iostream>
#include <vector>
#include <list>
#include <array>
#include <algorithm>
#include <iterator>
#include <string>
#include <sstream>
#include <cmath> 
#include <cstdlib>

#include "EuclideanVector.h"
#ifndef EUC_H
#define DEBUG false
#endif

namespace cs6771 {

	//copy constructor
	EuclideanVector::EuclideanVector(const EuclideanVector &ev) :
		dimension_{ev.dimension_},
		magnitude_{ev.magnitude_}
	{
		updateNormal();
		if (DEBUG) std::cout << "Copy constructor" << std::endl;
	}

	//move constructor
	EuclideanVector::EuclideanVector(EuclideanVector &&ev) :
		dimension_{std::move(ev.dimension_)},
		magnitude_{std::move(ev.magnitude_)}
	{
		updateNormal();
		if (DEBUG) std::cout << "Move constructor" << std::endl;
	}

	//Destructor
	EuclideanVector::~EuclideanVector()
	{
		if (DEBUG) std::cout << "deleting a EuclideanVector" << std::endl;
	}

	//=copy Operator
	EuclideanVector& EuclideanVector::operator=(const EuclideanVector &ev)
	{
		if (this != &ev) {
			dimension_ 	= ev.dimension_;
			magnitude_ 	= ev.magnitude_;
			normal_ 	= ev.normal_;
		}
		if (DEBUG) std::cout << "in copy operator" << std::endl;
		return *this;
	}
	//=move Operator
	EuclideanVector& EuclideanVector::operator=(EuclideanVector &&ev)
	{
		if (this != &ev) {
			dimension_ 	= std::move(ev.dimension_);
			magnitude_ 	= std::move(ev.magnitude_);
			normal_		= std::move(ev.normal_);
		}
		if (DEBUG) std::cout << "in move operator" << std::endl;
		return *this;
	}

	//---Member Functions---

	unsigned int EuclideanVector::getNumDimensions () const
	{
		return dimension_;
	}

	const std::vector<double>& EuclideanVector::getMagnitude () const
	{
		return magnitude_;
	}

	double EuclideanVector::get (int n) const
	{
		return magnitude_.at(n);
	}

	double EuclideanVector::getEuclideanNorm() const
	{
		return normal_;
	}

	EuclideanVector& EuclideanVector::createUnitVector() const
	{
		std::vector<double> fm(dimension_);	//initialise the new magnitude vector
		for (int i=0;i<int(dimension_);++i) {
			fm[i] = magnitude_[i] / normal_;
		}
		EuclideanVector *unitVector = new EuclideanVector{fm.begin(),fm.end()};
		return *unitVector;
	}

	//---Member Operators---

	double& EuclideanVector::operator[](int index)
	{
		return magnitude_.at(index);
	}

	double EuclideanVector::operator[](int index) const
	{
		return magnitude_.at(index);
	}

	EuclideanVector& EuclideanVector::operator+=(const EuclideanVector &ev)
	{
		if (dimension_ != ev.getNumDimensions()) {
			std::cerr << "Addition operation failed: incompatible dimensions" << std::endl;
			abort();
		}
		const std::vector<double> m = ev.getMagnitude();
		for (int i=0;i<int(dimension_);++i) {
			magnitude_[i] += m[i];
		}
		updateNormal();
		return *this;
	}


	EuclideanVector& EuclideanVector::operator-=(const EuclideanVector &ev)
	{
		if (dimension_ != ev.getNumDimensions()) {
			std::cerr << "Addition operation failed: incompatible dimensions" << std::endl;
			abort();
		}
		const std::vector<double> m = ev.getMagnitude();
		for (int i=0;i<int(dimension_);++i) {
			magnitude_[i] -= m[i];
		}
		updateNormal();
		return *this;
	}

	EuclideanVector& EuclideanVector::operator*=(const double s)
	{

		for (int i=0;i<int(dimension_);++i) {
			magnitude_[i] *= s;
		}
		updateNormal();
		return *this;
	}

	EuclideanVector& EuclideanVector::operator/=(const double s)
	{

		for (int i=0;i<int(dimension_);++i) {
			magnitude_[i] /= s;
		}
		updateNormal();
		return *this;
	}

	//---Type Conversion---

	EuclideanVector::operator std::vector<double>() const
	{
		return magnitude_;
	}

	EuclideanVector::operator std::list<double>() const
	{
		return std::list<double>(magnitude_.begin(),magnitude_.end());
	}

	// EuclideanVector::operator std::array<double,int>() const
	// {
	// 	return magnitude_;
	// }


	//---Friend Functions---

	std::ostream& operator<<(std::ostream &os, const EuclideanVector &ev)

	{
		const std::vector<double>& v = ev.getMagnitude();
		std::ostringstream ss;
		std::copy(v.begin(), v.end() - 1, std::ostream_iterator<double>(ss, " "));
	   	ss << v.back();
	   	os << "[" << ss.str() << "]";

		return os;
	}

	bool operator==(const EuclideanVector &lhs, const EuclideanVector &rhs)
	{
		if (lhs.getNumDimensions() != rhs.getNumDimensions()) return false;
		const std::vector<double>& l = lhs.getMagnitude();
		const std::vector<double>& r = rhs.getMagnitude();
		for (int i=0;i<int(lhs.getNumDimensions());++i) {
			if (!EuclideanVector::doubleEquals(l.at(i), r.at(i))) return false;
		}
		return true;
	}

	bool operator!=(const EuclideanVector &lhs, const EuclideanVector &rhs)
	{
		return !(lhs==rhs);
	}

	EuclideanVector& operator+(const EuclideanVector &lhs, const EuclideanVector &rhs)
	{
		if (lhs.getNumDimensions() != rhs.getNumDimensions()) {
			std::cerr << "Addition operation failed: incompatible dimensions" << std::endl;
			abort();
		}
		int d = lhs.getNumDimensions();
		const std::vector<double>& lm = lhs.getMagnitude();	//get the left and right magnitude vectors
		const std::vector<double>& rm = rhs.getMagnitude();
		std::vector<double> fm(d);					//initialise the new magnitude vector to the size of the original two
		
		for (int i=0;i<d;++i) {
			fm[i] = lm[i] + rm[i];
		}
		EuclideanVector *sum = new EuclideanVector{fm.begin(),fm.end()};	//create return value using iterator constructor

		return *sum;
	}

	EuclideanVector& operator-(const EuclideanVector &lhs, const EuclideanVector &rhs)
	{
		if (lhs.getNumDimensions() != rhs.getNumDimensions()) {
			std::cerr << "Subtraction operation failed: incompatible dimensions" << std::endl;
			abort();
		}
		int d = lhs.getNumDimensions();
		const std::vector<double>& lm = lhs.getMagnitude();	//get the left and right magnitude vectors
		const std::vector<double>& rm = rhs.getMagnitude();
		std::vector<double> fm(d);					//initialise the new magnitude vector to the size of the original two
		
		for (int i=0;i<d;++i) {
			fm[i] = lm[i] - rm[i];
		}
		EuclideanVector *sum = new EuclideanVector{fm.begin(),fm.end()};	//create return value using iterator constructor

		return *sum;
	}

	double operator*(const EuclideanVector &lhs, const EuclideanVector &rhs)
	{
		if (lhs.getNumDimensions() != rhs.getNumDimensions()) {
			std::cerr << "Multiplication operation failed: incompatible dimensions" << std::endl;
			abort();
		}
		int d = lhs.getNumDimensions();
		const std::vector<double>& lm = lhs.getMagnitude();	//get the left and right magnitude vectors
		const std::vector<double>& rm = rhs.getMagnitude();
		std::vector<double> fm(d);					//initialise the new magnitude vector to the size of the original two
		double dotproduct = 0;

		for (int i=0;i<d;++i) {
			dotproduct += lm[i]*rm[i];
		}
		return dotproduct;
	}

	//---Private Function---
	void EuclideanVector::updateNormal ()
	{
		double normal = 0;
		for (const double d : magnitude_) {
			normal += d*d;
		}
		normal_ =  sqrt(normal);

	}

	//---Static Functions---
	bool EuclideanVector::doubleEquals (double a, double b)
	{
		return fabs(a-b) < 0.00001;
	}

}




