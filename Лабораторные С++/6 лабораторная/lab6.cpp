/*************************************************************
	������������ ������� �5. ���������
//������������ ������ ��������
//�����
//����������
//���������� � �����
//������ �� �����
*************************************************************/

#define _CRT_SECURE_NO_WARNINGS
#include <tchar.h>
#include <iostream>
#include <cstdio>
#include "book.h"
#include "Kartoteka.h"
#include "input.h"
#include "vld.h"
#include "sorter.h"
#include< string.h >
#include<cmath>
#define	  stop __asm nop	




int main()
{
	//����������� ��������� BOOK, ��������� � ���������� ������.
	//��� ����� ���������� ���������� � ���������� � ������� �����
	//book.h � book.cpp
	setlocale(LC_ALL, "Russian");
	//������� 1. ������� ����������.
	//���������� - ��� ������ �������� => ����� ����� ������ �������.
	//���������: ������ ������� �������� ������������� ���� ���������� ���� =>
	//������ ������ ���� ����� ������???
	BOOK l;
	Library biblio;
	int N,D;
	N = sizeof(l);
	std::cin >> N;//���������� ���� ������� �� ����� ������ �� ���
	biblio.number = N;
	biblio.Spisok = new BOOK[N];
  bool(*sortart)(BOOK**&vec, int vard) = &sort_article;
  bool(*sortau)(BOOK**&vec, int vard) = &sort_author;
  bool(*sortcat)(BOOK**&vec, int vard) = &sort_category;
  bool(*sortage)(BOOK**&vec, int vard) = &sort_age;
  bool(*sortcost)(BOOK**&vec, int vard) = &sort_cost;
  bool(*func_mas[5])(BOOK**&vec, int vard){ sortart, sortau, sortcat, sortage, sortcost };
	BOOK** vec = new BOOK*  [N];
	for (int i = 0; i < N; i++)
	{
		vec[i] = &(biblio.Spisok[i]);
	}

	char action, action1;
	for (int i = 0; i < N; i++)
	{
		form_book(vec[i]);
		book_printer(vec,i);
		std::cout << std::endl;
	}
	bool o = true;
	
	printf("������ ������:\n");
	printf("'1'- ������� ���������\n");
	printf("'2' - �������� � ��������� ����� �����\n");
	printf("'3' - ������� ����� ��� �������� ����\n");
	printf("'4' - �������� ��������� � ����\n");
	printf("'5' - ��������� ��������� �� �����\n");
	printf("'6' - ������� ����� ������������ ���������\n");
	printf("'7' - ������������� ��������� �� ���������� ����\n");
	printf("'8' - ������� �������� ����\n");
	printf("'9' - ��������� ������ ���������\n");
	while (o)
	{
		std::cout << std::endl << "������� ����������� ������� "<<std::endl;
		std::cin >> action;
		switch (action)
		{
		case'0':
			o = false;
			break;
		case'1':
			biblio_printer(biblio,vec);
			break;
		case'2':
			book_adder(biblio.number, biblio.Spisok,vec);
			break;
		case '3':
			std::cout << "��� �������� ����� ������� 1, ���� �� ������ ������� �������� ����, ������� 2" << std::endl;
			std::cin >> action1;
			switch (action1)
			{
			case'1':
				std::cout << "�������� ����� ��������� �����\n";
				std::cin >> N;
				if ((N > biblio.number) || (N < 0) )
				{
					std::cout << "����� ����� �� ����������"; 
					break;
				}
				book_deleater(N, biblio.number, biblio.Spisok,vec);
				break;
			case'2':
				std::cout << "�������� �������� ��������� ����\n";
				std::cin >> N >> D;
				if ((N > biblio.number)||(D >biblio.number)||(N<0)||(D<0))
				{
					std::cout << "������ ��������� ���� �� ����������"; 
					break;
				}
				book_deleater(N, D, biblio.number, biblio.Spisok,vec);
				break;
			default:
				std::cout << "������. ���������� ������� ������ �������" << std::endl;
				break;
			}
			break;
		case'4':
		{
			FILE* fs = fopen("cart.txt", "wt");
			if (fs == 0)
			{
				perror("�� ���� ������� ���� ��� ������");
				break;
			}
			for (int i = 0; i < biblio.number; i++)
			{
				book_printerf(fs,vec,i);
				std::cout << std::endl;
			}
			fclose(fs);
			break;
		}
		case'5':
		{
			
			FILE* fs = fopen("cart.txt", "r");
			if (fs == 0)
			{
				perror("�� ���� ������� ���� ��� ������");
				break;
			}
			BOOK be;
			BOOK* ar = &be;
			int k = countNumberOfLines(fs)/ 5;
			fs = fopen("cart.txt", "r");
			if (!feof(fs))
			{
				for(int i=0;i<k;i++)
				{
					add(biblio.number, biblio.Spisok,vec);
					file_reader(fs, biblio.Spisok, biblio.number);
					vec[biblio.number-1] = &biblio.Spisok[biblio.number-1];
				}		
				fclose(fs);
			}
			break;
		}
		case '6':
			int a;
			std::cout << "������� ����������� ���������" << std::endl;
			std::cin >> a;
			if ((a == 1) || (a == 0)) 
			{ 
				std::cout << "���� ������ ��������� " << category_scorer(biblio.Spisok, biblio.number, a)<<std::endl; 
			}
			else
				{
				std::cout << "�������� ���������" << std::endl;
				}
			break;
		case'7':
			int ab;
			std::cout << "�� ������ ���� �� ������ �������������?" << std::endl;
			std::cin >> ab;
			if ((ab > 5) || (ab < 1) || biblio.number < 1)
			{
				std::cout << "�� ����� �������������� ���������, ���� ���������� ���� � ���������� ����� 0";
				break;
			}
			uni_puzirek(ab,biblio.number,func_mas ,vec );
			break;
		case'8':
			printf("������ ������:\n");
			printf("'1'- ������� ���������\n");
			printf("'2' - �������� � ��������� ����� �����\n");
			printf("'3' - ������� ����� ��� �������� ����\n");
			printf("'4' - �������� ��������� � ����\n");
			printf("'5' - ��������� ��������� �� �����");
			printf("'6' - ������� ����� ������������ ���������\n");
			printf("'7' - ������������� ��������� �� ���������� ����\n");
			printf("'8' - ������� �������� ����\n");
			printf("'9' - ��������� ������ ���������\n");
			break;
		case'9':
			o = false;
			break;
		default:
			std::cout << "������. ���������� ������� ������ �������" << std::endl;
			break;
		}
	}
	delete[] vec;
	delete[] biblio.Spisok;

	//������������ ������ ����� ����������� �� ������ ������� ���������
	//������ �������� � ���������� => ����� ����� ����������� ���
	//������������: ��� ����� ��������� ��� ����� "����" (��������
	//��������� �������� � ��������������� ������� ������������), ��������:
	//����������� ���������� ��������� (1)
	//������ ����� ����� (2)
	//������� ������������(��) (3)
	//�������� ������� ���������� ��������� � ���� (4)
	//������� �� ����� ���������� � ��������� (5)
	//...
	//����� �� ��������� (...)


	//���������� ����������� ������� ������ ����������� ������ � ����������




	//���������1: ��� ��������� �����/������ ����������� ������� fprintf � fscanf
	//(������������ ���� <cstdio>



	// ���������2: ������ � �������� ������� ������� � ����� ������� ����������
	// ���� � ���������
	//���� ���� ���������� � ��� ������� �������
	//if()
	//{
	//������ ������ �� �����
	//�) ������� ���������� ���������
	//�) ������� ������ ��������� �����������
	//�) ������� ������ �� ����� � ������
	//}




	//****************************************************************
	//������� 2. ������������ ������������ ����������� �������� �������� ����
	//� ������������ ������� => �������� ������� (�������) ���������� �������
	//�� ������ �� ����� ���������.
	//���������: ������� - "�� ������ ���� ���������" ����� ������ � �������
	//������������.
	return 0;

}