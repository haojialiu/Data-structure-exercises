#include "SqList.h"
#include "LinkList.h"

int main()
{
	//  �ṹ�����  elem  length  listsize
	SqList list;
	SqList list2;
	SqList list3;
	SqList list4;
	InitSqList(&list);			//��ʼ��
	InitSqList(&list2);
	InitSqList(&list3);
	InitSqList(&list4);
	InsertSqList(&list, 0, 9);	// ��˳����ָ��λ��pos��������val
	InsertSqList(&list, 1, 11);
	InsertSqList(&list, 2, 13);
	InsertSqList(&list, 3, 15);
	InsertSqList(&list, 4, 17);
	InsertSqList(&list, 5, 19);
	InsertSqList(&list, 6, 21);
	InsertSqList(&list2, 0, 9);
	InsertSqList(&list2, 1, 11);
	InsertSqList(&list2, 2, 13);
	InsertSqList(&list2, 3, 15);
	InsertSqList(&list3, 0, 8);
	InsertSqList(&list3, 1, 11);
	InsertSqList(&list3, 2, 13);
	InsertSqList(&list3, 3, 20);
	Printf(&list);
	Printf(&list2);
	Printf(&list3);

	//�ھ���
	/*Sort(&list, 16);
	Printf(&list);*/

	//��ʮ��
	/*
	Compare(&list, &list2);*/

	//��ʮһ��
	/*Reverse(&list);
	Printf(&list);*/

	//��ʮ����
	/*LinkList listA;
	LinkList listB;
	LinkList listC;
	InitLinkList(&listA);
	InitLinkList(&listB);
	InitLinkList(&listC);
	for (int i = 0; i < 5; ++i)
	{
		InsertElemToList(&listA, i+1, i);
	}
	for (int i = 0; i < 5; ++i)
	{
		InsertElemToList(&listB, i + 3, i);
	}
	ShowElemOfList(&listA);
	ShowElemOfList(&listB);
	Isintersect(&listA, &listB, &listC);
	ShowElemOfList(&listC);*/

	//��ʮ����
	/*DeleteIntersect(&list, &list2, &list3);
	Printf(&list);*/
	//��ʮ����
	/*CompareInsert(&list2, &list3);
	Printf(&list2);*/
	//��ʮ����

	//��ʮ����
	CompareDifferent(&list2, &list3, &list4);
	Printf(&list4);
	return 0;
}