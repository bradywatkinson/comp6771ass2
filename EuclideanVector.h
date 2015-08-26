#ifndef EUC_H
#define EUC_H

#include <iostream>
#include <vector>
#include <list>
#include <array>


namespace cs6771 {
	class EuclideanVector {
		public:

			//----Contructors----
			//normal constructors
			EuclideanVector(unsigned int dimension);
			EuclideanVector(unsigned int dimension, double magnitude);
			EuclideanVector(double dimension, double magnitude);
			template <typename T>
			EuclideanVector(T begin, T end);
			//EuclideanVector(std::vector<double>::iterator begin, std::vector<double>::iterator end);
			//EuclideanVector(std::list<double>::iterator begin, std::list<double>::iterator end);
			//EuclideanVector(std::array<double>::iterator begin, std::array<double>::iterator end);
			

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
			explicit operator std::vector<double>() const;

			//---Static Functions
			static bool doubleEquals (double a, double b);

			//---Friend Functions---
			friend std::ostream& operator<<(std::ostream &os, const EuclideanVector &v);
			friend bool operator==(const EuclideanVector &lhs, const EuclideanVector &rhs);
			friend bool operator!=(const EuclideanVector &lhs, const EuclideanVector &rhs);
			friend EuclideanVector& operator+(const EuclideanVector &lhs, const EuclideanVector &rhs);
			friend EuclideanVector& operator-(const EuclideanVector &lhs, const EuclideanVector &rhs);
			friend double operator*(const EuclideanVector &lhs, const EuclideanVector &rhs);
			friend EuclideanVector& operator*(const EuclideanVector &ev, const double s);
			friend EuclideanVector& operator*(const double s, const EuclideanVector &ev);
			//friend EuclideanVector& operator/(const EuclideanVector &ev, const double s);


		private:
			unsigned int dimension_;
			std::vector<double> magnitude_;
			double normal_;
			//---Private Functions---
			void updateNormal ();

			
	};
}

#endif