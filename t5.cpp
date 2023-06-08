// 4 вариант;
// Вычисление обратной матрицы методом присоединенной матрицы;

#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;


void PrintMatrix(int* ptr[], const unsigned char SIZE_R, const unsigned char SIZE_C)
{
	for (int i = 0; i < SIZE_R; i++) {
		for (int j = 0; j < SIZE_C; j++) {
			cout << setw(9) << ptr[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}


int main()
{
	const unsigned char SIZEi = 4;
	const unsigned char SIZEj = 8;

	int matrix[][SIZEj] = { {-1, -2, 0, 0, 1, 0, 0, 0},
								{-2, -5, -1, 0, 0, 1, 0, 0}, 
								{0, 1, 0, 0, 0, 0, 1, 0}, 
								{-2, -6, -2, -1, 0, 0, 0, 1} };
	int result[][SIZEi] = { {0, 0, 0, 0},
							{0, 0, 0, 0}, 
							{0, 0, 0, 0}, 
							{0, 0, 0, 0} };

	// создание массива указателей массива matrix
	int* ptr[SIZEi]{};
	for (int i = 0; i < SIZEi; i++)
		ptr[i] = matrix[i];

	PrintMatrix(ptr, SIZEi, SIZEj);
	cout << endl;

	// int m = 0;
	// прямой ход;
	for (int k = 0; k < SIZEi; k++)
	{
		// правило прямоугольника по Жордану-Гауссу;
		for (int i = 0; i < SIZEi; i++)
		{
			for (int j = k + 1; j < SIZEj; j++)
			{
				if (i != k)
					matrix[i][j] = (matrix[i][j] * matrix[k][k] - matrix[k][j] * matrix[i][k]) / matrix[k][k];
			}
		}

		// обнуление k-го столбца;
		for (int i = 0; i < SIZEi; i++)
		{
			if (i != k)
			{
				matrix[i][k] = 0;
			}
		}

		// деление элементов k-й строки на matrix[k][k];
		for (int j = SIZEj-1; j >= 0; j--)
		{
			matrix[k][j] /= matrix[k][k];
		}

		// вывод матрицы в консоль;
		PrintMatrix(ptr, SIZEi, SIZEj);
		cout << "====================================================================================" << endl;

	}

	cout << "Answer:" << endl;
	for (int i = 0; i < SIZEi; i++)
	{
		for (int j = SIZEj/2; j < SIZEj; j++)
		{
			result[i][j - SIZEj / 2] = matrix[i][j];
		}
	}
	// создание массива указателей массива result
	int* ptr2[SIZEi]{};
	for (int i = 0; i < SIZEi; i++)
		ptr2[i] = result[i];
	PrintMatrix(ptr2, SIZEi, SIZEi);

	return 0;
}
