#include "pch.h"
#include "service.h"
#include <iostream>

int main()
{
	setlocale(LC_ALL, "Rus");
	int punkt = 0, count = 0;
	Data pos;
	Train* list = NULL;
	while (punkt != 7)
	{
		punkt = startMenu();
		pos = startProg(punkt, list, count);
		count = pos.count;
		list = pos.pointer;
	}
	delete[] list;
	return 0;
}