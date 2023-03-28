#define _CRT_SECURE_NO_WARNINGS
#include <tchar.h>
#include <fstream>
#include "myRect.h"
#include <iostream>
#include <cstdarg>
#include <utility>
#include"vld.h"


int main()
{
	setlocale(LC_ALL, "Russian");
	using namespace std;
	List spisok;
	bool o = true;
	char action = '9', action1;
	int a, b=0, c=0;
	Circle tempor_c;
	Circle check;
	while (o)
	{
		cout << std::endl << "Укажите необходимую команду " << std::endl;
		if (b != 0) { cin >> action; }
		switch (action)
		{
		case'0':
			o = false;
			break;
		case'1':
			cout << spisok;
			break;
		case'3':
			cin >> tempor_c;
			if (spisok.remove(tempor_c) == true)
			{
				printf("Элемент был найден и удален\n");
			}
			else
			{
				printf("Данного элемента нет в списке\n");
			}
			break;
		case '2':
			cout << "Для добавление элемента в начало списка нажмите 1" << std::endl << "Для добавление элемента в конец списка нажмите 2" << std::endl;
			cin >> action1;
			switch (action1)
			{
			case'1':
				printf("Выведите координаты и радиус окружности\n");
				std::cin >> tempor_c;
				if (tempor_c == check) { printf("ВНИМАНИЕ, вы ввели невозможное значение\n"); break; }
				spisok.head_adder(tempor_c);
				break;
			case'2':
				printf("Выведите координаты и радиус окружности\n");
				std::cin >> tempor_c;
				spisok.tail_adder(tempor_c);
				break;
			default:
				std::cout << "Ошибка. Пожалуйста введите другую команду" << std::endl;
				break;
			}
			break;
		case'4':
		{
			cin >> tempor_c;
			a=spisok.delete_all(tempor_c);
			if (a > 0)
			{
				printf("Элементы успешно удалены\n");
				printf("Количество удаленных элементов ");
				cout << a<<endl;
			}
			else
			{
				printf("Данного элемента нет в списке\n");
			}
			a = 0;
			break;
		}
		case'5':
		{
			spisok.~List();
			printf("Список успешно отчистен\n");
			break;
		}
		case '6':
			spisok.sorter();
			printf("Список успешно отсортирован\n");
			break;
		case'7':
			spisok.file_writer();
			break;
		case'8':
			spisok.file_reader();
			break;
		case'9':
			printf("Список команд:\n");
			printf("'1'- Вывести список\n");
			printf("'2' - Добавить элемент\n");
			printf("'3' - Удаление из списка первого элемента, данное которого совпадает со значением параметра\n");
			printf("'4' - Удаление из списка всех элементов, данное которых совпадает со значением параметра\n");
			printf("'5' - Отчистить список\n");
			printf("'6' - Сортировка элментов по убыванию площадей окружностей\n");
			printf("'7' - Вывод списка в указанный файл\n");
			printf("'8' - Чтение элементов в начало списка из файла\n");
			printf("'9' - Вывод панели управления\n");
			printf("'0' - Завершение работы программы\n");
			b++;
			break;
		default:
			std::cout << "Ошибка. Пожалуйста введите другую команду" << std::endl;
			break;
		}
	}
return 0;

}//end_main

