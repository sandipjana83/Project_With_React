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
void push_back(struct Node **head,int val){
  struct Node *ptr=(struct Node*) malloc(sizeof(struct Node));
  struct Node *p=*head;
  ptr->data=val;
  
  while(p->next !=NULL){
    p=p->next;
  }
  
  p->next=ptr;
  ptr->next=NULL;
}
void leftPush(struct Node **head,int k){
  struct Node *p=*head;
  int count=1;
  while(count<k && p!=*head){
    p=p->next;
    count++;
  }
  struct Node *kthNode=p->next;
  while(p->next !=NULL){
    p=p->next;;
  }
  p->next=*head;
  *head=kthNode->next;
  kthNode->next=NULL;
}
void display(struct Node* head){
  while(head !=NULL){
    printf("%d->",head->data);
    head=head->next;
  }
  printf("NULL");
}
int main(){
struct Node *head=NULL;
push(&head,5);
push_back(&head,7);
push_back(&head,11);
push_back(&head,15);
push_back(&head,20);
display(head);
printf("\n");
leftPush(&head,3);
display(head);
return 0;
}