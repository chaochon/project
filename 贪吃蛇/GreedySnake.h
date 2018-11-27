#ifndef GREEDYSNACK_H
#define GREEDYSNACK_H
#include"LinkList.h"
#include"graphics.h"
#include"fstream"
#include"iostream"
#define N 5 //���а���Ŀ
enum Direct{ up, down, Left, Right };
class Rank{
public:
	void init();
	void write(int score);
	void draw();
};//���а���

class Apple{
public:
	void init(int xx, int yy);
	void newApple();
	void draw();
	friend class Snake;
private:
	int x, y;
};

class Wall{
public:
	void init(Point aa, Point bb);
	void draw();
	friend class Snake;
private:
	Point a, b;
};

class UI{
public:
	void init(int sscore, int cclass_game);
	void inc();
	void draw();
	int score;
private:
	int class_game;
};

class Snake{
public:
	void init(LinkList bbody,Direct dir);
	void move();
	bool tryeat(Apple apple);
	bool eatItself();
	bool hitwall(Wall wall);
	void changeDirect(Direct ddir);
	void draw();
	friend class Apple;
private:
	LinkList body;
	Direct dir;
};




void initGame();
bool isKeyDown(int key);//�ж��Ƿ����м�������
void draw();
void keyboardControl();//���ݼ��������ֵ ������Ӧ�ĸ�ֵ����
void handleLogic();
bool operator==(Point &a, Point &b);
void BubbleSort(int A[], int n);//ð������
#endif