#include <iostream>
#include <vector>
#include "gnuplot-iostream/gnuplot-iostream.h"

#define NUM_ITER 500

using namespace std;

double f(double x, double y) {return x*x;} //Function to be integrated



vector<pair<double, double>> euler(double x0, double y0, double h, int numIter, double (*f)(double, double))
{
	vector<pair<double, double>> result;
	double x = x0, y = y0;


	for(unsigned int i = 0; i < numIter; i++)
	{
		result.push_back(make_pair(x, y));

		x += h;
		y += h*f(x, y);
	}

	return result;
}



vector<pair<double, double>> rk2(double x0, double y0, double h, int numIter, double (*f)(double, double))
{
	vector<pair<double, double>> result;
	double x = x0, y = y0;


	for(unsigned int i = 0; i < numIter; i++)
	{
		result.push_back(make_pair(x, y));

		x += h;
		y += h*f(x + h/2, y + h/2*f(x, y));
	}

	return result;
}


vector<pair<double, double>> rk4(double x0, double y0, double h, int numIter, double (*f)(double, double))
{
	vector<pair<double, double>> result;
	double x = x0, y = y0;


	return result;
}


int main()
{
	Gnuplot gp;
	double xInicial = -2.0, yInicial = -5.0/3.0;

	vector<pair<double, double>> pontosEuler = euler(xInicial, yInicial, 0.1, NUM_ITER, f);
	vector<pair<double, double>> pontosRK2 = rk2(xInicial, yInicial, 0.1, NUM_ITER, f);

	gp << "set xrange [-2:2]\nset yrange [-2:2.1]\n";
	
	gp << "plot" << gp.file1d(pontosEuler) << "with lines title 'euler',"
		<< gp.file1d(pontosRK2) << "with lines title 'rk2'"<< endl;


	return 0;
}