#include <iostream>
#include <cmath>

using namespace std;

double babylonianMethod(double n)
{
	double error = 1;
	double x1 = n/2, x2;

	while(error > 1E-14)
	{
		x2 = (x1 + (n/x1))/2;
		error = abs(x2 - x1);
		x1 = x2;
	}

	return x2;
}

double bisectionMethod(double n)
{
	double upperBound = n, lowerBound = 0, average = (upperBound+lowerBound)/2;
	while(upperBound-lowerBound> 1E-14)
	{
		if(lowerBound*lowerBound<n && average*average>n)
		{
			upperBound = average;
			average = (upperBound+lowerBound)/2;
		}
		else if(average*average<n && upperBound*upperBound>n)
		{
			lowerBound = average;
			average = (upperBound+lowerBound)/2;
		}

	}

	return 	upperBound;
	
}

int main()
{
	double n, babM,bisM, sysF;

	cout << "Type a number: ";
	cin >> n;
	babM = babylonianMethod(n);
	sysF = sqrt(n);
	bisM = bisectionMethod(n);
	cout << endl << "Its square root (babylonian method) is: " << babM << endl;
	cout << "Its square root (bisection method) is: " << bisM << endl;
	cout << "Its sqrt is: " << sysF << endl << endl;

	if(bisM != sysF)
		cout << "Bisection Method is different from sqrt" <<endl;
	if(babM != sysF)
		cout << "Babylonian Method is different from sqrt" << endl;

	return 0;
}