#include "标头.h"
#include <stdio.h>
#include <conio.h>  

//一个有点丑陋的胜负判断函数，简单的使用了一堆if套娃，但是工作还是很稳定的
int WINorLOSE()
{
	result = 3;
	int i, j;
	for (i = 0; i <= SIZE - 5; i++)
	{
		for (j = 0; j <= SIZE - 1; j++)
		{
			if (Board[i][j] == WHITE || Board[i][j] == WHITEtem)
			{
				if (Board[i + 1][j] == WHITE || Board[i + 1][j] == WHITEtem)
				{
					if (Board[i + 2][j] == WHITE || Board[i + 2][j] == WHITEtem)
					{
						if (Board[i + 3][j] == WHITE || Board[i + 3][j] == WHITEtem)
						{
							if (Board[i + 4][j] == WHITE || Board[i + 4][j] == WHITEtem)
							{
								result = 0;
							}
							else
								;
						}
						else
							;
					}
					else
						;
				}
				else
					;
			}
			else
				;
		}
	}
	//横向出现白子成5//

	for (i = 0; i <= SIZE - 5; i++)
	{
		for (j = 0; j <= SIZE - 1; j++)
		{
			if (Board[i][j] == BLACK || Board[i][j] == BLACKtem)
			{
				if (Board[i + 1][j] == BLACK || Board[i + 1][j] == BLACKtem)
				{
					if (Board[i + 2][j] == BLACK || Board[i + 2][j] == BLACKtem)
					{
						if (Board[i + 3][j] == BLACK || Board[i + 3][j] == BLACKtem)
						{
							if (Board[i + 4][j] == BLACK || Board[i + 4][j] == BLACKtem)
							{
								result = 1;
							}
							else
								;
						}
						else
							;
					}
					else
						;
				}
				else
					;
			}
			else
				;
		}
	}
	//横向出现黑子成5//

	for (i = 0; i <= SIZE - 1; i++)
	{
		for (j = 0; j <= SIZE - 5; j++)
		{
			if (Board[i][j] == WHITE || Board[i][j] == WHITEtem)
			{
				if (Board[i][j + 1] == WHITE || Board[i][j + 1] == WHITEtem)
				{
					if (Board[i][j + 2] == WHITE || Board[i][j + 2] == WHITEtem)
					{
						if (Board[i][j + 3] == WHITE || Board[i][j + 3] == WHITEtem)
						{
							if (Board[i][j + 4] == WHITE || Board[i][j + 4] == WHITEtem)
							{
								result = 0;
							}
							else
								;
						}
						else
							;
					}
					else
						;
				}
				else
					;
			}
			else
				;
		}
	}
	//纵向出现白子成5//

	for (i = 0; i <= SIZE - 1; i++)
	{
		for (j = 0; j <= SIZE - 5; j++)
		{
			if (Board[i][j] == BLACK || Board[i][j] == BLACKtem)
			{
				if (Board[i][j + 1] == BLACK || Board[i][j + 1] == BLACKtem)
				{
					if (Board[i][j + 2] == BLACK || Board[i][j + 2] == BLACKtem)
					{
						if (Board[i][j + 3] == BLACK || Board[i][j + 3] == BLACKtem)
						{
							if (Board[i][j + 4] == BLACK || Board[i][j + 4] == BLACKtem)
							{
								result = 1;
							}
							else
								;
						}
						else
							;
					}
					else
						;
				}
				else
					;
			}
			else
				;
		}
	}
	//纵向出现黑子成5//

	for (i = 0; i <= SIZE - 5; i++)
	{
		for (j = 0; j <= SIZE - 5; j++)
		{
			if (Board[i][j] == WHITE || Board[i][j] == WHITEtem)
			{
				if (Board[i + 1][j + 1] == WHITE || Board[i + 1][j + 1] == WHITEtem)
				{
					if (Board[i + 2][j + 2] == WHITE || Board[i + 2][j + 2] == WHITEtem)
					{
						if (Board[i + 3][j + 3] == WHITE || Board[i + 3][j + 3] == WHITEtem)
						{
							if (Board[i + 4][j + 4] == WHITE || Board[i + 4][j + 4] == WHITEtem)
							{
								result = 0;
							}
							else
								;
						}
						else
							;
					}
					else
						;
				}
				else
					;
			}
			else
				;
		}
	}
	//左对角线出现白子成5//

	for (i = 0; i <= SIZE - 5; i++)
	{
		for (j = 0; j <= SIZE - 5; j++)
		{
			if (Board[i][j] == BLACK || Board[i][j] == BLACKtem)
			{
				if (Board[i + 1][j + 1] == BLACK || Board[i + 1][j + 1] == BLACKtem)
				{
					if (Board[i + 2][j + 2] == BLACK || Board[i + 2][j + 2] == BLACKtem)
					{
						if (Board[i + 3][j + 3] == BLACK || Board[i + 3][j + 3] == BLACKtem)
						{
							if (Board[i + 4][j + 4] == BLACK || Board[i + 4][j + 4] == BLACKtem)
							{
								result = 1;
							}
							else
								;
						}
						else
							;
					}
					else
						;
				}
				else
					;
			}
			else
				;
		}
	}
	//左对角线出现黑子成5//

	for (i = 0; i <= SIZE - 5; i++)
	{
		for (j = 4; j <= SIZE - 1; j++)
		{
			if (Board[i][j] == WHITE || Board[i][j] == WHITEtem)
			{
				if (Board[i + 1][j - 1] == WHITE || Board[i + 1][j - 1] == WHITEtem)
				{
					if (Board[i + 2][j - 2] == WHITE || Board[i + 2][j - 2] == WHITEtem)
					{
						if (Board[i + 3][j - 3] == WHITE || Board[i + 3][j - 3] == WHITEtem)
						{
							if (Board[i + 4][j - 4] == WHITE || Board[i + 4][j - 4] == WHITEtem)
							{
								result = 0;
							}
							else
								;
						}
						else
							;
					}
					else
						;
				}
				else
					;
			}
			else
				;
		}
	}
	//右对角线出现白子成5//

	for (i = 0; i <= SIZE - 5; i++)
	{
		for (j = 4; j <= SIZE - 1; j++)
		{
			if (Board[i][j] == BLACK || Board[i][j] == BLACKtem)
			{
				if (Board[i + 1][j - 1] == BLACK || Board[i + 1][j - 1] == BLACKtem)
				{
					if (Board[i + 2][j - 2] == BLACK || Board[i + 2][j - 2] == BLACKtem)
					{
						if (Board[i + 3][j - 3] == BLACK || Board[i + 3][j - 3] == BLACKtem)
						{
							if (Board[i + 4][j - 4] == BLACK || Board[i + 4][j - 4] == BLACKtem)
							{
								result = 1;
							}
							else
								;
						}
						else
							;
					}
					else
						;
				}
				else
					;
			}
			else
				;
		}
	}
	//右对角线出现黑子成5//

	return result;
}