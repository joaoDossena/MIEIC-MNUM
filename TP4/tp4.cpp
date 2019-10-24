#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

//Trocar tudo por iteradores com números

void printMatrix(vector<vector<double>> matrix)
{
	vector<vector<double>>::iterator itLinha;
	vector<double>::iterator itElemLinha;

	for(itLinha = matrix.begin(); itLinha != matrix.end(); itLinha++)
	{

		for(itElemLinha = itLinha->begin(); itElemLinha != itLinha->end(); itElemLinha++)
		{
			cout << setw(7) << *itElemLinha ;
		}
		cout << endl;
	}
}

void gauss(vector<vector<double>> matrix, vector<double> results) //NxN Matrix and 1xN Vector
{
	vector<vector<double>>::iterator itLinha;
	vector<double>::iterator itElemLinha;

	printMatrix(matrix);

	double pivot = matrix.at(0).at(0);
	double aux;
	for(itLinha = matrix.begin() + 1; itLinha != matrix.end(); itLinha++)
	{
		aux = itLinha->at(0);
		for(itElemLinha = itLinha->begin(); itElemLinha != itLinha->end(); itElemLinha++)
		{

			*itElemLinha *= pivot/aux;
		}
		
	}
	cout << endl << endl;
	printMatrix(matrix);
}



int main()
{
	vector<vector<double>> mat{{9, 1, 5}, {1, 4, 6}, {2, 9, 7}};
	vector<double> res{25, 16, 29};

	gauss(mat, res);


	return 0;
}