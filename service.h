/**
*\file
*\brief
Модуль программы по сервисной работе.
*\author Данил
*\version 1.0
*\example Запуск меню программы
*
*Все необходимые функции для корректной работы программы.
*/
#ifndef SERVICE_H
#define SERVICE_H

#include "pch.h"
#include "workWithList.h"

int startMenu();
Data startProg(int, Train*, int);
void finish();

#endif