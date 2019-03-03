#include"sort.h"


//√∞≈›≈≈–Ú
void Bubble_sort(int arr[], int len)
{
	int pos = 0;
	for (int i = 0; i < len - 1; i++)
	{
		for (int j = 0; j < len - i - 1; j++)
		{
			if (arr[j]>arr[j + 1])
			{
				pos++;
				int tmp = arr[j + 1];
				arr[j + 1] = arr[j];
				arr[j] = tmp;
			}
		}
		if (pos = 0)
			break;
	}
}

//—°‘Ò≈≈–Ú
void Select_sort(int arr[], int len)
{
	int tmp = 0;
	for (int j = 0; j < len; j++)
	{
		int min = j;
		for (int n = j+1; n < len; n++)
		{
			if (arr[min]>arr[n])
			min = n;
		}
			tmp = arr[j];
			arr[j] = arr[min];
			arr[min] = tmp;
	}
}

//≤Â»Î≈≈–Ú
void Insertion_sort(int arr[], int len)
{
	int tmp = 0;
	for (int i = 1; i < len; i++)
	{
		int j = i;
		while (arr[j] < arr[j-1])
		{
			tmp = arr[j];
			arr[j] = arr[j - 1];
			arr[j - 1] = tmp;
			j--;
		}
	}
}

//œ£∂˚≈≈–Ú
void Shell_sort(int arr[], int len)
{
	int tmp = 0;
	int m = len / 2;
	while (m >= 1)
	{
		for (int i = m; i < len; i++)
		{
			int j = i;
			while (arr[j] < arr[j - m])
			{
				tmp = arr[j];
				arr[j] = arr[j - m];
				arr[j - m] = tmp;
				j -= m;
			}
		}
		m /= 2;
	}
}

//øÏÀŸ≈≈–Ú
void Quick_sort(int arr[],int low,int high)
{
	int i = low;
	int j = high;
	int k = i;
	int kk = arr[i];
	int tmp = 0;
	while (i != j)
	{
		for (; (j >= 0)&&(i!=j); j--)
		{
			if (arr[j] < kk)
			{
				tmp = arr[j];
				arr[j] = arr[k];
				arr[k] = tmp;
				k = j;
				break;
			}
		}
		for (; (i <= high) && (i != j); i++)
		{
			if (arr[i]>kk)
			{
				tmp = arr[i];
				arr[i] = arr[k];
				arr[k] = tmp;
				k = i;
				break;
			}
		}
	}
	 
	if (low < i)
	{
		Quick_sort(arr, low, i-1);
	} 
	if (high>i)
	{
		Quick_sort(arr, i+1, high);
	}
	
}


//¥Ú”°
void Show(int arr[], int len)
{
	for (int i = 0; i < len; i++)
	{
		printf("%d,",arr[i]);
	}
	printf("\n");
}