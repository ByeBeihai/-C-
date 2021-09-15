#include "标头.h"
#include <stdio.h>
#include <conio.h>  
#include <stdlib.h>
#include <time.h>
#include"omp.h"

void AI(int color,int q)//三步保守型
{
	int a, b;
	//将原来的棋盘映射到虚拟棋盘上。黑子记为1，白子记为2，空位记为0
	for (a = 0; a <= SIZE-1; a++)
	{
		for (b = 0; b <= SIZE-1; b++)
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
	int i, j,x,y;
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
		if (Boardtest[7][7] == 0)
			return Airdrop(7, 7, color);//开局下在天元处
		else;
	}
	int last_score = -1000000, drop_i, drop_j, score;
	int Predrop = 0;

    for (i = 0; i <= SIZE -1; i++)
    {
        for (j = 0; j <= SIZE -1 ; j++)
        {
			if ((Boardtest[i][j] == 0)&&((q<=4&& next(i,j)!=0)||q>=5))
			{
				Boardtest[i][j] = color;
				score = point(i, j, color,1);
				switch (score)
				{
				case -23333:
					break;//禁手分数为-23333 不可下
				case 10000:
					return Airdrop(i, j, color);
					break;
				default:
					score = Step2(color,score,last_score);
					if (score >= last_score)
					{
						if (Predrop == 0)
							last_score = score, drop_i = i, drop_j = j, Predrop++;
						else
						{
							if (score > last_score)
							{
								last_score = score;
								drop_i = i ;
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
        }
    }
	return Airdrop(drop_i, drop_j, color);
}

int Step2(int color,int score1,int last_score1)
{
	int color2 = 3 - color;
	int last_score = 100000, score2;
	for (int i = 0; i <= SIZE - 1; i++)
	{
		for (int j = 0; j <= SIZE - 1; j++)
		{
			if ((Boardtest[i][j] == 0))
			{
				Boardtest[i][j] = color2;
				score2 = point(i, j, color2,2);
				switch (score2)
				{
				case -23333:
					break;
				case 10000:
					Boardtest[i][j] = 0;
					return -100000;
					break;
				default:
					score2 = Step3(color2, score2,last_score);
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
		}
	}
	return last_score + set_a * score1;
}

int Step3(int color2,int score2,int last_score2)
{
	int color3 = 3 - color2;
	int last_score = -1000000, score3;
	for (int i = 0; i <= SIZE - 1; i++)
	{
		for (int j = 0; j <= SIZE - 1; j++)
		{
			if ((Boardtest[i][j] == 0))
			{
				Boardtest[i][j] = color3;
				score3 = point(i, j, color3,3);
				switch (score3)
				{
				case -23333:
					break;
				case 10000:
					score3 = 1000;
					if (score3 > last_score)
						last_score = score3;
					else
						;
					break;
				default:
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
		}
	}
	return last_score-set_c*score2;
}
