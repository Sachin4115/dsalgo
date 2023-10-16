#include <stdio.h>
#include <stdlib.h>

struct node
{
  int data;
  struct node *next;
};

void printLinkedlist(struct node *p) {
  while (p != NULL) {
    printf("%d ", p->data);
    p = p->next;
  }
}

struct node* create(int n){
    struct node *ptr,*cpt;
    char ch;
    ptr = (struct node*) malloc (sizeof(struct node));
    printf("Input node information : ");
    scanf("%d",&ptr->data);
    struct node*first=ptr;
    n--;
    while(n--){
        cpt=(struct node*) malloc (sizeof(struct node));
        printf("Enter the next node : ");
        scanf("%d",&cpt->data);
        ptr->next=cpt;
        ptr=cpt;
    }
    ptr->next=NULL;
    return first;
}

int main()
{
    struct node* first = create(5);
    printLinkedlist(first);
    return 0;
}