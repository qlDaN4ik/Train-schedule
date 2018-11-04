#include "pch.h"
#include "workWithList.h"

Time operator+(Time a, Time b)
{
	Time c;
	int x = a.minute + b.minute;
	c.hour = (a.hour + b.hour + x / 60) % 24;
	c.minute = x % 60;
	return c;
}

bool sortName(Train a, Train b)
{
	if (strcmp(a.name, b.name) < 0)
		return 1;
	else 
		return 0;
}

bool sortDepart(Train a, Train b)
{
	if (a.departure.hour == b.departure.hour)
	{
		return a.departure.minute < b.departure.minute;
	}
	else
		return a.departure.hour < b.departure.hour;
}

bool sortWay(Train a, Train b)
{
	if (a.way.hour == b.way.hour)
	{
		return a.way.minute < b.way.minute;
	}
	else
		return a.way.hour < b.way.hour;
}

bool sortArrival(Train a, Train b)
{
	if (a.arrival.hour == b.arrival.hour)
	{
		return a.arrival.minute < b.arrival.minute;
	}
	else
		return a.arrival.hour < b.arrival.hour;
}

void SortName(Train* list, int count)
{
	Train a;
	for (int i = count - 1; i >= 0; i--)
	{
		for (int j = 0; j < i; j++)
		{
			if (sortName(list[i], list[j]))
			{
				a = list[j];
				list[j] = list[i];
				list[i] = a;
			}
		}
	}
}

void SortDepart(Train* list, int count)
{
	Train a;
	for (int i = count - 1; i >= 0; i--)
	{
		for (int j = 0; j < i; j++)
		{
			if (sortDepart(list[i], list[j]))
			{
				a = list[j];
				list[j] = list[i];
				list[i] = a;
			}
		}
	}
}

void SortWay(Train* list, int count)
{
	Train a;
	for (int i = count - 1; i >= 0; i--)
	{
		for (int j = 0; j < i; j++)
		{
			if (sortWay(list[i], list[j]))
			{
				a = list[j];
				list[j] = list[i];
				list[i] = a;
			}
		}
	}
}

void SortArrival(Train* list, int count)
{
	Train a;
	for (int i = count - 1; i >= 0; i--)
	{
		for (int j = 0; j < i; j++)
		{
			if (sortArrival(list[i], list[j]))
			{
				a = list[j];
				list[j] = list[i];
				list[i] = a;
			}
		}
	}
}

