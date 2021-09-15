#include "标头.h"
#include <stdio.h>
#include <conio.h>  

int ForbiddenCheck(char x2, int y2)
{
	int x, y;
	x = x2 - 'a';
	y = y2 - 0;
	int a, b;
	//将原来的棋盘映射到虚拟棋盘上。黑子记为1，白子记为2，空位记为0
	for (a = 0; a <= 14; a++)
	{
		for (b = 0; b <= SIZE - 1; b++)
		{
			if (Board[a][b] == BLACK || Board[a][b] == BLACKtem)
			{
				BoardCheck[a][b] = 1;
			}
			else if (Board[a][b] == WHITE || Board[a][b] == WHITEtem)
			{
				BoardCheck[a][b] = 2;
			}
			else
				BoardCheck[a][b] = 0;

		}
	}
	BoardCheck[x][y] = 1;

	int result;
	result = ForbiddenCheck_Unit(x, y);
	return result;

}

int ForbiddenCheck_forlive3(int x2, int y2)
{
	int x, y;
	x = x2 - 0;
	y = y2 - 0;
	int a, b;
	//将原来的棋盘映射到虚拟棋盘上。黑子记为1，白子记为2，空位记为0
	for (a = 0; a <= 14; a++)
	{
		for (b = 0; b <= SIZE - 1; b++)
		{
			if (Boardtest[a][b] == 1)
			{
				BoardCheck[a][b] = 1;
			}
			else if (Board[a][b] == 2)
			{
				BoardCheck[a][b] = 2;
			}
			else
				BoardCheck[a][b] = 0;
			
		}
	}

	BoardCheck[x][y] = 1;
	int forbid;
	forbid = ForbiddenCheck_Unit(x, y);
	BoardCheck[x][y] = 0;
	return forbid;

}

int ForbiddenCheck_Unit(int x, int y)
{
	//构建参数//
	int firstblack[8];
	int firstjump[8];
	int secondblack[8];
	int secondjump[8];

	//初始化参数//
	int i, j;
	i = j = 0;
	for (i = 0; i <= 7; ++i)
	{
		firstblack[i] = firstjump[i] = secondblack[i] = secondjump[i] = 0;
	}

	//扫描棋盘//
	int dx[8] = { 0, 1, 1, 1, 0, -1, -1, -1 };//方向向量扫描法
	int dy[8] = { 1, 1, 0, -1, -1, -1, 0, 1 };
	int r;
	for (r = 0; r <= 7; ++r)
	{
		int x1, y1;
		for (y1 = y + dy[r], x1 = x + dx[r]; 0 <= x1 && x1 <= 14 && 0 <= y1 && y1 <= 14 && BoardCheck[x1][y1] == 1; y1 = y1 + dy[r], x1 = x1 + dx[r], ++firstblack[r]);
		for (; 0 <= x1 && x1 <= 14 && 0 <= y1 && y1 <= 14 && BoardCheck[x1][y1] == 0; y1 = y1 + dy[r], x1 = x1 + dx[r], ++firstjump[r]);
		for (; 0 <= x1 && x1 <= 14 && 0 <= y1 && y1 <= 14 && BoardCheck[x1][y1] == 1; y1 = y1 + dy[r], x1 = x1 + dx[r], ++secondblack[r]);
		for (; 0 <= x1 && x1 <= 14 && 0 <= y1 && y1 <= 14 && BoardCheck[x1][y1] == 0; y1 = y1 + dy[r], x1 = x1 + dx[r], ++secondjump[r]);
	}
	//开始判定禁手//
	int DoubleFour = 0;
	int DoubleThree = 0;

	//判定长连//长连返回1//
	for (i = 0; i <= 3; ++i)
	{
		if ((firstblack[i] + firstblack[i + 4]) >= 5)
		{
			return 1;
		}
		else
			;
	}

	//判定双四//双四返回2
	int livefour = 0;//计算活四
	int halffour = 0;//计算冲四
	int nearfive = 0;//计算连五
	for (i = 0; i <= 3; ++i) //计算活四
	{
		if ((firstblack[i] + firstblack[i + 4]) == 3 && firstjump[i] >= 1 && firstjump[i + 4] >= 1)
			++livefour;
		else
			;
	}
	for (i = 0; i <= 3; ++i)//计算连五
	{
		if (((firstblack[i] + secondblack[i] + firstblack[i + 4]) == 3 && firstjump[i] == 1)
			|| ((firstblack[i] + firstblack[i + 4] == 3) && firstjump[i] >= 1))
			++nearfive;
		else
			;
	}
	for (i = 4; i <= 7; ++i)
	{
		if (((firstblack[i] + secondblack[i] + firstblack[i - 4]) == 3 && firstjump[i] == 1)
			|| ((firstblack[i] + firstblack[i - 4] == 3) && firstjump[i] >= 1))
			++nearfive;
		else
			;
	}

	halffour = nearfive - livefour * 2;
	if ((DoubleFour = halffour + livefour) >= 2)
		return 2;
	else
		;

	//开始判定双三//双三返回3//
	int livethree = 0;
	int halfthree = 0;
	for (i = 0; i <= 3; ++i)
	{
		if ((firstblack[i] + firstblack[i + 4]) == 2 && firstjump[i] >= 2 && firstjump[i + 4] >= 2)
		{
				++livethree;
		}
		else
			;
	}
	for (i = 0; i <= 3; ++i)
	{
		if ((firstblack[i] == 1 && firstjump[i] == 1 && secondblack[i] == 1 && secondjump[i] >= 1 && firstjump[i + 4] >= 1 && firstblack[i + 4] == 0)
			|| (firstblack[i] == 0 && firstjump[i] == 1 && secondblack[i] == 1 && secondjump[i] >= 1 && firstblack[i + 4] == 1 && firstjump[i + 4] >= 1)
			|| (firstblack[i] == 0 && firstjump[i] >= 1 && firstjump[i + 4] == 1 && firstblack[i + 4] == 0 && secondblack[i + 4] == 2 && secondjump[i + 4] >= 1))
			++halfthree;
		else
			;
		if ((firstblack[i] + firstblack[i + 4]) == 2 && ((firstjump[i] == 1 && firstjump[i + 4] >= 2) || (firstjump[i] >= 2 && firstjump[i + 4] == 1)))
		{
			if ((firstjump[i] == 1 && secondblack[i] == 1) || (firstjump[i + 4] == 1 && secondblack[i + 4] == 1))
				;
			else
				++halfthree;
		}
	}
	for (i = 4; i <= 7; ++i)
	{
		if ((firstblack[i] == 1 && firstjump[i] == 1 && secondblack[i] == 1 && secondjump[i] >= 1 && firstjump[i - 4] >= 1 && firstblack[i - 4] == 0)
			|| (firstblack[i] == 0 && firstjump[i] == 1 && secondblack[i] == 1 && secondjump[i] >= 1 && firstblack[i - 4] == 1 && firstjump[i - 4] >= 1)
			|| (firstblack[i] == 0 && firstjump[i] >= 1 && firstjump[i - 4] == 1 && firstblack[i - 4] == 0 && secondblack[i - 4] == 2 && secondjump[i - 4] >= 1))
			++halfthree;
		else
			;
	}

	if ((DoubleThree = livethree + halfthree) >= 2)
		return 3;
	else
		;

	return 0;//没有禁手返回0
}



