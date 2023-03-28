#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include<cstdlib>
using namespace std;
class MyString
{
    char* m_pStr;	//строка-член класса
public:
	MyString()
	{
		m_pStr = 0;
    }
	MyString(const char* a);
	~MyString();
	const char* GetString()
	{
		return m_pStr;
	}
	MyString(const MyString& a)
	{
		m_pStr = new char[strlen(a.m_pStr) + 1];
		strcpy(m_pStr, a.m_pStr);
	}
	void SetNewString(const char* a) 
	{
		delete[] m_pStr;
		m_pStr = new char[strlen(a) + 1];
		strcpy(m_pStr, a);
	}
	void Printer()
	{
			cout << m_pStr << endl;
	}
	MyString& operator=(const MyString& a);
	MyString& operator=(const char* q);
	MyString& operator+=(MyString& a);
	friend std::ostream& operator<< (std::ostream& out, const MyString& p);
	friend MyString operator+(MyString& a, MyString& b);
};