Data startEnter(Train* list, int count) // Заполнение расписания
{
	FILE *in;
	in = fopen("schedule.txt", "r");
	int type, countf = 0;
	Data pos;

	if (count > 0)
		delete[] list;

	printf("Заполнить расписание вручную(1) или из файла(2)? Введите номер варианта:");
	while (scanf("%d", &type) < 1 || type < 1 || type > 2)
	{
		printf("Ошибка! Введено некорректное значение!!!\n");
		scanf("%*[^\n]");
		scanf("%*c");
		printf("Заполнить расписание вручную(1) или из файла(2)? Введите номер варианта:");
	}

	if (type == 1) // Вручную
	{
		printf("Введите количество маршрутов:");
		while (scanf("%d", &count) < 1)
		{
			printf("Ошибка! Введено некорректное значение!!!\n");
			scanf("%*[^\n]");
			scanf("%*c");
			printf("Введите количество маршрутов:");
		}
		list = new Train[count];
		for (int i = 0; i < count; i++)
		{
			printf("%d-й маршрут:\n", i + 1);

			printf("Введите название конечной станции:");
			while (scanf("%s", list[i].name) < 1)
			{
				printf("Ошибка! Введено некорректное значение!!!\n");
				scanf("%*[^\n]");
				scanf("%*c");
				printf("Введите название конечной станции:");
			}

			printf("Введите время отправления в часах(0-23):");
			while (scanf("%d", &list[i].departure.hour) < 1 || list[i].departure.hour < 0 || list[i].departure.hour > 23)
			{
				printf("Ошибка! Введено некорректное значение!!!\n");
				scanf("%*[^\n]");
				scanf("%*c");
				printf("Введите время отправления в часах(0-23):");
			}
			printf("Введите время отправления в минутах(0-59):");
			while (scanf("%d", &list[i].departure.minute) < 1 || list[i].departure.minute < 0 || list[i].departure.minute > 59)
			{
				printf("Ошибка! Введено некорректное значение!!!\n");
				scanf("%*[^\n]");
				scanf("%*c");
				printf("Введите время отправления в минутах(0-59):");
			}

			printf("Введите время пути в часах:");
			while (scanf("%d", &list[i].way.hour) < 1 || list[i].way.hour < 0)
			{
				printf("Ошибка! Введено некорректное значение!!!\n");
				scanf("%*[^\n]");
				scanf("%*c");
				printf("Введите время пути в часах:");
			}
			printf("Введите время пути в минутах(0-59):");
			while (scanf("%d", &list[i].way.minute) < 1 || list[i].way.minute < 0 || list[i].way.minute > 59)
			{
				printf("Ошибка! Введено некорректное значение!!!\n");
				scanf("%*[^\n]");
				scanf("%*c");
				printf("Введите время пути в минутах(0-59):");
			}

			list[i].arrival = list[i].departure + list[i].way;
		}
		printf("Расписание успешно заполнено!!!\n\n");
	}
	else // Из файла
	{
		if (fscanf(in, "%d", &countf) < 1 || countf < 1)
			printf("В файле нет верного расписания!!!\n\n");
		else
		{
			count = countf;
			list = new Train[count];
			for (int i = 0; i < count; i++)
				fscanf(in, "%s %d:%d %d:%d %d:%d", list[i].name, &list[i].departure.hour, &list[i].departure.minute, &list[i].way.hour, &list[i].way.minute, &list[i].arrival.hour, &list[i].arrival.minute);
			printf("Расписание успешно считано из файла!!!\n\n");
			fclose(in);
		}
	}

	pos.pointer = list;
	pos.count = count;
	return pos;
}

Data addElem(Train* list, int count) // Добавление элемента
{
	Data pos;
	Train* tmp = new Train[count + 1];
	for (int i = 0; i < count; i++)
		tmp[i] = list[i];
	printf("Введите название конечной станции:");
	while (scanf("%s", tmp[count].name) < 1)
	{
		printf("Ошибка! Введено некорректное значение!!!\n");
		scanf("%*[^\n]");
		scanf("%*c");
		printf("Введите название конечной станции:");
	}

	printf("Введите время отправления в часах(0-23):");
	while (scanf("%d", &tmp[count].departure.hour) < 1 || tmp[count].departure.hour < 0 || tmp[count].departure.hour > 23)
	{
		printf("Ошибка! Введено некорректное значение!!!\n");
		scanf("%*[^\n]");
		scanf("%*c");
		printf("Введите время отправления в часах(0-23):");
	}
	printf("Введите время отправления в минутах(0-59):");
	while (scanf("%d", &tmp[count].departure.minute) < 1 || tmp[count].departure.minute < 0 || tmp[count].departure.minute > 59)
	{
		printf("Ошибка! Введено некорректное значение!!!\n");
		scanf("%*[^\n]");
		scanf("%*c");
		printf("Введите время отправления в минутах(0-59):");
	}

	printf("Введите время пути в часах:");
	while (scanf("%d", &tmp[count].way.hour) < 1 || tmp[count].way.hour < 0)
	{
		printf("Ошибка! Введено некорректное значение!!!\n");
		scanf("%*[^\n]");
		scanf("%*c");
		printf("Введите время пути в часах:");
	}
	printf("Введите время пути в минутах(0-59):");
	while (scanf("%d", &tmp[count].way.minute) < 1 || tmp[count].way.minute < 0 || tmp[count].way.minute > 59)
	{
		printf("Ошибка! Введено некорректное значение!!!\n");
		scanf("%*[^\n]");
		scanf("%*c");
		printf("Введите время пути в минутах(0-59):");
	}

	printf("Новый маршрут успешно добавлен!\n\n");
	tmp[count].arrival = tmp[count].departure + tmp[count].way;
	count++;
	delete[] list;
	list = tmp;
	pos.pointer = list;
	pos.count = count;
	return pos;
}
void saveList(Train* list, int count) // Сохранение в файл
{
	if (count < 1)
		printf("Вы не заполнили расписание!!!\n");
	else
	{
		FILE *out;
		out = fopen("schedule.txt", "w");
		fprintf(out, "%d\n", count);
		for (int i = 0; i < count; i++)
			fprintf(out, "%s %02d:%02d %02d:%02d %02d:%02d\n", list[i].name, list[i].departure.hour, list[i].departure.minute, list[i].way.hour, list[i].way.minute, list[i].arrival.hour, list[i].arrival.minute);
		printf("Расписание успешно сохранено в файл!!!\n\n");
		fclose(out);
	}
}

