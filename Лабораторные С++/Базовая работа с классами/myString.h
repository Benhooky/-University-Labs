#pragma once
class MyString
{
    char* m_pStr;	//строка-член класса
public:
	MyString() {
		m_pStr = nullptr;
	}
	~MyString();
	const char* GetString() {
		return m_pStr;
	}
	MyString(MyString& other);
	MyString(const char* pStr);
	void SetNewString(const char*);
};
