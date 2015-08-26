
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

namespace cs6771 {

	EuclideanVector::EuclideanVector(unsigned int dimension) :
		EuclideanVector(dimension,0.0)
	{
		updateNormal();
		std::cout << "EuclideanVector(1)" << std::endl;
	}

	EuclideanVector::EuclideanVector(unsigned int dimension, double magnitude) :
		dimension_{dimension}
	{
		std::vector<double> v (dimension, magnitude);
		magnitude_ 	= std::move(v);
		updateNormal();
		std::cout << "EuclideanVector(3)" << std::endl;
	}

	EuclideanVector::EuclideanVector(double dimension, double magnitude) :
		dimension_{static_cast<unsigned int>(dimension)}
	{
		std::vector<double> v (dimension, magnitude);
		magnitude_ 	= std::move(v);
		updateNormal();
		std::cout << "EuclideanVector(3)" << std::endl;
	}


	//Iterator Initialisers

	/*
	EuclideanVector::EuclideanVector(std::vector<double>::iterator begin, std::vector<double>::iterator end) :
		magnitude_{begin,end},
		dimension_{magnitude_.size}
	{ }
	*/
	// EuclideanVector::EuclideanVector(std::vector<double>::iterator begin, std::vector<double>::iterator end)
	// {
	// 	magnitude_ 	= std::vector<double>(begin,end);
	// 	dimension_ 	= magnitude_.size();	
	// 	updateNormal();
	// 	std::cout << "EuclideanVector Vector Init" << std::endl;
	// }

	// EuclideanVector::EuclideanVector(std::list<double>::iterator begin, std::list<double>::iterator end)
	// {
	// 	magnitude_ = std::vector<double>(begin,end);
	// 	dimension_ = magnitude_.size();	
	// 	updateNormal();
	// 	std::cout << "EuclideanVector List Init" << std::endl;
	// }
	/*

	EuclideanVector::EuclideanVector(std::array<double,int>::iterator begin, std::array<double,int>::iterator end)
	{
		std::vector<double> v (begin, end);
		magnitude_ = std::move(v);
		dimension_ = magnitude_.size();	
	}
	*/
	
	template <typename T>
	EuclideanVector::EuclideanVector(T begin, T end)
	{
		magnitude_ = std::vector<double>(begin, end);
		dimension_ = magnitude_.size();	
		updateNormal();
		std::cout << "EuclideanVector(4)" << std::endl;
	}

	//copy constructor
	EuclideanVector::EuclideanVector(const EuclideanVector &ev) :
		dimension_{ev.dimension_},
		magnitude_{ev.magnitude_}
	{
		updateNormal();
	}
	//move constructor
	EuclideanVector::EuclideanVector(EuclideanVector &&ev) :
		dimension_{std::move(ev.dimension_)},
		magnitude_{std::move(ev.magnitude_)}
	{
		updateNormal();
	}

	//Destructor
	EuclideanVector::~EuclideanVector()
	{
		std::cout << "deleting a EuclideanVector" << std::endl;
	}

	//=copy Operator
	EuclideanVector& EuclideanVector::operator=(const EuclideanVector &ev)
	{
		if (this != &ev) {
			dimension_ 	= ev.dimension_;
			magnitude_ 	= ev.magnitude_;
			normal_ 	= ev.normal_;
		}
		std::cout << "in copy operator" << std::endl;
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
		std::cout << "in move operator" << std::endl;
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
			fm[i] /= normal_;
		}
		EuclideanVector *unitVector = new EuclideanVector::EuclideanVector{fm.begin(),fm.end()};
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

	// bool EuclideanVector::operator==(const EuclideanVector &ev)
	// {
	// 	if (dimension_ != ev.getNumDimensions()) return false;
	// 	for (int i=0;i<dimension_;++i) {
	// 		if (!doubleEquals(magnitude_.at(i), magnitude_.at(i))) return false;
	// 	}
	// 	return true;
	// }

	// bool EuclideanVector::operator!=(const EuclideanVector &ev)
	// {
	// 	return !;
	// }

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
		return *this;
	}

	EuclideanVector& EuclideanVector::operator*=(const double s)
	{

		for (int i=0;i<int(dimension_);++i) {
			magnitude_[i] *= s;
		}
		return *this;
	}

	EuclideanVector& EuclideanVector::operator/=(const double s)
	{

		for (int i=0;i<int(dimension_);++i) {
			magnitude_[i] /= s;
		}
		return *this;
	}

	//---Type Conversion---

	EuclideanVector::operator std::vector<double>() const
	{
		return magnitude_;
	}


	//---Friend Functions---

	std::ostream& operator<<(std::ostream &os, const EuclideanVector &ev)

	{
		const std::vector<double>& v = ev.getMagnitude();
		std::ostringstream ss;
		std::copy(v.begin(), v.end() - 1, std::ostream_iterator<double>(ss, ", "));
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
		EuclideanVector *sum = new EuclideanVector::EuclideanVector{fm.begin(),fm.end()};	//create return value using iterator constructor

		return *sum;
	}

	EuclideanVector& operator-(const EuclideanVector &lhs, const EuclideanVector &rhs)
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
			fm[i] = lm[i] - rm[i];
		}
		EuclideanVector *sum = new EuclideanVector::EuclideanVector{fm.begin(),fm.end()};	//create return value using iterator constructor

		return *sum;
	}

	double operator*(const EuclideanVector &lhs, const EuclideanVector &rhs)
	{
		if (lhs.getNumDimensions() != rhs.getNumDimensions()) {
			std::cerr << "Addition operation failed: incompatible dimensions" << std::endl;
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

	EuclideanVector& operator*(const EuclideanVector &ev, const double s)
	{

		int d = ev.getNumDimensions();
		const std::vector<double>& v = ev.getMagnitude();
		std::vector<double> fm(d);					//initialise the new magnitude vector to the size of the original two

		for (int i=0;i<d;++i) {
			fm[i] = s*v[i];
		}

		EuclideanVector *product = new EuclideanVector::EuclideanVector{fm.begin(),fm.end()};	//create return value using iterator constructor

		return *product;
	}

	EuclideanVector& operator*(const double s, const EuclideanVector &ev)
	{

		int d = ev.getNumDimensions();
		const std::vector<double>& v = ev.getMagnitude();
		std::vector<double> fm(d);					//initialise the new magnitude vector to the size of the original two

		for (int i=0;i<d;++i) {
			fm[i] = s*v[i];
		}

		EuclideanVector *product = new EuclideanVector::EuclideanVector{fm.begin(),fm.end()};	//create return value using iterator constructor

		return *product;
	}

	EuclideanVector& operator/(const EuclideanVector &ev, const double s)
	{

		int d = ev.getNumDimensions();
		const std::vector<double>& v = ev.getMagnitude();
		std::vector<double> fm(d);					//initialise the new magnitude vector to the size of the original two

		for (int i=0;i<d;++i) {
			fm[i] = v[i]/s;
		}

		EuclideanVector *product = new EuclideanVector::EuclideanVector{fm.begin(),fm.end()};	//create return value using iterator constructor

		return *product;
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




