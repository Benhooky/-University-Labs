#include "myRect.h"
Point& Point::operator+=(Point& a)
{
	x += a.x;
	y += a.y;
	return *this;
}
Point& Point::operator+=(int a)
{
	x += a;
	y += a;
	return *this;
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

Point Point::operator+(const Point& a)
{
	return Point((x+a.x),(y+a.y));
}
Point Point::operator+(int a)
{
	return Point(x+a,y+a);
}
Point operator+(int a, Point& b)
{
	return Point(a+b.x,a+b.y);
}
Point Point::operator+()
{
	return Point(x,y);
}
Point Point::operator-()
{
	return Point(-x,-y);
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
void Swap(const T& a, const T& b)
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
void Min(T a, T b)
{
	return (a < b) ? a : b;
}