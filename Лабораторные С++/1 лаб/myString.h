#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
class MyString
{
    char* m_pStr;	//строка-член класса
public:
	MyString()
	{
		m_pStr = 0;
    }
	MyString(const char*);
	~MyString();
	const char* GetString()
	{
		return m_pStr;
	}
	MyString(const MyString& a)
	{
		if (m_pStr != nullptr)
		{
			m_pStr = new char[strlen(a.m_pStr) + 1];
			strcpy(m_pStr, a.m_pStr);
		}	
		else
		{		
			m_pStr = nullptr;
		}
	}
	void SetNewString(const char* a) 
	{
		delete[] m_pStr;
		m_pStr = new char[strlen(a) + 1];
		strcpy(m_pStr, a);
	}
};
