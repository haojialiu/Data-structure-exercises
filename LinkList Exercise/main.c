#include "LinkList.h"

int main()
{
	LinkList list;
	LinkList list2;
	InitLinkList(&list);
	InitLinkList(&list2);
	for (int i = 0; i < 5; ++i)
	{
		InsertElemToList(&list, i * 10, i);
	}
	for (int i = 0; i < 5; ++i)
	{
		InsertElemToList(&list2, i * 2, i);
	}
	ShowElemOfList(&list);
//===============================================================================================================
	//3、已知递增有序的单链表 A,B 和C 分别存储了一个集合，设计算法实现 A：=A∪（B∩C） ，并使求解结构 A 仍保持递增。要求算法的时间复杂度为 O(|A|+|B|+|C|)。其中,|A|为集合A 的元素个数。
	/*LinkList listA;
	LinkList listB;
	LinkList listC;
	InitLinkList(&listA);
	InitLinkList(&listB);
	InitLinkList(&listC);
	for (int i = 0; i < 10; ++i)
	{
		InsertElemToList(&listA, i, i);
	}
	for (int i = 0; i < 5; ++i)
	{
		InsertElemToList(&listB, i+3, i);
	}
	for (int i = 0; i < 5; ++i)
	{
		InsertElemToList(&listC, i+6, i);
	}
	ShowElemOfList(&listA);
	ShowElemOfList(&listB);
	ShowElemOfList(&listC);
	Isintersect(&listA, &listB, &listC);
	ShowElemOfList(&listA);*/
	//4、将带头节点的单链表改成不带头节点的单链表，并实现插入，删除，查找，求链表长度，打印等函数。
	//见NoheadLinkList.c文件
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	//	5、试写一算法，对单链表实现就地逆置，请注意时间复杂度最好能达到O(n)。
//	Revelinklist(&list);
//	ShowElemOfList(&list);
//====================================================================================================================
	//单链表链表相关面试题
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//题一、 给定单链表，检测是否有环。
//	IsBring(&list);
	//MakeBring(&list);    //制造一个带环单链表
//	IsBring(&list);
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//题二、 给定两个单链表(head1, head2)，检测两个链表是否有交点，如果有返回第一个交点。
//	int a = Intersect(&list, &list2);
//	if (a >= 0)
//	{
//		printf("相交。交点的值为%d\n", Intersect(&list, &list2));
//	}
//	else
//	{
//		printf("不相交\n");
//	}
	//--------------------------------------

	//制造相交的单链表，证明反例
//	Make(&list, &list2);
//	int b = Intersect(&list, &list2);
//	if (b >= 0)
//	{
//		printf("相交。交点为第%d位置\n", Intersect(&list, &list2));
//	}
//	else
//	{
//		printf("不相交\n");
//	}
	///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//题四、只给定单链表中某个结点p(并非最后一个结点，即p->next != NULL)指针，删除该结点。
//	Node *pp = list.head.next;
//	DeleteElemOfList(&list, pp);
//	ShowElemOfList(&list);
	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//题五、只给定单链表中某个结点p(非空结点)，在p前面插入一个结点。
//	Node *pp = list.head.next;
//	FrontInsert(&list, 1, pp);
//	ShowElemOfList(&list);
	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//题六、给定单链表头结点，删除链表中倒数第k个结点。
//	Find(&list, 2);
//	ShowElemOfList(&list);

}