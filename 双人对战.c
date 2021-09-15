#include "标头.h"
#include <stdio.h>
#include <conio.h>  


void PVP()
{
	char x;
	int y;
	char c;
	//初始化//
	InitBoardArray();
	DisplayBoard();
	printf("黑子先手，请黑子先下\n");

	//下棋部分//
	int q;
	for (q = 1; q <= 225 && result == 3; ++q) //下棋部分//
	{
		//黑子部分下棋：
		if (result == 3)//判断棋局是否已经结束
		{
			SwitchSituation_BLACK();//清除黑子上一步的标记//
			loop:
			scanf("%c%d", &x, &y);  //获得屏幕输入的坐标//
			while ((c = getchar()) != EOF && c != '\n');

			while (Board[x - 'a'][y - 1] == WHITE || Board[x - 'a'][y - 1] == BLACK || Board[x - 'a'][y - 1] == BLACKtem || Board[x - 'a'][y - 1] == WHITEtem)//防止下在棋子上//
			{
				printf("这里已经满员了\n");
				goto loop;
			}

			while ((x - 'a') > SIZE - 1 || (y - 1) > SIZE - 1 || (x - 'a') < 0 || (y - 1) < 0)//防止下到棋盘外//
			{
				printf("你下在了棋盘外，可能是字母的大小写导致的，请重新输入：\n");
				scanf("%c%d", &x, &y);
				goto loop;
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
					printf("这是怎么回事1？");

				goto loop;
			}

			Board[x - 'a'][y - 1] = BLACKtem;	//改变数组对应的数值//
			DisplayBoard();	//显示棋盘
			WINorLOSE();//判断黑子是否获胜或者平局

			if (result == 3)//回合提示
			{
				printf("现在轮到白子下棋：\n");
			}
		}
		else
			;

		//白子部分下棋：
		if (result == 3)
		{
			SwitchSituation_WHITE();//清除白子上一步的标记//
			label:
			scanf("%c%d", &x, &y);
			while ((c = getchar()) != EOF && c != '\n');

			while (Board[x - 'a'][y - 1] == WHITE || Board[x - 'a'][y - 1] == BLACK || Board[x - 'a'][y - 1] == BLACKtem || Board[x - 'a'][y - 1] == WHITEtem)//防止下在棋子上//
			{
				printf("这里已经满员了\n");
				goto label;
			}

			while ((x - 'a') > SIZE - 1 || (y - 1) > SIZE - 1 || (x - 'a') < 0 || (y - 1) < 0)//防止下到棋盘外//
			{
				printf("你下在了棋盘外，可能是字母的大小写导致的，请重新输入：\n");
				goto label;
			}

			Board[x - 'a'][y - 1] = WHITEtem;
			DisplayBoard();
			WINorLOSE();//判断白子是否获胜或者平局
			if (result == 3)
			{
				printf("现在轮到黑子下棋：\n");//回合提示
			}
		}
		else
			;
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
	getchar();
}