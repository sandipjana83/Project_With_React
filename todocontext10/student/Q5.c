#include <stdio.h>
#include <stdlib.h>
struct Node {
  int data;
  struct Node *next;
};
void push(struct Node **head,int newData){
  struct Node *ptr=(struct Node*) malloc(sizeof(struct Node));
  ptr->data=newData;
  ptr->next=*head;
  
  *head=ptr;
}
void modifyNode(struct Node *head,int val,int pos){
  struct Node *p=head;
  //struct Node *q=head->next;
  int i=0;
  while(i != pos){
    p=p->next;
    //=q->next;
    i++;
  }
  p->data=val;
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
printf("Original Linked list:\n");
display(head);
int val,pos;
printf("\nEnter index :");
scanf("%d",&pos);
printf("Enter new Node:");
scanf("%d",&val);
modifyNode(head,val,pos);
display(head);
return 0;
}