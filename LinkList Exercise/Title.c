#include"LinkList.h"
//3、已知递增有序的单链表 A,B 和C 分别存储了一个集合，设计算法实现 A：=A∪（B∩C） ，并使求解结构 A 仍保持递增。要求算法的时间复杂度为 O(|A|+|B|+|C|)。其中,|A|为集合A 的元素个数。

void Isintersect(pList listA, pList listB, pList listC)
{
	assert(listA != NULL);
	assert(listB != NULL);
	assert(listC != NULL);
	Node *a = listA->head.next;
	Node *b = listB->head.next;
	Node *c = listC->head.next;
	while (b != NULL&&c != NULL)
	{
		if (b->data > c->data)
		{
			c=c->next;
		}
		else if (b->data < c->data)
		{
			b = b->next;
		}
		else
		{
			while (a->next != NULL)
			{
				if (a->data > b->data)
				{
					FrontInsert(listA, b->data, a);//在a前面插入一个结点的data为b->data
					break;
				}
				else if (a->data < b->data)
				{
					a = a->next;
				}
				else
				{
					FrontInsert(listA, b->data, a);
					break;
				}
			}
			b = b->next;
			c = c->next;
		}
	}
}

//////////////////////////////////////////////////////////////////////////////////////////////
//4、将带头节点的单链表改成不带头节点的单链表，并实现插入，删除，查找，求链表长度，打印等函数。
//见NoheadLinkList.c文件
//////////////////////////////////////////////////////////////////////////////
//5、试写一算法，对单链表实现就地逆置，请注意时间复杂度最好能达到O(n)。
void Revelinklist(pList list)
{
	assert(list != NULL);
	Node *p = list->head.next;

	Node *pp = p->next;

	Node *ppp = pp->next;

	p->next = NULL;

	while (ppp->next != NULL)
	{
		pp->next = p;
		p = pp;
		pp = ppp;
		ppp = pp->next;
	}
	pp->next = p;
	ppp->next = pp;
	list->head.next = ppp;
}





//单链表链表相关面试题
//=================================================================================================================================
//题一、 给定单链表，检测是否有环。
//题三、 给定单链表(head)，如果有环的话请返回从头结点进入环的第一个节点。
void IsBring(pList list)
{
	assert(list != NULL);
	Node *a = list->head.next;
	Node *b = list->head.next;

	a = a->next;
	while (a != b)
	{
		a = a->next;
		if (a->next == NULL)
		{
			printf("不存在环\n");
			return;
		}
		a = a->next;
		if (a->next == NULL)
		{
			printf("不存在环\n");
			return;
		}
		b = b->next;
	}
	a = &list->head;

	int i = 0;

	while (a != b)
	{
		a = a->next;
		b = b->next;
		i++;
	}
	printf("第%d个结点为入环点\n", i);
}

//制造环单链表
void MakeBring(pList list)
{
	assert(list != NULL);

	Node *p = list->head.next;
	while (p->next != NULL)
	{
		p = p->next;
	}
	p->next = list->head.next->next;
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//题二、 给定两个单链表(head1, head2)，检测两个链表是否有交点，如果有返回第一个交点。
int Intersect(pList list, pList list2)
{
	assert(list != NULL && list2 != NULL);
	Node *p = list->head.next;
	Node *p2 = list2->head.next;
	int a = 0;
	while (p->next != NULL)
	{

		a++;
		p2 = list2->head.next;
		while (p2->next != NULL)
		{
			if (p == p2)
			{
				return a;
			}
			p2 = p2->next;

		}
		p = p->next;

	}
	if (p->next == NULL)
	{
		return -1;
	}
}

//制造相交的两个单链表
void Make(pList list, pList list2)
{
	assert(list != NULL && list2 != NULL);
	Node *p = list->head.next;
	list2->head.next = p->next;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//题四、只给定单链表中某个结点p(并非最后一个结点，即p->next != NULL)指针，删除该结点。
void DeleteElemOfList(pList list, Node *p)
{
	assert(list != NULL);
	assert(p != NULL);
	Node *pp = &list->head;
	while (pp->next != p&&pp->next != NULL)
	{
		pp = pp->next;
	}

	pp->next = p->next;

	free(p);

	list->count--;
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//题五、只给定单链表中某个结点p(非空结点)，在p前面插入一个结点。
static Node *BuyNode(int val, Node *next)
{
	Node *s = (Node *)malloc(sizeof(Node));

	assert(s != NULL);

	s->data = val;

	s->next = next;

	return s;
}
void FrontInsert(pList list, int val, Node *p)
{
	assert(list != NULL);
	assert(p != NULL);

	Node *pp = &list->head;
	while (pp->next != p&&pp->next != NULL)
	{
		pp = pp->next;
	}
	Node *s = BuyNode(val, p->next);
	pp->next = s;
	s->next = p;
	list->count++;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//题六、给定单链表头结点，删除链表中倒数第k个结点。
void Find(pList list, int pos)
{
	assert(list != NULL);
	Node *a = list->head.next;
	Node *b = list->head.next;
	while (pos > 1)
	{
		a = a->next;
		pos--;
	}
	while (a->next != NULL)
	{
		a = a->next;
		b = b->next;
	}
	Node *pp = &list->head;
	while (pp->next != b&&pp->next != NULL)
	{
		pp = pp->next;
	}

	pp->next = b->next;

	free(b);

	list->count--;
}



