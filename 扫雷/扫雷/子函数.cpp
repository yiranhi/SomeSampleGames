#define _CRT_SECURE_NO_WARNINGS
 
#include"game.h"

//1.菜单函数
void menu()
{
	printf("*********扫 雷*********\n");
	printf("****1.Play   2.Exit****\n");
	printf("***********************\n");
}


//2.1初始化函数
void InitBoard(char board[ROWS][COLS], int rows, int cols, char set)
{
	int i, j;
	for (i = 0; i < rows; i++)
	{
		for (j = 0; j < cols; j++)
		{
			board[i][j] = set;
		}
	}
}

//2.2棋盘展示函数
void DisplayBoard(char board[ROWS][COLS], int row, int col)
{
	int i, j;
	//打印行号
	for (i = 0; i <= col; i++)
	{
		printf("%2d", i);
	}
	printf("\n");
	//打印分割线
	//打印列号&棋盘
	for (i = 1; i <= row; i++)
	{
		printf("%2d",i);
		for (j = 1; j <= col; j++)
		{
			printf(" %c", board[i][j]);
		}
		printf("\n");
	}
}

//2.3布置雷函数
void SetBomb(char board[ROWS][COLS],int row, int col)
{
	int i, j, k;
	for (k = 0; k < BOOM;)
	{
		i = rand() % row + 1;
		j = rand() % col + 1;
		if (board[i][j] == '0')
		{
			board[i][j] = '1';
			k++;
		}
		else
		{
			;
		}
	}
}

//2.4查找雷函数
void FindBomb(char bomb[ROWS][COLS], char scan[ROWS][COLS], int row, int col)
{
	int i, j;
	int x, y;
	int win = 0;
	while (win != BOOM)
	{
		win = 0;
		//1.输入坐标
		printf("请输入要排查的坐标:");
		scanf("%d%d", &x, &y);
		//1.1坐标有效
		if (x > 0 && x <= row && y > 0 && y <= col)
		{
			//1.1.1踩雷
			if (bomb[x][y] == '1')
			{
				printf("*****踩雷,游戏结束*****\n");
				DisplayBoard(bomb, ROW, COL);
				break;
			}
			//1.1.2不是雷
			else
			{
				ExpandBoard(bomb, scan, x, y);
			}
			DisplayBoard(scan, ROW, COL);
			//DisplayBoard(bomb, ROW, COL);
			//遍历，Scan[][]== '*'的数量
			for (i = 1; i <= ROW; i++)
			{
				for (j = 1; j <= COL; j++)
				{
					if (scan[i][j] == '*')
						win++;
				}
			}
		}
		//1.2坐标无效
		else
			printf("坐标无效,");
	}
	if (win == BOOM)
	{
		printf("***恭喜你,排雷成功！***\n");
		DisplayBoard(bomb, ROW, COL);
	}
}

//2.4.1统计周围8格雷的个数函数
int CountBomb(char bomb[ROWS][COLS], int x, int y)
{
	int i, j;
	int result = 0;
	for (i = 0; i <= 2; i++)
	{
		for (j = 0; j <= 2; j++)
		{
			result = result + bomb[x - 1 + i][y - 1 + j] - '0';
		}
	}
	return result;
}

//2.4.2扩展无雷周围格子函数
void ExpandBoard(char bomb[ROWS][COLS], char scan[ROWS][COLS], int x, int y)
{
	//统计周围8格雷的个数
	int count = CountBomb(bomb, x, y);
	//周围8格有雷
	if (count != 0 && scan[x][y] == '*')
	{
		scan[x][y] = count + '0';
	}
	//周围8格无雷，递归，自动向外扩展排查
	if (count == 0 && scan[x][y] == '*')
	{
		scan[x][y] = ' ';
		if (scan[x - 1][y - 1] == '*' && x - 1 > 0 && x - 1 <= ROW && y - 1 > 0 && y - 1 <= COL)
			ExpandBoard(bomb, scan, x - 1, y - 1);
		if (scan[x - 1][y] == '*' && x - 1 > 0 && x - 1 <= ROW && y > 0 && y <= COL)
			ExpandBoard(bomb, scan, x - 1, y);
		if (scan[x - 1][y + 1] == '*' && x - 1 > 0 && x - 1 <= ROW && y + 1 > 0 && y + 1 <= COL)
			ExpandBoard(bomb, scan, x - 1, y + 1);
		if (scan[x][y - 1] == '*' && x > 0 && x <= ROW && y - 1 > 0 && y - 1 <= COL)
			ExpandBoard(bomb, scan, x, y - 1);
		if (scan[x][y] == '*' && x > 0 && x <= ROW && y > 0 && y <= COL)
			ExpandBoard(bomb, scan, x, y);
		if (scan[x][y + 1] == '*' && x > 0 && x <= ROW && y + 1 > 0 && y + 1 <= COL)
			ExpandBoard(bomb, scan, x - 1, y + 1);
		if (scan[x + 1][y - 1] == '*' && x + 1 > 0 && x + 1 <= ROW && y - 1 > 0 && y - 1 <= COL)
			ExpandBoard(bomb, scan, x + 1, y - 1);
		if (scan[x + 1][y] == '*' && x + 1 > 0 && x + 1 <= ROW && y > 0 && y <= COL)
			ExpandBoard(bomb, scan, x + 1, y);
		if (scan[x + 1][y + 1] == '*' && x + 1 > 0 && x + 1 <= ROW && y + 1 > 0 && y + 1 <= COL)
			ExpandBoard(bomb, scan, x + 1, y + 1);
	}
}

//2.游戏函数
void game()
{
	printf("\n");
	printf("******开 始 游 戏******\n");
	//存放随机生成的雷的数组
	char Bomb[ROWS][COLS] = {0};
	//存放排查出的雷的数组
	char Scan[ROWS][COLS] = { 0 };
	//2.1初始化
	InitBoard(Bomb, ROWS, COLS, '0');
	InitBoard(Scan, ROWS, COLS, '*');
	//2.2展示棋盘
	DisplayBoard(Scan, ROW, COL);
	//2.3布置雷
	SetBomb(Bomb, ROW, COL);
	//展示雷的位置
	//DisplayBoard(Bomb, ROW, COL);
	//2.4查找雷
	FindBomb(Bomb, Scan, ROW, COL);
}


//3.继续菜单
void ContinueMenu()
{
	printf("\n");
	printf("*****是否继续游戏?*****\n");
	printf("***1.Continue 2.Exit***\n");
	printf("***********************\n");
}