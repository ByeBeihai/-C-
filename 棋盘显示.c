#include "��ͷ.h"
#include <stdio.h>
#include <conio.h>  

void DisplayBoard()
{
	int i, j;
	char ary;

	system("cls");   //����

	for (j = SIZE - 1; j >= 0; j--)
	{
		printf("%2d", j+1);
		for (i = 0; i <= SIZE - 1; i++)
		{
			switch (Board[i][j])
			{
			case 1:
				printf("��");
				break;

			case 2:
				printf("��");
				break;

			case 3:
				printf("��");
				break;

			case 4:
				printf("��");
				break;

			case 5:
				printf("��");
				break;

			case 6:
				printf("��");
				break;

			case 7:
				printf("��");
				break;

			case 8:
				printf("��");
				break;

			case 9:
				printf("��");
				break;

			case BLACKtem:      // ������һ��
				printf("��");
				break;

			case WHITEtem:      //������һ��
				printf("��");
				break;

			case BLACK:      //����ͨ��
				printf("��");
				break;

			case WHITE:
				printf("��");  //����ͨ��
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

	printf("\n\n������Сд��ĸ�����ֵ�������ϣ����س�ȷ�ϡ����磺a1\n\n");
}


//����������������ʵ����ʾ��ǰ���µ�λ��
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