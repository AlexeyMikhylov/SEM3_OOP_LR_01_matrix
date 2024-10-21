#include <iostream>
#include <malloc.h>
#include <stdlib.h>
#include <time.h>

using namespace std;

class DynamicMatrix
{
	private:

		int rows, cols;
		int **matrix;
		int s_rows, s_cols;

		void setMatrixDims()
		{
			cout << "Enter number of rows" << endl;
			cin >> rows;
			cout << "Enter number of cols" << endl;
			cin >> cols;

			rows = abs(rows);
			cols = abs(cols);
		}

		void fillMatrixRand()
		{
			matrix = (int**)malloc(rows * sizeof(int*));
			for (int i = 0; i < rows; i++)
				matrix[i] = (int*)malloc(cols * sizeof(int));

			srand(time(0));
			for (int i = 0; i < rows; i++)
				for (int j = 0; j < cols; j++)
					matrix[i][j] = rand() % 10;
		}

		void fillMatrixManually()
		{
			matrix = (int**)malloc(rows * sizeof(int*));
			for (int i = 0; i < rows; i++)
			{
				matrix[i] = (int*)malloc(cols * sizeof(int));
			}

			for (int i = 0; i < rows; i++)
			{
				for (int j = 0; j < cols; j++)
				{
					cout << "\na[" << i + 1 << "][" << j + 1 << "] : ";
					cin >> matrix[i][j];
				}
			}
		}

	public:

		void fillMatrix()
		{
			setMatrixDims();

		gt:

			int opt;

			cout << "1 - auto fill" << "\n" << "2 - manual fill" << endl;
			cin >> opt;

			switch (opt)
			{
			case 1:
				fillMatrixRand();
				break;
			case 2:
				fillMatrixManually();
				break;
			default:
				cout << "oopsie\n" << endl;
				goto gt;
				break;
			}
		}

		void printMatrix()
		{
			cout << "\n" << " ~ MATRIX ~ " << endl;
			for (int i = 0; i < rows; i++)
			{
				for (int j = 0; j < cols; j++)
				{
					cout << matrix[i][j] << "\  ";
				}
				cout << "\n" << endl;
			}
		}

		void sumRows()
		{
			cout << "sum of rows" << endl;
			for (int i = 0; i < rows; i++)
			{
				s_rows = 0;
				for (int j = 0; j < cols; j++)
				{
					s_rows += matrix[i][j];
				}
				cout << "Row " << i+1 << ": " << s_rows << endl;
			}
			cout << endl;
		}

		void sumCols()
		{
			cout << "sum of cols" << endl;
			for (int j = 0; j < cols; j++)
			{
				s_cols = 0;
				for (int i = 0; i < rows; i++)
				{
					s_cols += matrix[i][j];
				}
				cout << "Col " << j + 1 << ": " << s_cols << endl;
			}
			cout << endl;
		}

		//умножение матрицы на число
		void by()
		{
			int number;
			cout << "input number: ";
			cin >> number;

			cout << "\n" << endl;

			for (int i = 0; i < rows; i++)
			{
				for (int j = 0; j < cols; j++)
				{
					matrix[i][j] = 0;
				}
			}
		}

		void freeMatrix()
		{
			free(matrix);
		}

	//тут двумерный массив динамический

	//функции:

	// функции принимает аргументом объект:
		//Сложение матриц 

		//Вычитание матриц

		//Умножение матриц (ФАКультативно)
		// n1xm1 * n2m2 ; m1=n2

	//Деструктор
};

int main()
{
	//тут объект класса матрица1 и матрица2 (если надо)

	//Через switch-case выбор операции над матрицей(ами)

	//ввод матрицы (одной или двух)

	//вывод матрицы

	//осталные операции

	DynamicMatrix test;
	test.fillMatrix();
	test.printMatrix();
	test.sumRows();
	test.sumCols();
	test.freeMatrix();

	test.by();
	test.printMatrix();

	return 0;
}