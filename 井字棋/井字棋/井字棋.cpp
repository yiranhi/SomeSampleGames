#define _CRT_SECURE_NO_WARNINGS

//井字棋游戏
#include"game.h"

int main()
{
	int input = 0;
	int con = 0;
	do
	{
		menu();
		printf("请选择：");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			printf("开始游戏\n");
			game();
			ContinueMenu();
			printf("请选择：");
			scanf("%d", &con);
			break;
		case 2:
			printf("退出游戏\n");
			break;
		default:
			printf("输入无效，请重新选择\n");
			break;
		}
	} while (con == 1 || (input != 2 && input != 1));
	return 0;
}