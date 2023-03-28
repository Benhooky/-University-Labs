#pragma once
class Rect
{
	int m_left, m_right, m_top, m_bottom;
public:
	Rect()
	{
		m_left = 0;
		m_right = 0;
		m_top = 0;
		m_bottom = 0;
	}
	Rect(int a, int b, int c, int d)
	{
		m_left = a;
		m_right = b;
		m_top = c;
		m_bottom = d;
	}
	~Rect()
	{
		m_left = 0;
		m_right = 0;
		m_top = 0;
		m_bottom = 0;
	}
	void InflateRect(int a=1 ,int b=1)
	{
		m_left += a;
		m_right += a;
		m_top += b;
		m_bottom+=b;
	}
	void InflateRect(int a, int b, int c, int d)
	{
		m_left += a;
		m_right += b;
		m_top += c;
		m_bottom += d;
	}
	Rect(const Rect& a)
	{
		m_left = a.m_left;
		m_right = a.m_right;
		m_top = a.m_top;
		m_bottom = a.m_bottom;
	}
	void SetAll(int a, int b, int c, int d)
	{
		m_left = a;
		m_right = b;
		m_top = c;
		m_bottom = d;
	}
	void GetAll(int*inf)
	{
		inf[0] = m_left;
		inf[1] = m_right;
		inf[2] = m_top;
		inf[3] = m_bottom;
	}
	void Get(int& a, int& b, int& c, int& d)
	{
		a = m_left;
	    b = m_right;
		c = m_top;
		d = m_bottom;
	}
	
};
class Point
{
	int x, y;
public:
	Point() 
	{
		x = 0;
		y = 0;
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
	friend Point operator--(Point& a);
	friend Point operator--(Point& a,int);
};
class A {
	int m_n; //количество элементов в массиве
	int* m_p; //массив из элементов
public:
	A(int n) { m_n = n;  m_p = new int[n]; }
	A() {};
	~A()
	{
		m_n = 0;
		delete[] m_p;
	}
	A(const A& a)
	{
		m_n = a.m_n;
		m_p = new int[a.m_n];
		for (int i = 0; i < a.m_n; i++)
		{
			m_p[i] = a.m_p[i];
		}
	}
	int Size()
	{
		return m_n;
	}
	int& operator[] (const int number)//оператор индексирования
	{
		return m_p[number];
	}
	A operator= (const A& ab)//присваивание(копирование) массива
	{
		m_n = ab.m_n;
		m_p = new int[ab.m_n];
		for (int i = 0; i < ab.m_n; i++)
		{
			m_p[i] = ab.m_p[i];
		}
		return *this;
	}
	friend bool operator== (const A& c1, const A& c2);
};
class Bochka
{
	double liquid,mass;//liquid - общее количество спирта в бочке mass- общее количество жидкости в бочке
	
public:
	Bochka(double a)
	{
		liquid = a;
		mass = 100;
	}
	void Pereliv(Bochka& a)
	{
		a.liquid += (liquid / mass);
		liquid -= (liquid/mass);
		mass -= 1;
		a.mass += 1;
	}
	double get(double&c)
	{
		c= liquid;
		return c;
	}
};
template <class T, int T1>
class MyArray
{
private:
	int length;
	T* q;

public:
	MyArray()
	{
		length = T1;
		q = new T[length];
	}
	MyArray(int a)
	{
		q = new T[a];
		length = a;
	}
	~MyArray()
	{
		delete[] q;
	}
	T& operator[](const int i)
	{
		return q[i];
	}
};
