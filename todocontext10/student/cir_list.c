#include <stdio.h>
#include <stdlib.h>

struct Node{
  int val;
  struct Node *next;
};
struct Node *push_front(struct Node *head,int newData){
  struct Node *ptr=(struct Node*)malloc(sizeof(struct Node));
  ptr->val=newData;
  struct Node *p=head;
  do{
    p=p->next;
  }while(p->next !=head);

  p->next=ptr;
  ptr->next=head;
  head=ptr;
  return head;
}
int isCir(struct Node *head){
  struct Node *slow=head;
  struct Node *fast=head;
  do{
    slow=slow->next;
    fast=fast->next->next;
    if(slow==fast){
      return 1;
    }
    return 0;
  }while(fast !=NULL && fast->next !=NULL);
}
void deleteAtIndex(struct Node *head,int idx){
  struct Node *p=head;
  struct Node *q=head->next;
  int i=0;
  while(i != idx){
    p=p->next;
    q=q->next;
    i++;
  }
  p->next=q->next;
  free(q);
}
void printLL(struct Node *head){
  struct Node *ptr=head;
  do{
    printf("Element:%d\n",ptr->val);
    ptr=ptr->next;
  }while(ptr !=head);
}

int main(){
struct Node *head;
struct Node *second;
struct Node *third;
head=(struct Node*) malloc(sizeof(struct Node));
second=(struct Node*) malloc(sizeof(struct Node));
third=(struct Node*) malloc(sizeof(struct Node));
head->val=13;
head->next=second;
second->val=45;
second->next=third;
third->val=78;
third->next=head;
push_front(head,25);
push_front(head,30);

printLL(head);
//printf("%d",isCir(head));
deleteAtIndex(head,2);
printf("\n");
printLL(head);
return 0;
}