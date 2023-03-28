#include <fstream>
#include "myRect.h"
Point::Point()
{
	m_left = 0;
	m_right = 0;

}
Point::Point(int a, int b)
{
	m_left = a;
	m_right = b;

}
Point::~Point()
{
	m_left = 0;
	m_right = 0;

}
void Point::InflatePoint(int a, int b)
{
	m_left += a;
	m_right += b;

}
Point::Point(const Point& a)
{
	m_left = a.m_left;
	m_right = a.m_right;

}
void Point::SetAll(int a, int b)
{
	m_left = a;
	m_right = b;

}
void Point::Get(int& a, int& b)
{
	a = m_left;
	b = m_right;
}
void Point::PointPrint()
{
	std::cout << "( " << m_left << " ," << m_right << " )" ;
}
std::ostream& operator<< (std::ostream& out, Point& a)
{
	out<< "( " << a.m_left << " ," << a.m_right << " )";
	return out;
}
std::istream& operator>> (std::istream& in, Point& a)
{
	in >> a.m_left >> a.m_right;
	return in;
}
void Point::operator=(const Point& a)
{
	m_left=a.m_left;
	m_right=a.m_right;
}
Circle::Circle()
{
	Point dot(0, 0);
	radius = 0;
}
Circle::~Circle()
{
	radius = 0;
}
Circle::Circle(Point& a, int b)
{
	dot.m_left = a.m_left;
	dot.m_right = a.m_right;
	radius = b;
}
void Circle::Circle_creator(int a, int b,unsigned int c)
{
	dot.SetAll(a, b);
	radius = c;
}
void Circle::Circle_Printer()
{
	dot.PointPrint();
	std::cout << "radius = " << radius;
}
void Circle::operator=(const Circle& a)
{
	dot = a.dot;
	radius = a.radius;
}
bool operator>(const Circle& a, const Circle& b)
{
	if (a.radius > b.radius)
	{		
		return true;
	}
	return false;
}
std::ostream& operator<< (std::ostream& out, Circle& a)
{
	out << a.dot;
	out<< "radius = " << a.radius;
	return out;
}
std::istream& operator>> (std::istream& in, Circle& a)
{
	in >> a.dot;
	in >> a.radius;
	return in;
}
List::node::node()
{
	pPrev = nullptr;
	pNext = nullptr;
	m_Data;
}
List::node::node(node* prev, const Circle &a)
{
	m_Data = a;
	pNext = prev->pNext;
	prev->pNext = this;
	pPrev = prev;
	pNext->pPrev = this;
}
List::node::node(const Circle& a,node* next)
{
	m_Data = a;
	pPrev = next->pPrev;
	next->pPrev = this;
	pNext = next;
	pPrev->pNext = this;
}
List::node::~node()
{
	if (pPrev)
	{
		pPrev->pNext = pNext;
	}
	if (pNext)
	{
		pNext->pPrev = pPrev;
	}
	pNext = nullptr;
	pPrev = nullptr;
}
List::List()
{
	head.pNext = &tail;
	tail.pPrev = &head;
	size = 0;
}
void List::head_adder(const Circle &a)
{
	node *tmp=new node(&head, a);
	size++;
}
void List::printer()
{
	std::cout << " Spisok list :" << std::endl;
	node* q = head.pNext;
	for (int i = 0; i < size; i++)
	{
		while (q->pNext != 0)
		{
			node* qq = q->pNext;
			q->m_Data.Circle_Printer();
			q = qq;
			std::cout << std::endl;
		}
	}
}
bool List::remove(const Circle& a)
{
	node* q = head.pNext;
	for (int i = 0; i < size; i++)
	{
		node* qq = q->pNext;
		if (q->m_Data == a)
		{
			delete q;
			size--;
			return true;
		}
		q = qq;
	}
	return false;
}
bool operator==(const Point& a, const Point& b)
{
	if ((a.m_left == b.m_left) && (a.m_right == b.m_right))
	{
		return true;
	}
	else return false;
}
bool operator==(const Circle& a, const Circle& b)
{
	if ((a.dot == b.dot) && (a.radius == b.radius))
	{
		return true;
	}
	else return false;
}
int List::delete_all(const Circle& a)
{
	int count = 0;
	while (remove(a) == true)
	{
		count++;
	}
	return count;
}
List::~List()
{
	node* q = head.pNext;
	for (int i = 0; i < size; i++)
	{
		while (q->pNext != 0)
		{
			node* qq = q->pNext;
			delete q;
			q = qq;
		}
	}
	size = 0;
}
void List::tail_adder(const Circle& a)
{
	node* tmp = new node(a,&tail);
	size++;
}
void List::sorter()
{
	node* tmp1 = head.pNext;
	node* temp=tmp1->pNext;
	node* temporary;
	for (int i = 0; i < size -1; i++) {
		for (int j = 0; j < size - i-1 ; j++) {
			if ((tmp1->m_Data)>(temp->m_Data) )
			{
				tmp1->pPrev->pNext = temp;
				temp->pNext->pPrev = tmp1;
				temp->pPrev = tmp1->pPrev;
				tmp1->pNext = temp->pNext;
				tmp1->pPrev = temp;
				temp->pNext = tmp1;

				temporary = tmp1;
				tmp1 = temp;
				temp = temporary;
				tmp1 = temp;
				temp = tmp1->pNext;
				printer();
			}
			else
			{
				tmp1 = temp;
				temp = tmp1->pNext;
			}
		}
		tmp1 = head.pNext;
		temp = tmp1->pNext;
		printer();

	}
}
std::ostream& operator<< (std::ostream& out,const List& a)
{
	out << " Вывод списка :" << std::endl;
	List::node* q = a.head.pNext;
	for (int i = 0; i < a.size; i++)
	{
		while (q->pNext != 0)
		{
			List::node* qq = q->pNext;
			out<<q->m_Data;
			q = qq;
			out << std::endl;
		}
	}
	return out;
}
void List::file_reader()
{
	std::ifstream fin("fas.txt");
	Circle okr;
	while (fin >> okr)
	{
		(*this).head_adder(okr);
	}
	std::cout <<"Файл после добавления: "<<std::endl<< *this;
	fin.close();
}
void List::file_writer()
{
	std::cout << "Введите имя файла вывода  - ";
	char ar[80];
	std::cin >> ar;
	std::ofstream fout(ar);
	fout << "Файл вывода: "<<std::endl<< *this << std::endl;
	fout.close(); 
}