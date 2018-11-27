#include"GreedySnake.h"
#include"graphics.h"
#include"conio.h"
/*全局变量begin*/
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
/*全局变量end*/


/*初始化游戏参数*/

int main()
{
	initgraph(640, 480);
	setbkcolor(WHITE);
	setlinecolor(BLACK);
	settextcolor(BLACK);
	cleardevice();
	/*初始化游戏参数*/
	initGame();
	//rrank.init();
	do {
	if (Restart){
		initGame();

	}//实现重置游戏
	keyboardControl();//按键控制
	handleLogic();//处理游戏逻辑
	draw();
	Sleep(30);//控制帧率
	} while (isGameRuning);

	closegraph();
	return 0;
}


