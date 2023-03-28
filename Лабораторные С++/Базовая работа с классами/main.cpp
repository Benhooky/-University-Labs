﻿#include "myRect.h"
#include "myString.h"
#include "vld.h"
#include <iostream>

#define stop __asm nop

Rect BoundingRect(Rect r1,Rect r2) {
	r1.Normalize(), r2.Normalize();
	Rect common_r(
		(r1.GetLeft() > r2.GetLeft() ? r1.GetLeft() : r2.GetLeft()),
		(r1.GetRight() > r2.GetRight() ? r1.GetRight() : r2.GetRight()),
		(r1.GetTop() > r2.GetTop() ? r1.GetTop() : r2.GetTop()),
		(r1.GetBottom() > r2.GetBottom() ? r1.GetBottom() : r2.GetBottom())
	);
	return common_r;
}
Rect BoundingRect2(Rect& r1, Rect& r2) {
	r1.Normalize(), r2.Normalize();
	Rect common_r(
		(r1.GetLeft() > r2.GetLeft() ? r1.GetLeft() : r2.GetLeft()),
		(r1.GetRight() > r2.GetRight() ? r1.GetRight() : r2.GetRight()),
		(r1.GetTop() > r2.GetTop() ? r1.GetTop() : r2.GetTop()),
		(r1.GetBottom() > r2.GetBottom() ? r1.GetBottom() : r2.GetBottom())
	);
	return common_r;
}

class Bochka {
	float C;
	float vol;
	public:
		Bochka(float con=0,float vol=1) {
			C = con;
			this->vol = vol;
		}
		void Pereliv(Bochka& other,float cup_vol) {
			other.vol--;
			C = (C * vol + cup_vol * other.C) / (vol + cup_vol);
			vol++;
		}
		float GetConcentration() {
			return C;
		}
		float SetConcentration(float con) {
			C = con;
		}
};

