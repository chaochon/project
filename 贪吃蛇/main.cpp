#include"GreedySnake.h"
#include"graphics.h"
#include"conio.h"
/*ȫ�ֱ���begin*/
bool isGameRuning = true;
bool GameOver = false;
bool Restart = false;
int Speed = 0;
int Pause = 1;
Wall wall;
Snake snake;
UI ui;
Apple apple;
Rank rrank;
/*ȫ�ֱ���end*/


/*��ʼ����Ϸ����*/

int main()
{
	initgraph(640, 480);
	setbkcolor(WHITE);
	setlinecolor(BLACK);
	settextcolor(BLACK);
	cleardevice();
	/*��ʼ����Ϸ����*/
	initGame();
	//rrank.init();
	do {
	if (Restart){
		initGame();

	}//ʵ��������Ϸ
	keyboardControl();//��������
	handleLogic();//������Ϸ�߼�
	draw();
	Sleep(30);//����֡��
	} while (isGameRuning);

	closegraph();
	return 0;
}


