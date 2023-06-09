#include "myRect.h"
#include "myString.h"
#include <iostream>
#include "vld.h"


Rect BoundingRect(Rect a, Rect b)
{
	Rect c;
	int left1, left2, right1, right2, top1, top2, bot1, bot2;
	a.Get(left1, right1, top1, bot1);
	b.Get(left2, right2, top2, bot2);
	int lenth1 = left1 + right1 + left2 + right2;
	int width1 = ((top1 + bot1) > (top2 + bot2) ? top1 + bot1 : top2 + bot2);
	c.SetAll((lenth1 + 1) / 2, (lenth1 + 1) / 2, (width1 + 1) / 2, (width1 + 1) / 2);
	return c;	
}
Rect BoundingRect2(Rect& a, Rect& b)
{
	Rect c;
	int left1, left2, right1, right2, top1, top2, bot1, bot2;
	a.Get(left1, right1, top1, bot1);
	b.Get(left2, right2, top2, bot2);
	int lenth1 = left1 + right1 + left2 + right2;
	int width1 = ((top1 + bot1) > (top2 + bot2) ? top1 + bot1 : top2 + bot2);
	c.SetAll((lenth1 + 1) / 2, (lenth1 + 1) / 2, (width1 + 1) / 2, (width1 + 1) / 2);
	return c;
}

