#include <iostream>

using namespace std;

#define NUM_PASSOS 50
#define LEARNING_RATE 1e-10

double f(double x, double y)
{ return y*y - 2*x*y - 6*y + 2*x*x + 12; }

double fx(double x, double y)
{ return -2*y + 4*x; }

double fy(double x, double y)
{ return 2*y - 2*x - 6; }

pair<double, double> gradient(double x, double y, double h, double n, double (*f) (double, double))
{
	double xn, yn, zn;

	for(unsigned int i = 0; i < n; i++)
	{
		xn = x - h*fx(x, y);
		yn = y - h*fy(x, y);
		zn = f(xn, yn);

		if(zn < f(x, y))
		{
			h *= 2;
			y = yn;
			x = xn;
		}

		else if(f(x, y) < zn)
			h /= 2;
		else
			break;

	}

	return make_pair(x, y);
}

int main()
{
	pair<double, double> res = gradient(7, 5, LEARNING_RATE, NUM_PASSOS, f);
	cout << "(" << res.first << ", " << res.second << ", " << f(res.first, res.second) << ")" << endl;

	return 0;
}