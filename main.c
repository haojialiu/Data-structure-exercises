#include<stdio.h>

//斐波那契数列循环解法
long Fibonacci(int n)
{
	int a = 0;
	int b = 1;
	int c;
	if (n == 1)
	{
		return 1;
	}
	else if (n == 0)
	{
		return 0;
	}
	else
	{
		for (int i = 2; i <= n; i++)
		{
			c = a + b;
			a = b;
			b = c;
		}
		return c;
	}
	
}
int main()
{
	for (int i = 0; i < 6; i++)
	{
		printf("%d\n", Fibonacci(i));
	}
}