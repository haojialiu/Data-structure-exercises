#include "SqList.h"

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

	if(list->length == list->listsize)
	{
		return true;
	}
	else
	{
		return false;
	}
}
//扩容
static int ExpandSpace(SqList *list)
{
	assert(list != NULL);
	int i;

	int *p = (int *)malloc(sizeof(int)* list->listsize *2);

	for (i=0; i<list->listsize; i++)
	{
		p[i] = list->elem[i];
	}
	list->elem = (int *)malloc(list->listsize * sizeof(int)* 2);

	list->listsize *= 2;

	for (int n=0; n<i; n++)
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
	if (pos<=list->length)
	{
		for (int i = pos; i < list->length + 1; i++)
		{
			int tmp = list->elem[i];

			list->elem[i] = val;

			val = tmp;
		}
		list->length++;
	}
	else if (pos == list->length+1)
	{
		list->elem[pos] = val;

		list->length++;
	}
	else
	{
		printf("%d前面有空位置\n",pos);

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

	if(IsEmpty(list))
	{
		list->elem[0] = val;
	}
	else
	{
		for (int i=0; i<list->length+1; i++)
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

// 删除指定位置的数据
int DeleteSqList(SqList *list, int pos)
{
	assert(list != NULL);

	int i;

	if(IsEmpty(list))
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
			list->elem[i] = list->elem[i+1];
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

	if(IsEmpty(list))
	{
		printf("删除失败，顺序表为空\n");

		return 0;
	}
	else
	{
		for (i=0; i<list->length; i++)
		{
			list->elem[i] = list->elem[i+1];
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

	if(IsEmpty(list))
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

	if(IsEmpty(list))
	{
		printf("查找失败，顺序表为空\n");

		return 0;
	}
	for (int i=0; i < list->length-1; i++)
	{
		if (list->elem[i] == val)
		{
			seat = i;

			count++;
		}
	}
	if(count == 0)
	{
		printf("没有查到\n");
	}
	else
	{
		printf("%d在%d这个位置\n",val,seat);
	}
	 return 0;
}

//打印顺序表
void Printf(SqList *list)
{
	if(IsEmpty(list))
	{
		printf("顺序表为空\n");
	}
	else
	{
		for (int i = 0; i < list->length; i++)
		{
			printf("%d\n",list->elem[i]);
		}
		printf("\n");
	}
}