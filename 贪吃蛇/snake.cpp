#include"GreedySnake.h"
extern int Speed;
void Snake::init(LinkList bbody,Direct ddir){

	body = bbody;
	dir = ddir;
}
void Snake::move(){
	int xofset[4] = { 0, 0, -1, 1 };
	int yofset[4] = { -1, 1, 0, 0 };
	/*控制游戏速度*/
	int intervalTime = 100 - Speed;
	static int lastMoveTick = 0;
	int curTicktime = GetTickCount();
	if (curTicktime - lastMoveTick < intervalTime){
		return;
	}
	lastMoveTick = curTicktime;
	/*控制游戏速度end*/
	LinkList p = body;
	int prex = p->next->data.x;
	int prey = p->next->data.y;

	p->next->data.x += xofset[dir];
	p->next->data.y += yofset[dir];
	p = p->next;
	do{
		int curx = p->next->data.x;
		int cury = p->next->data.y;
		p->next->data.x = prex;
		p->next->data.y = prey;
		prex = curx;
		prey = cury;
		p = p->next;
	} while (p->next != NULL);


}
void Snake::changeDirect(Direct direc){
	switch (dir)
	{
	case up:
	case down:
		if (direc == Left || direc == Right)
			dir = direc;
		break;
	case Left:
	case Right:
		if (direc == up || direc == down)
			dir = direc;
		break;
	default:
		break;
	}
}

bool Snake::tryeat(Apple apple){
	int xofset[4] = { 0, 0, -1, 1 };
	int yofset[4] = { -1, 1, 0, 0 };
	Point prePoint;
	prePoint.x = body->next->data.x;
	prePoint.y = body->next->data.y;
	prePoint.x += xofset[dir];
	prePoint.y += yofset[dir];
	if (prePoint.x == apple.x && prePoint.y == apple.y){
		Point apple1 = { apple.x, apple.y };
		ListInsert(body, 1, apple1);
		return true;
	}
	return false;
}

bool Snake::eatItself(){
	int xofset[4] = { 0, 0, -1, 1 };
	int yofset[4] = { -1, 1, 0, 0 };
	Point prePoint;
	prePoint.x = body->next->data.x;
	prePoint.y = body->next->data.y;
	prePoint.x += xofset[dir];
	prePoint.y += yofset[dir];
	LinkList p = body;
	do{
		if (p->next->data== prePoint)
			return true;
		p = p->next;
	} while (p->next != NULL);
	return false;
}

bool Snake::hitwall(Wall wall){
	int xofset[4] = { 0, 0, -1, 1 };
	int yofset[4] = { -1, 1, 0, 0 };
	Point prePoint;
	prePoint.x = body->next->data.x;
	prePoint.y = body->next->data.y;
	prePoint.x += xofset[dir];
	prePoint.y += yofset[dir];
	if (prePoint.x < wall.a.x || prePoint.x > wall.b.x-1 || prePoint.y < wall.a.y || prePoint.y > wall.b.y-1)
		return true;
	return false;
}

void Snake::draw(){
	LinkList p;
	int x, y;
	p = body;
	do{
		x = (p->next->data.x) * 10 + 160;
		y = (p->next->data.y) * 10;
		rectangle(x, y, x + 10, y + 10);
		p = p->next;
	} while (p->next != NULL);
}