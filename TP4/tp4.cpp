#include <iostream>
#include <vector>
#include <iomanip>
#define ERROR 1e-2

using namespace std;

typedef vector<vector<double>> matrix;



void printMatrix(matrix &m) //Prints a matrix on the console
{
	unsigned int i, j;
	for(i = 0; i < m.size(); i++)
	{
		for(j = 0; j < m[i].size(); j++)
		{
			cout << setw(10) << m[i][j];
		}
		cout << endl;
	}
	cout << endl;
}


void rowOp(matrix &m, unsigned int a, unsigned int b, double k) //Row A = Row A - K*Row B
{
	unsigned int i;
	for(i = 0; i < m[0].size(); i++)
	{
		m[a][i] -= k * m[b][i];
	}
}

void gauss(matrix &m) //Nx(N+1)
{
	matrix n = m; //Makes a copy of the matrix so we can compare it to the initial one
	double x, y, z; // Variables to store the results

	unsigned int i, j;


	for(i = 0; i < n.size(); i++)
	{
		rowOp(n, i, i, 1-1/n[i][i]);
		for(j = 0; j < n.size(); j++)
		{
			if(i != j)
			{
				rowOp(n, j, i, m[j][i]);
			}
		}
	}
	
	cout << "Solved matrix: " << endl;
	printMatrix(n);


	z = n[2][3]/n[2][2];
	y = (n[1][3] - n[1][2] * z)/n[1][1];
	x = (n[0][3] - n[0][2] * z - n[0][1] * y)/n[0][0];

	cout << "x = " << x << endl;
	cout << "y = " << y << endl;
	cout << "z = " << z << endl << endl;


	cout << "Residue: " << endl;
	cout << "First line: " << m[0][3] - (m[0][0] * x + m[0][1] * y + m[0][2] * z) << endl;
	cout << "Second line: " << m[1][3] - (m[1][0] * x + m[1][1] * y + m[1][2] * z) << endl;
	cout << "Third line: " << m[2][3] - (m[2][0] * x + m[2][1] * y + m[2][2] * z) << endl;
}



int main()
{
	matrix mat{{9, 1, 5, 25},
			   {1, 4, 6, 16},
			   {2, 9, 7, 29}};

	cout << "Initial matrix: " << endl;
	printMatrix(mat);

	gauss(mat);


	return 0;
}