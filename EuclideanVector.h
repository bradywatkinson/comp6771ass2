#ifndef EUC_H
#define EUC_H

#include <iostream>
#include <vector>
#include <list>
#include <array>
#include <iterator>

#include <typeinfo>
#include <type_traits>

#define DEBUG false

namespace cs6771 {
	class EuclideanVector {
		public:

			//----Contructors----
			//normal constructors
			template <typename NUM> EuclideanVector(const NUM dimension, typename std::enable_if<std::is_arithmetic<NUM>::value>::type* = 0) :
				EuclideanVector(dimension,0.0)
			{
				updateNormal();
				if (DEBUG) std::cout << "EuclideanVector(1)" << std::endl;
			}

			template <typename NUM> EuclideanVector(const NUM dimension, const NUM magnitude, typename std::enable_if<std::is_arithmetic<NUM>::value>::type* = 0) :
				dimension_{static_cast<unsigned int>(dimension)}
			{
				magnitude_ 	= std::vector<double>(dimension_, static_cast<double>(magnitude));
				updateNormal();
				if (DEBUG) std::cout << "EuclideanVector(2): "<< dimension_ << " " << magnitude << std::endl;
			}

			template <typename NUM1, typename NUM2> EuclideanVector(const NUM1 dimension, const NUM2 magnitude, typename std::enable_if<std::is_arithmetic<NUM1>::value>::type* = 0, typename std::enable_if<std::is_arithmetic<NUM2>::value>::type* = 0) :
				dimension_{static_cast<unsigned int>(dimension)}
			{
				magnitude_ 	= std::vector<double>(dimension_, static_cast<double>(magnitude));
				updateNormal();
				if (DEBUG) std::cout << "EuclideanVector(3): "<< dimension_ << " " << magnitude << std::endl;
			}

			template <typename T> EuclideanVector(T begin, T end, typename std::enable_if<!std::is_integral<T>::value>::type* = 0)
			{
				magnitude_ = std::vector<double>(begin, end);
				dimension_ = magnitude_.size();	
				updateNormal();
				if (DEBUG) std::cout << "EuclideanVector(4) received " << typeid(begin).name() << typeid(end).name() << std::endl;
			}

			//copy constructor
			EuclideanVector(const EuclideanVector &ev);
			//move constructor
			EuclideanVector(EuclideanVector &&ev);
			
			//Destructor
			~EuclideanVector();

			//=copy Operator
			EuclideanVector& operator=(const EuclideanVector &ev);
			//=move Operator
			EuclideanVector& operator=(EuclideanVector &&ev);
			
			//---Member Functions---
			unsigned int getNumDimensions() const;
			const std::vector<double>& getMagnitude () const;
			double get (int n) const;
			double getEuclideanNorm() const;
			EuclideanVector& createUnitVector() const;

			//--Member Operators---
			double& operator[] (int index);
			double operator[] (int index) const;
			//bool operator==(const EuclideanVector &ev);
			//bool operator!=(const EuclideanVector &ev);
			EuclideanVector& operator+=(const EuclideanVector &ev);
			EuclideanVector& operator-=(const EuclideanVector &ev);
			EuclideanVector& operator*=(const double s);
			EuclideanVector& operator/=(const double s);

			//---Type Conversion---
			operator std::vector<double>() const;
			operator std::list<double>() const;
			//operator std::array<double,int>() const;

			//---Static Functions
			static bool doubleEquals (double a, double b);

			//---Friend Functions---
			friend std::ostream& operator<<(std::ostream &os, const EuclideanVector &v);
			friend bool operator==(const EuclideanVector &lhs, const EuclideanVector &rhs);
			friend bool operator!=(const EuclideanVector &lhs, const EuclideanVector &rhs);
			friend EuclideanVector& operator+(const EuclideanVector &lhs, const EuclideanVector &rhs);
			friend EuclideanVector& operator-(const EuclideanVector &lhs, const EuclideanVector &rhs);
			friend double operator*(const EuclideanVector &lhs, const EuclideanVector &rhs);
			template <typename NUM> friend EuclideanVector& operator*(const EuclideanVector &ev, const NUM s);
			template <typename NUM> friend EuclideanVector& operator*(const NUM s, const EuclideanVector &ev);
			template <typename NUM> friend EuclideanVector& operator/(const EuclideanVector &ev, const NUM s);


		private:
			unsigned int dimension_;
			std::vector<double> magnitude_;
			double normal_;
			//---Private Functions---
			void updateNormal ();

			
	};
}

#endif