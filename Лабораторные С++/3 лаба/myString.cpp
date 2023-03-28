#define _CRT_SECURE_NO_WARNINGS
#include <string>
#include "myString.h"
using namespace std;

// Определение конструктора.

MyString::MyString(const char* q)
{
	m_pStr = new char[strlen(q)+1];
	strcpy(m_pStr, q);
}
// Определение деструктора.
MyString::~MyString()
{
	delete[] m_pStr;
}
MyString& MyString::operator=(const MyString& a)
{
	if (this == &a) { return *this; };
	if (a.m_pStr == nullptr) 
	{ 
		delete[] m_pStr;
		m_pStr = 0; 
	}
	else 
	{
		delete[] m_pStr;
		m_pStr = new char[strlen(a.m_pStr) + 1];
		strcpy(m_pStr, a.m_pStr);
	}
	return *this;
	//вопрос
}
MyString& MyString::operator=(const char* q)
{
	delete[] m_pStr;
	m_pStr = new char[strlen(q) + 1];
	strcpy(m_pStr, q);
	return *this;
}
MyString& MyString::operator+=(MyString& a)
{
	if ((m_pStr != 0) && (a.m_pStr != 0))
	{
		int size = strlen(a.m_pStr) + strlen(m_pStr);
		char* wholestr = new char[size + 1]{ 0 };
		strcat(wholestr, m_pStr);
		strcat(wholestr, a.m_pStr);
		*this = wholestr;
		delete[] wholestr;
	}
	else if (m_pStr==0)
	{
		*this = a;
	}
	return *this;
}
std::ostream& operator<< (std::ostream& out, const MyString& p)
{
	out << "contents: " << "\"" << p.m_pStr << "\""<<endl;
	return out;
}