#include "±êÍ·.h"
#include <stdio.h>
#include <conio.h>  
#include <stdlib.h>
#include <time.h>

void Train()
{
	double round;
	set_d1 = 1.5;
	system("cls");
	for (round = 1; round <= 20; round++)
	{
		set_e = 2;
		int wintime1 = 0, wintime2 = 0;
		int w;
		for (w = 0; w <= 19; ++w)
		{
			int q;
			int turn = 1;
			result = 3;
			InitBoardArray();
			DisplayBoard();
			for (q = 1; q <= 225 && result == 3; ++q)
			{
				if (turn == 1)
				{
					AInew(turn, q);
					printf("wintime1:%d wintime2:%d", wintime1, wintime2);
					DisplayBoard();

					printf("wintime1:%d wintime2:%d", wintime1, wintime2);
					WINorLOSE();
					turn = 3 - turn;
				}
				else
				{
					AI(turn,q);
					printf("wintime1:%d wintime2:%d", wintime1, wintime2);
					DisplayBoard();

					printf("wintime1:%d wintime2:%d", wintime1, wintime2);
					WINorLOSE();
					turn = 3 - turn;
				}
			}
			if (result == 1)
				++wintime1;
			else if (result == 0)
				++wintime2;
			else
				;
			InitBoardArray();
			DisplayBoard();
			q = 0;
			turn = 1;
			result = 3;
			for (q = 1; q <= 225 && result == 3; ++q)
			{
				if (turn == 1)
				{
					AI(turn,q);
					printf("wintime1:%d wintime2:%d", wintime1, wintime2);
					DisplayBoard();
					WINorLOSE();

					printf("wintime1:%d wintime2:%d", wintime1, wintime2);
					turn = 3 - turn;
				}
				else
				{
					AInew(turn,q);
					printf("wintime1:%d wintime2:%d", wintime1, wintime2);
					DisplayBoard();

					printf("wintime1:%d wintime2:%d", wintime1, wintime2);
					WINorLOSE();
					turn = 3 - turn;
				}
			}
			if (result == 1)
				++wintime2;
			else if (result == 0)
				++wintime1;
			else
				;
		}
		int a = round;
		double WHO[20] = {0};
		if (wintime1 >= wintime2+2)
			WHO[a] = set_e;
		else if (wintime1 < wintime2+2)
		{
			 ;
		}
	}
	printf("²âÊÔÍê±Ï£¬set_e = %f\n", set_d);
	
	getchar();
}