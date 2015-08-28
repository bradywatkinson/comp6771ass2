#ifndef EUC_H
#define EUC_H

#include <iostream>
#include <vector>
#include <list>
#include <array>
#include <iterator>

#include <typeinfo>


namespace cs6771 {
	class EuclideanVector {
		public:

			//----Contructors----
			//normal constructors
			EuclideanVector(const unsigned dimension);
			//template <typename NUM> EuclideanVector(const NUM dimension);
			//EuclideanVector(unsigned int dimension, double magnitude);
			//EuclideanVector(unsigned int dimension, int magnitude);
			// template <typename NUM> EuclideanVector(NUM dimension);
			template <typename NUM1, typename NUM2> EuclideanVector(const NUM1 dimension, const NUM2 magnitude);

			template <typename T> EuclideanVector(T begin, T end)
			{
				magnitude_ = std::vector<double>(begin, end);
				dimension_ = magnitude_.size();	
				updateNormal();
				std::cout << "EuclideanVector(4) received " << typeid(begin).name() << std::endl;
			}
			// EuclideanVector(std::vector<double>::iterator begin, std::vector<double>::iterator end);
			// EuclideanVector(std::list<double>::iterator begin, std::list<double>::iterator end);
			// EuclideanVector(std::array<double>::iterator begin, std::array<double>::iterator end);
			

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