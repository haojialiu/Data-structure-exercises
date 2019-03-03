#include "SqList.h"


int main()
{
	//  结构体变量  elem  length  listsize
	SqList list;  
	InitSqList(&list);			//初始化
	InsertSqList(&list, 0, 10);	// 在顺序表的指定位置pos插入数据val
	InsertSqList(&list, 1, 11);
	InsertSqList(&list, 2, 12);
	InsertSqList(&list, 3, 13);
	InsertSqList(&list, 4, 14);
	InsertSqList(&list, 5, 15);
	InsertSqList(&list, 9, 15);
	Printf(&list);
	InsertHead(&list,9);		// 在顺序表的第一个位置插入数据
	Printf(&list);				//打印顺序表
	InsertTail(&list,16);		// 在顺序表的最后一个位置插入数据
	Printf(&list);
	DeleteSqList(&list,3);		// 删除指定位置的数据
	Printf(&list);
	DeleteHead(&list);			// 删除第一个数据元素
	DeleteTail(&list);			// 删除最后一个数据元素
	Printf(&list);
	FindVal(&list,12);			// 查找val所在的位置(最后一次出现的位置)
	FindVal(&list,10);
	
	
	DestroySqList(&list);		//删除顺序表
	return 0;
}