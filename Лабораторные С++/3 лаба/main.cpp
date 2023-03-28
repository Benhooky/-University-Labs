// Темы:
// Перегрузка операторов.
// Встроенные объекты 
#define _CRT_SECURE_NO_WARNINGS
#include <tchar.h>
#include "myString.h"
#include "myRect.h"
#include "BD.h"
#include <iostream>
#include <cstdarg>
#include <utility>
#include"vld.h"
//#include "stdafx.h"	//если Вы используете предкомпиляцию заголовочных
					//файлов, раскомментируйте эту строчку

Point operator-=(Point& a, Point& b)
{
	a.x -= b.x;
	a.y -= b.y;
	return a;
}
Point operator-=(Point& a, int b)
{
	a.x -= b;
	a.y -= b;
	return a;
}
Point operator-(Point a, Point& b)
{
	a.x -= b.x;
	a.y -= b.y;
	return a;
}
Point operator-(Point a, int b)
{
	return Point(a.x-b,a.y-b);
}
MyString operator+(MyString& a, MyString& b)
{
	int size = strlen(a.m_pStr)+strlen(b.m_pStr);
	char* wholestr = new char[size + 1]{ 0 };
	strcat(wholestr, a.m_pStr);
	strcat(wholestr, b.m_pStr);
	MyString aac;
	aac = wholestr;
	delete[] wholestr;
	return aac;
}
person Data(int a, int b, N_TYPE c)
{
	return person(a, b, c);
}
int main()
{
//////////////////////////////////////////////////////////////////////



	//Задание 1.Перегрузка операторов.

	//Подключите к проекту файлы MyString.cpp и MyString.h
	//класса MyString, разработанного Вами на предыдущем занятии
	//9a. Перегрузите оператор присваивания для класса MyString
	//Проверьте корректность работы перегруженного оператора

	{
		MyString s1("AAA"), s2;
		//s1 = s2;
		s2 += s1;
		s1=s2;
		s2 += s1;
		s2.Printer();
		s1="CCC";
		s1.Printer();
		s2= MyString("tmp");
		s2.Printer();
		s1=s1;
		s1.Printer();
	}




	//2.Создайте класс Point, который будет содержать координаты
	//"точки". Объявите конструктор (конструкторы) класса   

	//2b. "Перегрузите" оператор += так, чтобы при выполнении
	//операции типа pt2+=pt1; складывались
	//одноименные переменные объектов pt1 и pt2, а сумма
	//присваивалась соответствующим переменным объекта pt2 или
	// в случае  pt2+=1; обе переменные объекта pt2 увеличивались на
	// указанное значение
	//a) с помощью метода класса (оператор +=)
	//б) с помощью глобальной функции (оператор -=)
	//Проверьте корректность работы перегруженного оператора
	{
		Point pt1(1, 1);
		Point pt2(2, 2);
		pt2 += pt1+pt2+=pt1;
		pt2.Printer();
		//вопросы
		pt2 += 1;
		pt2.Printer();
		Point pt3(3, 3);
		pt2 += pt1 += pt3+pt1+pt2+=pt3;
		pt1.Printer();
		pt2.Printer();
	}
	{
		Point pt1(1, 1);
		Point pt2(2, 2);
		pt2 -= pt1;
		pt2.Printer();
		pt2 -= 1;
		pt2.Printer();
		Point pt3(3, 3);
		pt1 -= pt3;
		pt1.Printer();
		pt2.Printer();
	}




	//Задание 2c. Перегрузите оператор +/- 
	//a)с помощью методов класса (оператор +)
	//б) с помощью  глобальных функций (оператор -)
	//так, чтобы любая из закомментированных строк
	//кода выполнялась корректно
	{
		Point pt1(1, 1);
		Point pt2(2, 2);
		Point pt3;
		pt3 = pt1 + 5;
		pt3.Printer();
		pt3 = 2 + pt1;
		pt3.Printer();
		pt3 = pt1 + pt2;
		pt3.Printer();
		pt3 = pt1 - 5;
		pt3.Printer();
		pt3 = pt1 - pt2;
		pt3.Printer();

		//Задание 1d. Перегрузите унарный оператор +/- 
		pt3 = -pt1;
		pt3.Printer();
		pt3 = +pt1;
		pt3.Printer();
		//Задание 1d. Перегрузите унарный оператор +/- 
		pt3 = -pt1;
		pt3.Printer();
		pt3 = +pt1;
		pt3.Printer();
	}



	//Задание 2d. Перегрузите оператор << (вывода в поток) для
	//класса MyString таким образом, чтобы при выполнении приведенной строки
	//на экран было выведено:
	//contents:  "QWERTY"
	{
		MyString s("QWERTY");
		cout << s << endl;
	}



	

//Задание 2e*. Перегрузите операторы + и += для класса MyString таким образом,
  //чтобы происходила конкатенация строк
	MyString s1("QWERTY"), s2("AAA"), s3, s4("BBB");
	s3 = s1+s2;
	s3.Printer();
	s4 += s1; 
	s4.Printer();
	


	//Задание 3. Разработать "базу данных" о сотрудниках посредством ассоциативного
	//массива. Ключом является фамилия (ключ в задании уникален, поэтому нескольких Ивановых
	//в базе быть не может), а данными: пол, возраст, должность, зарплата...
	//Реализуйте:
	//добавление сотрудников в базу
	//исключение
	//вывод информации о конкретном сотруднике
	//вывод всей (или интересующей) информации о всех сотрудниках
	//Например:
	
	{
		BD a;
		a.Employ("IGOR", 23, 10000, beginner);
		a.Employ("FAGOR", 23, 15555, beginner);
		a.Employ("DAGON", 23, 66000, beginner);
		a.Employ("RASON", 23, 10000, beginner);
		a.Show(1);
		a.fire(1);
		a.Show(1);
		a.fire(2);
		a.Show(1);
		a["AMAZON"] = Data(30, 5000, header);
		a.Show(1);
		a.Show(2);
		a.Show(3);
		a.Show(4);


		BD bd;	//создание пустой базы
		bd["Ivanov"] = Data(30, 12222, beginner);	//если Ivanov-а в базе еще нет, то
						//добавление, если уже есть, то замена его реквизитов
		std::cout << bd;	//вывод информации обо всех сотрудниках
		std::cout << a;

		//А также:
		BD bdnew = bd;
		bdnew = bd;
		std::cout << bdnew;
		bdnew = bd;

		//А также семантику перемещения:
		BD bdmove;
		bdmove.move(bdnew);
		std::cout << bdnew;
		std::cout << bdmove;
	}

	
	return 0;
}//endmain

