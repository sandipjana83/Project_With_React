#include <stdio.h>
#include <stdlib.h>

struct Node{
  struct Node *next;
  int data;
};
void push_front(struct Node **head,int val){
  struct Node *ptr=(struct Node*)malloc(sizeof(struct Node));
  ptr->data=val;
  struct Node *p=*head;
  do{
    p=p->next;
  }while(p->next != *head);
  p->next=ptr;
  ptr->next=*head;
  *head=ptr;
}
void isCir(struct Node **head){
  struct Node *slow=*head;
  struct Node *fast=*head;
  do{
    slow=slow->next;
    fast=(fast->next)->next;
    if(slow==fast){
      printf("circular Linked list");
      break;
    }
    else{
      printf("no");
    }
  }while(fast !=NULL && fast->next !=NULL);

}
void printll(struct Node *head){
  struct Node *ptr=head;
  do{
    printf("%d ",ptr->data);
    ptr=ptr->next;
  }while(ptr !=head);
}
int main(){
struct Node *head=(struct Node *)malloc(sizeof(struct Node));
struct Node *second=(struct Node *)malloc(sizeof(struct Node));
struct Node *third=(struct Node*)malloc(sizeof(struct Node));
head->data=3;
head->next=second;
second->data=7;
second->next=third;
third->data=11;
third->next=NULL;
// push_front(&head,8);
// printll(head);
printf("\n");
isCir(&head);
return 0;
}