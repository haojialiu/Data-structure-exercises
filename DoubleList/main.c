#include "DoubleList.h"

int main()
{
	DoubleList list;

	InitDoubleList(&list);

	for (int i = 0; i < 5; ++i)
	{
		InsertDoubleList(&list, i * 10, i);
	}

	ShowDoubleList(&list);

	ReverseShow(&list);
}