#pragma once

#define ROW 3
#define COL 3

#include<stdio.h>
#include<time.h>
#include<stdlib.h>

//菜单函数
void menu();
//是否继续游戏菜单
void ContinueMenu();
//游戏函数
void game();
//初始化棋盘
void InitBoard(char Board[ROW][COL], int row, int col);
//展示棋盘
void DisplayBoard(char Board[ROW][COL], int row, int col);
//玩家下棋
void PlayerMove(char Board[ROW][COL], int row, int col);
//电脑下棋
void ComputerMove(char Board[ROW][COL], int row, int col);
//判断胜、负或平局
char Judge(char Board[ROW][COL], int row, int col);
//判断棋盘是否下满了
int Full(char Board[ROW][COL], int row, int col);