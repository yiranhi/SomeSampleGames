#define _CRT_SECURE_NO_WARNINGS

#define ROW 3
#define COL 3

#include"game.h"

//1.�˵�����
void menu()
{
	printf("************************\n");
	printf("*****1.Play  2.Exit*****\n");
	printf("************************\n");
}


//2.��Ϸ����
void game()
{
	char result;
	//��������
	char Board[ROW][COL] = { 0 };
	//��ʼ������
	InitBoard(Board, ROW, COL);
	//չʾ����
	DisplayBoard(Board, ROW, COL);
	while (1)
	{
		//�������
		PlayerMove(Board, ROW, COL);
		DisplayBoard(Board, ROW, COL);
		//�ж�ʤ��
		result = Judge(Board, ROW, COL);
		if (result != 'C')
		{
			break;
		}
		//��������
		ComputerMove(Board, ROW, COL);
		DisplayBoard(Board, ROW, COL);
		//�ж�ʤ��
		result = Judge(Board, ROW, COL);
		if (result != 'C')
		{
			break;
		}
	}
	if (result == 'O')
		printf("��һ�ʤ\n");
	else if (result == 'X')
		printf("���Ի�ʤ\n");
	else
		printf("ƽ��\n");
}


//2.1���̳�ʼ������
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

//2.2�������ɺ���
void DisplayBoard(char Board[ROW][COL], int row, int col)
{
	int i, j;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			//1.��ӡһ������
			printf(" %c ", Board[i][j]);
			if (j < col - 1)
				printf("|");
		}
		printf("\n");
		//2.��ӡ�ָ���
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

//2.3�������
void PlayerMove(char Board[ROW][COL], int row, int col)
{
	int i, j;
	int flag = 1;
	printf("��һغ�\n");
	do
	{
		printf("���������꣺");
		scanf("%d%d", &i, &j);
		//��Ϊ�������ʼλ��Ϊ[0][0],������һ����Ϊ����ʼλ��Ϊ[1][1],����Ҫ����+1��-1����
		if ((i > 0 && i < row + 1 && j > 0 && j < col + 1) && (Board[i - 1][j - 1] == ' '))
		{
			Board[i - 1][j - 1] = 'O';
			flag = 1;
		}
		else
		{
			//��������������Ч����Ҫ�������룬Ϊ��������һ����־flag
			printf("������Ч������������\n");
			flag = 0;
		}
	} while (flag == 0);
}

//2.4��������
void ComputerMove(char Board[ROW][COL], int row, int col)
{
	int i, j;
	int flag = 1;
	printf("���Իغ�\n");
	do
	{
		//ͨ��ʱ���������λ��
		srand((unsigned int)time(NULL));
		//ͨ��ģrowȡ������������i��0~row-1֮�両����jͬ��
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

//2.5�ж�ʤ������
char Judge(char Board[ROW][COL], int row, int col)
{
	int i, j;
	//�ж����Ƿ���������
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
	//�ж����Ƿ���������
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
		//����Ԫ����ȣ�������������Ӧ�ñ�������1��������������������⡣
		if (row - 1 == count)
			return Board[0][j];
	}
	//�ж�б���Ƿ���������
	if (Board[0][0] == Board[1][1] && Board[2][2] == Board[1][1] && Board[0][0] != ' ')
		return Board[0][0];
	if (Board[0][2] == Board[1][1] && Board[2][0] == Board[1][1] && Board[0][2] != ' ')
		return Board[0][2];
	//�ж��Ƿ�ƽ��
	if (1 == Full(Board, ROW, COL))
	{
		return 'E';
	}
	return 'C';
}

//2.5.1�ж������Ƿ����˺���
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



//3.������Ϸ����
void ContinueMenu()
{
	printf("************************\n");
	printf("��Ϸ�ѽ������Ƿ������Ϸ\n");
	printf("***1.Continue  2.Exit***\n");
	printf("************************\n");
}

