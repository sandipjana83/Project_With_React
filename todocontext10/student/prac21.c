#include <stdio.h>
#include <stdlib.h>

struct Node{
  int data;
  struct Node *next;
  struct Node *prev;
};
void insert(struct Node **head,int val ){
  struct Node *ptr=(struct Node*)malloc(sizeof(struct Node));
  ptr->data=val;
  ptr->next=NULL;
  ptr->prev=NULL;
  
  if(*head ==NULL){
    *head=ptr;
    return;
  }
  struct Node *p=*head;
  while(p->next !=NULL){
    p=p->next;
  }
  p->next=ptr;
  ptr->prev=p; 
}
void forwardPrint(struct Node *head){
  struct Node *temp=head;
  while(temp!=NULL){
    printf("%d->",temp->data);
    temp=temp->next;
  }
  printf("NULL");
}
void backwardPrint(struct Node *head){
  struct Node *temp=head;
  if(temp==NULL){
    return;
  }
  while(temp->next !=NULL){
    temp=temp->next;
  }
  while(temp!=NULL){
    printf("%d->",temp->data);
    temp=temp->prev;
  }
}
int main(){
struct Node *head=NULL;
insert(&head,12);
insert(&head,17);
insert(&head,9);
insert(&head,25);
forwardPrint(head);
printf("\n");
backwardPrint(head);
return 0;
}