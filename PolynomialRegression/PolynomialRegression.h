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

	bool SPolynomialRegression( vector<vector<T>>&, int &,  vector<T>&,vector<T>&);

private:
	T(*Operation)(int);
	T Polynominal(int);
	T Sinoidal(int);
	T Logarithimic(int);

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
	typename vector<vector<T>>	 &Pts,
	int							 &order,	// the coefficient we pretend to generate
	typename vector<T>			 &coeffs,
	typename vector<T>			 &operation) 
{
	

}


