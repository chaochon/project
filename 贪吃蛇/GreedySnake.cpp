#include"GreedySnake.h"
#include"graphics.h"
#include"time.h"
using namespace std;
/*全局变量声明引用start*/
extern Wall wall;
extern Snake snake;
extern Apple apple;
extern UI ui;
extern Rank rrank;
extern bool GameOver, isGameRuning,Restart;
extern int Speed;
extern int Pause;
/*全局变量声明引用end*/
/*运算符重载*/
bool operator==(Point &a, Point &b){
	if (a.x == b.x&&a.y == b.y)
		return OK;
	else
		return ERROR;
}

/*其他函数实现*/

void initGame(){
	Point point1, point2;
	point1 = { 0, 0 };
	point2 = { 47, 47 };
	wall.init(point1, point2);//初始化墙

	ui.init(0, 1);//初始化ui

	apple.init(20, 30);//初始化apple

	LinkList body;
	InitList(body);
	Point head, a2, a3, a4;
	head = { 1, 1 };
	a2 = { 2, 1 };
	a3 = { 3, 1 };
	a4 = { 4, 1 };
	ListInsert(body, 1, head);
	ListInsert(body, 1, a2);
	ListInsert(body, 1, a3);
	ListInsert(body, 1, a4);
	snake.init(body,Right);//初始化蛇
	
	
	Restart = false;
	GameOver = false;
	Speed = 0;
}

void draw(){
	/*清空上一帧的图像*/
	cleardevice();
	/*绘制本帧的图像*/
	wall.draw();
	ui.draw();
	apple.draw();
	snake.draw();
	rrank.draw();
	if (GameOver){
		TCHAR s[] = _T("game over");
		outtextxy(400, 240, s);
	}

}
void keyboardControl(){
	if (isKeyDown(VK_ESCAPE)){
		isGameRuning = false;
		return;
	}
	if (isKeyDown(VK_SPACE)){
		Restart = true;
		return;
	}
	if (isKeyDown(VK_F1)){
		Pause *= -1;
	}
	if (isKeyDown(VK_UP)){
		snake.changeDirect(up);
	}
	else if (isKeyDown(VK_DOWN)){
		snake.changeDirect(down);
	}
	else if (isKeyDown(VK_LEFT)){
		snake.changeDirect(Left);
	}
	else if (isKeyDown(VK_RIGHT)){
		snake.changeDirect(Right);
	}
	

}
bool isKeyDown(int key){
	return (GetAsyncKeyState(key) & 0x8000 ? 1 : 0);
}

void handleLogic(){
	if (GameOver||(Pause==-1)){
		return;
	}
		
	/*判断下一位置是否吃到自己或者撞墙*/
	if (snake.eatItself() || snake.hitwall(wall)){
		rrank.write(ui.score);
		GameOver = true;
	}
	if (snake.tryeat(apple)){
		apple.newApple();
		ui.inc();
	}
	else
		snake.move();
}

void BubbleSort(int A[], int n)
{
	int tmp = 0;
	for (int j = 0; j < n - 1; j++){         
		for (int i = 0; i < n - 1 - j; i++){
			if (A[i] < A[i + 1])            
			{
				tmp = A[i + 1];
				A[i + 1] = A[i];
				A[i] = tmp;
			}
		}
	}
}