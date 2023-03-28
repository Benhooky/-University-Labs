#include <stdarg.h>
//Прототипы используемых в данном задании функций:
int b;
int& ref = b;
const int N = 2;
const int M = 2;
int I = 3;
int L = 4;

int incByValue(int val)
{	
	val++;
	return val;
}
void incByPointer(int* val) 
{
	 ++(*val);
}
void incByReference(int& val) {
	val++;
}
void Swap(int*x , int*y ) {
	int temp = *x;
	*x = *y;
	*y = temp;
}
void Swap(int& x, int& y) {
	int temp = x;
	x = y;
	y = temp;
}
int Min(int ar[][M],int v)
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (ar[i][j] < v)
			{
				v = ar[i][j];
			}
		}
	}
	return v;
}
int min(int **arr,int V,int C)
{
	int minimum = arr[0][0];
	for (int i = 0; i < V; i++)
	{
		for (int j = 0; j < C; j++)
		{
			if (arr[i][j] < minimum)
			{
				minimum = arr[i][j];
			}
		}
	}
	return minimum;
}
int MyStrCmp(const char* string1, const char* string2, int a, int b)
{
	int max = a;
	if (a < b)
	{
		return -1;
	}
	else if (a > b)
	{
		return 1;
	}
	else {

		for (int i = 0; i < a; i++)
		{
			if (string1[i] < string2[i])
			{
				return -1;
			}
			else if (string1[i] > string2[i])
			{
				return 1;
			}
			else if (i == a)
			{
				return 0;
			}

		}
	}
}
int DayOfYear(int number, int month, int year, int nd[][12])
{
	int day=0;
	if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0)
	{		
		for (int i = 0; i < month; i++)
		{
			day += nd[1][i];
		}
		day += number;
	}
	else
	{
		for (int i = 1; i < month; i++)
		{
			day += nd[0][i];
		}
		day += number-1;
	}
	return day;
}
int DayOfMonth(int ray, int year, int nd[][12])
{
	if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0)
	{
		for (int i = 0; i <12 ; i++)
		{
			while(ray>31)
			ray -= nd[1][i];
		}
	}
	else
	{
		for (int i = 0; i <12 ; i++)
		{
			if (ray>nd[0][i])
			ray -= nd[0][i];
		}
	}
	return ray;
}
int* newf(int* ab,int R,int *arrrr)
{
	int a;
	int b = 0;
	int v = R;
	std::cin >> a;
	for (int i = 0; i < R; i++)
	{
		if (ab[i] == a)
			b = 1;
	}
	if (b == 0)
	{
		int* tmp = new int[R + 1];
		for (int i = 0; i < R; i++)
		{
			tmp[i] = ab[i];
		}
		tmp[R] = a;
		delete[] ab;
		ab = tmp;
		*arrrr += 1;
	}
	return ab;
}
void printff(int arr[],int L)
{
	int* w = &arr[0];
	for (int i = 0; i < L; i++)
	{
		std::cout << *w;
		w++;
	}
}
void F(int n,int& ress)
{

	if(n!=0)
	{
		ress += n;
		F(n - 1, ress);
	}
}

void VarArgsss(int arg1, ... )
{
	int number = 0;	//счетчик элементов
	//Объявите указатель на int и инициализируйте его адресом
	//первого аргумента
	int *pcas = &arg1;
	//Пока не достигнут конец списка:
	// а) печать значения очередного аргумента
	// б) модификация указателя (он должен указывать на
	//следующий аргумент списка)
	// в) увеличить счетчик элементов
	while (*pcas != 0)
	{
		std::cout << *pcas<<std::endl;
		pcas++;
		pcas++;
		number++;
	}
	std::cout << "NUMBER " << number << std::endl;


	//Печать числа элементов

}
void macro(int arg1, ...)
{
	int number = 0;
	int i = arg1;
		va_list list;
		va_start(list, arg1);
		while (i != 0)
		{
			std::cout << i << std::endl;
			i = va_arg(list, int);
			number++;
		}
		std::cout << "NUMBER " << number << std::endl;
		va_end(list);
}
int* myMin(int* arr, int r)
{
	int l=0;
	for (int i = 0; i < r; i++) 
	{
		if (arr[l] > arr[i]) 
		{
			l = i;
		}
	}
	return &arr[l];
}