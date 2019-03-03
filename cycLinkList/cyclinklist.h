#ifndef __CYCLINKLIST_H
#define __CYCLINKLIST_H
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <assert.h>

typedef int ElemType;

typedef struct Node
{
	ElemType data;

	struct Node *next;

}Node;

typedef struct CycLinkList
{
	Node *head;

	int count;

}CycLinkList, *pCyc;

void InitCycList(pCyc list);//初始化

void InsertCycList(pCyc list, ElemType val, int pos);//指定位置插入节点

void DeleteCycList(pCyc list, int pos);//删除指定位置

void ShowList(pCyc list);//打印链表及链表长度

void InquiryCycList(pCyc list,int pos);//查询指定位置

#endif