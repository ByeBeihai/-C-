#include "БъЭЗ.h"
#include <stdio.h>
#include <conio.h>  

void InitBoardArray()
{
	int i, j;

	Board[0][0] = 1;
	Board[SIZE - 1][0] = 2;
	Board[SIZE - 1][SIZE - 1] = 3;
	Board[0][SIZE - 1] = 4;

	for (j = 1; j <= SIZE - 2; j++)
	{
		Board[0][j] = 5;
	}

	for (i = 1; i <= SIZE - 2; i++)
	{
		Board[i][0] = 6;
	}

	for (j = 1; j <= SIZE - 2; j++)
	{
		Board[SIZE - 1][j] = 7;
	}

	for (i = 1; i <= SIZE - 2; i++)
	{
		Board[i][SIZE - 1] = 8;
	}

	for (j = 1; j <= SIZE - 2; j++)
	{
		for (i = 1; i <= SIZE - 2; i++)
		{
			Board[i][j] = 9;
		}
	}
}