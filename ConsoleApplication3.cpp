#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <windows.h>

#include "Header.hpp"

using namespace std;
using namespace input;
using namespace funct;
using namespace output;

struct wall
{
	int s1, n1, n2, s2;
};
wall Sides;

int matrix1[100][100], number;

//n - столбцов 
//s - строк

int main()
{

	setlocale(LC_ALL, "Russian");

	cout << "Enter the matrix size\n(First - the columns, then - rows)\n";
	cin >> Sides.n1 >> Sides.s1;
	cout << "\nEnter the matrix\n";
	for (int i = 0; i < Sides.s1; i++)
		for (int j = 0; j < Sides.n1; j++)
		{ 
			cin >> matrix1[i][j];
			InPut(matrix1[i][j], i, j);
		}


	int min = INT_MAX, l = 0, param = 0, max = 1;


	for (int i = 0; i < Sides.s1; i++)
		for (int j = 0; j < Sides.n1; j++)
			if (matrix1[i][j] < min)
				min = matrix1[i][j];
	

	int counter = 0;
	for (int i = 0; i < Sides.s1; i++)
		for (int j = 0; j < Sides.n1; j++)
			if (matrix1[i][j] == min)
				counter++;

	
	int counter_2 = 0;
	for (int i = 0; i < Sides.s1; i++)
		for (int j = 0; j < Sides.n1; j++)
			if (itsProst(matrix1[i][j]) == TRUE)
				counter_2++;

	MainOperation(Sides.s1, Sides.n1, counter, counter_2);

	cout << "\n\nThe changed matrix: \n";


	OutPut(Sides.s1, Sides.n1);

	_getch();
}