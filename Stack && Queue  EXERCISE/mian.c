#include "Stack.h"

int main()
{
	Stack stack;
	Stack stack1;
	InitStack(&stack);
	InitStack(&stack1);

	//������
	/*char buff[128] = "��3*[5 + 4] * {[3 + 5] * [40 - 2 * (5 - 3)]}��";
	IsMate(buff, sizeof(buff) / sizeof(buff[0]));*/

	//�ڰ���
	/*char str[128] = "435*+23*-";
	printf("%d\n", Pulish(&stack,str));*/

	//12����������ջģ��ʵ��һ���ӵ���Ӻͳ������㡣
	//queue.c�ļ�

	//��ʮ����
	/*char buff[] = "a+b*(c-d)-e/f";
	Prefix(&stack, buff);*/

	return 0;
}