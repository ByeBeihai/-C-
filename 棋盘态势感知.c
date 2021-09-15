#include "标头.h"
#include <stdio.h>
#include <conio.h>  


/*HSD:战斗机航电系统中的态势感知系统，以本机为中心，显示战场上的敌我战机位置以及攻击威胁
      这里引用其意，可用于检测棋盘上任何一个子附近位置的情况，包括：临近和间隔的同色，异色，以及空格或者边界*/
int HSD(int x, int y,int step)
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
		for (y1 = y + dy[r], x1 = x + dx[r]; 0 <= x1 && x1 <= 14 && 0 <= y1 && y1 <= 14 && Boardtest[x1][y1] == color; y1=y1+dy[r],x1=x1+dx[r], ++firstsame[r]);
		for (; 0 <= x1 && x1 <= 14 && 0 <= y1 && y1 <= 14 && Boardtest[x1][y1] == 0; y1 = y1 + dy[r], x1 = x1 + dx[r], ++firstjump[r]);
		for (; 0 <= x1 && x1 <= 14 && 0 <= y1 && y1 <= 14 && Boardtest[x1][y1] == color; y1 = y1 + dy[r], x1 = x1 + dx[r], ++secondsame[r]);
		for (; 0 <= x1 && x1 <= 14 && 0 <= y1 && y1 <= 14 && Boardtest[x1][y1] == 0; y1 = y1 + dy[r], x1 = x1 + dx[r], ++secondjump[r]);
		for (; 0 <= x1 && x1 <= 14 && 0 <= y1 && y1 <= 14 && Boardtest[x1][y1] == 3-color; y1 = y1 + dy[r], x1 = x1 + dx[r], ++firstdifferent[r]);
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
				{
					if((firstjump[i] == 1&& secondsame[i] == 1)||(firstjump[i+4]==1&&secondsame[i+4] == 1))
						;
					else
					++halfthree;
				}
				else
					;
			}
			else
			{
				if ((firstjump[i] == 1 && secondsame[i] == 1) || (firstjump[i + 4] == 1 && secondsame[i + 4] == 1))
					;
				else
					++halfthree;
			}
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
		if (firstsame[i] == 0 && firstjump[i] == 1 && firstsame[i + 4] == 0 && firstjump[i+4]>=0 && secondsame[i] == 1&&secondjump[i]>=1)
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

	int point = 1000 * livefour + 100 * (livethree + chong4) + 10* halfthree + next;//基础打分
	point = point + 500 * back_two_three + 500 * ((livethree != 0 || halfthree != 0) && chong4 != 0) + 700 * ((chong4 + livefour) >= 2) + 600 * ((livethree + halfthree) >= 2);//复杂棋型补充
	if (step == 2||step == 4)
		point = point + 2*set_d * livetwo + 2 * halftwo;
	else
		;
	if (step == 1 && (livefour >=1||((livethree != 0 || halfthree != 0) && chong4 != 0) || ((chong4 + livefour) >= 2)))
		point = 10 * point;//双四或者三四在我方时大幅度提升优先级
	HSD_point[0] = forbid;
	HSD_point[1] = point;
	HSD_point[2] = end;
	HSD_point[3] = next;

}
int next(int x, int y)//检测附近是否有棋子，用于剪枝
{


	int color = Boardtest[x][y];
	int dx[8] = { 1, 1, 0, -1, -1, -1, 0, 1 };
	int dy[8] = { 0, 1, 1, 1, 0, -1, -1, -1 };
	int nextone = 8;
	int i;
	for (i = 0; i <= 7; ++i)
	{
		if ((Boardtest[x + dx[i]][y + dy[i]] != 1) && (Boardtest[x + dx[i]][y + dy[i]] != 2)
			|| x + dx[i] < 0 || x + dx[i] >= 15 || y + dy[i] < 0 || y + dy[i] >= 15)
			--nextone;
		else
			;
	}
	return nextone;
}
int next1(int x, int y)//检测附近是否有棋子，用于剪枝
{


	int color = Boardtest[x][y];
	int dx[8] = { 1, 1, 0, -1, -1, -1, 0, 1 }; 
	int dy[8] = { 0, 1, 1, 1, 0, -1, -1, -1 };
	int nextone = 16;
	int i;
	for (i = 0; i <= 7; ++i)
	{
		if ((Boardtest[x + dx[i]][y + dy[i]] != 1) && (Boardtest[x + dx[i]][y + dy[i]] != 2)
			|| x + dx[i]<0 || x + dx[i] >= 15|| y + dy[i]<0 || y + dy[i] >=15)
			--nextone;
		else
			;
		if ((Boardtest[x + 2*dx[i]][y + 2*dy[i]] != 1) && (Boardtest[x + 2*dx[i]][y + 2*dy[i]] != 2)
			|| x + 2 * dx[i] < 0 || x + 2 * dx[i] >= 15 || y + 2 * dy[i] < 0 || y + 2 * dy[i] >= 15)
			--nextone;
		else
			;
	}
	return nextone;
}

int point(int x, int y, int color, int step)
{
	HSD(x, y, step);
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
