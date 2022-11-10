#include <iostream>
#include "TMatrix.h"
#include "TVector.h"
#include <locale>

using namespace std;

int main()
{
	setlocale(LC_ALL, "rus");
	TMatrix<int> A(4); 
	TMatrix<int> B(4);
	TMatrix<int> C(4);
	int i, j;

	//Наши матрица А и В
	for (i = 0; i < A.GetSizematr(); i++) {
		for (j = i; j < A.GetSizematr(); j++)
		{
			A[i][j] = i * 10 + j;
			B[i][j] = (i * 10 + j) * 100;
		}
	}
	C = A + B;

	cout << "Матрица А = " << endl << A << endl;

	cout << "Матрица B = " << endl << B << endl;

	cout << "Матрица C = A + B" << endl << C << endl;

	C = A - B;

	cout << "Матрица С = А - В" << endl << C;

	B = A * C;

	cout << "Матрица А*C = " << endl << B << endl;

	return 0;
}
