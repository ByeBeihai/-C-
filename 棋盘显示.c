#include "标头.h"
#include <stdio.h>
#include <conio.h>  

void DisplayBoard()
{
	int i, j;
	char ary;

	system("cls");   //清屏

	for (j = SIZE - 1; j >= 0; j--)
	{
		printf("%2d", j+1);
		for (i = 0; i <= SIZE - 1; i++)
		{
			switch (Board[i][j])
			{
			case 1:
				printf("┗");
				break;

			case 2:
				printf("┛");
				break;

			case 3:
				printf("┓");
				break;

			case 4:
				printf("┏");
				break;

			case 5:
				printf("┠");
				break;

			case 6:
				printf("┷");
				break;

			case 7:
				printf("┨");
				break;

			case 8:
				printf("┯");
				break;

			case 9:
				printf("┼");
				break;

			case BLACKtem:      // 黑子上一步
				printf("△");
				break;

			case WHITEtem:      //白子上一步
				printf("▲");
				break;

			case BLACK:      //黑子通常
				printf("○");
				break;

			case WHITE:
				printf("●");  //白子通常
				break;
			}
			if (i == SIZE - 1)
			{
				printf("\n");
			}

		}
	}

	printf("   ");
	for (ary = 'A'; ary < 'A' + SIZE; ary++)
		printf("%c ", ary);

	printf("\n\n请输入小写字母加数字的坐标组合，按回车确认。例如：a1\n\n");
}


//下面两个函数用来实现显示当前所下的位置
void SwitchSituation_WHITE()
{
	int i, j;
	for (j = 0; j <= SIZE - 1; j++)
	{
		for (i = 0; i <= SIZE - 1; i++)
		{
			if (Board[i][j] == WHITEtem)
				Board[i][j] = WHITE;
			else
				;
		}
	}
}
void SwitchSituation_BLACK()
{
	int i, j;
	for (j = 0; j <= SIZE - 1; j++)
	{
		for (i = 0; i <= SIZE - 1; i++)
		{
			if (Board[i][j] == BLACKtem)
				Board[i][j] = BLACK;
			else
				;
		}
	}
}