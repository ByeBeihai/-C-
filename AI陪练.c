#include "标头.h"
#include <stdio.h>
#include <conio.h>  
#include <stdlib.h>
#include <time.h>

void AInew(int color, int q)//三步进攻型，调参在三者中最为完善
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
	if (empty_place <= 2)
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

	for (i = 0; i <= SIZE - 1; i++)
	{
		for (j = 0; j <= SIZE - 1; j++)
		{
			if ((Boardtest[i][j] == 0) && ((q <= 6 && next(i, j) != 0) || q >= 7))
			{
				Boardtest[i][j] = color;
				score = point2(i, j, color, 1);
				switch (score)
				{
				case -23333:
					break;//禁手分数为-23333 不可下
				case 10000:
					return Airdrop(i, j, color);
					break;
				default:
					score = Step2new(color, score, last_score);
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
								srand((unsigned)time(NULL));//分数相同随机落子
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

int Step2new(int color, int score1, int last_score1)
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
				score2 = point2(i, j, color2, 2);
				switch (score2)
				{
				case -23333:
					break;
				case 10000:
					Boardtest[i][j] = 0;
					return -100000;
					break;
				default:
					score2 = Step3new(color2, score2, last_score);
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
			if (last_score + 1 * score1 < last_score1)//阿尔法贝塔剪枝
				return last_score + 1 * score1;
			else
				;
		}
	}
	return last_score + 1 * score1;
}

int Step3new(int color2, int score2, int last_score2)
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
				score3 = point2(i, j, color3, 3);
				switch (score3)
				{
				case -23333:
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
			if (last_score - set_c * score2 > last_score2)
				return last_score - set_c * score2;
			else
				;
		}
	}
	return last_score - set_c * score2;
}