bool operator== (const A& c1, const A& c2)
{
	int q = 0;
	if (c1.m_n == c2.m_n)
	{
		for (int i = 0; i < c1.m_n; i++)
		{
			if (c1.m_p[i] == c2.m_p[i])
			{
				q++;
			}
		}
		if (q == c1.m_n)
		{
			return true;
		}

	}
}
Point operator--(Point& a)
{
	a.x--;
	a.y--;
	return(a);
}
Point operator--(Point& a, int)
{
	Point b(a);
	--a;
	return b;
}
template <typename T>
void Swap(T a, T b)
{
	T ab;
	ab = a;
	a = b;
	b = ab;
}
template <typename T>
void Swap(const T& a,const T& b)
{
	T ab;
	ab = a;
	a = b;
	b = ab;
}
template <typename T>
void Min(const T& a, const T& b)
{
	return (strcmp(a, b) < 0) ? a : b;
}
template <typename T>
void Min( T a,  T b)
{
	return (a<b) ? a : b;
}
int main()
{
	using namespace std;

	//������� 1.���������� ������. �������� ���������� ������.
	//����� ������� ������. 
	//�������� �������� Class View - (����� �� ������� ����� ������� �
	//������ - ������� Rect � MyString)
	//�������� �������� �� ����������� ����� �� ���� ������ ������ - ���
	//���������� ������������ ������� � ������� ����� ������.

	//����� ����������� ���������� ��� �������� ���������� ������?

	{
		MyArray<int, 5> arr; //������� ������ ������������ 5 ���� int
		MyArray<Rect, 6> arr2;

		std::cout << arr[2] << std::endl;
	}
	{
		Rect rect;
	}
	{
		Point pt1(1, 1), pt2, pt3;
		pt2 = pt1--;

		pt2 = --pt1;
	}
	//1a. �������� � ���������� ����������� � ����������� ���
	//������������� ���������� ������. �������� ��������� ������ Rect
	//� ������� ������������ � �����������. ���� ���������� ������
	//������ � ���������� ���������, ��������� - ���� ��� ��
	//�������? ��������� ���������� ������.
	//�������� ������� � ������ ������ �� �����, ����������:
	//� ����� ������ ���������� ����� ������������(������?)?
	{


		Rect f(-100000, 20, 30, 40);


		//���������: ������, ��� ������������ ������ ������ ����� ���������
		//� �������� ���������� ����� ��������!


		//1�. ��� ��������������� ������� ����������� ������������ ��� ����������
		//������������� ������������� ���������� ������, ��������, �����

		Rect sq;

		//1�. ��������, ���������� � �������� ����� ������ InflateRect(), 
		//������� ����������� ������� �������������� �� �������� ����������
		//(��������� ������� �� ������ - ������ ������� �� ���� ��������).
		//���������: �������� � ���������� ������ ����� �� ������ "�������",
		//�� � � ������� Wizard-a Class View. ��� �����: �������� ��������
		//ClassView ���� �������, �������� �������� ����� Rect � �������
		//������ ������ ���� - � ����������� ����������� ���� ��������
		//Add/Add Member Function... � ������� ����������� ���������� ������
		//"����� ��������" Wizard-� ��� �������� � ���������� �����.

		sq.InflateRect(2, 4, 6, 8);
	}
	//������� 2.���������� ������������� � ������� ������.
	//����������� �����������.
	{
		//2�.�������� � ���������� ����������� ����������� � ������ Rect.
		//�������� ������� �� �����, ����������, �����
		//����������� ���������� ��� �������� r1,r2,r3 � r4?
		//���� ����� ���������� ��������� ��������?
		Rect r1;
		Rect r2(1, 2, 3, 4);
		Rect r3;
		r3= r1;
		Rect r4(r2);



		//2�. �������� � ���������� � ������ Rect ����� InflateRect(),
		  //������� ��������� ��� ���������, �� ��������� ������ 1, � 
		  //���������� ������� �������������� �� �� �������� ����������.
		  //��� ����� �������� ���������� ������� InflateRect()?
		r1.InflateRect(1, 1);
		r2.InflateRect(2, 2);
		//����� �� ������� InflateRect() ���������� � ������ �� ���� �������?
		r3.InflateRect(2, 2, 2, 2);
		r3.InflateRect(3, 3);
		r3.InflateRect(5);
		r3.InflateRect();


	}

	//������� 3.������������� �������. ������������. 
	{
	Rect r;
	//���������������� ��������� ������. ��������� ������
	//�����������

	//int tmp = r.m_left;  �� ��������� ���������� ��������� � private ��� ���������� �������� ������������



	//������� � ����� Rect ����� void SetAll(...),
	//������� ����������� ���������� ������ ������������
	//��������. �������� ��������� �����, ��������� ������������. 
	r.SetAll(5, -5, 125, 625);

	//������� � ����� Rect ������ ����� GetAll(...),
	//������� "�������" �������� private-���������� ������.
	//�������� ��������� �����, ��������� ������������. 
	int inf[4];
	r.GetAll(inf);

	for (int i = 0; i < 4; i++)
	{
		cout << inf[i] << ' ';
	}
	
	}


	//������� 4.�������� ���������� ������ � �������� ���������
	//�������. ����������� ������� ������ �� ��������. ��������
	//�������� � ������������ ����������� ��� �������� ��������
	//�� �����, ����������: � ����� ������ ���������� ���������
	//� ������������ �����������. 
	//�������� ���������� ������� 
	// Rect BoundingRect(Rect, Rect);
	//������� ��������� ��� ������� ������ Rect �� �������� �
	//���������� ������ ������ Rect, ������� �������� ���������������,
	//� ������� ������� �������� ��������������. ��� ����������
	//�������� ���������� � ����������� ������� ������?


	//���������*: ������ ���� �� ������ ��� ����, ��� �������������
	//����� ��������� "�����������������", �� ���� m_left>m_right ���/�
	//m_top>m_bottom

	{

		Rect r1(1,2,3,4), r2(5,6,7,8),r3;
		r3= BoundingRect(r1, r2);
	
	
	//������� 4�. �������� �������� �� ������.
	//�������� ���������� ������� BoundingRect2, ������� ��������� �� ��
	//������, �������� ��������� �� ������
	//���������� �� ������������ ��� �������� ����������?
	

	r3 = BoundingRect2(r1, r2);
	
	}

	


	//������� 5. ����� ���������� ������������ � �����������.
	//�������� � ����������
	//����� ���������� ������. ��������� �������� � 
	//������������ (�������������) � �����������. ����������: ����� ���
	//������� �� �������� ���������� �����������, � ����� - ����������?
	{
		Rect r1;
		Rect*	pR = new Rect(1,2,1,2);	
		{
			Rect r2(r1);
			Rect* arRect[2];  // 2 default
			for(int i=0; i<2; i++)
			{
				 Rect r3 (i,i,i,i) ;
				 static Rect r4(*pR);  // �� ������ ��. copy
				Rect r5(i,i,i,i);
			}
		}
		delete pR;	
		
	}


	//������� 6.����������� + ���������� = ��������������
	// ���������. ����� MyString
	// ����������� ������������ (�������������) � ����������� ����������
	//���������� ������������� � ����������� �������
	//C ������� ��������� ���������� ����� ����������
	//������ � ������������ ������ ��� ������-����� ������
	{
		MyString	str("It's my string!"),str22;
		MyString str33(str22);
		str33 = str;
		//�������� ����� GetString(), ������� ��������� ������ � ���������� ������.
		//� ������� cout � ������ GetString() ������������ ������ ������� str
		//���������: ���������, ��� ������� ��������� ����������� ����� GetString().
		const char* string=str.GetString();
		while (*string != 0)
		{
			cout << *string;
			string++;
		}
		//...
	}
	


		//6a. ���������������� ��������� ��������. ��������� - �����
		//������������ ��� �������. ���������� ��������� ��������� (���?)
	{
		MyString str1("The first string!");//������ ��������� ���� � �� �� ������ ������ �.� ���������� ��������� 
			MyString str2=str1;
			
	}
		

	//6�. ���������� ����� SetNewString, ������� ����� �������� ������
	// �� �����

	
	{

	MyString	str("It's");
	char q[] = "ha";
	str.SetNewString(q);
	}
		
	
	




	//������� 7.  ������ � ������� ������� ��������� ������:
	//���� ��� ����� ���������� ������. � ����� ����� � ��������� ������
	//������� ���������� ����� (96%), � ������ � ����.
	//������� �������� 1� ���������� ���������� ���������� �� ����� �����
	//� ������ ��������� ��������: �� ������ ��������
	//���������� �� ������ ����� -> ������ �� ������
	//���������� �� ������ ����� -> ������ � ������.
	//��������� ���������� ����� ��������, �� ������� ������������ ������ �
	//������ ����� ������ ������ 50%.

	Bochka first(96);
	Bochka second(0);
	Bochka check(50);
	double a, b;
	int counter = 0;
	//]���� ����� 100 ������
	
	while(first.get(a)>check.get(b))
	{
		counter++;
			first.Pereliv(second); //��� spirt.Pereliv(water, �����_������);
			second.Pereliv(first); // ����������
	    }
	cout << endl << counter<<endl;
return 0;

}//end_main

