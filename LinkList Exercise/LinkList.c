#include "LinkList.h"

void InitLinkList(pList list)
{
	list->count = 0;

	list->head.next = NULL;
}

static Node *BuyNode(int val, Node *next)
{
	Node *s = (Node *)malloc(sizeof(Node));

	assert(s != NULL);

	s->data = val;

	s->next = next;

	return s;
}

void InsertElemToList(pList list, int val, int pos)
{
	if (pos < 0 || pos > list->count)
	{
		printf("insert pos is error\n");

		return;
	}

	Node *p = &list->head;

	while (pos > 0)
	{
		p = p->next;
		pos--;
	}

	Node *s = BuyNode(val, p->next);

	p->next = s;

	list->count++;
}



void ShowElemOfList(pList list)
{
	assert(list != NULL);

	Node *p = list->head.next;

	while (p != NULL)
	{
		printf("%d  ", p->data);

		p = p->next;
	}
	printf("\n");
}