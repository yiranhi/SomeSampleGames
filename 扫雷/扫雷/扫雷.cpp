#define _CRT_SECURE_NO_WARNINGS

//ɨ����Ϸ
#include"game.h"

int main()
{
	int input;
	srand((unsigned int)time(NULL));
	menu();
again:
	printf("��ѡ��:");
	scanf("%d",&input);
	switch (input)
	{
	case 1:
		game();
		ContinueMenu();
		goto again;
		break;
	case 2:
		printf("******�� �� �� Ϸ******\n");
		break;
	default:
		printf("**������Ч,����������**\n");
		printf("\n");
		goto again;
	}
	return 0;
}