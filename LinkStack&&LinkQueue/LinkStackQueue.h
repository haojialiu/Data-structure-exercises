#ifndef __STACK_H
#define __STACK_H

#include<iostream>
#include<string.h>
#include<assert.h>
#include<ctype.h>

using namespace std;
typedef int  ElemType;


class Stack
{
	class Node
	{
	public:
		ElemType _data;
		Node *_next;
		Node()
		{
			_next = NULL;
		}
		friend class LinkStack;

	};
private: 
	Node * _LinkNode;
public:

	Stack();
	bool IsEmpty();
	void Push(ElemType val);
	void Pop();
	Stack(const Stack & src);
	Stack &operator=(const Stack& src);
	void show();
};




class Queue
{
	class Node
	{
	public:
		ElemType _data;
		Node *_next;
		Node()
		{
			_next = NULL;
		}
		friend class LinkStack;

	};
private:
	Node * _Linkhead;
	Node * _Linktail;
public:

	Queue();
	bool IsEmptyQue();
	void PushQue(ElemType val);
	bool PopQue();
	Queue(const Queue & src);
	Queue &operator=(const Queue& src);
	void show();
};
#endif