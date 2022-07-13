// main.c

#include <stdio.h>
#include "list.h"

int action(Ldata d1, Ldata d2)
{
  if(d1 > d2)
    return 1;
  else
    return 0;
}

void show(List* plist, Ldata* val)
{
  if(first_Search(plist, val))
  {
    printf("%d\n", *val);
    while(next_Search(plist, val))
    {
      printf("%d\n", *val);
    }
  }
}

int main(int argc, char* argv[])
{
  List list;
  Ldata val;
  Ldata r_val;
  Init(&list);
  set_Rule(&list, action);

  Insert(&list, 1);
  Insert(&list, 2);
  Insert(&list, 2);
  Insert(&list, 3);
  Insert(&list, 4);
  Insert(&list, 5);

  printf("data number : %d\n", get_Num(&list));
  show(&list, &val);

  if(first_Search(&list, &val))
  {
    if(val == 2)
    {
      val = Delete(&list);
      printf("deleted value : %d\n", val);
    }
    while(next_Search(&list, &val))
    {
      if(val == 2)
      {
        val = Delete(&list);
        printf("deleted value : %d\n", val);
      }
    }
  }

  show(&list, &val);

  return 0;
}
