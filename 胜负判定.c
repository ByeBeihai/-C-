#include "��ͷ.h"
#include <stdio.h>
#include <conio.h>  

//һ���е��ª��ʤ���жϺ������򵥵�ʹ����һ��if���ޣ����ǹ������Ǻ��ȶ���
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
	//������ְ��ӳ�5//

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
	//������ֺ��ӳ�5//

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
	//������ְ��ӳ�5//

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
	//������ֺ��ӳ�5//

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
	//��Խ��߳��ְ��ӳ�5//

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
	//��Խ��߳��ֺ��ӳ�5//

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
	//�ҶԽ��߳��ְ��ӳ�5//

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
	//�ҶԽ��߳��ֺ��ӳ�5//

	return result;
}