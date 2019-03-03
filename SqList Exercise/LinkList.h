#ifndef __LINKLIST_H
#define __LINKLIST_H

#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <malloc.h>

typedef struct Node
{
	int data;

	struct Node *next;

}Node;

typedef struct LinkList
{
	struct Node head;

	int count;

}LinkList, *pList;


void InitLinkList(pList list);

void InsertElemToList(pList list, int val, int pos);

void DeleteElemOfList(pList list, Node *p);

void ShowElemOfList(pList list);

void Find(pList list, int pos);

int Intersect(pList list, pList list2);

void Make(pList list, pList list2);

void IsBring(pList list);

void MakeBring(pList list);

void Revelinklist(pList list);

void FrontInsert(pList list, int val, Node *p);

void Isintersect(pList listA, pList listB, pList listC);


#endif