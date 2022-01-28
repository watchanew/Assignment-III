#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "node.h"

void display(int n);
void FreeNode();

int main()
{
  int i, idnum;
  char name[20];
  int n=3;
  NODE *head,*temp ;
  stnode=(NodePtr) malloc(sizeof(NODE));
//get input
  printf(" Input ID 1 : ");
  scanf("%d", &idnum);
  printf(" Input Name 1 : ");
  scanf("%s", name);

//create link list
  stnode->id = idnum;
  strcpy(stnode->name, name);     
  stnode->next = NULL;
  temp = stnode;
  
  for(i=2; i<=n; i++)
  {
    head = (NodePtr) malloc(sizeof(NODE));
    printf(" Input ID %d : ", i);
    scanf("%d", &idnum);
    if(idnum == 0) break;
    printf(" Input Name %d : ", i);
    scanf("%s", name);

    head->id = idnum;      
    strcpy(head->name, name); 
    head->next = NULL;
    temp->next = head; 
    temp = temp->next; 
    n++;
  }

  display(n);
  FreeNode();

  return 0;
}

void display(int n)
{
  NODE *head,*temp;
  int i;
  //display
  temp = stnode;
  printf("\n[   ID, NAME]\n");
  for(i=1; i<n-1; i++)
  {
    printf("[ %4d, %s]\n", temp->id, temp->name);
    temp = temp->next;        
  }
}

void FreeNode()
{
  //free
  NODE *head,*temp;
  while (temp != NULL)
   {
       temp = head->next;
       free(head);
       head = temp;
   }
   stnode = NULL;
}