/*************************************************************
	Практическое занятие №5. Структуры
//динамический массив структур
//поиск
//сортировка
//сохранение в файле
//чтение из файла
*************************************************************/

#define _CRT_SECURE_NO_WARNINGS
#include <tchar.h>
#include <iostream>
#include <cstdio>
#include "book.h"
#include "Kartoteka.h"
#include "input.h"
#include "vld.h"
#include "sorter.h"
#include< string.h >
#include<cmath>
#define	  stop __asm nop	




int main()
{
	//Используйте структуру BOOK, созданную в предыдущей работе.
	//Для этого достаточно переписать и подключить к проекту файлы
	//book.h и book.cpp
	setlocale(LC_ALL, "Russian");
	//Задание 1. Создаем «картотеку».
	//«Картотека» - это массив структур => нужно такой массив создать.
	//Замечание: размер массива придется увеличиватьпо мере добавления книг =>
	//кКаким должен быть такой массив???
	BOOK l;
	Library biblio;
	int N,D;
	N = sizeof(l);
	std::cin >> N;//количество книг которое мы хотим ввести за раз
	biblio.number = N;
	biblio.Spisok = new BOOK[N];
  bool(*sortart)(BOOK**&vec, int vard) = &sort_article;
  bool(*sortau)(BOOK**&vec, int vard) = &sort_author;
  bool(*sortcat)(BOOK**&vec, int vard) = &sort_category;
  bool(*sortage)(BOOK**&vec, int vard) = &sort_age;
  bool(*sortcost)(BOOK**&vec, int vard) = &sort_cost;
  bool(*func_mas[5])(BOOK**&vec, int vard){ sortart, sortau, sortcat, sortage, sortcost };
	BOOK** vec = new BOOK*  [N];
	for (int i = 0; i < N; i++)
	{
		vec[i] = &(biblio.Spisok[i]);
	}

	char action, action1;
	for (int i = 0; i < N; i++)
	{
		form_book(vec[i]);
		book_printer(vec,i);
		std::cout << std::endl;
	}
	bool o = true;
	
	printf("Список команд:\n");
	printf("'1'- Вывести картотеку\n");
	printf("'2' - Записать в картотеку новую книгу\n");
	printf("'3' - Удалить книги или диапозон книг\n");
	printf("'4' - Записать картотеку в файл\n");
	printf("'5' - Прочитать картотеку из файла\n");
	printf("'6' - Вывести книги определенной категории\n");
	printf("'7' - Отсортировать картотеку по выбранному полю\n");
	printf("'8' - Вывести повторно меню\n");
	printf("'9' - Завершить работу программы\n");
	while (o)
	{
		std::cout << std::endl << "Укажите необходимую команду "<<std::endl;
		std::cin >> action;
		switch (action)
		{
		case'0':
			o = false;
			break;
		case'1':
			biblio_printer(biblio,vec);
			break;
		case'2':
			book_adder(biblio.number, biblio.Spisok,vec);
			break;
		case '3':
			std::cout << "Для удаления одной нажмите 1, если вы хотите удалить диапозон книг, нажмите 2" << std::endl;
			std::cin >> action1;
			switch (action1)
			{
			case'1':
				std::cout << "Напишите номер удаляемой книги\n";
				std::cin >> N;
				if ((N > biblio.number) || (N < 0) )
				{
					std::cout << "Такой книги не существует"; 
					break;
				}
				book_deleater(N, biblio.number, biblio.Spisok,vec);
				break;
			case'2':
				std::cout << "Напишите диапозон удаляемых книг\n";
				std::cin >> N >> D;
				if ((N > biblio.number)||(D >biblio.number)||(N<0)||(D<0))
				{
					std::cout << "Такого диапозона книг не существует"; 
					break;
				}
				book_deleater(N, D, biblio.number, biblio.Spisok,vec);
				break;
			default:
				std::cout << "Ошибка. Пожалуйста введите другую команду" << std::endl;
				break;
			}
			break;
		case'4':
		{
			FILE* fs = fopen("cart.txt", "wt");
			if (fs == 0)
			{
				perror("Не могу открыть файл для записи");
				break;
			}
			for (int i = 0; i < biblio.number; i++)
			{
				book_printerf(fs,vec,i);
				std::cout << std::endl;
			}
			fclose(fs);
			break;
		}
		case'5':
		{
			
			FILE* fs = fopen("cart.txt", "r");
			if (fs == 0)
			{
				perror("Не могу открыть файл для записи");
				break;
			}
			BOOK be;
			BOOK* ar = &be;
			int k = countNumberOfLines(fs)/ 5;
			fs = fopen("cart.txt", "r");
			if (!feof(fs))
			{
				for(int i=0;i<k;i++)
				{
					add(biblio.number, biblio.Spisok,vec);
					file_reader(fs, biblio.Spisok, biblio.number);
					vec[biblio.number-1] = &biblio.Spisok[biblio.number-1];
				}		
				fclose(fs);
			}
			break;
		}
		case '6':
			int a;
			std::cout << "Введите необходимую категорию" << std::endl;
			std::cin >> a;
			if ((a == 1) || (a == 0)) 
			{ 
				std::cout << "Книг данной категории " << category_scorer(biblio.Spisok, biblio.number, a)<<std::endl; 
			}
			else
				{
				std::cout << "Неверная категория" << std::endl;
				}
			break;
		case'7':
			int ab;
			std::cout << "По какому полю вы хотите отсортировать?" << std::endl;
			std::cin >> ab;
			if ((ab > 5) || (ab < 1) || biblio.number < 1)
			{
				std::cout << "Вы ввели несуществующию категорию, либо количетсво книг в библиотеке равно 0";
				break;
			}
			uni_puzirek(ab,biblio.number,func_mas ,vec );
			break;
		case'8':
			printf("Список команд:\n");
			printf("'1'- Вывести картотеку\n");
			printf("'2' - Записать в картотеку новую книгу\n");
			printf("'3' - Удалить книги или диапозон книг\n");
			printf("'4' - Записать картотеку в файл\n");
			printf("'5' - Прочитать картотеку из файла");
			printf("'6' - Вывести книги определенной категории\n");
			printf("'7' - Отсортировать картотеку по выбранному полю\n");
			printf("'8' - Вывести повторно меню\n");
			printf("'9' - Завершить работу программы\n");
			break;
		case'9':
			o = false;
			break;
		default:
			std::cout << "Ошибка. Пожалуйста введите другую команду" << std::endl;
			break;
		}
	}
	delete[] vec;
	delete[] biblio.Spisok;

	//Пользователь должен иметь возможность по своему желанию выполнять
	//разные действия с картотекой => нужно такую возможность ему
	//предоставить: это может выглядеть как вывод "меню" (перечень
	//возможных действий и соответствующих реакций пользователя), например:
	//Распечатать содержимое картотеки (1)
	//Ввести новую книгу (2)
	//Удалить существующую(ие) (3)
	//Записать текущее содержимое картотеки в файл (4)
	//Считать из файла содержимое в картотеку (5)
	//...
	//Выход из программы (...)


	//Реализуйте посредством функций разные возможности работы с картотекой




	//Подсказка1: для файлового ввода/вывода используйте функции fprintf и fscanf
	//(заголовочный файл <cstdio>



	// Подсказка2: удобно в качестве первого данного в файле хранить количество
	// книг в картотеке
	//Если файл существует и его удалось открыть
	//if()
	//{
	//Чтение данных из файла
	//а) считали количество элементов
	//б) создали массив требуемой размерности
	//в) считали данные из файла в массив
	//}




	//****************************************************************
	//Задание 2. Предоставьте пользователю возможность выводить перечень книг
	//в определенном порядке => напишите функцию (функции) сортировки массива
	//по любому из полей структуры.
	//Замечание: признак - "по какому полю сортируем" можно ввести с помощью
	//перечисления.
	return 0;

}