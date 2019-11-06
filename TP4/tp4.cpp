#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

typedef vector<vector<double>> matrix;

//Auxiliar functions
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


void rowOp(matrix &m, unsigned int a, unsigned int b, double k) //Does the following operation: Row A = Row A - K*Row B
{
	unsigned int i;
	for(i = 0; i < m[0].size(); i++)
	{
		m[a][i] -= k * m[b][i];
	}
}

vector<double> gauss(matrix &m) //Solves a system of equations of 3x4 matrix and returns vector with solutions (x, y, z)
{
	vector<double> res = {0, 0, 0}; // Variables to store the results

	unsigned int i, j;


	for(i = 0; i < m.size(); i++)
	{
		rowOp(m, i, i, 1-1/m[i][i]);
		for(j = i+1; j < m.size(); j++)
		{
			if(i != j)
			{
				rowOp(m, j, i, m[j][i]);
			}
		}
	}

	res.at(2) = m[2][3]/m[2][2];
	res.at(1) = (m[1][3] - m[1][2] * res.at(2))/m[1][1];
	res.at(0) = (m[0][3] - m[0][2] * res.at(2) - m[0][1] * res.at(1))/m[0][0];

	return res;
}

void printResult(vector<double> res) //Prints vector with solution (x, y, z)
{
	cout << "x = " << res.at(0) << endl;
	cout << "y = " << res.at(1) << endl;
	cout << "z = " << res.at(2) << endl << endl;
}

void printResidue(matrix &m, vector<double> res) //Prints the difference of independent terms
{
	cout << "Residue: " << endl;
	cout << "1st line: " << m[0][3] - (m[0][0] * res.at(0) + m[0][1] * res.at(1) + m[0][2] * res.at(2)) << endl;
	cout << "2nd line: " << m[1][3] - (m[1][0] * res.at(0) + m[1][1] * res.at(1) + m[1][2] * res.at(2)) << endl;
	cout << "3rd line: " << m[2][3] - (m[2][0] * res.at(0) + m[2][1] * res.at(1) + m[2][2] * res.at(2)) << endl;
}


int main()
{
	vector<double> result;
	matrix mat{{9, 1, 5, 25}, //Declaring 3x4 matrix
			   {1, 4, 6, 16},
			   {2, 9, 7, 29}};
	matrix original = mat; //Makes a copy of the matrix so we can compare it to the initial one


	cout << "Initial matrix: " << endl; //Prints original matrix
	printMatrix(original);


	result = gauss(mat); //Solves matrix "mat" and puts results to the vector "result"


	cout << "Solved matrix: " << endl; //Prints solved matrix
	printMatrix(mat);


	printResult(result); //Prints (x, y, z)

	printResidue(original, result); //Prints residue (plugs result in matrix and compares independent terms with the original one)



	return 0;
}