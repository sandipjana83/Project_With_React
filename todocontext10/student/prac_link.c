// #include <stdio.h>
// #include <stdlib.h>

// struct Node{
//   int data;
//   struct Node *next;
// };
// void push(struct Node **head,int val){
//   struct Node *ptr=(struct Node *)malloc(sizeof(struct Node));
//   ptr->data=val;
//   ptr->next=*head;
//   *head=ptr;
// }
// void push_back(struct Node **head,int val){
//   struct Node *ptr=(struct Node *)malloc(sizeof(struct Node));
//   ptr->data=val;
//   struct Node *p=*head;
//   while(p->next!=NULL){
//     p=p->next;
//   }
//   p->next=ptr;
//   ptr->next=NULL;
// }
// void pop(struct Node **head){
//   if (*head ==NULL){
//     return;
//   }
//   struct Node *temp=*head;
//   *head=(*head)->next;
//   free(temp);
// }
// void popAtLast(struct Node **head){
//   struct Node *p=*head;
//   struct Node *q=(*head)->next;
//   while(q->next!=NULL){
//     q=q->next;
//     p=p->next;
//   }
//   p->next=NULL;
//   free(q);
  
// }
// void reverseList(struct Node **head){
//   struct Node *prev=NULL;
//   struct Node *curr=*head;
//   struct Node *Next=NULL;
//   while(curr !=NULL){
//     Next=curr->next;
//     curr->next=prev;
//     prev=curr;
//     curr=Next;
//   }
//   *head=prev;

// }
// void printLL(struct Node *head){
//   while(head !=NULL){
//     printf("%d->",head->data);
//     head=head->next;
//   }
//   printf("NULL");
// }

// int main(){
// struct Node *head=NULL;
// push(&head,2);
// push(&head,5);
// push(&head,11);
// push_back(&head,7);
// push_back(&head,16);
// push_back(&head,1);
// printLL(head);
// printf("\n");
// reverseList(&head);
// printLL(head);
// return 0;
// }

#include <stdio.h>
#include <stdlib.h>
struct Node{
  int data;
  struct Node *next;
  struct Node *prev;
};
void push(struct Node **head,int val){
  struct Node *ptr=(struct Node *)malloc(sizeof(struct Node));
  ptr->data=val;
  ptr->next=NULL;
  ptr->prev=NULL;
  if(*head ==NULL){
    *head=ptr;
    ptr->next=ptr->prev=ptr;
    return;
  }
  else{
    struct Node *p=*head;
    do{
      p=p->next;
    }while(p->next != *head);
    p->next=ptr;
    ptr->next=*head;
    ptr->prev=p;
    *head=ptr;
  }
}
void displayForward(struct Node *head){
  while (head !=NULL){
    printf("%d->",head->data);
    head=head->next;
  }
  printf("NULL\n");
}
void displayBackward(struct Node *head){
  struct Node *temp=head;
  while(temp->next !=NULL){
    temp=temp->next;
  }
  while(temp !=NULL){
    printf("%d->",temp->data);
    temp=temp->prev;
  } 
  printf("NULL\n");
}
int main(){
struct Node *head=NULL;
push(&head,3);
push(&head,5);
push(&head,10);
push(&head,16);
displayForward(head);
displayBackward(head);
return 0;
}