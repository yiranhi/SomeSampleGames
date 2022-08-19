#define _CRT_SECURE_NO_WARNINGS
 
#include"game.h"

//1.�˵�����
void menu()
{
	printf("*********ɨ ��*********\n");
	printf("****1.Play   2.Exit****\n");
	printf("***********************\n");
}


//2.1��ʼ������
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

//2.2����չʾ����
void DisplayBoard(char board[ROWS][COLS], int row, int col)
{
	int i, j;
	//��ӡ�к�
	for (i = 0; i <= col; i++)
	{
		printf("%2d", i);
	}
	printf("\n");
	//��ӡ�ָ���
	//��ӡ�к�&����
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

//2.3�����׺���
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

//2.4�����׺���
void FindBomb(char bomb[ROWS][COLS], char scan[ROWS][COLS], int row, int col)
{
	int i, j;
	int x, y;
	int win = 0;
	while (win != BOOM)
	{
		win = 0;
		//1.��������
		printf("������Ҫ�Ų������:");
		scanf("%d%d", &x, &y);
		//1.1������Ч
		if (x > 0 && x <= row && y > 0 && y <= col)
		{
			//1.1.1����
			if (bomb[x][y] == '1')
			{
				printf("*****����,��Ϸ����*****\n");
				DisplayBoard(bomb, ROW, COL);
				break;
			}
			//1.1.2������
			else
			{
				ExpandBoard(bomb, scan, x, y);
			}
			DisplayBoard(scan, ROW, COL);
			//DisplayBoard(bomb, ROW, COL);
			//������Scan[][]== '*'������
			for (i = 1; i <= ROW; i++)
			{
				for (j = 1; j <= COL; j++)
				{
					if (scan[i][j] == '*')
						win++;
				}
			}
		}
		//1.2������Ч
		else
			printf("������Ч,");
	}
	if (win == BOOM)
	{
		printf("***��ϲ��,���׳ɹ���***\n");
		DisplayBoard(bomb, ROW, COL);
	}
}

//2.4.1ͳ����Χ8���׵ĸ�������
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

//2.4.2��չ������Χ���Ӻ���
void ExpandBoard(char bomb[ROWS][COLS], char scan[ROWS][COLS], int x, int y)
{
	//ͳ����Χ8���׵ĸ���
	int count = CountBomb(bomb, x, y);
	//��Χ8������
	if (count != 0 && scan[x][y] == '*')
	{
		scan[x][y] = count + '0';
	}
	//��Χ8�����ף��ݹ飬�Զ�������չ�Ų�
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

//2.��Ϸ����
void game()
{
	printf("\n");
	printf("******�� ʼ �� Ϸ******\n");
	//���������ɵ��׵�����
	char Bomb[ROWS][COLS] = {0};
	//����Ų�����׵�����
	char Scan[ROWS][COLS] = { 0 };
	//2.1��ʼ��
	InitBoard(Bomb, ROWS, COLS, '0');
	InitBoard(Scan, ROWS, COLS, '*');
	//2.2չʾ����
	DisplayBoard(Scan, ROW, COL);
	//2.3������
	SetBomb(Bomb, ROW, COL);
	//չʾ�׵�λ��
	//DisplayBoard(Bomb, ROW, COL);
	//2.4������
	FindBomb(Bomb, Scan, ROW, COL);
}


//3.�����˵�
void ContinueMenu()
{
	printf("\n");
	printf("*****�Ƿ������Ϸ?*****\n");
	printf("***1.Continue 2.Exit***\n");
	printf("***********************\n");
}