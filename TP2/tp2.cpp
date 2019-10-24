#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

double func(double x)
{
	return x*x - 3*x - 5;
}

double deriv(double x)
{
	return 2*x - 3;
}

double g(double x)
{
	return (x*x - 5)/3;
}

double g2(double x)
{
	return (3*x + 5)/x;
}

vector<double> bisection()
{
	vector<double> result;
	double lowerBound = -2, upperBound = 0, average = (lowerBound + upperBound)/2;
	double error = 0.00000000001;

	while(abs(upperBound - lowerBound) > error)
	{
		if(func(lowerBound) > 0 && func(average) < 0)
		{
			upperBound = average;
			average = (lowerBound + upperBound)/2;
		}

		else if(func(upperBound) < 0 && func(average) > 0)
		{
			lowerBound = average;
			average = (lowerBound + upperBound)/2;
		}
	}

	result.push_back(average);

	lowerBound = 0;
	upperBound = 5;
	average = (lowerBound + upperBound)/2;

	while(abs(upperBound - lowerBound > error))
	{
		if(func(lowerBound) * func(average) < 0 )
		{
			upperBound = average;
			average = (lowerBound + upperBound)/2;
		}

		else if(func(upperBound) * func(average) < 0)
		{
			lowerBound = average;
			average = (lowerBound + upperBound)/2;
		}
	}

	result.push_back(average);

	return result;

}

vector<double> falsePosition()
{
	vector<double> result;
	int maxRep = 200;
	double a = -2, b = 0, c;

	while(abs(b-a)>1e-10 && maxRep > 0)
	{
		c = (a*func(b) - b*func(a)) / (func(b) - func(a));
		if(func(c) == 0.0)
			break;

		else if(func(c)*func(a) < 0)
			b = c;
		else
			a = c;
		maxRep--;
	}

	result.push_back(c);

	a = 0;
	b = 5;
	maxRep = 200;

	while(abs(b-a)>1e-10 && maxRep > 0)
	{
		c = (a*func(b) - b*func(a)) / (func(b) - func(a));
		if(func(c) == 0.0)
			break;

		else if(func(c)*func(a) < 0)
			b = c;
		else
			a = c;

		maxRep--;
	}

	result.push_back(c);

	return result;
}

vector<double> newton()
{
	double x0 = -2, x1;
	vector<double> result;
	
	x1 = x0 - func(x0)/deriv(x0);

	while(abs(x1-x0) >= 1E-10)
	{
		x0 = x1;
		x1 = x0 - func(x0)/deriv(x0);
	}

	result.push_back(x1);

	x0 = 5;
	x1 = x0 - func(x0)/deriv(x0);

	while(abs(x1-x0) >= 1E-10)
	{
		x0 = x1;
		x1 = x0 - func(x0)/deriv(x0);
	}

	result.push_back(x1);

	return result;
}

vector<double> picardPeano()
{
	vector<double> result;

	double guess = 0;

	for(unsigned int i = 0; i < 100; i++)
	{
		guess = g(guess);
	}

	result.push_back(guess);

	guess = 5;

	for(unsigned int i = 0; i < 100; i++)
	{
		guess = g2(guess);
	}

	result.push_back(guess);

	return result;
}

int main()
{
	vector<double> result = bisection();
	cout << "Bisection: "  << endl << result.at(0) << endl << result.at(1) << endl;
	result = falsePosition();
	cout << "False Position: " << endl << result.at(0) << endl << result.at(1) << endl;
	result = newton();
	cout << "Newton: " << endl << result.at(0) << endl << result.at(1) << endl;
	result = picardPeano();
	cout << "Picard Peano: " << endl << result.at(0) << endl << result.at(1) << endl;


	return 0;
}