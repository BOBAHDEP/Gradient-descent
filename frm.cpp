#include "defFunctions.h"
#include "math.h"
#include <iostream>

using namespace std;

void fletcRivsMethod(double epsilon, double x0, double y0) {
	double *x = new double[2];					// минимум
	double r[2], rNext[2],		// направление антиградиента
		lambda;					// (x + lamda*s) -> min в линейной минимизации
	double s[2];				// направление поиска минимума одномерного
	double f_prev = f(x0, y0), w;

	s[0] = r[0] = -gradfx(x0, y0);
	s[1] = r[1] = -gradfy(x0, y0);

	x[0] = x0;
	x[1] = y0;

	int i = 0;
	do {

		f_prev = f(x[0], x[1]);
		i++;
		lambda = getLinearMinimum(s, x[0], x[1]);	// (x + lamda*s) -> min
		//cout<<lambda<<" "<<s[0]<<" "<<s[1]<<" "<<x[0]<<" "<<x[1]<<" "<<i<<" "<<f(x[0], x[1])<<" "<<f_prev<<endl;
		x[0] = x[0] + lambda * s[0];
		x[1] = x[1] + lambda * s[1];
		//cout<<lambda<<" "<<s[0]<<" "<<s[1]<<" "<<x[0]<<" "<<x[1]<<" "<<i<<" "<<f(x[0], x[1])<<" "<<f_prev<<endl;
		rNext[0] = -gradfx(x[0], x[1]);
		rNext[1] = -gradfy(x[0], x[1]);

		w = scalarMultiply(rNext, rNext)/scalarMultiply(r, r);
		cout<<w<<"]]"<<endl;
		r[0] = rNext[0];
		r[1] = rNext[1];

		s[0] = w*s[0] + r[0];
		s[1] = w*s[1] + r[1];

	} while(abs(f_prev - f(x[0], x[1])) > epsilon);

	cout<<"x = "<<x[0]<<" y  = "<<x[1]<<" f = "<<f(x[0], x[1])<<" n = "<<i<<endl;
}

int main() {
	fletcRivsMethod(0.01, -10, 1200);
}