int main()
{
	using namespace std;
	//Задание 1.Объявление класса. Создание экземпляра класса.
	//Вызов методов класса.
	//Откройте закладку Class View - (здесь Вы увидите имена методов и
	//данных - классов Rect и MyString)
	//Обратите внимание на пиктограммы слева от имен членов класса - они
	//обозначают спецификатор доступа к каждому члену класса.

	//Какой конструктор вызывается при создании экземпляра класса?
	{
		Rect rect; //неявный default-конструктор
		stop
	}

	//1a. Объявите и определите конструктор с параметрами для
	//инициализации переменных класса. Создайте экземляры класса Rect
	//с помощью конструктора с параметрами. Если компилятор выдает
	//ошибку в предыдущем фрагменте, подумайте - чего ему не
	//хватает? Добейтесь отсутствия ошибок.
	//Выполняя задание с самого начала по шагам, определите:
	//в какой момент происходит вызов конструктора(какого?)?
	
	Rect rect1(1, 5, 6, 10);

	//Подсказка: учтите, что пользователь Вашего класса может указывать
	//в качестве параметров любые значения!
	MyString ddd;
	MyString sss(ddd);

	stop
	//1б. При конструировании объекта посредством конструктора без параметров
	//предусмотрите инициализацию переменных класса, например, нулем

	Rect rect0;

	stop
	//1в. Объявите, определите и вызовите метод класса InflateRect(),
	//который увеличивает размеры прямоугольника на заданные приращения
	//(раздвигая стороны от центра - каждую сторону на свое значение).
	//Подсказка: объявить и определить методы можно не только "вручную",
	//но и с помощью Wizard-a Class View. Для этого: откройте закладку
	//ClassView окна проекта, сделайте активным класс Rect и нажмите
	//правую кнопку мыши - в появившемся контекстном меню выберите
	//Add/Add Member Function... С помощью появившейся диалоговой панели
	//"дайте указания" Wizard-у как объявить и определить метод.

	rect0.InflateRect(40,42,67,95);

	stop

		//Задание 2.Перегрузка конструкторов и методов класса.
		//Конструктор копирования.

		//2а.Объявите и определите конструктор копирования в классе Rect.
		//Выполняя задание по шагам, определите, какой
		//конструктор вызывается при создании r1,r2,r3 и r4?
		//Чему равны переменные созданных объектов?
			Rect r1;
			Rect r2(1,2,3,4);
			Rect r3 = r1;
			Rect r4(r2);
			stop


	  //2б. Объявите и определите в классе Rect метод InflateRect(),
		//который принимает два аргумента, по умолчанию равных 1, и
		//раздвигает стороны прямоугольника на на заданные приращения.
		//Для каких объектов вызывается функция InflateRect()?
			r1.InflateRect(1,1);
			r2.InflateRect(2,2);
		//Какая из функций InflateRect() вызывается в каждом из трех случаев?
			r3.InflateRect(2,2,2,2);
			r3.InflateRect(3,3);
			r3.InflateRect(5);
			r3.InflateRect();
		stop


		//Задание 3.Спецификаторы доступа. Инкапсуляция.
		{
		Rect r;
		//Раскомментируйте следующую строку. Объясните ошибку
		//компилятора

		//int tmp = r.m_left; // поле по-умолчанию находится в private-блоке



		//Введите в класс Rect метод void SetAll(...),
		//который присваивают переменным класса передаваемые
		//значения. Вызовите созданный метод, проверьте корректность.

		r.SetAll(10, 56, 23, 10);

		//Введите в класс Rect парный метод GetAll(...),
		//который "достает" значения private-переменных класса.
		//Вызовите созданный метод, проверьте корректность.
		int r_left, r_right, r_top, r_bottom;
		r.GetAll(r_left, r_right, r_top, r_bottom);

		stop
		}

		//Задание 4.Передача экземпляра класса в качестве параметра
		//функции. Возвращение объекта класса по значению. Поставив
		//остановы в конструкторе копирования или выполняя фрагмент
		//по шагам, определите: в какой момент происходит обращение
		//к конструктору копирования.
		//Создайте глобальную функцию
		// Rect BoundingRect(Rect, Rect);
		//которая принимает два объекта класса Rect по значению и
		//возвращает объект класса Rect, который является прямоугольником,
		//в который вписаны заданные прямоугольники. Как происходит
		//передача параметров и возвращение объекта класса?

		//Замечание*: хорошо было бы учесть тот факт, что прямоугольник
		//может оказаться "ненормализованным", то есть m_left>m_right или/и
		//m_top>m_bottom

		{

			Rect r1(1,2,3,4), r2(5,6,7,8),r3;
			r3= BoundingRect(r1, r2);
		stop

		//Задание 4а. Передача объектов по ссылке.
		//Создайте глобальную функцию BoundingRect2, которая выполняет ту же
		//задачу, принимая параметры по ссылке
		//Вызываются ли конструкторы при передаче параметров? 


		r3 = BoundingRect2(r1, r2); //Конструкторы не вызываются, т.к. копии объектов не создаются
		stop
		}

		Rect dd; // 10 20 
		Rect dd1(1, 2, 3, 4); // 1 ,2,3
		dd1 = dd;
		stop

		//Задание 5. Когда вызываются конструкторы и деструкторы.
		//Объявите и определите
		//явный деструктор класса. Поставьте остановы в
		//конструкторе (конструкторах) и деструкторе. Определите: когда для
		//каждого из объектов вызывается конструктор, а когда - деструктор?
		{
			std::cout << "sssssssssss\n";
			Rect r1;
			Rect*	pR = new Rect(1,2,1,2);
			{
				Rect r2(r1);
				Rect* arRect[2];
				for(int i=0; i<2; i++)
				{
					 Rect r3 (i,i,i,i) ;
					 static Rect r4(*pR);
					Rect r5(i,i,i,i);
				}
			}
			delete pR;
			stop
		}
		//Задание 6.Конструктор + деструктор = функциональное
		// замыкание. Класс MyString
		// Посредством конструктора (конструкторов) и деструктора обеспечьте
		//корректные инициализацию и деактивацию объекта
		//C помощью остановов определите когда происходит
		//захват и освобождение памяти для строки-члена класса
		{
			MyString	str("It's my string!");
			//Создайте метод GetString(), который обеспечит доступ к хранящейся строке.
			//С помощью cout и метода GetString() распечатайте строку объекта str
			//Замечание: подумайте, как следует корректно реализовать метод GetString().
			const char* pStr = str.GetString();
			while (*pStr != '\0') {
				cout << *pStr;
				pStr++;
			}
			cout << endl;
		}
		stop

		//6a. Раскомментируйте следующий фрагмент. Подумайте - какие
		//неприятности Вас ожидают. Попробуйте исправить положение (как?)
			{
				MyString str1("The first string!"); //Два объекта будут указывать на одну строку
				MyString str2;
				str2  = str1;
				stop
			}
			stop

		//6б. Реализуйте метод SetNewString, который будет заменять строку
		// на новую

			MyString str("OldObjectString");
			str.SetNewString("ObjectString");

	//Задание 7.  Решите с помощью классов следующую задачу:
	//даны две бочки известного объема. В одной бочке в начальный момент
	//времени содержится спирт (96%), в другой – вода.
	//Кружкой емкостью 1л переливаем итеративно содержимое из одной бочки
	//в другую следующим способом: на каждой итерации
	//зачерпнули из первой бочки -> вылили во вторую
	//зачерпнули из второй бочки -> вылили в первую.
	//Требуется определить номер итерации, на которой концентрация спирта в
	//первой бочке станет меньше 50%.
	const float V = 50;

	Bochka spirt(96,V);
	Bochka water(0, V);
	int count = 0;
		while(spirt.GetConcentration()>50)
		{
			spirt.Pereliv(water,1); //или spirt.Pereliv(water, объем_кружки);
			water.Pereliv(spirt,1); // аналогично
			count++;
		}
		cout << count << endl;



	return 0;

}//end_main