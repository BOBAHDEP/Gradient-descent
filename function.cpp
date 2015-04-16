#include "math.h"
#include "defFunctions.h"
#include <iostream>

using namespace std;

double f(double x, double y) {
	return x*x + y*y + (x-y)*(x-y)*(x-y)*(x-y);
}

double gradfx(double x, double y) {
	std::cout<<2*x + 4*(x-y)*(x-y)*(x-y)<<endl;
	return 2*x + 4*(x-y)*(x-y)*(x-y)/100000;
}

double gradfy(double x, double y) {
	std::cout<<2*y - 4*(x-y)*(x-y)*(x-y)<<"#"<<endl;
	return 2*y - 4*(x-y)*(x-y)*(x-y)/100000;
}

double getLinearMinimum(double s[2], double x0, double y0) {	//метод золотого сечения
	const double eps = 1e-2;
    const double tay = 1.618;
    double a = 0;
    double b = 1e4;
    double x01, x02,					// параметр
		xf1, xf2;						// значения ф-и

	double t1[2], t2[2];				// значения на плоскости
    x01 = b - (b - a) / tay;			// расчитываем точки деления
    x02 = a + (b - a) / tay;         

    
    t1[0] = x0 + x01 * s[0];
    t1[1] = y0 + x01 * s[1];
    t2[0] = x0 + x02 * s[0];
    t2[1] = y0 + x02 * s[1];
    xf1 = f(t1[0], t1[1]);				// расчитываем в точках деления значение целевой функции
    xf2 = f(t2[0], t2[1]);

	int i = 0;
	//cout<<a<<" ----- "<<b<<" ---- "<<abs(b - a)<<" "<<(abs(b - a) < eps)<<endl;
	while(abs(b - a) > eps) {
		if(xf1 >= xf2) {
			a = x01;
			x01 = b - (b - a) / tay;
			x02 = a + (b - a) / tay;
		    t1[0] = x0 + x01 * s[0];
			t1[1] = y0 + x01 * s[1];
			t2[0] = x0 + x02 * s[0];
			t2[1] = y0 + x02 * s[1];
			xf1 = f(t1[0], t1[1]);			// расчитываем в точках деления значение целевой функции
			xf2 = f(t2[0], t2[1]);
		}else {
			b = x02;
			x01 = b - (b - a) / tay;
			x02 = a + (b - a) / tay;
		    t1[0] = x0 + x01 * s[0];
			t1[1] = y0 + x01 * s[1];
			t2[0] = x0 + x02 * s[0];
			t2[1] = y0 + x02 * s[1];
			xf1 = f(t1[0], t1[1]);			// расчитываем в точках деления значение целевой функции
			xf2 = f(t2[0], t2[1]);
		}
	}
    return (a + b) / 2;
}

double scalarMultiply(double x[2], double y[2]) {
	return x[0]*y[0] + x[1]*y[1];
}