#define _CRT_SECURE_NO_WARNINGS

#define ROW 3
#define COL 3

#include"game.h"

//1.菜单函数
void menu()
{
	printf("************************\n");
	printf("*****1.Play  2.Exit*****\n");
	printf("************************\n");
}


//2.游戏函数
void game()
{
	char result;
	//生成棋盘
	char Board[ROW][COL] = { 0 };
	//初始化棋盘
	InitBoard(Board, ROW, COL);
	//展示棋盘
	DisplayBoard(Board, ROW, COL);
	while (1)
	{
		//玩家下棋
		PlayerMove(Board, ROW, COL);
		DisplayBoard(Board, ROW, COL);
		//判断胜负
		result = Judge(Board, ROW, COL);
		if (result != 'C')
		{
			break;
		}
		//电脑下棋
		ComputerMove(Board, ROW, COL);
		DisplayBoard(Board, ROW, COL);
		//判断胜负
		result = Judge(Board, ROW, COL);
		if (result != 'C')
		{
			break;
		}
	}
	if (result == 'O')
		printf("玩家获胜\n");
	else if (result == 'X')
		printf("电脑获胜\n");
	else
		printf("平局\n");
}


//2.1棋盘初始化函数
void InitBoard(char Board[ROW][COL], int row, int col)
{
	int i, j;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			Board[i][j] = ' ';
		}
	}
}

//2.2棋盘生成函数
void DisplayBoard(char Board[ROW][COL], int row, int col)
{
	int i, j;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			//1.打印一行数据
			printf(" %c ", Board[i][j]);
			if (j < col - 1)
				printf("|");
		}
		printf("\n");
		//2.打印分割线
		if (i < row - 1)
		{
			for (j = 0; j < col; j++)
			{
				printf("---");
				if (j < col - 1)
					printf("|");
			}
			printf("\n");
		}
	}
}

//2.3玩家下棋
void PlayerMove(char Board[ROW][COL], int row, int col)
{
	int i, j;
	int flag = 1;
	printf("玩家回合\n");
	do
	{
		printf("请输入坐标：");
		scanf("%d%d", &i, &j);
		//因为数组的起始位置为[0][0],但大众一般认为的起始位置为[1][1],所以要进行+1、-1调整
		if ((i > 0 && i < row + 1 && j > 0 && j < col + 1) && (Board[i - 1][j - 1] == ' '))
		{
			Board[i - 1][j - 1] = 'O';
			flag = 1;
		}
		else
		{
			//如果输入的坐标无效，就要重新输入，为此设置了一个标志flag
			printf("坐标无效，请重新输入\n");
			flag = 0;
		}
	} while (flag == 0);
}

//2.4电脑下棋
void ComputerMove(char Board[ROW][COL], int row, int col)
{
	int i, j;
	int flag = 1;
	printf("电脑回合\n");
	do
	{
		//通过时间生成随机位置
		srand((unsigned int)time(NULL));
		//通过模row取余数，就能让i在0~row-1之间浮动；j同理
		i = rand() % row;
		j = rand() % col;
		if (Board[i][j] == ' ')
		{
			Board[i][j] = 'X';
			flag = 1;
		}
		else
			flag = 0;
	} while (flag == 0);
}

//2.5判断胜负函数
char Judge(char Board[ROW][COL], int row, int col)
{
	int i, j;
	//判断行是否连成三个
	for (i = 0; i < row; i++)
	{
		int count = 0;
		for (j = 0; j < col - 1; j++)
		{
			if ((Board[i][0] != ' ') && (Board[i][j] == Board[i][j + 1]))
			{
				count++;
			}
		}
		if (col - 1 == count)
			return Board[i][0];
	}
	//判断列是否连成三个
	for (j = 0; j < col; j++)
	{
		int count = 0;
		for (i = 0; i < row - 1; i++)
		{
			if ((Board[0][j] != ' ') && (Board[i][j] == Board[i + 1][j]))
			{
				count++;
			}
		}
		//三个元素相等，计数器的数字应该比行数少1。可以用两刀切三段理解。
		if (row - 1 == count)
			return Board[0][j];
	}
	//判断斜线是否连成三个
	if (Board[0][0] == Board[1][1] && Board[2][2] == Board[1][1] && Board[0][0] != ' ')
		return Board[0][0];
	if (Board[0][2] == Board[1][1] && Board[2][0] == Board[1][1] && Board[0][2] != ' ')
		return Board[0][2];
	//判断是否平局
	if (1 == Full(Board, ROW, COL))
	{
		return 'E';
	}
	return 'C';
}

//2.5.1判断棋盘是否满了函数
int Full(char Board[ROW][COL], int row, int col)
{
	int i, j;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			if (Board[i][j] == ' ')
				return 0;
		}
	}
	return 1;
}



//3.继续游戏函数
void ContinueMenu()
{
	printf("************************\n");
	printf("游戏已结束，是否继续游戏\n");
	printf("***1.Continue  2.Exit***\n");
	printf("************************\n");
}

