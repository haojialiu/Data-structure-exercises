#include "cyclinklist.h"

int main()
{
	CycLinkList  list;

	InitCycList(&list);

	for (int i = 0; i < 5; ++i)
	{
		InsertCycList(&list, i * 10, i);
	}
	ShowList(&list);
	InquiryCycList(&list, 3);
}