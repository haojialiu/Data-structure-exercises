#include "cyclinklist.h"

void InitCycList(pCyc list)
{
	assert(list != NULL);

	list->count = 0;

	list->head = NULL;
}

static Node *BuyNode(ElemType val, Node *next)
{
	Node *s = (Node *)malloc(sizeof(Node));

	assert(s != NULL);

	s->data = val;

	if (next != NULL)
	{
		s->next = next;
	}
	else
	{
		s->next = s;
	}	
	return s;
}

void InsertCycList(pCyc list, ElemType val, int pos)
{
	if (list->head == NULL)   
	{
		list->head = BuyNode(val, NULL);

		list->count++;

		return;
	}
	if (pos < 0 || pos > list->count)
	{
		printf("insert pos is error\n");

		return;
	}
	Node *p = list->head;

	int pos2;

	if(pos != 0)
	{
		pos2 = pos;
	}
	else
	{
		pos2 = list->count;
	}
	while (pos2 > 1)
	{
		p = p->next;
		pos2--;
	}
	Node *s = BuyNode(val, p->next);

	p->next = s;

	if (pos == 0)
	{
		list->head = s;
	}
	list->count++;
}

void DeleteCycList(pCyc list, int pos)
{
	assert(list != NULL && list->head != NULL);

	if (list->head->next == list->head)
	{
		free(list->head);

		list->head = NULL;

		list->count--;

		return;
	}
	if (pos < 1 || pos > list->count)
	{
		printf("delete pos is error\n");

		return;
	}
	Node *p = list->head;

	if (pos == 1)
	{
		while (p->next != list->head)
		{
			p = p->next;
		}

		list->head = list->head->next;
	}
	else
	{
		while (pos > 2)
		{
			p = p->next;

			pos--;
		}
	}
	Node *q = p->next;

	p->next = q->next;

	free(q);

	list->count--;
}

void ShowList(pCyc list)
{
	assert(list != NULL);

	int tmp = 0;
	if (list->head == NULL)
	{
		printf("list is empty\n");

		return;
	}
	Node *p = list->head;

	while (p->next != list->head)
	{
		printf("%d  ", p->data);
		tmp++;
		p = p->next;
	}
	printf("%d  \n", p->data);
	printf("链表长度为%d\n", tmp);
}


void InquiryCycList(pCyc list, int pos)
{
	assert(list != NULL && list->head != NULL);

	if (pos < 1 || pos > list->count)
	{
		printf("delete pos is error\n");

		return;
	}
	Node *p = list->head;

	while (pos > 1)
	{
		p = p->next;
		pos--;
	}
	printf("该位置的值为%d\n",p->data);
}