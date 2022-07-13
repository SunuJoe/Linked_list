// list.h 
// header define (linked list)

#ifndef __LIST_H__
#define __LIST_H__

#define TRUE 1
#define FALSE 0

typedef int Ldata;
typedef struct __node
{
  Ldata data;
  struct __node* next;
} Node;

typedef int (*Func_React)(Ldata data1, Ldata data2);
typedef struct __list
{
  Node* head;
  Node* cur;
  Node* bef;
  int num_of_data;
  Func_React comp;
} List;

void Init(List* plist);
void set_Rule(List* plist, Func_React comp_rule);

// helper func of insert defined in function.c 

void Insert(List* plist, Ldata data);

int first_Search(List* plist, Ldata* target);
int next_Search(List* plist, Ldata* target);

Ldata Delete(List* plist);
int get_Num(List* plist);

#endif
