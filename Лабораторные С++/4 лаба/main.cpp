#define _CRT_SECURE_NO_WARNINGS
#include <tchar.h>
#include <fstream>
#include "myRect.h"
#include <iostream>
#include <cstdarg>
#include <utility>
#include"vld.h"


int main()
{
	setlocale(LC_ALL, "Russian");
	using namespace std;
	List spisok;
	bool o = true;
	char action = '9', action1;
	int a, b=0, c=0;
	Circle tempor_c;
	Circle check;
	while (o)
	{
		cout << std::endl << "������� ����������� ������� " << std::endl;
		if (b != 0) { cin >> action; }
		switch (action)
		{
		case'0':
			o = false;
			break;
		case'1':
			cout << spisok;
			break;
		case'3':
			cin >> tempor_c;
			if (spisok.remove(tempor_c) == true)
			{
				printf("������� ��� ������ � ������\n");
			}
			else
			{
				printf("������� �������� ��� � ������\n");
			}
			break;
		case '2':
			cout << "��� ���������� �������� � ������ ������ ������� 1" << std::endl << "��� ���������� �������� � ����� ������ ������� 2" << std::endl;
			cin >> action1;
			switch (action1)
			{
			case'1':
				printf("�������� ���������� � ������ ����������\n");
				std::cin >> tempor_c;
				if (tempor_c == check) { printf("��������, �� ����� ����������� ��������\n"); break; }
				spisok.head_adder(tempor_c);
				break;
			case'2':
				printf("�������� ���������� � ������ ����������\n");
				std::cin >> tempor_c;
				spisok.tail_adder(tempor_c);
				break;
			default:
				std::cout << "������. ���������� ������� ������ �������" << std::endl;
				break;
			}
			break;
		case'4':
		{
			cin >> tempor_c;
			a=spisok.delete_all(tempor_c);
			if (a > 0)
			{
				printf("�������� ������� �������\n");
				printf("���������� ��������� ��������� ");
				cout << a<<endl;
			}
			else
			{
				printf("������� �������� ��� � ������\n");
			}
			a = 0;
			break;
		}
		case'5':
		{
			spisok.~List();
			printf("������ ������� ��������\n");
			break;
		}
		case '6':
			spisok.sorter();
			printf("������ ������� ������������\n");
			break;
		case'7':
			spisok.file_writer();
			break;
		case'8':
			spisok.file_reader();
			break;
		case'9':
			printf("������ ������:\n");
			printf("'1'- ������� ������\n");
			printf("'2' - �������� �������\n");
			printf("'3' - �������� �� ������ ������� ��������, ������ �������� ��������� �� ��������� ���������\n");
			printf("'4' - �������� �� ������ ���� ���������, ������ ������� ��������� �� ��������� ���������\n");
			printf("'5' - ��������� ������\n");
			printf("'6' - ���������� �������� �� �������� �������� �����������\n");
			printf("'7' - ����� ������ � ��������� ����\n");
			printf("'8' - ������ ��������� � ������ ������ �� �����\n");
			printf("'9' - ����� ������ ����������\n");
			printf("'0' - ���������� ������ ���������\n");
			b++;
			break;
		default:
			std::cout << "������. ���������� ������� ������ �������" << std::endl;
			break;
		}
	}
return 0;

}//end_main

