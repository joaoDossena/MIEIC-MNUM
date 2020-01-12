#include <iostream>
#include <cmath>

#define ERROR 1e-15

using namespace std;

//Funções
double f1(double x, double y)
{
	double result = 2*x*x - x*y - 5*x + 1;
	return result;
}

double f2(double x, double y)
{
	double result = x + 3*log10(x) - y*y;
	return result;
}


//Derivadas
double df1_dx(double x, double y)
{
	double result = 4*x - y - 5;
	return result;
}

double df1_dy(double x, double y)
{
	double result = -x;
	return result;
}

double df2_dx(double x, double y)
{
	double result = 1 + 3/(log(10)*x);
	return result;
}

double df2_dy(double x, double y)
{
	double result = -2*y;
	return result;
}



//Auxiliar Functions:
//Newton
double jacobian(double x, double y)
{
	double result = df1_dx(x, y) * df2_dy(x, y) - df1_dy(x, y) * df2_dx(x, y);
	return result;
}

double hn(double x, double y)
{
	double result = (f1(x,y) * df2_dy(x,y) - f2(x,y) * df1_dy(x,y))/jacobian(x, y);
	return result;
}

double kn(double x, double y)
{
	double result = (df1_dx(x,y) * f2(x,y) - df2_dx(x,y) * f1(x,y))/jacobian(x,y);
	return result;
}
//Picard-Peano
double exp1x(double x, double y)
{
	double result = (sqrt(-7*y*y + 12*y + 24*log10(x) + 28) + y + 6)/4;
	return result;
}

double exp1y(double x, double y)
{
	double result = (sqrt(12*log10(x) - 7*x*x + 24*x - 4) + x)/2;
	return result;
}

double exp2x(double x, double y)
{
	double result = -(sqrt(-7*y*y + 12*y + 24*log10(x) + 28) + y + 6)/4;
	return result;
}

double exp2y(double x, double y)
{
	double result = -(sqrt(12*log10(x) - 7*x*x + 24*x - 4) + x)/2;
	return result;
}

//Main Functions
void newton()
{
	double x, y, xNovo, yNovo;

	x =  4;   //initial guess for x
	y =  2;   //initial guess for y

	xNovo = x - hn(x, y);
	yNovo = y - kn(x, y);

	while(abs(xNovo - x) > ERROR || abs(yNovo - y) > ERROR)
	{
		x = xNovo;
		y = yNovo;

		xNovo = x - hn(x,y);
		yNovo = y - kn(x,y);

	}

	cout << "Newton:" << endl;
	cout <<  "First solution: (" << xNovo << ", " << yNovo << ")" << endl;

	
	x =  1;   //initial guess for x
	y =  -2;   //initial guess for y

	xNovo = x - hn(x, y);
	yNovo = y - kn(x, y);

	while(abs(xNovo - x) > ERROR || abs(yNovo - y) > ERROR)
	{
		x = xNovo;
		y = yNovo;

		xNovo = x - hn(x,y);
		yNovo = y - kn(x,y);

	}

	cout <<  "Second solution: (" << xNovo << ", " << yNovo << ")" << endl;	
}

void picardPeano()
{
	unsigned int i;
	double x, y;

	x = 1.5;
	y = -1.4;

	for(i = 0; i < 500; i++)
	{
		//cout << x << y << endl;
		x = exp1x(x, y);
		y = exp1y(x, y);
		//cout << x << y << endl;
	}

	cout << "Picard-Peano:" << endl;
	cout << "First solution: (" << x << ", " << y << ")" << endl;


}

int main()
{
	newton();
	picardPeano();

	return 0;
}