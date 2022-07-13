// func_list.c

#include "list.h"
#include <stdio.h>
#include <stdlib.h>

void Init(List* plist)
{
  // initiallizing list
  plist->head = (Node*)malloc(sizeof(Node));
  plist->head->next = NULL;
  plist->comp = NULL;
  plist->num_of_data = 0;
}

void set_Rule(List* plist, Func_React comp_rule)
{
  plist->comp = comp_rule;
}

void head_Insert(List* plist, Ldata data)
{
  Node* newNode = (Node*)malloc(sizeof(Node));
  newNode->data = data;

  newNode->next = plist->head->next;
  plist->head->next = newNode;
  (plist->num_of_data)++;
}

void sort_Insert(List* plist, Ldata data)
{
  Node* newNode = (Node*)malloc(sizeof(Node));
  newNode->data = data;
  Node* pred = plist->head;
  
  while((pred->next != NULL) && plist->comp(data, pred->next->data) != 0)
  {
    pred = pred->next;  
  }

  newNode->next = pred->next;
  pred->next = newNode;
  (plist->num_of_data)++;
}

void Insert(List* plist, Ldata data)
{
  if(plist->comp == NULL)
    head_Insert(plist, data);
  else
    sort_Insert(plist, data);
}

int first_Search(List* plist, Ldata* target)
{
  if(plist->head->next == NULL)
  {
    printf("No data\n");
    return FALSE;
  }
  else
  {
    plist->bef = plist->head;
    plist->cur = plist->head->next;
    *target = plist->cur->data;
    return TRUE;
  }
}

int next_Search(List* plist, Ldata* target)
{
  if(plist->cur->next == NULL)
  {
    printf("EOD\n");
    return FALSE;
  }
  else
  {
    plist->bef = plist->cur;
    plist->cur = plist->cur->next;
    *target = plist->cur->data;
    return TRUE;
  }
}

Ldata Delete(List* plist)
{
  Node* temp = plist->cur;
  Ldata temp_data = plist->cur->data;

  plist->bef->next = plist->cur->next;
  plist->cur = plist->bef;
  free(temp);
  (plist->num_of_data)--;
  return temp_data;
}

int get_Num(List* plist)
{
  return plist->num_of_data;
}
