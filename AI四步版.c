#include "标头.h"
#include <stdio.h>
#include <conio.h>  
#include <stdlib.h>
#include <time.h>

void AIB(int color, int q)
{
	int a, b;
	//将原来的棋盘映射到虚拟棋盘上。黑子记为1，白子记为2，空位记为0
	for (a = 0; a <= SIZE - 1; a++)
	{
		for (b = 0; b <= SIZE - 1; b++)
		{
			if (Board[a][b] == BLACK || Board[a][b] == BLACKtem)
			{
				Boardtest[a][b] = 1;
			}
			else if (Board[a][b] == WHITE || Board[a][b] == WHITEtem)
			{
				Boardtest[a][b] = 2;
			}
			else
				Boardtest[a][b] = 0;

		}
	}

	int i, j, x, y;
	int empty_place = 225;
	for (i = 0; i <= SIZE - 1; i++)
	{
		for (j = 0; j <= SIZE - 1; j++)
		{
			if (Boardtest[i][j] != 0)
			{
				empty_place = empty_place - 1;
			}
			else
			{
				x = i;
				y = j;
			}
			;
		}
	}
	if (empty_place <= 2)//直接绕开了一个BUG：棋盘上只剩两个空位时，AI程序报错。
	{
		return Airdrop(x, y, color);
	}

	if (color == 1)
	{
		if (Board[7][7] == 9)
			return Airdrop(7, 7, color);
		else;
	}

	int last_score = -1000000, drop_i, drop_j, score;
	int Predrop = 0;
	long start = time(NULL);

	for (i = 0; i <= SIZE - 1; i++)
	{
		for (j = 0; j <= SIZE - 1; j++)
		{
			if ((Boardtest[i][j] == 0) && next1(i, j) != 0)
			{
				Boardtest[i][j] = color;
				score = point(i, j, color, 1);
				switch (score)
				{
				case -23333:
					break;
				case 10000:
					return Airdrop(i, j, color);
					break;
				default:
					score = Step2B(color,score, last_score);
					if (score >= last_score)
					{
						if (Predrop == 0)
							last_score = score, drop_i = i, drop_j = j, Predrop++;
						else
						{
							if (score > last_score)
							{
								last_score = score;
								drop_i = i;
								drop_j = j;
								Predrop = 0;
							}
							else
							{
								srand((unsigned)time(NULL));
								int random = rand() % 2;
								if (random == 1)
								{
									last_score = score;
									drop_i = i;
									drop_j = j;
									Predrop++;
								}
								else
									;
							}

						}
					}
					break;
				}
				Boardtest[i][j] = 0;
			}
			else
				;
			long end = time(NULL);
			int tend=end - start;
			if (tend >= 10)
				return AInew(color, q);//超过10秒自动切换为3步版AI
			else
				;
		}
	}
	return Airdrop(drop_i, drop_j, color);
}

int Step2B(int color, int score1, int last_score1)
{
	int color2 = 3 - color;
	int last_score = 1000000, score2;
	for (int i = 0; i <= SIZE - 1; i++)
	{
		for (int j = 0; j <= SIZE - 1; j++)
		{
			if ((Boardtest[i][j] == 0) && next1(i, j) != 0)
			{
				Boardtest[i][j] = color2;
				score2 = point(i, j, color2, 2);
				switch (score2)
				{
				case -23333:
					break;
				default:
					score2 = -10*score2 + Step3B(color2, score2, last_score);
					if (score2 < last_score)
						last_score = score2;
					else
						;
					break;
				}
				Boardtest[i][j] = 0;
			}
			else
				;
			if (last_score + set_a * score1 < last_score1)//阿尔法贝塔剪枝结构
				return last_score+set_a * score1;
			else
				;
		}
	}
	return last_score+set_a * score1;
}

int Step3B(int color2, int score2, int last_score2)
{
	int color3 = 3 - color2;
	int last_score = -1000000, score3;
	for (int i = 0; i <= SIZE - 1; i++)
	{
		for (int j = 0; j <= SIZE - 1; j++)
		{
			if ((Boardtest[i][j] == 0) && next(i, j) != 0)
			{
				Boardtest[i][j] = color3;
				score3 = point(i, j, color3, 3);
				switch (score3)
				{
				case -23333:
					break;
				case 10000:
					Boardtest[i][j] = 0;
					return 10000;
					break;
				default:
					score3 = Step4B(color3, score3, last_score);
					if (score3 > last_score)
						last_score = score3;
					else
						;
					break;
				}
				Boardtest[i][j] = 0;
			}
			else
				;
			if (last_score - set_c * score2 > last_score2)
				return last_score - set_c * score2;
			else
				;
		}
	}
	return last_score - set_c * score2;
}

int Step4B(int color3, int score3, int last_score3)
{
	int color4 = 3 - color3;
	int last_score = 1000000, score4;
	for (int i = 0; i <= SIZE - 1; i++)
	{
		for (int j = 0; j <= SIZE - 1; j++)
		{
			if ((Boardtest[i][j] == 0) && next(i, j) != 0)
			{
				Boardtest[i][j] = color4;
				score4 = point(i, j, color4, 4);
				switch (score4)
				{
				case -23333:
					break;
				case 10000:
					Boardtest[i][j] = 0;
					return -10000;
					break;
				default:
					score4 = set_e * score3 - 2 * score4;
					if (score4 < last_score)
						last_score = score4;
					else
						;
					break;
				}
				Boardtest[i][j] = 0;
			}
			else
				;
		}
	}
	return last_score;
}

int Step5B(int color4, int score4)//未实现的五步版本的废弃函数，暂且保留待后续优化。不参与任何运算和执行。
{
	int color5 = 3 - color4;
	int last_score = -1000000, score5;
	for (int i = 0; i <= SIZE - 1; i++)
	{
		for (int j = 0; j <= SIZE - 1; j++)
		{
			if ((Boardtest[i][j] == 0) && next(i, j) != 0)
			{
				Boardtest[i][j] = color5;
				score5 = point(i, j, color5, 5);
				switch (score5)
				{
				case 0:
					break;
				case 10000:
					Boardtest[i][j] = 0;
					return 10000;
					break;
				default:
					if (score5 > last_score)
						last_score = score5;
					else
						;
					break;
				}
				Boardtest[i][j] = 0;
			}
			else
				;
		}
	}
	return last_score - set_c * score4;
}
