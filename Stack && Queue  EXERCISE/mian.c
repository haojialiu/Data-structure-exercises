#include "Stack.h"

int main()
{
	Stack stack;
	Stack stack1;
	InitStack(&stack);
	InitStack(&stack1);

	//第七题
	/*char buff[128] = "（3*[5 + 4] * {[3 + 5] * [40 - 2 * (5 - 3)]}）";
	IsMate(buff, sizeof(buff) / sizeof(buff[0]));*/

	//第八题
	/*char str[128] = "435*+23*-";
	printf("%d\n", Pulish(&stack,str));*/

	//12、利用两个栈模拟实现一个队的入队和出队运算。
	//queue.c文件

	//第十四题
	/*char buff[] = "a+b*(c-d)-e/f";
	Prefix(&stack, buff);*/

	return 0;
}