Data deleteElem(Train* list, int count) // Удаление элемента
{
	Data pos;
	if (count < 1)
		printf("Вы не заполнили расписание!!!\n");
	else
	{
		int num;
		printf("Введите порядковый номер марштрута в последней сортировке, который хотите удалить:");
		while (scanf("%d", &num) < 1 || num < 1 || num > count)
		{
			printf("Ошибка! Введено некорректное значение!!!\n");
			scanf("%*[^\n]");
			scanf("%*c");
			printf("Введите порядковый номер марштрута, который хотите удалить:");
		}
		Train* tmp = new Train[count - 1];
		int i = 0, j = 0;
		while (i != count)
		{
			if (i != num - 1)
			{
				tmp[j] = list[i];
				j++;
			}
			i++;
		}
		delete[] list;
		list = tmp;
		count--;
		printf("%d-й маршрут успешно удален!\n\n", num);
	}
	pos.pointer = list;
	pos.count = count;
	return pos;
}

void sortList(Train* list, int count) // Сортировка
{
	if (count < 1)
		printf("Вы не заполнили расписание!!!\n");
	else
	{
		int field;
		printf("Выберите поле для сортировки расписания: название конечной станции(1), время отправления(2), длительность пути(3), время прибытия(4). Введите номер поля:");
		while (scanf("%d", &field) < 1 || field < 1 || field > 4)
		{
			printf("Ошибка! Введено некорректное значение!!!\n");
			scanf("%*[^\n]");
			scanf("%*c");
			printf("Выберите поле для сортировки расписания: название конечной станции(1), время отправления(2), длительность пути(3), время прибытия(4). Введите номер поля:");
		}
		switch (field)
		{
		case 1: // По названию
			SortName(list, count);
			printf("Расписание успешно отсортировано по названию конечной станции!\n\n");
			break;
		case 2: // По времени отправления
			SortDepart(list, count);
			printf("Расписание успешно отсортировано по времени отправления!\n\n");
			break;
		case 3: // По длительности пути
			SortWay(list, count);
			printf("Расписание успешно отсортировано по длительности пути!\n\n");
			break;
		case 4: // По времени прибытия
			SortArrival(list, count);
			printf("Расписание успешно отсортировано по времени прибытия!\n\n");
			break;
		default:
			break;
		}
	}
}

void outList(Train* list, int count) // Вывод расписания на экран
{
	if (count < 1)
		printf("Вы не заполнили расписание!!!\n");
	else
	{
		printf("Ваше расписание:\n");
		printf("№  Название    Отправление    Путь      Прибытие  \n");
		for (int i = 0; i < count; i++)
			printf("%d) %-12s%02d:%02d          %02d:%02d     %02d:%02d\n", i + 1, list[i].name, list[i].departure.hour, list[i].departure.minute, list[i].way.hour, list[i].way.minute, list[i].arrival.hour, list[i].arrival.minute);
	}
}