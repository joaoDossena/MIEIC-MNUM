#include <iostream>
#include <vector>
#include "gnuplot-iostream/gnuplot-iostream.h"

#define NUM_ITER 500

using namespace std;

double f(double x, double y, double z) {return x*x + y;} //First differential equation of the system of equations

double g(double x, double y, double z) {return x*x + z + 5;} //Second differential equation of the system of equations



vector<tuple<double, double, double>> euler(double x0, double y0, double z0, double h, int numIter, double (*f)(double, double, double), double (*g)(double, double, double))
{
	vector<tuple<double, double, double>> result;
	double x = x0, y = y0, z = z0;

	for(unsigned int i = 0; i < numIter; i++)
	{
		result.push_back(make_tuple(x, y, z));

		x += h;
		y += h*f(x, y, z);
		z += h*g(x, y, z);
	}

	return result;
}

int main()
{
	Gnuplot gp;
	double xInicial = 0.0, yInicial = 0.0, zInicial = 0.0;

	vector<tuple<double, double, double>> pontosEuler = euler(xInicial, yInicial, zInicial, 0.1, NUM_ITER, f, g);


	gp << "set xrange [-1:6]\nset yrange [-1:25]\n";

	gp << "splot" << gp.file1d(pontosEuler) << "with lines title 'euler'" << endl;

}
