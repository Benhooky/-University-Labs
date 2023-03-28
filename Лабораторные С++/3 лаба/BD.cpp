#include "BD.h"
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include<cstdlib>
using namespace std;
person::person()
{
	name = 0;
	age = 0;
	paymanet = 0;
	position = beginner;
}
person::person(const char* nam, unsigned int ag, unsigned int pay, N_TYPE pos)
{
	if (nam != 0)
	{
		age = ag;
		paymanet = pay;
		position = pos;
		name = new char[strlen(nam) + 1];
		strcpy(name, nam);
	}
	else
	{
		age = ag;
		paymanet = pay;
		position = pos;
	}
}
person::person(unsigned int ag, unsigned int pay, N_TYPE pos)
{
	name = 0;
	age = ag;
	paymanet = pay;
	position = pos;
}
person::person(const char* nam)
{
	name = new char[strlen(nam) + 1];
	strcpy(name, nam);
}
person::~person()
{
		delete name;
}
person::person(const person& a)
{
	name = new char[strlen(a.name) + 1];
	strcpy(name, a.name);
	age = a.age;
	paymanet = a.paymanet;
	position = a.position;
}
void person::printer(int i)
{
	std::cout << i+1<< "|" << name << " |" << age << " |" << paymanet << " |" << position << " |" << std::endl;
}
person& person::operator=(person a)
{
	if (a.name != 0)
	{
		age = a.age;
		paymanet = a.paymanet;
		position = a.position;
		name = new char[strlen(a.name) + 1];
		strcpy(name, a.name);
		return *this;
	}
	else
	{
		age = a.age;
		paymanet = a.paymanet;
		position = a.position;
		return *this;
	}
}
std::ostream& operator<< (std::ostream& out, BD& a)
{
	for (int i = 0; i < a.size; i++)
	{
		a.mass[i]->printer(i);
	}
	return out;
}
BD::BD()
{
	size = 0;
	mass = new person * [size];
}
BD::~BD()
{
	for (int i = 0; i < size ; i++)
	{
		delete mass[i];
	}
	delete[] mass;
	size = 0;
}
BD::BD(const BD& a)

{
	//вопрос
	for (int i = 0; i < size; i++)
	{
		delete mass[i];
	}
	size = a.size;
	person** q = new person * [size];
	for (int i = 0; i < size; i++)
	{
		q[i] = new person;
	}
	for (int i = 0; i < size; i++)
	{
		*q[i] = *a.mass[i];
	}
	delete[] mass;
	mass = q;
}
void BD::move(BD& other)
{
	for (int i = 0; i < size; i++)
	{
		delete mass[i] ;
	}
	delete[] mass;
	size = other.size;
	for (int i = 0; i < size; i++)
	{
		mass[i] = other.mass[i];
	}
	mass = other.mass;
	other.size = 0;
	other.mass=nullptr;
}
BD& BD::operator=(BD& a)
{
	for (int i = 0; i < size; i++)
	{
		delete mass[i];
	}
	size = a.size;
	person** q = new person * [size];
	for (int i = 0; i < size; i++)
	{
		q[i] = new person;
	}
	for (int i = 0; i < size ; i++)
	{
		*q[i] = *a.mass[i];
	}
	delete[] mass;
	mass = q;
	return *this;
}

person& BD::operator[](const char* a)
{
	for (int i = 0; i < size; i++)
	{
		if (mass[i]->name == a)
		{
			return *mass[i];
		}
	}
	this->Employ(a);
	return *mass[size-1];
}
void BD::Show(int a)
{
	switch (a)
	{
	case 1:
		cout << "| Full |" << endl;
		for (int i = 0; i < size; i++)
		{
			mass[i]->printer(i);
		}
		break;
	case 2:
		cout << "| Age |" << endl;
		for (int i = 0; i < size; i++)
		{
			cout <<mass[i]->name<< " |"<< mass[i]->age<<endl;
		}
		break;
	case 3:
	{
		cout << "| Pay |" << endl;
		for (int i = 0; i < size; i++)
		{
			cout << mass[i]->name << " |" << mass[i]->paymanet<<endl;
		}
		break;
	}
	case 4:
	{
		cout << "| Pos |" << endl;
		for (int i = 0; i < size; i++)
		{
			cout << mass[i]->name << " |" << mass[i]->position<<endl;
		}
		break;
	}
	default:
		cout << "Wrong type" << endl;
		break;
	}
}
void BD::Employ(const char* nam)
{
	size++;
	person** q = new person * [size];
	for (int i = 0; i < size - 1; i++)
	{
		q[i] = mass[i];
	}
	delete[] mass;
	mass = q;
	mass[size - 1] = new person;
	person chance(nam);
	*mass[size - 1] = chance;
}
void BD::Employ(const char* nam, unsigned int ag, unsigned int pay, N_TYPE pos)
{
	size++;
	person** q = new person*[size];
	for (int i = 0; i < size-1;i++)
	{
		q[i] = mass[i];
	}	
	delete[] mass;
	mass = q;
	mass[size-1] = new person;
	person chance(nam, ag, pay, pos);
	*mass[size-1] = chance;
}
void BD::fire(int a)
{
	size--;
	person** q = new person * [size];
	for (int i = 0; i < a - 1; i++)
	{
		q[i] = mass[i];
	}
	for (int i = a-1; i < size ; i++)
	{
		q[i] = mass[i+1];
	}
	delete mass[a-1];
	delete[] mass;
	mass = q;
}