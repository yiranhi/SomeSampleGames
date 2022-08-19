#define _CRT_SECURE_NO_WARNINGS

//扫雷游戏
#include"game.h"

int main()
{
	int input;
	srand((unsigned int)time(NULL));
	menu();
again:
	printf("请选择:");
	scanf("%d",&input);
	switch (input)
	{
	case 1:
		game();
		ContinueMenu();
		goto again;
		break;
	case 2:
		printf("******退 出 游 戏******\n");
		break;
	default:
		printf("**输入无效,请重新输入**\n");
		printf("\n");
		goto again;
	}
	return 0;
}