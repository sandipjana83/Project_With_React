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
void deleteAt_index(struct Node **head,int idx){
  struct Node *p=*head;
  struct Node *q=(*head)->next;
  int i=0;
  while(i!=idx-1){
    p=p->next;
    q=q->next;
    i++;
  }
  p->next=q->next;
  free(q);

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
void printLL(struct Node *temp){
  while(temp !=NULL){
    printf("Element: %d\n",temp->data);
    temp=temp->next;
  }
}

int main(){
struct Node *head=NULL;
push(&head,7);
push_back(&head,20);
push_back(&head,30);
push_back(&head,42);
push_back(&head,49);
printf("Original linked list:\n");
printLL(head);
// delete_first(&head);
deleteAt_index(&head,2);
// deleteAt_last(&head);
printf("Linked list after deletation:\n");
printLL(head); 
return 0;
}