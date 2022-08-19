#pragma once

#define ROW 9
#define COL 9
#define ROWS ROW+2
#define COLS COL+2
#define BOOM 10

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void menu();
void game();
void InitBoard(char board[ROWS][COLS], int rows, int cols, char set);
void DisplayBoard(char board[ROWS][COLS], int row, int col);
void FindBomb(char bomb[ROWS][COLS], char scan[ROWS][COLS], int row, int col);
int CountBomb(char bomb[ROWS][COLS], int x, int y);
void ContinueMenu();
void ExpandBoard(char bomb[ROWS][COLS], char scan[ROWS][COLS], int x, int y);
