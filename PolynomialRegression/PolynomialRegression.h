#pragma once

using namespace std;

template<class T>
class NonlinearRegression
{
public:
	NonlinearRegression<T>();
	~NonlinearRegression<T>();

	static Vector<T> PolynomialRegression(const vector<vector<T>>&,const int &); // y = a0 + a1 * x + a2 * x^2 + ... + an * x^n
	static Vector<T> SinusoidalRegression(const vector<vector<T>>&, const int &); // y = a0 + a1 * sin(2^(-n/2)*x) + a2 * sin(2^(-n/2+1)*x) + ... + an * sin(2^(n/2)*x)
	static Vector<T> MixedRegression(const vector<vector<T>>&, const int &, const vector<T>&); // To be continued...

private:

	T Polynominal(const T var,const int&n) { return pow(var, n); }
	T Sinoidal(const T var,const int&n) {  return sin(var*pow(2, n)); }
	T Logarithimic(const T var,const int &n) { return 5; };

	typedef T (NonlinearRegression::*fptr)(const T,const int&);
	
public:
	fptr func[3] = { &NonlinearRegression::Polynominal, &NonlinearRegression::Sinoidal, &NonlinearRegression::Logarithimic };

};

template<class T>
NonlinearRegression<T>::NonlinearRegression()
{
}

template<class T>
NonlinearRegression<T>::~NonlinearRegression()
{
}


template<typename T>
inline Vector<T> NonlinearRegression<T>::PolynomialRegression(
	const vector<vector<T>>		 &Pts,			// the points we use
	const int					 &order)		// the coefficient we pretend to generate
{
	// Calculate the half part of A (Matrix)
	Vector<T> A(order);
	for (int i = 0; i < order; i++) {
		for (int j = i; j < order; j++) {
			for (int k = 0; k < Pts.size();k++) {
				A.v[i][j] += pow(Pts[k][0], i)*pow(Pts[k][0], j);
			}
			A.v[j][i] = A.v[i][j];
		}
	}

	// Pivotate the Matrix to fill the rest part
	Vector<T>C(order,1);
	for (int i = 0; i < order; i++) {
		for (int k = 0; k < Pts.size(); k++) {
			C.v[i][0] += (Pts[k][1] * pow(Pts[k][0], i));
		}
	}

	// A*B=C --> B = A.inverse() * C
	A.Inverse2();
	A*=C;
	return A;
}

template<class T>
inline Vector<T> NonlinearRegression<T>::SinusoidalRegression(
	const vector<vector<T>>		&Pts,		// the points we use
	const int					&order)		// the sinusoidal max coefficient
{
	Vector<T> A(order);
	int norder = order / 2;
	for (int i = 0; i < order; i++) {
		for (int j = i; j < order; j++) {
			for (int k = 0; k < Pts.size(); k++) {
				A.v[i][j] += sin(Pts[k][0]* pow(2,i-norder))*sin(Pts[k][0]* pow(2,j-order));
			}
			A.v[j][i] = A.v[i][j];
		}
	}

	// Pivotate the Matrix to fill the rest part
	Vector<T>C(order, 1);
	for (int i = 0; i < order; i++) {
		for (int k = 0; k < Pts.size(); k++) {
			C.v[i][0] += (Pts[k][1] * pow(Pts[k][0], i));
		}
	}

	// A*B=C --> B = A.inverse() * C
	A.Inverse2();
	A *= C;
	return A;
}
