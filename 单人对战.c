#include "��ͷ.h"
#include <stdio.h>
#include <conio.h> 
#include"ctype.h"

void PVE()
{
	system("cls");
	printf("����Ҫ���ֻ��Ǻ����أ�\n1��AI����ִ��\n2���������ִ��\n");
	int choice = 0;
	char c;
    scanf_s("%d", &choice);
	while ((c = getchar()) != EOF && c != '\n');
	while((choice != 1) && (choice != 2))
	{
		printf("�ƺ�û�����ѡ����������룺\n1��AI����ִ��\n2���������ִ��\n");
		scanf_s("%d", &choice);
		while ((c = getchar()) != EOF && c != '\n');
	}

	system("cls");
	printf("ѡ��һ��AI\n1����������+�����֦ģʽ(������)\n2����������+�����֦ģʽ(������)\n2���Ĳ�����+�����֦ģʽ\n");
	int AImode = 0;
	scanf_s("%d", &AImode);
	while ((c = getchar()) != EOF && c != '\n');

	while ((choice != 1) && (choice != 2)&& (choice != 3))
	{
		printf("ѡ��һ��AI\n1����������+�����֦ģʽ(������)\n2����������+�����֦ģʽ(������)\n2���Ĳ�����+�����֦ģʽ\n");
		scanf_s("%d", &choice);
		while ((c = getchar()) != EOF && c != '\n');
	}

	int s0 = choice;
	int turn = choice;
	int AIturn = 1;


	//��ʼ��//
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
			if (result == 3)//�غ���ʾ
			{
				char x = 'a' + Last_step[0];
				printf("AI����%c%d\n\n�����ֵ������壺\n", x, Last_step[1]+1);
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
	//����ж�//
	if (q > 255)
	{
		result = 2;
		DisplayBoard();
		printf("\nƽ��");
	}
	else if (result == 0)
	{
		DisplayBoard();
		printf("\n����ʤ��");
	}
	else if (result == 1)
	{
		DisplayBoard();
		printf("\n����ʤ��");
	}
	else
		printf("������ô���£�");
	while ((c = getchar()) != EOF && c != '\n');
}

void Playerpart(int color)
{
	char x;
	int y;
	char c;
	if (color == 2)
	{
		SwitchSituation_BLACK();//���������һ���ı��//
		label:
		scanf("%c%d", &x, &y);  //�����Ļ���������//
		while ((c = getchar()) != EOF && c != '\n');

		while (isalpha(x) == 0||(x - 'a') > SIZE - 1 || (y - 1) > SIZE - 1 || (x - 'a') < 0 || (y - 1) < 0)//��ֹ�µ�������//
		{
			printf("�������������⣬��������ĸ�Ĵ�Сд���µģ����������룺\n");
			goto label;
		}
		while (Board[x - 'a'][y - 1] == WHITE || Board[x - 'a'][y - 1] == BLACK || Board[x - 'a'][y - 1] == BLACKtem || Board[x - 'a'][y - 1] == WHITEtem)//��ֹ����������//
		{
			printf("�����Ѿ���Ա��\n");
			goto label;
		}

		int ForbiddenResult = ForbiddenCheck(x, y-1);
		while (ForbiddenResult != 0)//�ж��Ƿ��ǽ���//
		{
			if (ForbiddenResult == 1)
				printf("�������˳������֣������£�\n");
			else if (ForbiddenResult == 2)
				printf("��������˫�Ľ��֣������£�\n");
			else if (ForbiddenResult == 3)
				printf("��������˫�����֣������£�\n");
			else
				printf("������ô���£�");

			goto label;
		}

		Board[x - 'a'][y - 1] = BLACKtem;	//�ı������Ӧ����ֵ//
	}
	else
	{
		SwitchSituation_WHITE();//���������һ���ı��//
		loop:
		scanf("%c%d", &x, &y);
		while ((c = getchar()) != EOF && c != '\n');

		while (isalpha(x) == 0||(x - 'a') > SIZE - 1 || (y -1) > SIZE - 1 || (x - 'a') < 0 || (y - 1) < 0)//��ֹ�µ�������//
		{
			printf("�������������⣬��������ĸ�Ĵ�Сд���µģ����������룺\n");
			goto loop;
		}

		while (Board[x - 'a'][y - 1] == WHITE || Board[x - 'a'][y - 1] == BLACK || Board[x - 'a'][y - 1] == BLACKtem || Board[x - 'a'][y - 1] == WHITEtem)//��ֹ����������//
		{
			printf("�����Ѿ���Ա��\n");
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



