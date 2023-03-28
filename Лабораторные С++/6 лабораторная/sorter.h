
void uni_puzirek(int a, int number, bool(*func_mas[5])(BOOK**&vec, int vard),BOOK**&vec)
{
	a -= 1;
  for (int i = 0; i < number; i++)
  {
    bool check = true;
    for (int j = 0; j < number - i - 1; j++)
    {
      if (func_mas[a](vec,j))
      {
        BOOK* h = vec[j];
        vec[j] = vec[j + 1];
        vec[j + 1] = h;
        check = false;
      };
    }
    if (check)break;
  }
}
bool sort_article(BOOK**&vec,int vard)
{
  if (strcmp(vec[vard]->article, vec[vard + 1]->article)>0)
  {
	  return true;
  }
  else 
  {
	  return false;
  }
}
bool sort_author(BOOK**&vec, int vard)
{
  if (strcmp(vec[vard]->author, vec[vard + 1]->author)>0)
  {
	  return true;
  }
  else
  {
	  return false;
  }
}
bool sort_category(BOOK**&vec, int vard)
{
  if ((vec[vard]->cat)> (vec[vard + 1]->cat))
  {
	  return true;
  }
  else
  {
	  return false;
  }
}
bool sort_age(BOOK**&vec, int vard)
{
  if ((vec[vard]->age)> (vec[vard + 1]->age))
  {
	  return true;
  }
  else
  {
	  return false;
  }
}
bool sort_cost(BOOK**&vec, int vard)
{
  if ((vec[vard]->cost)> (vec[vard + 1]->cost))
  {
	  return true;
  }
  else
  {
	  return false;
  }
}

