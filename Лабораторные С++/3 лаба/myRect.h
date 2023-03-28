#pragma once
#include <iostream>
using namespace std;
class Point
{
	int x, y;
public:
	Point()
	{
		x = 0;
		y = 0;
	}
	Point(int a)
	{
		x = a;
		y = a;
	}
	Point(int a, int b)
	{
		x = a;
		y = b;
	}
	~Point()
	{
		x = 0;
		y = 0;
	}
	Point(const Point& a)
	{
		x = a.x;
		y = a.y;
	}
	void Printer()
	{
		cout << "( " << x << " , " << y << " )"<<endl;
	}
	Point operator+();
	Point operator-();
	Point operator+(const Point& a);
	Point operator+(int a);
	Point& operator +=(Point& a);
	Point& operator +=(int a);
	friend Point operator+(int a, Point& b);
	friend Point operator-(Point a,Point& b);
	friend Point operator-(Point a, int b);
	friend Point operator-=(Point& a, Point& b);
	friend Point operator-=(Point& a, int b);
	friend Point operator--(Point& a);
	friend Point operator--(Point& a, int);
};
