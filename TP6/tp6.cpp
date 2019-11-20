#include <iostream>
#include <cmath>

#define STEPS_SIMPSON 1

using namespace std;


double f(double x, double y) {return 2;}

double g(double x, double y) {return x*y + sin(x);}

double cubatura(double x0, double x, double y0, double y, int n, double (*f)(double x, double y))
{
	double hx = (x - x0)/2;
	double hy = (y - y0)/2;
	double integral = 0;

	for(int i = 0; i < 3; i++)
	{
		double temp = 0;
		for(int j = 0; j < 3; j++)
		{
			if(j == 1)
				temp += 4 * f(j, i);
			else
				temp += f(j, i);
		}

		if(i == 1)
			integral += 4 * temp;
		else
			integral += temp;
	}

	integral *= (hx * hy)/9;

	return integral;
}


int main()
{

	cout << "Double Integral of f(x,y): " << cubatura(0, 2, 0, 2, STEPS_SIMPSON, f) << endl; 
	cout << "Double Integral of g(x,y): " << cubatura(0, 2, 0, 2, STEPS_SIMPSON, g) << endl;
	

	return 0;
}