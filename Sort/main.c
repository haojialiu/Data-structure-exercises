#include"sort.h"
int main()
{
	int arr[10] = { 1, 2, 5, 7, 0, 7, 3, 6, 9, 4 };
	int len = sizeof(arr) / sizeof(arr[0]);

	//Bubble_sort(arr, len);	//ð������
	//Show(arr,len);
	//

	//Select_sort(arr, len);	//ѡ������
	//Show(arr, len);

	//Insertion_sort(arr,len);	//��������
	//Show(arr, len);
	//
	//Shell_sort(arr,len);	//ϣ������
	//Show(arr, len);

	//Quick_sort(arr, len);	////��������
	//Show(arr, len);

	Quick_sort(arr, 0, 9);
	Show(arr, len);
}
