#include < string.h > 
#include <iostream>
#include<limits>
#include <fstream>
#include <string>
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
	while ((c != 0) && (c != 1))
	{
		printf("Wrong category,try again");
		std::cin >> c;
	}

	printf("Age(if BC use '-')=");
	std::cin >> a;
	while ((a < -4999)||(a>2020))
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
	f->cat = static_cast<category>(c);

}
void book_printer(BOOK**&vec,int a)
{
	printf("|Article %s |Author %s |Category %s |Age %d| Cost %d|\n", vec[a]->article, vec[a]->author, category1(vec[a]->cat), vec[a]->age,vec[a]->cost);

}
void biblio_printer(struct Library &red,BOOK**&vec)
{
	for (int i=red.number;i>0;i--)
	{
		std::cout << red.number - i+1<<" |";
		book_printer(vec,red.number-i);
	}
}
void add(int& number, BOOK*& Spisok, BOOK**& vec)
{
	number++;
	BOOK** masvec = new BOOK * [number];
	BOOK* massive = new BOOK[number];
	for (int i = 0; i < number - 1; i++)
	{
		massive[i] = Spisok[i];
	}
	for (int i = 0; i < number - 1; i++)
	{
		masvec[i] = &massive[i];
	}
	delete[] vec;
	delete[] Spisok;
	vec = masvec;
	Spisok = massive;
	vec[number-1] = &Spisok[number-1];
}
void book_adder(int&number,BOOK*&Spisok,BOOK**&vec)
{
	add(number, Spisok, vec);
	form_book(vec[number-1]);
}
void book_deleater(int a,int& number, BOOK*& Spisok, BOOK**& vec)
{
	a -= 1;
	for (int i = a; i < number-1; i++)
	{
		Spisok[i] = Spisok[i + 1];
	}
	for (int i = a; i < number - 1; i++)
	{
		vec[i] =&Spisok[i];
	}
	number--;
	BOOK** masvec = new BOOK * [number];
	BOOK* massive = new BOOK[number];
	for (int i = 0; i < number; i++)
	{
		massive[i] = Spisok[i];
	}
	for (int i = 0; i < number; i++)
	{
		masvec[i] = &massive[i];
	}
	delete[] vec;
	delete[] Spisok;
	vec = masvec;
	Spisok = massive;
}
void book_deleater(int a, int b, int& number, BOOK*& Spisok, BOOK**& vec)
{
	for (int i = a; a < b+1; a++)
	{
		book_deleater(a, number, Spisok,vec);
	}
}
void book_printerf(FILE*fs,BOOK**&vec,int i)
{
	fprintf(fs," %s %s %s %d %d \n", vec[i]->article, vec[i]->author, category1(vec[i]->cat), vec[i]->age, vec[i]->cost);
}
void file_reader(FILE* fs,BOOK*& be,int number)
{
	fscanf(fs, " %s  %s %c %d %d \n", &be[number-1].article, &be[number-1].author,&be[number-1].cat, &be[number-1].age, &be[number-1].cost);

}
int category_scorer(BOOK*& Spisok, int number,char category)
{
	int a = 0;
	for (int i = 0; i < number; i++)
	{
		if (category1(Spisok[i].cat) ==category1(category)) { a++; };
	}
	return a;
}
int countNumberOfLines(FILE* file) 
{
	unsigned int numberOfLines = 1;
	char ch;
	while (EOF != (ch = getc(file))) 
	{
		if (ch == '\n')numberOfLines++;
	}
	return numberOfLines;
}