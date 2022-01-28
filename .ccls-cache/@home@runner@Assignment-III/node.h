struct node
{
  int id;
  char name[20];
  struct node *next;
}*stnode;
typedef struct node NODE;
typedef NODE* NodePtr;