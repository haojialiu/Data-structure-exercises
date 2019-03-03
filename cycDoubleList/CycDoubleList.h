#ifndef __CYCDOULIST_H
#define __CYCDOULIST_H

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <malloc.h>

typedef int ElemType;

typedef struct Node
{
	struct Node *prev;

	ElemType data;

	struct Node *next;

}Node;

typedef struct CycDouList
{
	Node *head;
	int count;
}CycDouList, *pCycList;

void InitCycDouList(pCycList list);

void InsertCycDouList(pCycList list, ElemType value, int pos);

void DestroyCycDouList(pCycList list,int pos);

void ShowDouList(pCycList list);

void ReverseShow(pCycList list);
#endif