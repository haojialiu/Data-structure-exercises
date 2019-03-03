#include "Stack.h"


//7、假设一个表达式中可以包含三种括号：小括号，中括号，大括号，且这三种括号可以任意次序嵌套使用，如：“（3*[5 + 4] * {[3 + 5] * [40 - 2 * (5 - 3)]}）”, 编写判断表达式括号是否匹配的程序。表达式为字符串。
void IsMate(char buff[], int len)
{
	int small = 0;
	int medium = 0;
	int big = 0;

	for (int i = 0; i < len; i++)
	{
		if (buff[i] == '(')
			small++;
		if (buff[i] == ')')
			small--;
		if (buff[i] == '[')
			medium++;
		if (buff[i] == ']')
			medium--;
		if (buff[i] == '{')
			big++;
		if (buff[i] == '}')
			big--;
	}
	if (small == 0 && medium == 0 && big == 0)
	{
		printf("表达式括号是匹配的\n");
	}
	else
	{
		printf("表达式括号不是匹配的\n");
	}
}

//8、编程对一个逆波兰式（后缀表达式）进行求值，如“435*+23 * -”的结果是13，函数的参数为字符串（后缀表达式），假定字符串为正确的逆波兰式。
int Pulish(pStack stack, char *buff)
{
	assert(stack != NULL);
	char *p = buff;
	int right;
	int left;
	while (*p != '\0')
	{
		if (isdigit(*p))
		{
			stack->data[stack->top++] = *p;
		}
		else if (*p == '+')
		{
			right = stack->data[--stack->top] - 48;
			left = stack->data[--stack->top] - 48;
			stack->data[stack->top++] = left + right + 48;
		}
		else if (*p == '-')
		{
			right = stack->data[--stack->top] - 48;
			left = stack->data[--stack->top] - 48;
			stack->data[stack->top++] = left - right + 48;
		}
		else if (*p == '*')
		{
			right = stack->data[--stack->top] - 48;
			left = stack->data[--stack->top] - 48;
			stack->data[stack->top++] = left * right + 48;
		}
		else if (*p == '/')
		{
			right = stack->data[--stack->top] - 48;
			left = stack->data[--stack->top] - 48;
			stack->data[stack->top++] = left / right + 48;
		}
		p++;
	}
	int a = stack->data[--stack->top];
	a -= 48;
	return a;
}

//14、编程实现将中缀表达式转成前缀表达式，如a+b*(c-d)-e/f转成-+a*b-cd/ef。

//1、如果遇到操作数，直接将操作数放入到prefix 中
//2、如果遇到操作符，如果符号栈为空，直接放入符号栈中，如果符号栈不为空，则判断当前栈顶元素
//（1）如果当前栈顶元素为右括号‘）’，直接将操作符放入符号栈中
//（2）如果当前栈顶元素的优先级大于操作数的优先级，则将栈顶元素移除，再次和判断移除后栈的栈顶元素比较优先级大小，直到当前栈顶元素小于或等于操作数优先级，将操作符放入符号栈中
//3、如果遇到右括号，直接将右括号放入符号栈中
//4、如果遇到左括号，将右括号到左括号之间的全部符号移出到prefix 中（记得左括号不要入栈，并且在最后将右括号从栈中删除）
//5、重复1 - 4，直到最后一个字符被读入。
//6、判断当前栈是否为空，如果不为空，将栈中的元素依次移出到prefix 中
//7、翻转字符串
int Decide(char a)
{
	if (a == '-')
		return 1;
	if (a == '+')
		return 1;
	if (a == '/')
		return 2;
	if (a == '*')
		return 2;
}

void Prefix(pStack stack, char *buff)
{
	assert(stack != NULL);
	char str[127] = { 0 };
	int len = strlen(buff);
	int i = len - 1;
	int n = 0;
	for (; i >= 0; i--)
	{
		if (isalpha(buff[i]))
		{
			str[n++] = buff[i];
		}
		else
		{
			if (stack->top == 0)
			{
				stack->data[stack->top++] = buff[i];
			}
			else
			{
				if (buff[i] == ')')
				{
					stack->data[stack->top++] = buff[i];
				}
				else if (buff[i] == '(')
				{
					while (stack->data[stack->top - 1] != ')')
					{
						str[n++] = stack->data[--stack->top];
					}
					stack->top--;
				}
				else
				{
					while (1)
					{
						if (stack->top == 0 || stack->data[stack->top - 1] == ')')
						{
							stack->data[stack->top++] = buff[i];
							break;
						}
						if (Decide(buff[i]) < Decide(stack->data[stack->top - 1]))
						{
							str[n++] = stack->data[--stack->top];
						}
						else
						{
							stack->data[stack->top++] = buff[i];
							break;
						}

					}
				}
			}
		}
		if (i <= 0)
		{
			while (1)
			{
				str[n++] = stack->data[--stack->top];
				if (stack->top <= 0)
				{
					break;
				}
			}
		}
	}
	printf("%s\n", str);
}