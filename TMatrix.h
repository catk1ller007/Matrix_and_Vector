#pragma once
//#include <iostream>
#include "TVector.h"

using namespace std;

template<typename T>
class TMatrix
{
private:
	TVector<TVector<T>> matrica;
	int size_matrica;
public:
	TMatrix(int size = 0)
	{
		size_matrica = size;
		matrica = TVector<TVector<T>>(size_matrica, 0);
		for (int i = 0; i < size_matrica; i++)
		{
			matrica[i] = TVector<T>(size_matrica - i, i);
		}
	}
	~TMatrix()
	{
	}
	TMatrix(const TMatrix& tmp)
	{
		size_matrica = tmp.size_matrica;
		matrica = tmp.matrica;
	}
	TMatrix& operator= (const TMatrix& tmp)
	{
		size_matrica = tmp.size_matrica;
		matrica = tmp.matrica;
		return *this;
	}
	TVector<T>& operator[](int k)
	{
		return matrica[k];
	}
	
	//сложение матриц
	TMatrix operator+ (TMatrix tmp)
	{
		TMatrix res;
		if (size_matrica = tmp.size_matrica)
		{
			res.size_matrica = size_matrica;
			res.matrica = matrica + tmp.matrica;
		}
		return res;
	}
	//вычитание матриц
	TMatrix operator- (TMatrix tmp)
	{
		TMatrix res;
		if (size_matrica = tmp.size_matrica)
		{
			res.size_matrica = size_matrica;
			res.matrica = matrica - tmp.matrica;
		}
		return res;
	}
	//перемножение матриц
	TMatrix operator* (TMatrix tmp)
	{
		TMatrix res(*this);
		TMatrix C;
		if (size_matrica = tmp.size_matrica)
		{
			C = TMatrix(size_matrica);
			for (int i = 0; i < size_matrica; i++)
			{
				for (int j = i; j < size_matrica; j++)
				{
					C[i][j] = 0;
					for (int k = i; k <= j; k++)
					{
						C[i][j] += res[i][k] * tmp[k][j];
					}
				}
			}
		}
		return C;
	}
	TMatrix operator* (int k)
	{
		TMatrix res(*this);
		res.matrica = matrica * k;
		return res;
	}
	int GetSizematr()
	{
		return size_matrica;
	}

	friend ostream& operator<<(ostream& out, TMatrix& mt)
	{
		for (int i = 0; i < mt.size_matrica; i++)
		{
			out << mt.matrica[i] << endl;
		}
		return out;
	}
};
