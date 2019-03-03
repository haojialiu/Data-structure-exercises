#include "CycDoubleList.h"

void InitCycDouList(pCycList list)
{
	assert(list != NULL);

	list->head = NULL;

	list->count = 0;
}

static Node *BuyNode(ElemType value, Node *prev, Node* next)
{
	Node * s = (Node *)malloc(sizeof(Node));

	assert(s != NULL);

	s->data = value;

	if (prev == NULL || next == NULL)
	{
		s->next = s->prev = s;
	}
	else
	{
		s->next = next;
		s->prev = prev;
	}
	return s;
}

 void Insert(ElemType value, pCycList list, Node* p)
{
	Node *s = BuyNode(value, p, p->next);

	p->next->prev = s;

	p->next = s;

	list->count++;
}

void InsertCycDouList(pCycList list, ElemType value, int pos)
{
	assert(list != NULL);

	if (list->head == NULL)
	{
		Node *s = BuyNode(value, NULL, NULL);

		list->head = s;

		list->count++;

		return;
	}
	if (pos < 0 || pos > list->count)
	{
		printf("insert pos is error\n");

		return;
	}

	Node *p = list->head;

	if (pos == 0)
	{
		p = p->prev;

		Insert(value, list, p);

		list->head = list->head->prev;
	}
	else
	{
		while (pos > 1)
		{
			p = p->next;

			pos--;
		}
		Insert(value, list, p);
	}
}

void DestroyCycDouList(pCycList list,int pos)
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
		list->head->next->prev = p;
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

	q->next->prev = q->prev;

	free(q);

	list->count--;
}

void ShowDouList(pCycList list)
{
	assert(list != NULL);

	Node *p = list->head;

	while (p != list->head)
	{
		printf("%d  ", p->data);

		p = p->next;
	}
	printf("\n");
}

void ReverseShow(pCycList list)
{
	assert(list != NULL);

	Node *p = list->head;

	while (p->prev != list->head)
	{
		printf("%d  ", p->data);

		p = p->prev;
	}
	printf("\n");
}