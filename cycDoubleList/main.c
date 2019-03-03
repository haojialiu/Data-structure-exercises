#include "CycDoubleList.h"

int main()
{
	CycDouList list;

	InitCycDouList(&list);

	for (int i = 0; i < 5; ++i)
	{
		InsertCycDouList(&list, i * 10, i);
	}
	ShowDouList(&list);

	ReverseShow(&list);
}