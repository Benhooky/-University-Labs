// ����:
// ���������� ����������.
// ���������� ������� 
#define _CRT_SECURE_NO_WARNINGS
#include <tchar.h>
#include "myString.h"
#include "myRect.h"
#include "BD.h"
#include <iostream>
#include <cstdarg>
#include <utility>
#include"vld.h"
//#include "stdafx.h"	//���� �� ����������� �������������� ������������
					//������, ���������������� ��� �������

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



	//������� 1.���������� ����������.

	//���������� � ������� ����� MyString.cpp � MyString.h
	//������ MyString, �������������� ���� �� ���������� �������
	//9a. ����������� �������� ������������ ��� ������ MyString
	//��������� ������������ ������ �������������� ���������

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




	//2.�������� ����� Point, ������� ����� ��������� ����������
	//"�����". �������� ����������� (������������) ������   

	//2b. "�����������" �������� += ���, ����� ��� ����������
	//�������� ���� pt2+=pt1; ������������
	//����������� ���������� �������� pt1 � pt2, � �����
	//������������� ��������������� ���������� ������� pt2 ���
	// � ������  pt2+=1; ��� ���������� ������� pt2 ������������� ��
	// ��������� ��������
	//a) � ������� ������ ������ (�������� +=)
	//�) � ������� ���������� ������� (�������� -=)
	//��������� ������������ ������ �������������� ���������
	{
		Point pt1(1, 1);
		Point pt2(2, 2);
		pt2 += pt1+pt2+=pt1;
		pt2.Printer();
		//�������
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




	//������� 2c. ����������� �������� +/- 
	//a)� ������� ������� ������ (�������� +)
	//�) � �������  ���������� ������� (�������� -)
	//���, ����� ����� �� ������������������ �����
	//���� ����������� ���������
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

		//������� 1d. ����������� ������� �������� +/- 
		pt3 = -pt1;
		pt3.Printer();
		pt3 = +pt1;
		pt3.Printer();
		//������� 1d. ����������� ������� �������� +/- 
		pt3 = -pt1;
		pt3.Printer();
		pt3 = +pt1;
		pt3.Printer();
	}



	//������� 2d. ����������� �������� << (������ � �����) ���
	//������ MyString ����� �������, ����� ��� ���������� ����������� ������
	//�� ����� ���� ��������:
	//contents:  "QWERTY"
	{
		MyString s("QWERTY");
		cout << s << endl;
	}



	

//������� 2e*. ����������� ��������� + � += ��� ������ MyString ����� �������,
  //����� ����������� ������������ �����
	MyString s1("QWERTY"), s2("AAA"), s3, s4("BBB");
	s3 = s1+s2;
	s3.Printer();
	s4 += s1; 
	s4.Printer();
	


	//������� 3. ����������� "���� ������" � ����������� ����������� ��������������
	//�������. ������ �������� ������� (���� � ������� ��������, ������� ���������� ��������
	//� ���� ���� �� �����), � �������: ���, �������, ���������, ��������...
	//����������:
	//���������� ����������� � ����
	//����������
	//����� ���������� � ���������� ����������
	//����� ���� (��� ������������) ���������� � ���� �����������
	//��������:
	
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


		BD bd;	//�������� ������ ����
		bd["Ivanov"] = Data(30, 12222, beginner);	//���� Ivanov-� � ���� ��� ���, ��
						//����������, ���� ��� ����, �� ������ ��� ����������
		std::cout << bd;	//����� ���������� ��� ���� �����������
		std::cout << a;

		//� �����:
		BD bdnew = bd;
		bdnew = bd;
		std::cout << bdnew;
		bdnew = bd;

		//� ����� ��������� �����������:
		BD bdmove;
		bdmove.move(bdnew);
		std::cout << bdnew;
		std::cout << bdmove;
	}

	
	return 0;
}//endmain