int HSD2(int x, int y, int step)//作为陪练，有一个单独的态势感知函数
{

	int color = Boardtest[x][y];

	//构建参数//
	int firstsame[8];
	int firstjump[8];
	int secondsame[8];
	int secondjump[8];
	int firstdifferent[8];

	//初始化参数//
	int i, j;
	i = j = 0;
	for (i = 0; i <= 7; ++i)
	{
		firstsame[i] = firstjump[i] = secondsame[i] = secondjump[i] = firstdifferent[i] = 0;
	}

	//扫描棋盘//
	int dx[8] = { 0, 1, 1, 1, 0, -1, -1, -1 };//方向向量扫描法
	int dy[8] = { 1, 1, 0, -1, -1, -1, 0, 1 };
	int r;
	for (r = 0; r <= 7; ++r)
	{
		int x1, y1;
		for (y1 = y + dy[r], x1 = x + dx[r]; 0 <= x1 && x1 <= 14 && 0 <= y1 && y1 <= 14 && Boardtest[x1][y1] == color; y1 = y1 + dy[r], x1 = x1 + dx[r], ++firstsame[r]);
		for (; 0 <= x1 && x1 <= 14 && 0 <= y1 && y1 <= 14 && Boardtest[x1][y1] == 0; y1 = y1 + dy[r], x1 = x1 + dx[r], ++firstjump[r]);
		for (; 0 <= x1 && x1 <= 14 && 0 <= y1 && y1 <= 14 && Boardtest[x1][y1] == color; y1 = y1 + dy[r], x1 = x1 + dx[r], ++secondsame[r]);
		for (; 0 <= x1 && x1 <= 14 && 0 <= y1 && y1 <= 14 && Boardtest[x1][y1] == 0; y1 = y1 + dy[r], x1 = x1 + dx[r], ++secondjump[r]);
		for (; 0 <= x1 && x1 <= 14 && 0 <= y1 && y1 <= 14 && Boardtest[x1][y1] == 3 - color; y1 = y1 + dy[r], x1 = x1 + dx[r], ++firstdifferent[r]);
	}

	int livefour = 0;//计算活四
	for (i = 0; i <= 3; ++i) //计算活四
	{
		if ((firstsame[i] + firstsame[i + 4]) == 3 && firstjump[i] >= 1 && firstjump[i + 4] >= 1)
			++livefour;
		else
			;
	}

	int nearfive = 0;//计算连五
	for (i = 0; i <= 3; ++i)//计算连五
	{
		if ((
			(firstsame[i] + secondsame[i] + firstsame[i + 4]) == 3 && firstjump[i] == 1)
			|| ((firstsame[i] + firstsame[i + 4] == 3) && firstjump[i] >= 1))
			++nearfive;
		else
			;
	}
	for (i = 4; i <= 7; ++i)
	{
		if (
			((firstsame[i] + secondsame[i] + firstsame[i - 4]) == 3 && firstjump[i] == 1)
			|| ((firstsame[i] + firstsame[i - 4] == 3) && firstjump[i] >= 1))
			++nearfive;
		else
			;
	}

	int chong4 = nearfive - 2 * livefour;//计算冲四

	int longfive = 0;//扫描长连
	for (i = 0; i <= 3; ++i)
	{
		if ((firstsame[i] + firstsame[i + 4]) >= 5)
		{
			++longfive;
		}
		else
			;
	}

	int livethree = 0;//活三
	for (i = 0; i <= 3; ++i)
	{
		if ((firstsame[i] + firstsame[i + 4]) == 2 && firstjump[i] >= 2 && firstjump[i + 4] >= 2)
		{
			if (color == 1)
			{
				if (ForbiddenCheck_forlive3(x + dx[i] * (firstsame[i] + 1), y + dy[i] * (firstsame[i] + 1)) == 0
					&& ForbiddenCheck_forlive3(x + dx[i + 4] * (firstsame[i + 4] + 1), y + dy[i + 4] * (firstsame[i + 4] + 1)) == 0)
					++livethree;
			}
			else
				++livethree;
		}
		else
			;
	}

	int halfthree = 0;//冲3
	for (i = 0; i <= 3; ++i)
	{
		if ((firstsame[i] == 1 && firstjump[i] == 1 && secondsame[i] == 1 && secondjump[i] >= 1 && firstjump[i + 4] >= 1 && firstsame[i + 4] == 0)
			|| (firstsame[i] == 0 && firstjump[i] == 1 && secondsame[i] == 1 && secondjump[i] >= 1 && firstsame[i + 4] == 1 && firstjump[i + 4] >= 1)
			|| (firstsame[i] == 0 && firstjump[i] >= 1 && firstjump[i + 4] == 1 && firstsame[i + 4] == 0 && secondsame[i + 4] == 2 && secondjump[i + 4] >= 1))
			++halfthree;
		else
			;
		if ((firstsame[i] + firstsame[i + 4]) == 2 && ((firstjump[i] == 1 && firstjump[i + 4] >= 2) || (firstjump[i] >= 2 && firstjump[i + 4] == 1)))
		{
			if (color == 1)
			{
				if (ForbiddenCheck_forlive3(x + dx[i] * (firstsame[i] + 1), y + dy[i] * (firstsame[i] + 1)) == 0
					&& ForbiddenCheck_forlive3(x + dx[i + 4] * (firstsame[i + 4] + 1), y + dy[i + 4] * (firstsame[i + 4] + 1)) == 0)
					++halfthree;
				else
					;
			}
			else
				++halfthree;
		}
	}
	for (i = 4; i <= 7; ++i)
	{
		if ((firstsame[i] == 1 && firstjump[i] == 1 && secondsame[i] == 1 && secondjump[i] >= 1 && firstjump[i - 4] >= 1 && firstsame[i - 4] == 0)
			|| (firstsame[i] == 0 && firstjump[i] == 1 && secondsame[i] == 1 && secondjump[i] >= 1 && firstsame[i - 4] == 1 && firstjump[i - 4] >= 1)
			|| (firstsame[i] == 0 && firstjump[i] >= 1 && firstjump[i - 4] == 1 && firstsame[i - 4] == 0 && secondsame[i - 4] == 2 && secondjump[i - 4] >= 1))
			++halfthree;
		else
			;
	}

	int back_two_three = 0;//背靠背的双三
	for (i = 0; i <= 3; ++i)
	{
		if ((firstsame[i] + firstsame[i + 4]) == 2 && firstjump[i] == 1 && firstjump[i + 4] == 1 && secondsame[i] >= 1 && secondsame[i + 4] >= 1)
			++back_two_three;
		else
			;
	}

	int livetwo = 0;
	for (i = 0; i <= 3; ++i)
	{
		if ((firstsame[i] + firstsame[i + 4]) == 1 && firstjump[i] >= 1 && firstjump[i + 4] >= 1)
			++livetwo;
		else
			;
	}

	int halftwo = 0;
	for (i = 0; i <= 7; ++i)
	{
		if (firstsame[i] == 0 && firstjump[i] == 1 && firstsame[i + 4] == 0 && firstjump[i + 4] >= 0 && secondsame[i] == 1 && secondjump[i] >= 1)
			++halftwo;
		else
			;
	}

	int forbid = 0;//计算禁手数
	if (color == 1)
	{
		if (
			(livethree + halfthree >= 2) || (livefour + chong4 >= 2) || (longfive >= 1)
			)
		{
			++forbid;
		}
		else
			;
	}
	else
		;

	int end = 0;//计算是否结束
	for (i = 0; i <= 3; ++i)
	{
		if ((firstsame[i] + firstsame[i + 4]) >= 4)
		{
			end = 1;
		}
		else
			;
	}

	int next = 8;//计算周围临近的棋子个数
	for (i = 0; i <= 7; ++i)
	{
		if ((Boardtest[x + dx[i]][y + dy[i]] != 1) && (Boardtest[x + dx[i]][y + dy[i]] != 2))
			--next;
		else
			;
	}

	int point = 1000 * livefour + 100 * (livethree + chong4) + 10 * halfthree + next;//基础打分
	point = point + 500 * back_two_three + 500 * ((livethree != 0 || halfthree != 0) && chong4 != 0) + 700 * ((chong4 + livefour) >= 2) + 600 * ((livethree + halfthree) >= 2);//复杂棋型补充
	if (step == 2 || step == 4)
		point = point + 2 * set_d * livetwo + 2 * halftwo;
	else
		;
	HSD_point[0] = forbid;
	HSD_point[1] = point;
	HSD_point[2] = end;
	HSD_point[3] = next;

}


int point2(int x, int y, int color, int step)
{
	HSD2(x, y, step);
	int point = HSD_point[1];
	int nextone = HSD_point[3];
	int end = HSD_point[2];
	int forbid = HSD_point[0];
	if ((forbid != 0))
	{
		return -23333;
	}
	else
	{
		if (end == 1)
		{
			return 10000;
		}
		else
			return point;
	}
}
