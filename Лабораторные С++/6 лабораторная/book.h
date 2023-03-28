
//Прототипы используемых в данном задании функций:
enum category { classic, modern };
struct BOOK
{
	char article[36];
	char author[20];//20 байт
	category cat;
	int age;//4
	int cost;//4
};
const char* category1(char a)
{
	if (a == 1)
	{
		return "modern";
	}
	else if (a == 0)
	{
		return "classic";
	}
	else if (a == '1')
	{
		return "modern";
	}
	else if (a == '0')
	{
		return "classic";
	}

	else
	{
		return"ERROR";
	}
}
