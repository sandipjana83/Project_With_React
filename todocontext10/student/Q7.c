#include <stdio.h>
#include <stdlib.h>
struct Node{
  struct Node *next;
  int data;
};

void insert(struct Node **head,int val){
  struct Node *ptr=(struct Node *)malloc(sizeof(struct Node));
  ptr->data=val;
  ptr->next=*head;
  *head=ptr;
}
struct Node *mergeList(struct Node *list1,struct Node *list2){
  if(list1==NULL) return  list2;
  if(list2==NULL) return list1;
  struct Node *result=NULL;
  if(list1->data < list2->data){
    result=list1;
    result->next=mergeList(result->next,list2);
  }
  else{
    result =list2;
    result->next=mergeList(list1,result->next);
  }
  return result;
}
void reverse(struct Node **head){
    struct Node *prev=NULL;
    struct Node *curr=*head;
    struct Node *n=NULL;
    while(curr != NULL){
        n=curr->next;
        curr->next=prev;
        prev=curr;
        curr=n;
    }
    *head=prev;
    
}
void display(struct Node *head){
  while(head !=NULL){
    printf("%d->",head->data);
    head=head->next;
  }
  printf("NULL");
}
int main(){
struct Node *l1=NULL;
struct Node *l2=NULL;
insert(&l1,117);
insert(&l1,13);
insert(&l1,10);
printf("First list:\n");
display(l1);
insert(&l2,20);
insert(&l2,12);
insert(&l2,2);
printf("\nSecond list::\n");
display(l2);
struct Node *merge=mergeList(l1,l2);
printf("\nMerge Linked List:\n");
display(merge);
printf("\nReversed List:\n");
reverse(&merge);
display(merge);
return 0;
}