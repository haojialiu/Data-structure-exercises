#include "SqList.h"
#include "LinkList.h"
/*
1������ռ䣬��ʹlist��elemָ��ָ�����ռ�
2����list��length��listsize���ó�ʼֵ

typedef struct
{
int *elem;   //  ָ��洢����Ԫ�صĿռ��ָ��
int length;  //  ��ǰ�洢���ݵĸ���
int listsize;  //  ��ǰ����Ĵ洢�ռ�Ĵ�С
}SqList;
*/
//�ж��Ƿ��ǿ�
static int IsEmpty(SqList *list)
{
	assert(list != NULL);

	if (list->length == 0)
	{
		return TRUE;
	}

	return FALSE;
}
//�ж��Ƿ������
static int IsFull(SqList *list)
{
	assert(list != NULL);

	if (list->length == list->listsize)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
//����
static int ExpandSpace(SqList *list)
{
	assert(list != NULL);
	int i;

	int *p = (int *)malloc(sizeof(int)* list->listsize * 2);

	for (i = 0; i<list->listsize; i++)
	{
		p[i] = list->elem[i];
	}
	list->elem = (int *)malloc(list->listsize * sizeof(int)* 2);

	list->listsize *= 2;

	for (int n = 0; n<i; n++)
	{
		list->elem[n] = p[n];
	}
	return 0;
}
//��ʼ��
void InitSqList(SqList *list)
{
	assert(list != NULL);

	list->elem = (int *)malloc(sizeof(int)* LEN);
	list->length = 0;
	list->listsize = LEN;
}
//ɾ��˳���
void DestroySqList(SqList *list)
{
	assert(list != NULL);

	free(list->elem);
	list->length = list->listsize = 0;
}

// ��˳����ָ��λ��pos��������val
int InsertSqList(SqList *list, int pos, int val)
{
	assert(list != NULL);

	if (IsFull(list))
	{
		ExpandSpace(list);
	}
	if (pos <= list->length)
	{
		for (int i = pos; i < list->length + 1; i++)
		{
			int tmp = list->elem[i];

			list->elem[i] = val;

			val = tmp;
		}
		list->length++;
	}
	else if (pos == list->length + 1)
	{
		list->elem[pos] = val;

		list->length++;
	}
	else
	{
		printf("%dǰ���п�λ��\n", pos);

		return 0;
	}

	return 0;
}

// ��˳���ĵ�һ��λ�ò�������
int InsertHead(SqList *list, int val)
{
	assert(list != NULL);

	if (IsFull(list))
	{
		ExpandSpace(list);
	}

	if (IsEmpty(list))
	{
		list->elem[0] = val;
	}
	else
	{
		for (int i = 0; i<list->length + 1; i++)
		{
			int tmp = list->elem[i];

			list->elem[i] = val;

			val = tmp;
		}
	}
	list->length++;

	return 0;
}

// ��˳�������һ��λ�ò�������


// ɾ��ָ��λ�õ�����
int DeleteSqList(SqList *list, int pos)
{
	assert(list != NULL);

	int i;

	if (IsEmpty(list))
	{
		printf("ɾ��ʧ�ܣ�˳���Ϊ��\n");

		return 0;
	}
	else if (pos >= list->length)
	{
		printf("ɾ��ʧ�ܣ����λ��Ϊ��\n");
		return 0;
	}
	else
	{
		for (i = pos; i < list->length; i++)
		{
			list->elem[i] = list->elem[i + 1];
		}
		list->elem[i] = NULL;

		list->length--;
	}
	return 0;
}

// ɾ����һ������Ԫ��
int DeleteHead(SqList *list)
{
	assert(list != NULL);

	int i;

	if (IsEmpty(list))
	{
		printf("ɾ��ʧ�ܣ�˳���Ϊ��\n");

		return 0;
	}
	else
	{
		for (i = 0; i<list->length; i++)
		{
			list->elem[i] = list->elem[i + 1];
		}
		list->elem[i] = NULL;

		list->length--;
	}
	return 0;
}

// ɾ�����һ������Ԫ��
int DeleteTail(SqList *list)
{
	assert(list != NULL);

	if (IsEmpty(list))
	{
		printf("ɾ��ʧ�ܣ�˳���Ϊ��\n");

		return 0;
	}
	list->elem[list->length - 1] = NULL;

	list->length--;

	return 0;
}

// ����val���ڵ�λ��(���һ�γ��ֵ�λ��)
int FindVal(SqList *list, int val)
{
	assert(list != NULL);

	int seat = 0;

	int count = 0;

	if (IsEmpty(list))
	{
		printf("����ʧ�ܣ�˳���Ϊ��\n");

		return 0;
	}
	for (int i = 0; i < list->length - 1; i++)
	{
		if (list->elem[i] == val)
		{
			seat = i;

			count++;
		}
	}
	if (count == 0)
	{
		printf("û�в鵽\n");
	}
	else
	{
		printf("%d��%d���λ��\n", val, seat);
	}
	return 0;
}

//��ӡ˳���
void Printf(SqList *list)
{
	if (IsEmpty(list))
	{
		printf("˳���Ϊ��\n");
	}
	else
	{
		for (int i = 0; i < list->length; i++)
		{
			printf("%d ", list->elem[i]);
		}
		printf("\n");
	}
}



//=====================================================================================================================
//9����˳���va�е�����Ԫ�ص���������дһ�㷨����x���뵽˳�����ʵ�λ���ϣ��Ա��ָñ�������ԡ�
void Sort(SqList *list, int val)
{
	assert(list != NULL);

	if (IsFull(list))
	{
		ExpandSpace(list);
	}
	for (int i = 0; i < list->length - 1; i++)
	{
		if (list->elem[i] > val)
		{
			InsertSqList(list, i, val);
			break;
		}
		else if (list->elem[i] == val)
		{
			InsertSqList(list, i, val);
			break;
		}
		if (i == list->length - 1)
		{
			InsertSqList(list, i, val);
			break;
		}
	}
}
//10����a ��b ��Ϊ˳��� �� �ֱ�Ϊ �� �г�ȥ���ͬǰ׺����ӱ��� �ձ��� ���� =�ձ��� �ձ��������߾���Ϊ�ձ��� ����ԪС�� ����Ԫ���� ������ ����дһ���Ƚ� �� ��С���㷨��
void Compare(SqList *list, SqList *list2)
{
	assert(list != NULL);
	assert(list2 != NULL);
	int i = 0;
	if (IsEmpty(list) && IsEmpty(list2))
	{
		printf("����˳������\n");
	}
	else if (IsEmpty(list) && !IsEmpty(list2))
	{
		printf("˳���1С��˳���2\n");
	}
	else if (!IsEmpty(list) && IsEmpty(list2))
	{
		printf("˳���1����˳���2\n");
	}
	else
	{
		for (; i < list->length && i < list2->length;i++)
		{
			if (list->elem[i]>list2->elem[i])
			{
				printf("˳���1����˳���2\n");
				break;
			}
			else if (list->elem[i] < list2->elem[i])
			{
				printf("˳���1С��˳���2\n");
				break;
			}
			else if (i == list->length-1 && i < list2->length-1)
			{
				printf("˳���1С��˳���2\n");
				break;
			}
			else if (i == list2->length-1 && i < list->length-1)
			{
				printf("˳���1����˳���2\n");
				break;
			}
			else if (i == list->length-1 && i == list2->length-1)
			{
				printf("����˳������\n");
			}
		}
	}
}

//11����дһ�㷨��ʵ��˳���ľ͵����ã�������ԭ��Ĵ洢�ռ佫���Ա� ����Ϊ ��
void Reverse(SqList *list)
{
	assert(list != NULL);
	if (IsEmpty(list))
	{
		printf("˳���Ϊ��\n");
	}
	int tmp = 0;
	int n = 0;
	int m = list->length - 1;
	while (n<m)
	{
		tmp = list->elem[n];
		list->elem[n] = list->elem[m];
		list->elem[m] = tmp;
		n++;
		m--;
	}
}

//12��������������Ԫ��ֵ�����������е����Ա�A��B�����Ե��������洢�ṹ�����д�㷨��A���B��鲢��һ����Ԫ��ֵ�ݼ����򣨼��ǵ�������������к���ֵ��ͬ��Ԫ�أ����е����Ա�C����Ҫ������ԭ����A���B���Ľ��ռ乹��C��
void Isintersect(pList listA, pList listB, pList listC)
{
	assert(listA != NULL);
	assert(listB != NULL);
	assert(listC != NULL);
	Node *a = listA->head.next;
	Node *b = listB->head.next;
	Node *c = &listC->head;
	Node *ap = listA->head.next;
	Node *bp = listB->head.next;
	while (b != NULL&&a != NULL)
	{
		ap = a;
		bp = b;
		if (b->data > a->data)
		{
			ap = ap->next;
			a->next = c->next;
			c->next = a;
			a = ap;
		}
		else if (b->data < a->data)
		{
			bp = bp->next;
			b->next = c->next;
			c->next = b;
			b = bp;
		}
		else
		{
			if (a->next != NULL)
			{
				ap = ap->next;
				a->next = c->next;
				c->next = a;
				a = ap;
			}
			else if (b->next != NULL)
			{
				bp = bp->next;
				b->next = c->next;
				c->next = b;
				b = bp;
			}
			else
			{
				ap = ap->next;
				a->next = c->next;
				c->next = a;
				a = ap;

				bp = bp->next;
				b->next = c->next;
				c->next = b;
				b = bp;
			}
		}
		if (b != NULL&&a == NULL)
		{
			while (b != NULL)
			{
				bp = bp->next;
				b->next = c->next;
				c->next = b;
				b = bp;
			}
		}
		else if (b == NULL&&a != NULL)
		{
			while (a != NULL)
			{
				ap = ap->next;
				a->next = c->next;
				c->next = a;
				a = ap;
			}
		}
	}
}
//13����֪A��B��CΪ����������������Ա���Ҫ���A�������²�����ɾȥ��Щ����B���г�������C���г��ֵ�Ԫ�ء��Զ�˳����дʵ�������������㷨������������㷨��ʱ�临�Ӷȣ�ע�⣺����û���ر�ָ��ͬһ���е�Ԫ��ֵ������ͬ����
void DeleteIntersect(SqList *lista, SqList *listb, SqList *listc)//ʱ�临�Ӷ�Ϊo(a+b+c),aΪ˳���a���ݸ���
{
	assert(lista != NULL);
	assert(listb != NULL);
	assert(listc != NULL);

	int aa = 0;
	int bb = 0;
	int cc = 0;
	if (IsEmpty(lista))
	{
		printf("˳���aΪ��\n");
	}
	if (IsEmpty(listb))
	{
		printf("˳���bΪ��\n");
	}
	if (IsEmpty(listc))
	{
		printf("˳���cΪ��\n");
	}
	while (cc<listc->length && bb<listb->length)
	{
		if (listb->elem[bb] > listc->elem[cc])
		{
			cc++;
		}
		else if (listb->elem[bb] < listc->elem[cc])
		{
			bb++;
		}
		else
		{
			while (aa < lista->length)
			{
				if (lista->elem[aa] < listb->elem[bb])
				{
					aa++;
				}
				else if (lista->elem[aa] > listb->elem[bb])
				{
					break;
				}
				else
				{
					DeleteSqList(lista, aa);
					break;
				}
			}
			bb++;
			cc++;
		}
	}
}
//14�����þ�̬����ʵ�֣�A-B��U (B-A),���µ�������ΪA�������Ƚ�����̬����A��Ȼ�����B�� ������Ԫ�أ����B�е�Ԫ�ش���A�У���A�еĸ�Ԫ��ɾ�������򽫸�Ԫ����ӵ�A�С�
void CompareInsert(SqList *listN, SqList *listM)
{
	assert(listN != NULL);
	assert(listM != NULL);

	int n = 0;
	int m = 0;
	int count = 0;
	int buff[127] = {0};
	int i = 0;
	for (; m < listM->length;m++)
	{
		n = 0;
		count = 0;
		for (; n < listN->length;n++)
		{
			if (listN->elem[n] == listM->elem[m])
			{
				DeleteSqList(listN, n);
				count++;
			}
		}
		if (count == 0)
		{
			buff[i++] = listM->elem[m];
		}
	}
	for (int ii = 0; ii < i;ii++)
	{
		InsertHead(listN, buff[ii]);
	}
}

//15������̬����Ĳ��뺯����Ϊβ�巨
int InsertTail(SqList *list, int val)
{
	assert(list != NULL);

	if (IsFull(list))
	{
		ExpandSpace(list);
	}

	if (IsEmpty(list))
	{
		list->elem[0] = val;

		list->length++;

		return 0;
	}
	list->elem[list->length] = val;

	list->length++;

	return 0;
}

//16������˳����������ִ�� C=AUB,�㷨ʱ�临�Ӷ�Ҫ��ΪO(n+m)(A,B������˳���ֻ�������һ��)
void CompareDifferent(SqList *lista, SqList *listb, SqList *listc)
{
	assert(lista != NULL);
	assert(listb != NULL);
	assert(listc != NULL);

	int aa = 0;
	int bb = 0;
	int cc = 0;
	if (IsEmpty(lista))
	{
		printf("˳���aΪ��\n");
	}
	if (IsEmpty(listb))
	{
		printf("˳���bΪ��\n");
	}

	while (aa < lista->length && bb < listb->length)
	{
		if (lista->elem[aa] > listb->elem[bb])
		{
			InsertTail(listc, listb->elem[bb]);
			bb++;
		}
		else if (lista->elem[aa] < listb->elem[bb])
		{
			InsertTail(listc, lista->elem[aa]);
			aa++;
		}
		else
		{
			InsertTail(listc, listb->elem[bb]);
			aa++;
			bb++;
		}
		if (aa == lista->length && bb != listb->length)
		{
			while (bb < listb->length)
			{
				InsertTail(listc, listb->elem[bb]);
				bb++;
			}
		}
		if (aa != lista->length && bb == listb->length)
		{
			while (aa < lista->length)
			{
				InsertTail(listc, lista->elem[aa]);
				aa++;
			}
		}
	}
}