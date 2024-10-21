#include <iostream>
#include <malloc.h>
#include <stdlib.h>
#include <time.h>

using namespace std;

class DynamicMatrix
{
	private:

		int** matrix;
		int rows, cols;

		void setMatrixDims()
		{
			cout << "Enter number of rows" << endl;
			cin >> rows;
			cout << "Enter number of cols" << endl;
			cin >> cols;

			rows = abs(rows);
			cols = abs(cols);
		}

		void newMatrix()
		{
			/*
			for (int i = 0; i < rows; ++i)
			{
				delete[] matrix[i];
			}

			delete[] matrix;
			*/
			
			matrix = new int* [rows];
			for (int i = 0; i < rows; i++)
				matrix[i] = new int[cols];
		}

		void fillMatrixRand()
		{
			newMatrix();

			srand(time(0));
			for (int i = 0; i < rows; i++)
				for (int j = 0; j < cols; j++)
					matrix[i][j] = rand() % 10;
		}

		void fillMatrixManually()
		{
			newMatrix();

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

		DynamicMatrix() : rows(1), cols(1)
		{
			matrix = new int* [rows];
			for (int i = 0; i < rows; i++)
				matrix[i] = new int[cols];
		}

		~DynamicMatrix()
		{
			for (int i = 0; i < rows; ++i)	
			{
				delete[] matrix[i];
			}

			delete[] matrix;
		}

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
			int s_rows;
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
			int s_cols;
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

			cout << endl;

			for (int i = 0; i < rows; i++)
			{
				for (int j = 0; j < cols; j++)
				{
					matrix[i][j] *= number;
				}
			}
		}

		//Сложение матриц
		void sum(DynamicMatrix sumMatrix)
		{
			if (rows == sumMatrix.rows && cols == sumMatrix.cols)
			{
				for (int i = 0; i < rows; i++)
				{
					for (int j = 0; j < cols; j++)
					{
						matrix[i][j] += sumMatrix.matrix[i][j];
					}
				}
			}
			else
			{
				cout << "\nmatrixes should have the same dimensions!\n" << endl;
			}
		}

		//Сложение матриц
		void sub(int** matrix2, int rows2, int cols2)
		{
			if (rows == rows2 && cols == cols2)
			{
				for (int i = 0; i < rows; i++)
				{
					for (int j = 0; j < cols; j++)
					{
						matrix[i][j] -= matrix2[i][j];
					}
				}
			}
			else
			{
				cout << "\nmatrixes should have the same dimensions!\n" << endl;
			}
		}

		//Умножение матриц


};

int main()
{
	DynamicMatrix test;
	DynamicMatrix test2;

	test.fillMatrix();
	test.printMatrix();

	//test.sumRows();
	//test.sumCols();

	test.by();
	test.printMatrix();

	test2.fillMatrix();
	test2.printMatrix();

	
	test.sum(test2);
	test.printMatrix();
	
	/*
	cout << "\n-----------------------\n" << endl;

	test2.printMatrix();
	test.printMatrix();

	test2.sub(test.matrix, test.rows, test.cols);
	test2.printMatrix();
	*/

	return 0;
}