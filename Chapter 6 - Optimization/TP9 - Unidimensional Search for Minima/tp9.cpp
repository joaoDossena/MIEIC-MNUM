#include <iostream>
#include <cmath>
#include <vector>

#define PRECISION 1e-6

using namespace std;

double f(double x) {return sin(x) * sin(x);}

vector<double> thirds(double a, double b, double error, double (*f)(double)) //Calculates a broad interval in which the function's minima is
{
	double c, d, aux;
	vector<double> result;
	while(abs(b - a) > error)
	{
		aux = (b - a)/3; //Divides the interval in 3 thirds
		c = a + aux;
		d = b - aux; //In the order a, c, d, b

		if(f(c) > f(d)) //If the function moves down
			a = c; //Close up the interval on the left
		else //If the function moves up
			b = d; //Close up the interval on the right		
	}

	if(a == c)
	{
		result.push_back(c);
		result.push_back(d);
		result.push_back(b);
	}
	else
	{
		result.push_back(a);
		result.push_back(c);
		result.push_back(d);
	}

	return result;
}

vector<double> searchMinima(double guess, double step, double (*f)(double)) //Calculates a smaller interval in which the function's minima is
{
	vector<double> result;
	if(f(guess) < f(guess + step))
		step = 0;
	double x0 = guess, x1 = guess + step, x2 = guess + 2*step;

	while(f(x1) > f(x2))
	{
		x0 = x1;
		x1 = x2;
		x2 += step;
	}

	result.push_back(x0);
	result.push_back(x1);
	result.push_back(x2);
	return result;
}

double quadrica(double x1, double x2, double x3, double (*f)(double)) //Approximates the small interval to a parabola and calculates its minima
{
	double h = x3 - x2;
	return x2 - (h*(f(x1) - f(x3))) / (2*(f(x3) - 2*f(x2) + f(x1)));
}

int main()
{
	vector<double> resultThirds = thirds(2.0, 4.0, PRECISION, f);
	vector<double> resultMinima = searchMinima(resultThirds.at(0), PRECISION, f);

	cout << "Function's minima's interval:" << endl;

	cout << "Thirds: (" << resultThirds.at(0) << ", " << resultThirds.at(1) <<  ", " << resultThirds.at(2) << ")" << endl; 

	cout << "Search: (" << resultMinima.at(0) << ", " << resultMinima.at(1) <<  ", " << resultMinima.at(2) << ")" << endl; 

	cout << "Final result: " << quadrica(resultMinima.at(0), resultMinima.at(1), resultMinima.at(2), f) << endl;
	

	return 0;
}