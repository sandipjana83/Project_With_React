#include <stdio.h>
#include <stdlib.h>

struct Node {
  int data;
  struct Node *next;
};
void insert(struct Node **head,int val){
  struct Node *ptr=(struct Node *)malloc(sizeof(struct Node));
  ptr->data=val;
  ptr->next=*head;
  *head=ptr;
}
void deletaion(struct Node *head){
  struct Node *p=head;
  struct Node *ptr=head->next;
  while(ptr->next !=NULL){
    p=p->next;
    ptr=ptr->next;
  }
  p->next=NULL;
  free(ptr);
}
void display(struct Node *head){
  while (head !=NULL)
  {
    printf("%d ->",head->data);
    head=head->next;
  }
  
}
int main(){
struct Node *head=NULL;
insert(&head,10);
insert(&head,20);
insert(&head,25);
printf("Insert At first:\n");
display(head);
deletaion(head);
printf("Delet From Ee"); 
display(head);
return 0;
}