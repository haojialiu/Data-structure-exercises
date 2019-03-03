#include"LinkStackQueue.h"


bool Stack::IsEmpty()
{
	if (_LinkNode == NULL)
	{
		return true;
	}
	return false;
}

Stack::Stack()
{
	_LinkNode = NULL;
}


void Stack::Push(ElemType val)
{
	Node *s = new Node;
	s->_data = val;
	s->_next = _LinkNode;
	_LinkNode = s;
}
void Stack::Pop()
{
	Node *p = _LinkNode;
	_LinkNode = p->_next;
	delete p;
}
Stack::Stack(const Stack & src)
{
	Node *src_Node = src._LinkNode;
	if (src._LinkNode == NULL)
	{
		_LinkNode = NULL;
	}
	else
	{
		Node *_LinkNode1 = new Node;
		_LinkNode = _LinkNode1;
		_LinkNode->_data = src_Node->_data;
		while (src_Node->_next != NULL)
		{
			src_Node = src_Node->_next;
			_LinkNode1->_next = new Node;
			_LinkNode1->_next->_data = src_Node->_data;
			_LinkNode1 = _LinkNode1->_next;
			
		}
	}

}

Stack &Stack::operator=(const Stack& src)
{
	if (this == &src)
	{
		return *this;
	}

	if (NULL != _LinkNode)
		delete _LinkNode;

	Node *src_Node = src._LinkNode;
	if (src._LinkNode == NULL)
	{
		_LinkNode = NULL;
	}
	else
	{
		Node *_LinkNode1 = new Node;
		_LinkNode = _LinkNode1;
		_LinkNode->_data = src_Node->_data;
		while (src_Node->_next != NULL)
		{
			src_Node = src_Node->_next;
			_LinkNode1->_next = new Node;
			_LinkNode1->_next->_data = src_Node->_data;
			_LinkNode1 = _LinkNode1->_next;

		}
	}
	return *this;
}

void Stack::show()
{
	Node *_LinkNode1 = _LinkNode;
	while (_LinkNode1 != NULL)
	{
		cout << _LinkNode1->_data << " ";
		_LinkNode1 = _LinkNode1->_next;
	}
	cout << endl;

}