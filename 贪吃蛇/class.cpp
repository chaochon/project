#include"GreedySnake.h"
#include"graphics.h"
#include"time.h"
using namespace std;
/*全局变量声明引用start*/
extern Snake snake;
extern int Speed;
/*全局变量声明引用end*/

/*类的实现start*/
void Wall::init(Point aa, Point bb){
	a = aa;
	b = bb;
}
void Wall::draw(){
	int x0 = a.x * 10 + 160;
	int y0 = a.y * 10;
	int x1 = b.x * 10 + 160;
	int y1 = b.y * 10;
	rectangle(x0, y0, x1, y1);
}

void Apple::init(int xx, int yy){
	x = xx;
	y = yy;
}
void Apple::newApple(){
	int flag = 0;
	do{
		x = rand() % 47;
		y = rand() % 47;
		Point a1 = { x, y };
		LinkList p = snake.body;
		flag = 0;//0标识苹果不再蛇身
		do{
			if (p->next->data == a1){
				flag = 1;
				break;
			}
			p = p->next;
		} while (p->next != NULL);
	} while (flag);
}
void Apple::draw(){

	int xx = x * 10 + 160;
	int yy = y * 10;
	rectangle(xx, yy, xx + 10, yy + 10);
}

void UI::init(int sscore, int cclass_game){
	score = sscore;
	class_game = cclass_game;
}
void UI::draw(){
	/*分数难度*/
	TCHAR str1[10] = _T("分数:");
	TCHAR str2[10] = _T("难度:");
	TCHAR str11[10], str22[10];
	_stprintf_s(str11, _T("%d"), score);//将数据格式化输出到字符串
	_stprintf_s(str22, _T("%d"), class_game);
	lstrcat(str1, str11);
	lstrcat(str2, str22);
	outtextxy(50, 70, str2);
	outtextxy(50, 50, str1);

}
void UI::inc(){
	score++;
	if (score % 2 == 0){
		class_game++;
		if (100 - Speed >= 0)
			Speed += 10;
	}
}

void Rank::init(){
	ofstream outfile;
	outfile.open("afile.dat");
	for (int i = 0; i<N; i++)
		outfile << 0 << endl;
	outfile.close();
}//初始化
void Rank::write(int score){
	ifstream  infile;
	infile.open("afile.dat", ios::in);
	int data[N];
	int i;
	/*读入数据*/
	for (i = 0; i < N; i++)
		infile >> data[i];
	infile.close();
	/*替换掉最低成绩*/
	int min = 0;
	for (i = 1; i < N; i++)
		if (data[i]<data[min])
			min = i;
	if (data[min]<score)
		data[min] = score;
	/*写入数据*/
	ofstream oufile;
	oufile.open("afile.dat", ios::out | ios::trunc);
	for (i = 0; i < N; i++)
		oufile << data[i] << endl;
	oufile.close();
}//将一个成绩写入排行榜
void Rank::draw(){
	TCHAR str[10] = _T("排行榜");
	outtextxy(50, 200, str);
	TCHAR str1[10] = _T("第一名："), str11[10];
	TCHAR str2[10] = _T("第二名："), str22[10];
	TCHAR str3[10] = _T("第三名："), str33[10];
	TCHAR str4[10] = _T("第四名："), str44[10];
	TCHAR str5[10] = _T("第五名："), str55[10];

	TCHAR *ptr[N] = { str1, str2, str3, str4, str5 };//指针数组
	TCHAR *ptr1[N] = { str11, str22, str33, str44, str55 };
	ifstream infile;
	infile.open("afile.dat", ios::in);
	int data[N] = { 0 };
	for (int i = 0; i < N; i++){
		infile >> data[i];
	}
	BubbleSort(data, N);
	_stprintf_s(str11, _T("%d"), data[0]);
	_stprintf_s(str22, _T("%d"), data[1]);
	_stprintf_s(str33, _T("%d"), data[2]);
	_stprintf_s(str44, _T("%d"), data[3]);
	_stprintf_s(str55, _T("%d"), data[4]);
	for (int i = 0; i < N; i++){
		lstrcat(ptr[i], ptr1[i]);
		outtextxy(50, 250 + 50 * i, ptr[i]);
	}
}
/*类的实现end*/