#pragma once
#include <iostream>
class Point
{
	int m_left, m_right;
public:
	Point();
	Point(int a, int b);
	~Point();
	void InflatePoint(int a, int b);
	Point(const Point& a);
	void SetAll(int a, int b);
	void Get(int& a, int& b);
	void PointPrint();
	void operator=(const Point& a);
	friend std::ostream& operator<< (std::ostream& out, Point& a);
	friend std::istream& operator>> (std::istream& in, Point& a);
	friend bool operator==(const Point& a, const Point& b);
	friend class Circle;
};
class Circle
{
	Point dot;
	unsigned int radius;
public:
	Circle();
	Circle(Point& a, int b);
	~Circle();
	void Circle_Printer();
	void Circle_creator(int a, int b,unsigned int c);
	void operator=(const Circle& a);
	friend bool operator>(const Circle& a, const Circle& b);
	friend std::ostream& operator<< (std::ostream& out, Circle& a);
	friend bool operator==(const Circle& a, const Circle& b);
	friend std::istream& operator>> (std::istream& in, Circle& a);
};
class List
{
	class node
	{
		node* pPrev;		//указатель на предыдущий элемент
		node* pNext;		//указатель на следующий элемент
		Circle m_Data;
	public:
		node();
		~node();
		node(node* prev, const Circle &a);
		node(const Circle& a, node* prev);
		friend class List;
		friend std::ostream& operator<< (std::ostream& out, const List& a);
	};
	node head;
	node tail;
	int size;
public:
	List();
	~List();
	void head_adder(const Circle &a);
	void tail_adder(const Circle& a);
	void printer();
	void sorter();
	void file_reader();
	void file_writer();
	int delete_all(const Circle& a);
	bool remove(const Circle& a);
	friend std::ostream& operator<< (std::ostream& out,const List& a);
};

