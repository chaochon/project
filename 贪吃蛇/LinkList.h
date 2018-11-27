#ifndef LINKLIST_H
#define LINKLIST_H

#define OK 1
#define ERROR 0
/*链表数据结构*/
typedef int Status;
typedef struct Point{
	int x;
	int y;
}Point;
typedef  Point ElemType;

typedef struct LNode
{
	ElemType data;
	struct LNode *next;
}LNode, *LinkList;
Status InitList(LinkList &L);
Status ListInsert(LinkList L, int i, ElemType e);
#endif