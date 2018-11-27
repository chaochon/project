#include"stdlib.h"
#include"LinkList.h"

Status InitList(LinkList &L)
{
	L = (LinkList)malloc(sizeof(LNode));
	if (!L)
		exit(0);//�쳣���룬�˳�
	L->next = NULL;
	return OK;
}
/*�ڵ�i��Ԫ����ǰ����Ԫ��*/
Status ListInsert(LinkList L, int i, ElemType e)
{
	LinkList p, s;
	int j;
	p = L;
	j = 0;
	while (p && j<i - 1)					//Ѱ�ҵ�i-1����� 
	{
		p = p->next;
		++j;
	}
	if (!p || j > i - 1)
		return ERROR;
	s = (LinkList)malloc(sizeof(LNode));
	if (!s)
		exit(0);
	s->data = e;
	s->next = p->next;
	p->next = s;
	return OK;
}


