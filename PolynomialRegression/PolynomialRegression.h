#pragma once

using namespace std;

class PolynomialRegression
{
public:
	PolynomialRegression();
	~PolynomialRegression();

	template<class T>
	static Vector<T> SPolynomialRegression(const vector<vector<T>>&,const int &,const vector<T>&,const vector<T>&);

private:

	void Polynominal() {  }
	void Sinoidal() {  }
	void Logarithimic() {  };

	typedef void (PolynomialRegression::*fptr)();
	
public:
	fptr func[3] = { &PolynomialRegression::Polynominal, &PolynomialRegression::Sinoidal, &PolynomialRegression::Logarithimic };

};

PolynomialRegression::PolynomialRegression()
{
}

PolynomialRegression::~PolynomialRegression()
{
}


template<class T>
static Vector<T> PolynomialRegression::SPolynomialRegression(
	typename const vector<vector<T>>	 &Pts,			// the points we use
	const int							 &order,		// the coefficient we pretend to generate
	typename const vector<T>			 &coeffs,		// TODO
	typename const vector<T>			 &operation)	// TODO
{
	Vector<double> A(order);
	for (int i = 0; i < order; i++) {
		for (int j = i; j < order; j++) {
			for (int k = 0; k < Pts.size();k++) {
				A.v[i][j] += pow(Pts[k][0], i)*pow(Pts[k][0], j);
			}
			A.v[j][i] = A.v[i][j];
		}
	}

	Vector<double>C(order,1);
	for (int i = 0; i < order; i++) {
		for (int k = 0; k < Pts.size(); k++) {

			C.v[i][0] += (Pts[k][1] * pow(Pts[k][0], i));
		}
	}

	A.Inverse();
	A*=C;
	return A;
}

