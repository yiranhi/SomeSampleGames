#define _CRT_SECURE_NO_WARNINGS

//��������Ϸ
#include"game.h"

int main()
{
	int input = 0;
	int con = 0;
	do
	{
		menu();
		printf("��ѡ��");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			printf("��ʼ��Ϸ\n");
			game();
			ContinueMenu();
			printf("��ѡ��");
			scanf("%d", &con);
			break;
		case 2:
			printf("�˳���Ϸ\n");
			break;
		default:
			printf("������Ч��������ѡ��\n");
			break;
		}
	} while (con == 1 || (input != 2 && input != 1));
	return 0;
}