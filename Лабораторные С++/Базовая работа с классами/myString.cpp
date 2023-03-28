#define _CRT_SECURE_NO_WARNINGS
#include <string>
#include "myString.h"
using namespace std;

// Определение конструктора.
MyString::MyString(const char* pStr) {
	m_pStr = new char[strlen(pStr) + 1];
	strcpy(m_pStr, pStr);
	//m_pStr = const_cast<char*>(pStr);
}
// Опредеоение деструктора.
MyString::~MyString() {
	//m_pStr = 0;
	delete[] m_pStr;
}
MyString::MyString(MyString& other) {
	if (other.m_pStr != nullptr) {
		m_pStr = new char[strlen(other.GetString()) + 1];
		strcpy(m_pStr, other.GetString());
	}
	else other.m_pStr = 0;
}
void MyString::SetNewString(const char* new_str) {
	delete[] m_pStr;
	m_pStr = new char[strlen(new_str) + 1];
	strcpy(m_pStr, new_str);
}


