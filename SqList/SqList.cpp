#include "SqList.h"

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

	if(list->length == list->listsize)
	{
		return true;
	}
	else
	{
		return false;
	}
}
//����
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
		printf("%dǰ���п�λ��\n",pos);

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

// ��˳�������һ��λ�ò�������
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

// ɾ��ָ��λ�õ�����
int DeleteSqList(SqList *list, int pos)
{
	assert(list != NULL);

	int i;

	if(IsEmpty(list))
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
			list->elem[i] = list->elem[i+1];
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

	if(IsEmpty(list))
	{
		printf("ɾ��ʧ�ܣ�˳���Ϊ��\n");

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

// ɾ�����һ������Ԫ��
int DeleteTail(SqList *list)
{
	assert(list != NULL);

	if(IsEmpty(list))
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

	if(IsEmpty(list))
	{
		printf("����ʧ�ܣ�˳���Ϊ��\n");

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
		printf("û�в鵽\n");
	}
	else
	{
		printf("%d��%d���λ��\n",val,seat);
	}
	 return 0;
}

//��ӡ˳���
void Printf(SqList *list)
{
	if(IsEmpty(list))
	{
		printf("˳���Ϊ��\n");
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