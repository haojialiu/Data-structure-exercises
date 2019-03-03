#include"LinkList.h"
//3����֪��������ĵ����� A,B ��C �ֱ�洢��һ�����ϣ�����㷨ʵ�� A��=A�ȣ�B��C�� ����ʹ���ṹ A �Ա��ֵ�����Ҫ���㷨��ʱ�临�Ӷ�Ϊ O(|A|+|B|+|C|)������,|A|Ϊ����A ��Ԫ�ظ�����

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
					FrontInsert(listA, b->data, a);//��aǰ�����һ������dataΪb->data
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
//4������ͷ�ڵ�ĵ�����ĳɲ���ͷ�ڵ�ĵ�������ʵ�ֲ��룬ɾ�������ң��������ȣ���ӡ�Ⱥ�����
//��NoheadLinkList.c�ļ�
//////////////////////////////////////////////////////////////////////////////
//5����дһ�㷨���Ե�����ʵ�־͵����ã���ע��ʱ�临�Ӷ�����ܴﵽO(n)��
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





//�������������������
//=================================================================================================================================
//��һ�� ��������������Ƿ��л���
//������ ����������(head)������л��Ļ��뷵�ش�ͷ�����뻷�ĵ�һ���ڵ㡣
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
			printf("�����ڻ�\n");
			return;
		}
		a = a->next;
		if (a->next == NULL)
		{
			printf("�����ڻ�\n");
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
	printf("��%d�����Ϊ�뻷��\n", i);
}

//���컷������
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
//����� ��������������(head1, head2)��������������Ƿ��н��㣬����з��ص�һ�����㡣
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

//�����ཻ������������
void Make(pList list, pList list2)
{
	assert(list != NULL && list2 != NULL);
	Node *p = list->head.next;
	list2->head.next = p->next;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//���ġ�ֻ������������ĳ�����p(�������һ����㣬��p->next != NULL)ָ�룬ɾ���ý�㡣
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
//���塢ֻ������������ĳ�����p(�ǿս��)����pǰ�����һ����㡣
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
//����������������ͷ��㣬ɾ�������е�����k����㡣
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



