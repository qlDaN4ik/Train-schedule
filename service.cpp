#include "pch.h"
#include "service.h"

int startMenu() // Меню
{
	int punkt;
	printf("Выберите пункт меню и введите его номер(1,2,3,4,5,6,7):\n 1. Заполнение расписания;\n 2. Добавить один новый маршрут;\n 3. Сохранение расписания в файл;\n 4. Удаление определенного маршрута;\n 5. Сортировка расписания;\n 6. Вывести расписание на экран;\n 7. Выход;\n");
	while (scanf("%d", &punkt) < 1)
	{
		printf("Ошибка! Введено некорректное значение!!!\n");
		scanf("%*[^\n]");
		scanf("%*c");
		printf("Выберите пункт меню и введите его номер(1,2,3,4,5,6,7):\n 1. Заполнение расписания;\n 2. Добавить один новый маршрут;\n 3. Сохранение расписания в файл;\n 4. Удаление определенного маршрута;\n 5. Сортировка расписания;\n 6. Вывести расписание на экран;\n 7. Выход;\n");
	}
	return punkt;
}

Data startProg(int punkt, Train* list, int count) // Пункты
{
	Data pos;
	pos.count = count;
	pos.pointer = list;
	switch (punkt)
	{
	case 1:
		pos = startEnter(list, count);
		break;
	case 2:
		pos = addElem(list, count);
		break;
	case 3:
		saveList(list, count);
		break;
	case 4:
		pos = deleteElem(list, count);
		break;
	case 5:
		sortList(list, count);
		break;
	case 6:
		outList(list, count);
		break;
	case 7:
		finish();
		break;
	default:
		printf("Ошибка! Введено некорректное значение!!!\n");
		scanf("%*[^\n]");
		scanf("%*c");
		break;
	}
	return pos;
}

void finish() // Завершение программы
{
	printf("Спасибо за использование программы!!!\n");
	getchar();
}