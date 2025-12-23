#include <stdio.h>
#include <stdlib.h>
struct Node{
  struct Node *next;
  int data;
};
void push(struct Node **head,int newData){
  struct Node *ptr=(struct Node*) malloc(sizeof(struct Node));
  ptr->data=newData;
  ptr->next=*head;
  
  *head=ptr;
}
void delete_first(struct Node **head){
  if(*head==NULL){
    return;
  }
  else{
    struct Node *ptr=*head;
    *head=(*head)->next;
    free(ptr);
  }
} 
void deleteAt_last(struct Node **head){
  struct Node *p=*head;
  struct Node *q=(*head)->next;
  int i=0;
  while(q->next !=NULL){
    p=p->next;
    q=q->next;
    
  }
  p->next=NULL;
  free(q);
}
void display(struct Node *head){
  while(head !=NULL){
    printf("%d->",head->data);
    head=head->next;
  }
  printf("NULL");
}
int main(){
struct Node *head=NULL;
push(&head,10);
push(&head,14);
push(&head,17);
push(&head,20);
printf("Original linked List:\n");
display(head);
printf("\nDelete At First:\n");
delete_first(&head);
display(head);
printf("\nDelete At End:\n");
deleteAt_last(&head);
display(head);
return 0;
}