#define _CRT_SECURE_NO_WARNINGS
#include <string>
#include "myString.h"
using namespace std;

// ����������� ������������.

MyString::MyString(const char* q)
{
	m_pStr = new char[strlen(q)+1];
	strcpy(m_pStr, q);
}

// ����������� �����������.
MyString::~MyString()
{
	delete[] m_pStr;
}

