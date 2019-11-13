#include <iostream>

#define STEPS_TRAPEZIUM 150
#define STEPS_SIMPSON 1

using namespace std;

double f(double x) {return x*x;}

double trapeziumRule(double a, double b, int n)
{
	double h = (b-a)/n;
	double x = a + h;
	double soma = f(a) + f(b), temp = 0;

	for(int i = 1; i <= n - 1; i += 1)
	{
		temp += f(x);
		x += h;
	}
	temp *= 2;
	soma += temp;
	soma = soma * h/2;

	return soma;
}

double simpsonRule(double a, double b, int n)
{
	double h = ((b-a)/n);
	n = n/2;
	
	
	double x;
	double soma = f(a) + f(b), temp = 0, temp2 = 0;

	for(int i = 1; i <= 2*n - 1; i += 2)
	{
		x = a + i*h;
		temp += f(x);
	}
	temp *= 4;
	
	for(int i = 2; i <= 2*n - 2; i += 2)
	{
		x = a + i*h;
		temp2 += f(x);
	}
	temp2 *= 2;
	soma += temp + temp2;
	soma = soma * h/3;

	return soma;
}

int main()
{
	double expectedResult = 64.0/3.0;
	double trapRule = trapeziumRule(0, 4, STEPS_TRAPEZIUM);
	double simpRule = simpsonRule(0, 4, STEPS_SIMPSON);
	double Et0 = expectedResult - trapRule;
	double Et1 = expectedResult - trapeziumRule(0, 4, STEPS_TRAPEZIUM*2);
	double Es0 = expectedResult - simpRule;
	double Es1 = expectedResult - simpsonRule(0, 4, STEPS_SIMPSON*2);

	cout << "Expected: " << expectedResult << endl << endl;

	cout << "Trapezium Rule: " <<  trapRule << endl;
	cout << "Et0: " << Et0 << endl;
	cout << "Et1: " << Et1 << endl; 
	cout << "Et0/Et1: " << Et0/Et1 << endl << endl;


	cout << "Simpson Rule: " << simpRule << endl;
	cout << "Es0: " << Es0 << endl;
	cout << "Es1: " << Es1 << endl;
	cout << "Es0/Es1: " << Es0/Es1 << endl;


	return 0;
}