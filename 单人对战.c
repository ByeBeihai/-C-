#include "标头.h"
#include <stdio.h>
#include <conio.h> 
#include"ctype.h"

void PVE()
{
	system("cls");
	printf("你想要先手还是后手呢？\n1，AI先手执黑\n2，玩家先手执黑\n");
	int choice = 0;
	char c;
    scanf_s("%d", &choice);
	while ((c = getchar()) != EOF && c != '\n');
	while((choice != 1) && (choice != 2))
	{
		printf("似乎没有这个选项，请重新输入：\n1，AI先手执黑\n2，玩家先手执黑\n");
		scanf_s("%d", &choice);
		while ((c = getchar()) != EOF && c != '\n');
	}

	system("cls");
	printf("选择一个AI\n1，三步计算+无损剪枝模式(进攻型)\n2，三步计算+无损剪枝模式(保守型)\n2，四步计算+有损剪枝模式\n");
	int AImode = 0;
	scanf_s("%d", &AImode);
	while ((c = getchar()) != EOF && c != '\n');

	while ((choice != 1) && (choice != 2)&& (choice != 3))
	{
		printf("选择一个AI\n1，三步计算+无损剪枝模式(进攻型)\n2，三步计算+无损剪枝模式(保守型)\n2，四步计算+有损剪枝模式\n");
		scanf_s("%d", &choice);
		while ((c = getchar()) != EOF && c != '\n');
	}

	int s0 = choice;
	int turn = choice;
	int AIturn = 1;


	//初始化//
	InitBoardArray();
	DisplayBoard();
	int q;
	for (q = 1; q <= 225 && result == 3; ++q)
	{
		if (turn == AIturn)
		{
			if (AImode == 1)
				AI(choice, q);
			else if (AImode == 2)
				AInew(choice, q);
			else
				AIB(choice, q);
			DisplayBoard();
			WINorLOSE();
			if (result == 3)//回合提示
			{
				char x = 'a' + Last_step[0];
				printf("AI下在%c%d\n\n现在轮到你下棋：\n", x, Last_step[1]+1);
			}
			else
				;
			turn = 3 - turn;

		}
		else
		{
			Playerpart(choice);
			DisplayBoard();
			WINorLOSE();
			turn = 3 - turn;
		}
	}
	//结局判定//
	if (q > 255)
	{
		result = 2;
		DisplayBoard();
		printf("\n平局");
	}
	else if (result == 0)
	{
		DisplayBoard();
		printf("\n白子胜利");
	}
	else if (result == 1)
	{
		DisplayBoard();
		printf("\n黑子胜利");
	}
	else
		printf("这是怎么回事？");
	while ((c = getchar()) != EOF && c != '\n');
}

void Playerpart(int color)
{
	char x;
	int y;
	char c;
	if (color == 2)
	{
		SwitchSituation_BLACK();//清除黑子上一步的标记//
		label:
		scanf("%c%d", &x, &y);  //获得屏幕输入的坐标//
		while ((c = getchar()) != EOF && c != '\n');

		while (isalpha(x) == 0||(x - 'a') > SIZE - 1 || (y - 1) > SIZE - 1 || (x - 'a') < 0 || (y - 1) < 0)//防止下到棋盘外//
		{
			printf("你下在了棋盘外，可能是字母的大小写导致的，请重新输入：\n");
			goto label;
		}
		while (Board[x - 'a'][y - 1] == WHITE || Board[x - 'a'][y - 1] == BLACK || Board[x - 'a'][y - 1] == BLACKtem || Board[x - 'a'][y - 1] == WHITEtem)//防止下在棋子上//
		{
			printf("这里已经满员了\n");
			goto label;
		}

		int ForbiddenResult = ForbiddenCheck(x, y-1);
		while (ForbiddenResult != 0)//判断是否是禁手//
		{
			if (ForbiddenResult == 1)
				printf("你输入了长连禁手，请重下：\n");
			else if (ForbiddenResult == 2)
				printf("你输入了双四禁手，请重下：\n");
			else if (ForbiddenResult == 3)
				printf("你输入了双三禁手，请重下：\n");
			else
				printf("这是怎么回事？");

			goto label;
		}

		Board[x - 'a'][y - 1] = BLACKtem;	//改变数组对应的数值//
	}
	else
	{
		SwitchSituation_WHITE();//清除白子上一步的标记//
		loop:
		scanf("%c%d", &x, &y);
		while ((c = getchar()) != EOF && c != '\n');

		while (isalpha(x) == 0||(x - 'a') > SIZE - 1 || (y -1) > SIZE - 1 || (x - 'a') < 0 || (y - 1) < 0)//防止下到棋盘外//
		{
			printf("你下在了棋盘外，可能是字母的大小写导致的，请重新输入：\n");
			goto loop;
		}

		while (Board[x - 'a'][y - 1] == WHITE || Board[x - 'a'][y - 1] == BLACK || Board[x - 'a'][y - 1] == BLACKtem || Board[x - 'a'][y - 1] == WHITEtem)//防止下在棋子上//
		{
			printf("这里已经满员了\n");
			goto loop;
		}

		Board[x - 'a'][y - 1] = WHITEtem;
	}
}

void Airdrop(int x, int y, int color)
{
	Last_step[0] = x;
	Last_step[1] = y;
	if (color == 1)
	{
		SwitchSituation_BLACK();
		Board[x][y] = BLACKtem;

	}
	else
	{
		SwitchSituation_WHITE();
		Board[x][y] = WHITEtem;
	}
}



