#include <stdio.h>
#include <stdlib.h>

struct Node{
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
  ptr->data=val;
  if(*head==NULL){
    *head=ptr;
    return;
  }
  struct Node *p=*head;
  
  while(p->next !=NULL){
    p=p->next;
  }
  
  p->next=ptr;
  ptr->next=NULL;
  
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
void mid_val(struct Node **head){
  struct Node *temp=*head;
  int count=0;
  while(temp !=NULL){
    count++;
    temp=temp->next;
    
  } 
  int mid_idx=count/2;
  temp=*head;
  for(int i=0;i<mid_idx;i++){
    temp=temp->next;
  }
  printf("%d",temp->data);
}
void mid_cal(struct Node **head){
  struct Node *slow=*head;
  struct Node *fast=*head;
  while(fast !=NULL && fast->next !=NULL){
    slow=slow->next;
    fast=(fast->next)->next;
  }
  printf("mid value =%d",slow->data);
}
struct Node *merge_sort(struct Node *head1,struct Node *head2){
  if(head1==NULL || head2==NULL){
    return head1=NULL?head2:head1;
  }
  else{
    if(head1->data<=head2->data){
      head1->next=merge_sort(head1->next,head2);
      return head1;
    }
    else{
      head2->next=merge_sort(head1,head2->next);
      return head2;
    }
  }

};
void printLL(struct Node *temp){
  while(temp !=NULL){
    printf("Element: %d\n",temp->data);
    temp=temp->next;
  }
}

int main(){
struct Node *head=NULL;
struct Node *head1=NULL;
push(&head,2);
push_back(&head,4);
push_back(&head,20);
push_back(&head,30);
push(&head1,3);
push_back(&head1,5);
push_back(&head1,20);
push_back(&head1,49);
printf("original linked list1:\n");
printLL(head);
printf("original linked list2:\n");
printLL(head1);
//reverse(&head);
// printf("reversed linked_list:\n");
// printLL(head);
// printf("middle index:\n");
// mid_val(&head);
//mid_cal(&head);
struct Node *mergelist=merge_sort(head,head1);
printf("merge sorted list:\n");
printLL(mergelist);

return 0;
}