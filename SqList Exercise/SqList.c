#include "SqList.h"
#include "LinkList.h"
/*
1、申请空间，并使list中elem指针指向这块空间
2、将list中length与listsize设置初始值

typedef struct
{
int *elem;   //  指向存储数据元素的空间的指针
int length;  //  当前存储数据的个数
int listsize;  //  当前分配的存储空间的大小
}SqList;
*/
//判断是否是空
static int IsEmpty(SqList *list)
{
	assert(list != NULL);

	if (list->length == 0)
	{
		return TRUE;
	}

	return FALSE;
}
//判断是否存满了
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
//扩容
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
//初始化
void InitSqList(SqList *list)
{
	assert(list != NULL);

	list->elem = (int *)malloc(sizeof(int)* LEN);
	list->length = 0;
	list->listsize = LEN;
}
//删除顺序表
void DestroySqList(SqList *list)
{
	assert(list != NULL);

	free(list->elem);
	list->length = list->listsize = 0;
}

// 在顺序表的指定位置pos插入数据val
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
		printf("%d前面有空位置\n", pos);

		return 0;
	}

	return 0;
}

// 在顺序表的第一个位置插入数据
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

// 在顺序表的最后一个位置插入数据


// 删除指定位置的数据
int DeleteSqList(SqList *list, int pos)
{
	assert(list != NULL);

	int i;

	if (IsEmpty(list))
	{
		printf("删除失败，顺序表为空\n");

		return 0;
	}
	else if (pos >= list->length)
	{
		printf("删除失败，这个位置为空\n");
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

// 删除第一个数据元素
int DeleteHead(SqList *list)
{
	assert(list != NULL);

	int i;

	if (IsEmpty(list))
	{
		printf("删除失败，顺序表为空\n");

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

// 删除最后一个数据元素
int DeleteTail(SqList *list)
{
	assert(list != NULL);

	if (IsEmpty(list))
	{
		printf("删除失败，顺序表为空\n");

		return 0;
	}
	list->elem[list->length - 1] = NULL;

	list->length--;

	return 0;
}

// 查找val所在的位置(最后一次出现的位置)
int FindVal(SqList *list, int val)
{
	assert(list != NULL);

	int seat = 0;

	int count = 0;

	if (IsEmpty(list))
	{
		printf("查找失败，顺序表为空\n");

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
		printf("没有查到\n");
	}
	else
	{
		printf("%d在%d这个位置\n", val, seat);
	}
	return 0;
}

//打印顺序表
void Printf(SqList *list)
{
	if (IsEmpty(list))
	{
		printf("顺序表为空\n");
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
//9、设顺序表va中的数据元素递增有序。试写一算法，将x插入到顺序表的适当位置上，以保持该表的有序性。
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
//10、设a 和b 均为顺序表， 和 分别为 和 中除去最大共同前缀后的子表。若 空表，则 ；若 =空表，而 空表，或者两者均不为空表，且 的首元小于 的首元，则 ；否则 。试写一个比较 ， 大小的算法。
void Compare(SqList *list, SqList *list2)
{
	assert(list != NULL);
	assert(list2 != NULL);
	int i = 0;
	if (IsEmpty(list) && IsEmpty(list2))
	{
		printf("两个顺序表相等\n");
	}
	else if (IsEmpty(list) && !IsEmpty(list2))
	{
		printf("顺序表1小于顺序表2\n");
	}
	else if (!IsEmpty(list) && IsEmpty(list2))
	{
		printf("顺序表1大于顺序表2\n");
	}
	else
	{
		for (; i < list->length && i < list2->length;i++)
		{
			if (list->elem[i]>list2->elem[i])
			{
				printf("顺序表1大于顺序表2\n");
				break;
			}
			else if (list->elem[i] < list2->elem[i])
			{
				printf("顺序表1小于顺序表2\n");
				break;
			}
			else if (i == list->length-1 && i < list2->length-1)
			{
				printf("顺序表1小于顺序表2\n");
				break;
			}
			else if (i == list2->length-1 && i < list->length-1)
			{
				printf("顺序表1大于顺序表2\n");
				break;
			}
			else if (i == list->length-1 && i == list2->length-1)
			{
				printf("两个顺序表相等\n");
			}
		}
	}
}

//11、试写一算法，实现顺序表的就地逆置，即利用原表的存储空间将线性表 逆置为 。
void Reverse(SqList *list)
{
	assert(list != NULL);
	if (IsEmpty(list))
	{
		printf("顺序表为空\n");
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

//12、假设有两个按元素值递增有序排列的线性表A和B，均以单链表作存储结构，请编写算法将A表和B表归并成一个按元素值递减有序（即非递增有序，允许表中含有值相同的元素）排列的线性表C，并要求利用原表（即A表和B表）的结点空间构造C表。
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
//13、已知A，B和C为三个递增有序的线性表，现要求对A表作如下操作：删去那些既在B表中出现又在C表中出现的元素。试对顺序表编写实现上述操作的算法，并分析你的算法的时间复杂度（注意：题中没有特别指明同一表中的元素值各不相同）。
void DeleteIntersect(SqList *lista, SqList *listb, SqList *listc)//时间复杂度为o(a+b+c),a为顺序表a数据个数
{
	assert(lista != NULL);
	assert(listb != NULL);
	assert(listc != NULL);

	int aa = 0;
	int bb = 0;
	int cc = 0;
	if (IsEmpty(lista))
	{
		printf("顺序表a为空\n");
	}
	if (IsEmpty(listb))
	{
		printf("顺序表b为空\n");
	}
	if (IsEmpty(listc))
	{
		printf("顺序表c为空\n");
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
//14、利用静态链表实现（A-B）U (B-A),将新的链表保存为A链表。即先建立静态链表A，然后遍历B中 的所有元素，如果B中的元素存在A中，则将A中的该元素删除，否则将该元素添加到A中。
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

//15、将静态链表的插入函数改为尾插法
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

//16、两个顺序表递增有序，执行 C=AUB,算法时间复杂度要求为O(n+m)(A,B这两个顺序表只允许遍历一遍)
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
		printf("顺序表a为空\n");
	}
	if (IsEmpty(listb))
	{
		printf("顺序表b为空\n");
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