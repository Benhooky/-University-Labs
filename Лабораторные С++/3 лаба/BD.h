#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include<cstdlib>
enum N_TYPE {fired, beginner, middle, header };
class person
{
	char* name;
	unsigned int age;
	unsigned int paymanet;
	N_TYPE position;
public:
	person();
	person(const char* nam, unsigned int ag, unsigned int pay, N_TYPE pos);
	person(const char* nam);
	~person();
	person(const person& a);
	person(unsigned int ag, unsigned int pay, N_TYPE pos);
	person& operator=(person a);
	void printer(int i);
	friend person Data( int a, int b, N_TYPE c);
	friend class BD;
	
};
class BD
{
	int size;
	person** mass;
public:
	BD();
	~BD();
	void Show(int a);
	BD(const BD& a);
	void move( BD& other);
	void Employ(const char* nam, unsigned int ag, unsigned int pay, N_TYPE pos);
	void Employ(const char* nam);
	void fire(int a);
	friend std::ostream& operator<< (std::ostream& out, BD& a);
	BD& operator=(BD& a);
	person& operator[](const char* a);
	friend class person;
};

