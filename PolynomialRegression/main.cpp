#include "../../Vector2/Vector/Vector.h"
#include "PolynomialRegression.h"


int main() {
	Vector<double> Pts;Pts.v = { { 0,2.1 },{ 1,7.7 },{ 2,12.6 },{ 3,27.2 },{ 4,40.9 },{ 5,61.1 } };
	Vector<double> Pts; Pts.v = { { 0,2.1 },{ 1,7.7 },{ 2,12.6 },{ 3,27.2 },{ 4,40.9 },{ 5,61.1 } };
	vector<vector<double>> e = { { 1,1,-1 },{ 3,2,1 },{ 5,3,4 } };
	vector<double> e2 = { 1,1,2 };
	Vector<double>dani=PolynomialRegression::SPolynomialRegression(Pts.v, 4, e2, e2);
	dani.Print();
	getchar();
}