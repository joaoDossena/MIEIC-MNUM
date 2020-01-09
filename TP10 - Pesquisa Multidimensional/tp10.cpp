#include <iostream>
#include <cmath>

using namespace std;

#define NUM_PASSOS 50
#define LEARNING_RATE 1e-10

double f(double x, double y)
{ return sin(y) + y*y/4 + cos(x) + x*x/4 - 1; }

double fx(double x, double y)
{ return -sin(x) + x/2; }

double fy(double x, double y)
{ return cos(y) + y/2; }

double fxx(double x, double y)
{ return 1/2 - cos(x); }

double fxy(double x, double y)
{ return 0; }

double fyx(double x, double y)
{ return 0; }

double fyy(double x, double y)
{ return 1/2 - sin(y); }

pair<double, double> gradient(double x, double y, double h, unsigned int n, double (*f) (double, double))
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


pair<double, double> quadrica(double x, double y, double h, unsigned int n, double (*f) (double, double))
{
	double x_ant, y_ant, det;

	for(unsigned int i = 0; i < n; i++)
	{
		x_ant = x;
		y_ant = x;
		det = fxx(x_ant, y_ant) * fyy(x_ant, y_ant) - (fxy(x_ant, y_ant) * fyx(x_ant, y_ant));

		x = x_ant - (fyy(x_ant, y_ant) * fx(x_ant, y_ant) - fxy(x_ant, y_ant) * fy(x_ant, y_ant)) / det;
        y = y_ant - (-fxy(x_ant, y_ant) * fx(x_ant, y_ant) + fxx(x_ant, y_ant) * fy(x_ant, y_ant)) / det;
	}

	return make_pair(x, y);
}

int main()
{
	pair<double, double> grad = gradient(7, 5, LEARNING_RATE, NUM_PASSOS, f);
	cout << "Gradient: " << endl;
	cout << "(" << grad.first << ", " << grad.second << ", " << f(grad.first, grad.second) << ")" << endl;

	pair<double, double> quad = quadrica(grad.first, grad.second, LEARNING_RATE, 20, f);
	cout << "New interval after quadric: " << endl;
	cout << "(" << quad.first << ", " << quad.second << ")" << endl;

	grad = gradient(quad.first, quad.second, LEARNING_RATE, NUM_PASSOS, f);
	cout << "New gradient adjusted: " << endl;
	cout << "(" << grad.first << ", " << grad.second << ", " << f(grad.first, grad.second) << ")" << endl;


	return 0;
}