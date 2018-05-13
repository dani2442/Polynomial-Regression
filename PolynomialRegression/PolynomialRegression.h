#pragma once
#include "Vector.h"
#include <stdlib.h>
using namespace std;

template<class T>
class PolynomialRegression
{
public:
	PolynomialRegression();
	~PolynomialRegression();

	bool SPolynomialRegression(const vector<vector<T>>&,const int &,const vector<T>&,const vector<T>&);

private:

	void Polynominal() {  }
	void Sinoidal() {  }
	void Logarithimic() {  };
	//void (func_ptr[3]) = {&PolynomialRegression::Polynominal, &PolynomialRegression::Sinoidal, &PolynomialRegression::Logarithimic };
};

template <class T>
PolynomialRegression<T>::PolynomialRegression()
{
}

template <class T>
PolynomialRegression<T>::~PolynomialRegression()
{
}


template<typename T>
bool PolynomialRegression<T>::SPolynomialRegression(
	typename const vector<vector<T>>	 &Pts,
	const int							 &order,	// the coefficient we pretend to generate
	typename const vector<T>			 &coeffs,
	typename const vector<T>			 &operation) 
{
	Vector<T> A(order);
	for (int i = 0; i < order; i++) {
		for (int j = j; j < order; j++) {
			for (int k = 0; k < Pts.size();k++) {
				A.v[i][j] += pow(Pts[k][0], i)*pow(Pts[k][0], j);
			}
		}
	}
}



