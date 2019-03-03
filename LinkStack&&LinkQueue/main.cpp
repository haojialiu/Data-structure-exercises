#include"LinkStackQueue.h"



int main()
{
	/*Stack Stack1;
	Stack1.Push(11);
	Stack1.Push(12);
	Stack1.Push(13);
	Stack1.Push(14);
	Stack1.show();
	Stack Stack2(Stack1);
	Stack2.show();
	Stack2.Pop();
	Stack2.show();
	Stack Stack3;
	Stack3 = Stack1;
	Stack3.show();*/


	Queue Queue1;
	Queue1.PushQue(11);
	Queue1.PushQue(12);
	Queue1.PushQue(13);
	Queue1.PushQue(14);
	Queue1.show();
	Queue Queue2(Queue1);
	Queue2.show();
	Queue2.PopQue();
	Queue2.show();
	Queue Queue3;
	Queue3 = Queue1;
	Queue3.show();
}