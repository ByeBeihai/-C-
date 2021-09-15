#include <stdio.h>
#include <conio.h>  
#include "标头.h"


int Board[SIZE][SIZE];//用于棋盘打印
int BoardCheck[SIZE][SIZE];//构造一个新的虚拟棋盘，进行禁手模拟和判定：
int Boardtest[SIZE][SIZE];//给AI打分和模拟使用的棋盘
int HSD_point[4];//用于存储HSD态势感知函数的数据
int result = 3;//判断棋局是否结束的变量
int Last_step[2];//最后一步所下的位置，用于实现最后一步棋的特殊标记
double set_a = 3, set_c = 10, set_d = 2, set_e;//调参和自动学习时的一系列参数
double set_a1 = 0, set_c1 = 10, set_d1 = 2;
//set_a我方该次棋的分数权重
//set_d活二的分数
//set_c我方第二步棋的分数权重
//set_e四步算法中 我方第三步的权重



void main()
{
	char c;
	printf("/////欢迎来到吉祥的五子棋比赛/////\n\n请输入任意文字继续\n\n");
	getche();
	system("cls");

	printf("\n请选择你的冒险模式：\n\n1.双人对战     2.人机模式\n\n请输入对应数字并按回车结束：\n\n");
	int choice = 0;
	scanf("%d", &choice);
	while ((c = getchar()) != EOF && c != '\n');

	while (choice != 1 && choice != 2 && choice!=114514)//114514为隐藏选项，进入训练模式
	{
		printf("好像没有这个选项，请重新输入：\n\n");
		scanf("%d", &choice);
		while ((c = getchar()) != EOF && c != '\n');
	}

	if (choice == 1)
		PVP();
	else if (choice == 2)
		PVE();
	else
		Train();
	
}
