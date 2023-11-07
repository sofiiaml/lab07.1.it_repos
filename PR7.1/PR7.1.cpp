#include <iostream>
#include <iomanip>
#include <time.h>
using namespace std;
void Create(int** y, const int rowCount, const int colCount, const int Low,
	const int High);
void Print(int** y, const int rowCount, const int colCount);
void Sort(int** y, const int rowCount, const int colCount);
void Change(int** y, const int row1, const int row2, const int colCount);
void Calc(int** y, const int rowCount, const int colCount, int& S, int& k);

void Create(int** y, const int rowCount, const int colCount, const int Low,
	const int High)
{
	for (int i = 0; i < rowCount; i++)
		for (int j = 0; j < colCount; j++)
			y[i][j] = Low + rand() % (High - Low + 1);
}
void Print(int** y, const int rowCount, const int colCount) // кількість рядків і стовпців у динамічному двовимірному масиві
{
	cout << endl;
	for (int i = 0; i < rowCount; i++)
	{
		for (int j = 0; j < colCount; j++)
			cout << setw(4) << y[i][j];
		cout << endl;
	}
	cout << endl;
}
void Sort(int** y, const int rowCount, const int colCount)
{
	for (int i0 = 0; i0 < rowCount - 1; i0++)
		for (int i1 = 0; i1 < rowCount - i0 - 1; i1++)
			if ((y[i1][0] > y[i1 + 1][0])
				||
				(y[i1][0] == y[i1 + 1][0] &&
					y[i1][1] > y[i1 + 1][1])
				||
				(y[i1][0] == y[i1 + 1][0] &&
					y[i1][1] == y[i1 + 1][1] &&
					y[i1][3] > y[i1 + 1][3]))
				Change(y, i1, i1 + 1, colCount);
}
void Change(int** y, const int row1, const int row2, const int colCount)
{
	int tmp;
	for (int j = 0; j < colCount; j++)
	{
		tmp = y[row1][j];
		y[row1][j] = y[row2][j];
		y[row2][j] = tmp;
	}
}
void Calc(int** y, const int rowCount, const int colCount, int& sum, int& count)
{
	sum = 0;
	count = 0;
	for (int i = 0; i < rowCount; i++)
		for (int j = 0; j < colCount; j++)
			if (y[i][j] % 2 != 0 || !(y[i][j] % 3 == 0))
			{
				sum += y[i][j];
				count++;
				y[i][j] = 0;
			}
}
int main()
{
	srand((unsigned)time(NULL));
	int Low = 11;
	int High = 64;
	int rowCount = 8;
	int colCount = 5;
	int** y = new int* [rowCount];
	for (int i = 0; i < rowCount; i++)
		y[i] = new int[colCount];
	Create(y, rowCount, colCount, Low, High);
	cout << "Array:" ;
	Print(y, rowCount, colCount);
	cout << "Sort Array:";
	Sort(y, rowCount, colCount);
	Print(y, rowCount, colCount);
	int sum = 0;
	int count = 0;
	Calc(y, rowCount, colCount, sum, count);
	cout << setw(4) << "S = " << sum << endl;
	cout << setw(4) << "k = " << count << endl;
	cout << "Changed Array:";
	Print(y, rowCount, colCount);
	for (int i = 0; i < rowCount; i++)
		delete[] y[i];
	delete[] y;
	return 0;
}