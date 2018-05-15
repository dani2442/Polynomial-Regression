#include "../../Vector2/Vector/Vector.h"
#include "PolynomialRegression.h"
#include <ctime>

int main() {
	Vector<double> Pts;Pts.v = { { 0,2.1 },{ 1,7.7 },{ 2,12.6 },{ 3,27.2 },{ 4,40.9 },{ 5,61.1 } };
	Vector<double> Pts2; Pts2.v = { { 0,0 },{ 2,215 },{ 4,394 },{ 6,553 },{ 8,639 },{ 10,701 },{12,740},{14,729},{16,653},{18,584},{20,430} };

	Vector<double>dani;
	clock_t start = clock();
	for (int i = 0; i < 1000; i++) {
		dani = NonlinearRegression<double>::PolynomialRegression(Pts2.v, 10);
	}
	double time = clock() - start;
	cout << time<<endl;
	dani.Print();
	getchar();
}