#include "��ͷ.h"
#include <stdio.h>
#include <conio.h>  

int ForbiddenCheck(char x2, int y2)
{
	int x, y;
	x = x2 - 'a';
	y = y2 - 0;
	int a, b;
	//��ԭ��������ӳ�䵽���������ϡ����Ӽ�Ϊ1�����Ӽ�Ϊ2����λ��Ϊ0
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
	//��ԭ��������ӳ�䵽���������ϡ����Ӽ�Ϊ1�����Ӽ�Ϊ2����λ��Ϊ0
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
	//��������//
	int firstblack[8];
	int firstjump[8];
	int secondblack[8];
	int secondjump[8];

	//��ʼ������//
	int i, j;
	i = j = 0;
	for (i = 0; i <= 7; ++i)
	{
		firstblack[i] = firstjump[i] = secondblack[i] = secondjump[i] = 0;
	}

	//ɨ������//
	int dx[8] = { 0, 1, 1, 1, 0, -1, -1, -1 };//��������ɨ�跨
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
	//��ʼ�ж�����//
	int DoubleFour = 0;
	int DoubleThree = 0;

	//�ж�����//��������1//
	for (i = 0; i <= 3; ++i)
	{
		if ((firstblack[i] + firstblack[i + 4]) >= 5)
		{
			return 1;
		}
		else
			;
	}

	//�ж�˫��//˫�ķ���2
	int livefour = 0;//�������
	int halffour = 0;//�������
	int nearfive = 0;//��������
	for (i = 0; i <= 3; ++i) //�������
	{
		if ((firstblack[i] + firstblack[i + 4]) == 3 && firstjump[i] >= 1 && firstjump[i + 4] >= 1)
			++livefour;
		else
			;
	}
	for (i = 0; i <= 3; ++i)//��������
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

	//��ʼ�ж�˫��//˫������3//
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

	return 0;//û�н��ַ���0
}



