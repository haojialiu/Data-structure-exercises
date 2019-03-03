#include "SqList.h"
#include "LinkList.h"

int main()
{
	//  结构体变量  elem  length  listsize
	SqList list;
	SqList list2;
	SqList list3;
	SqList list4;
	InitSqList(&list);			//初始化
	InitSqList(&list2);
	InitSqList(&list3);
	InitSqList(&list4);
	InsertSqList(&list, 0, 9);	// 在顺序表的指定位置pos插入数据val
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

	//第九题
	/*Sort(&list, 16);
	Printf(&list);*/

	//第十题
	/*
	Compare(&list, &list2);*/

	//第十一题
	/*Reverse(&list);
	Printf(&list);*/

	//第十二题
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

	//第十三题
	/*DeleteIntersect(&list, &list2, &list3);
	Printf(&list);*/
	//第十四题
	/*CompareInsert(&list2, &list3);
	Printf(&list2);*/
	//第十五题

	//第十六题
	CompareDifferent(&list2, &list3, &list4);
	Printf(&list4);
	return 0;
}