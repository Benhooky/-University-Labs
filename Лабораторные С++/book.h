
//Прототипы используемых в данном задании функций:

void Sort(char* pcFirst, int nNumber, int size,
	void (*Swap)(void*, void*), int (*Compare)(void*, void*))
{
	int i;
	for (i = 1; i < nNumber; i++)
		for (int j = nNumber - 1; j >= i; j--)
		{
			char* pCurrent = pcFirst + j * size;
			char* pPrevious = pcFirst + (j - 1) * size;
			if ((*Compare)(pPrevious, pCurrent) > 0)
				(*Swap)(pPrevious, pCurrent);
		}
}
void SwapInt(void* p1, void* p2)
{
	int* pn = static_cast<int*>(p1);
	int* pnn = static_cast<int*>(p2);
	int a = *pn;
	*pn = *pnn;
	*pnn = a;
}
void SwapDouble(void* p1, void* p2)
{
	double* pn = static_cast<double*>(p1);
	double* pnn = static_cast<double*>(p2);
	double a = *pn;
	*pn = *pnn;
	*pnn = a;
}
int CmpDouble(void* p1, void* p2)
{
	double* pn = static_cast<double*>(p1);
	double* pnn = static_cast<double*>(p2);
	if (*pn > * pnn)
	{
		return -1;
	}
	else if (*pn < *pnn)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
int CmpInt(void* p1, void* p2)
{
	int* pn = static_cast<int*>(p1);
	int* pnn = static_cast<int*>(p2);
	if (*pn > * pnn)
	{
		return -1;
	}
	else if (*pn < *pnn)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
void SwapString(void* p1, void* p2) 
{
	char** pn = static_cast<char**>(p1);
	char** pnn = static_cast<char**>(p2);
	char* a = *pn;
	int b = **pn;
	*pn = *pnn;
	*pnn = a;
}
int CmpString(void* p1, void* p2) {
	char* str_1 = *static_cast<char**>(p1);
	char* str_2 = *static_cast<char**>(p2);
	while ((*str_1) && (*str_1 == *str_2)) 
	{
		++str_1;
		++str_2;
	}
	return *str_1 - *str_2;
}
double Sum(double A, double B)
{
	return A + B;
}
double Sub(double A, double B)
{
	return A - B;
}
double Mul(double A, double B)
{
	return A * B;
}
double Div(double A, double B)
{
	return A / B;
}
const char* GetString1() 
{
	return "AAA";
}

const char* GetString2()
{
	return "BBB";
}

const char* GetString3() 
{
	return "CCC";
}
enum category { classic, modern };
struct BOOK
{
	char author[12];//12 байт
	char article[36];//36 байт
	int age;//4
  char ttt;
  //double tttt;
	int cost;//4
	category cat;//4
};
const char* category1(int a)
{
	if (a == 1)
	{
		return "modern";
	}
	else if (a == 0)
	{
		return "classic";
	}
}
void book_printer(struct BOOK f)
{
	printf("Article %s Author %s Category %s Age %d Cost %d", f.article, f.author, category1(f.cat),f.age, f.cost);
}
void form_book(struct BOOK* f)
{
	int a = -5000;
	int b = -1;
	int c = -2;
	printf("Article=");
	scanf("%s32", f->article);
	fflush(stdin);
	printf("Author=");
	scanf("%s12", f->author);
	fflush(stdin);
	printf("Category:classic(0) , modern(1)");
	std::cin >> c;
	while ((c != 0)&&(c!=1 ))
	{
		printf("Wrong category,try again");
		std::cin >> c;
	}

	printf("Age(if BC use '-')=");
	std::cin >> a;
	while (a < -4999)
	{
		printf("Wrong age,try again=");
		std::cin >> a;
	}
	printf("Cost=");
	std::cin >> b;
	while (b < 0)
	{
		printf("Wrong cost,try again=");
		std::cin >> b;
	}
	f->age = a;
	f->cost = b;
	f->cat=static_cast<category>(c);
}