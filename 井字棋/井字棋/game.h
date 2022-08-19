#pragma once

#define ROW 3
#define COL 3

#include<stdio.h>
#include<time.h>
#include<stdlib.h>

//�˵�����
void menu();
//�Ƿ������Ϸ�˵�
void ContinueMenu();
//��Ϸ����
void game();
//��ʼ������
void InitBoard(char Board[ROW][COL], int row, int col);
//չʾ����
void DisplayBoard(char Board[ROW][COL], int row, int col);
//�������
void PlayerMove(char Board[ROW][COL], int row, int col);
//��������
void ComputerMove(char Board[ROW][COL], int row, int col);
//�ж�ʤ������ƽ��
char Judge(char Board[ROW][COL], int row, int col);
//�ж������Ƿ�������
int Full(char Board[ROW][COL], int row, int col);