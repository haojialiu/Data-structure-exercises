#include"LinkStackQueue.h"



bool Queue::IsEmptyQue()
{
	if (_Linktail == _Linkhead)
	{
		return true;
	}
	return false;
}
Queue::Queue()
{
	_Linkhead = NULL;
	_Linktail = NULL;
}

void Queue::PushQue(ElemType val)
{
	if (_Linkhead == NULL)
	{
		Node *s = new Node;
		s->_data = val;
		s->_next = NULL;
		_Linkhead = s;
		_Linktail = s;
	}
	else
	{
		Node *s = new Node;
		s->_data = val;
		s->_next = NULL;
		_Linktail->_next = s;
		_Linktail = s;
	}
}

bool Queue::PopQue()
{
	if (IsEmptyQue())
	{
		return false;
	}

	Node *p = _Linkhead;
	_Linkhead = p->_next;
	delete p;
	return true;
}

Queue::Queue(const Queue & src)
{
	Node *src_head = src._Linkhead;
	if (src._Linkhead == NULL)
	{
		_Linkhead = NULL;
		_Linktail = NULL;
	}
	else
	{
		while (src_head != src._Linktail)
		{
			PushQue(src_head->_data);
			src_head = src_head->_next;
		}
		PushQue(src_head->_data);
	}
}


Queue &Queue::operator=(const Queue& src)
{
	if (this == &src)
	{
		return *this;
	}

	Node *src_head = src._Linkhead;
	if (src._Linkhead == NULL)
	{
		_Linkhead = NULL;
		_Linktail = NULL;
	}
	else
	{
		while (src_head != src._Linktail)
		{
			PushQue(src_head->_data);
			src_head = src_head->_next;
		}
		PushQue(src_head->_data);
	}

	return *this;
}



void Queue::show()
{
	Node *_Linkhead1 = _Linkhead;
	while (_Linkhead1 != _Linktail)
	{
		cout << _Linkhead1->_data << " ";
		_Linkhead1 = _Linkhead1->_next;
	}
	cout << _Linkhead1->_data << " ";
	cout << endl;
}