#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <windows.h>

#include "Header.hpp"
using namespace std;

int mas[100][100];

namespace input
{
	void InPut(int a, int i, int j)
	{
		mas[i][j] = a;
	}
}

namespace funct
{
	bool itsProst(int n)
	{
		for (int i = 2; i < n; i++)
			if (n % i == 0)
				return FALSE;
		return TRUE;
	}

	void MainOperation(int s1, int n1, int counter, int counter_2)
	{
		int b = 0, swap, mas_1[100];

		for (int i = 0; i < s1; i++)
			mas_1[i] = 1;

		if ((counter >= 2) && (counter_2 >= 2))
		{
			for (int i = 0; i < s1; i++)
			{
				for (int j = 0; j < n1; j++)
				{
					mas_1[i] *= mas[i][j];
				}
			}

			for (int j = 0; j < s1; j++)
			{
				b = j;
				for (int k = j; k < n1; k++)
				{
					if (mas_1[k] >= mas_1[b])
						b = k;
				}
				for (int i = 0; i < s1; i++)
				{
					swap = mas[j][i];
					mas[j][i] = mas[b][i];
					mas[b][i] = swap;
				}
			}
		}
		else
		{
			cout << "The conditions are not met. Nothing will be sorted\n";
		}

	}
}


namespace output
{
	void OutPut(int s1, int n1)
	{
		for (int i = 0; i < s1; i++)
		{
			for (int j = 0; j < n1; j++)
				cout << mas[i][j] << " ";
			cout << "\n";
		}
	}
}