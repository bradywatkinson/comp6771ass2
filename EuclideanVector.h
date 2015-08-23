#ifndef EUC_H
#define EUC_H

#include <iostream>
#include <vector>
#include <list>
#include <array>



	class EuclideanVector {
		public:

			//----Contructors----
			//normal constructors
			EuclideanVector(unsigned int dimension);
			EuclideanVector(unsigned int dimension, double magnitude);
			//template <typename T>
			//EuclideanVector(T begin, T end);
			EuclideanVector(std::vector<double>::iterator begin, std::vector<double>::iterator end);
			EuclideanVector(std::list<double>::iterator begin, std::list<double>::iterator end);
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
			std::vector<double> getMagnitude () const;


			//---Friend Functions---
			friend std::ostream& operator<<(std::ostream &os, const EuclideanVector &v);

		private:
			unsigned int dimension_;
			std::vector<double> magnitude_;
	};

#endif