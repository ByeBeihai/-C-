#include "��ͷ.h"
#include <stdio.h>
#include <conio.h>  


void PVP()
{
	char x;
	int y;
	char c;
	//��ʼ��//
	InitBoardArray();
	DisplayBoard();
	printf("�������֣����������\n");

	//���岿��//
	int q;
	for (q = 1; q <= 225 && result == 3; ++q) //���岿��//
	{
		//���Ӳ������壺
		if (result == 3)//�ж�����Ƿ��Ѿ�����
		{
			SwitchSituation_BLACK();//���������һ���ı��//
			loop:
			scanf("%c%d", &x, &y);  //�����Ļ���������//
			while ((c = getchar()) != EOF && c != '\n');

			while (Board[x - 'a'][y - 1] == WHITE || Board[x - 'a'][y - 1] == BLACK || Board[x - 'a'][y - 1] == BLACKtem || Board[x - 'a'][y - 1] == WHITEtem)//��ֹ����������//
			{
				printf("�����Ѿ���Ա��\n");
				goto loop;
			}

			while ((x - 'a') > SIZE - 1 || (y - 1) > SIZE - 1 || (x - 'a') < 0 || (y - 1) < 0)//��ֹ�µ�������//
			{
				printf("�������������⣬��������ĸ�Ĵ�Сд���µģ����������룺\n");
				scanf("%c%d", &x, &y);
				goto loop;
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
					printf("������ô����1��");

				goto loop;
			}

			Board[x - 'a'][y - 1] = BLACKtem;	//�ı������Ӧ����ֵ//
			DisplayBoard();	//��ʾ����
			WINorLOSE();//�жϺ����Ƿ��ʤ����ƽ��

			if (result == 3)//�غ���ʾ
			{
				printf("�����ֵ��������壺\n");
			}
		}
		else
			;

		//���Ӳ������壺
		if (result == 3)
		{
			SwitchSituation_WHITE();//���������һ���ı��//
			label:
			scanf("%c%d", &x, &y);
			while ((c = getchar()) != EOF && c != '\n');

			while (Board[x - 'a'][y - 1] == WHITE || Board[x - 'a'][y - 1] == BLACK || Board[x - 'a'][y - 1] == BLACKtem || Board[x - 'a'][y - 1] == WHITEtem)//��ֹ����������//
			{
				printf("�����Ѿ���Ա��\n");
				goto label;
			}

			while ((x - 'a') > SIZE - 1 || (y - 1) > SIZE - 1 || (x - 'a') < 0 || (y - 1) < 0)//��ֹ�µ�������//
			{
				printf("�������������⣬��������ĸ�Ĵ�Сд���µģ����������룺\n");
				goto label;
			}

			Board[x - 'a'][y - 1] = WHITEtem;
			DisplayBoard();
			WINorLOSE();//�жϰ����Ƿ��ʤ����ƽ��
			if (result == 3)
			{
				printf("�����ֵ��������壺\n");//�غ���ʾ
			}
		}
		else
			;
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
	getchar();
}