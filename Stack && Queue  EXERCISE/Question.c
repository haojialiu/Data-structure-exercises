#include "Stack.h"


//7������һ�����ʽ�п��԰����������ţ�С���ţ������ţ������ţ������������ſ����������Ƕ��ʹ�ã��磺����3*[5 + 4] * {[3 + 5] * [40 - 2 * (5 - 3)]}����, ��д�жϱ��ʽ�����Ƿ�ƥ��ĳ��򡣱��ʽΪ�ַ�����
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
		printf("���ʽ������ƥ���\n");
	}
	else
	{
		printf("���ʽ���Ų���ƥ���\n");
	}
}

//8����̶�һ���沨��ʽ����׺���ʽ��������ֵ���硰435*+23 * -���Ľ����13�������Ĳ���Ϊ�ַ�������׺���ʽ�����ٶ��ַ���Ϊ��ȷ���沨��ʽ��
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

//14�����ʵ�ֽ���׺���ʽת��ǰ׺���ʽ����a+b*(c-d)-e/fת��-+a*b-cd/ef��

//1�����������������ֱ�ӽ����������뵽prefix ��
//2������������������������ջΪ�գ�ֱ�ӷ������ջ�У��������ջ��Ϊ�գ����жϵ�ǰջ��Ԫ��
//��1�������ǰջ��Ԫ��Ϊ�����š�������ֱ�ӽ��������������ջ��
//��2�������ǰջ��Ԫ�ص����ȼ����ڲ����������ȼ�����ջ��Ԫ���Ƴ����ٴκ��ж��Ƴ���ջ��ջ��Ԫ�رȽ����ȼ���С��ֱ����ǰջ��Ԫ��С�ڻ���ڲ��������ȼ������������������ջ��
//3��������������ţ�ֱ�ӽ������ŷ������ջ��
//4��������������ţ��������ŵ�������֮���ȫ�������Ƴ���prefix �У��ǵ������Ų�Ҫ��ջ����������������Ŵ�ջ��ɾ����
//5���ظ�1 - 4��ֱ�����һ���ַ������롣
//6���жϵ�ǰջ�Ƿ�Ϊ�գ������Ϊ�գ���ջ�е�Ԫ�������Ƴ���prefix ��
//7����ת�ַ���
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