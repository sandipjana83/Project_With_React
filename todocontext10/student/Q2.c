#include <stdio.h>
#include <stdlib.h>
struct Node {
  char data;
  struct Node *next;
};
struct Node *createNode(char ch){
  struct Node *ptr=(struct Node*)malloc(sizeof(struct Node));
  ptr->data=ch;
  ptr->next=NULL;
  return ptr;
}
struct Node *strIntoList(char str[]){
  struct Node *head=NULL;
  struct Node *tail=NULL;
  struct Node *newNode;
  for(int i=0;str[i]!='\0';i++){
    newNode=createNode(str[i]);
  
  if(head==NULL){
    head=tail=newNode;
  }

  else{
  tail->next=newNode;
  
  tail=newNode;}
  }
  return head;
}
void printLL(struct Node *head){
  while(head !=NULL){
    printf("%c->",head->data);
    head=head->next;
  }
}
int main(){
char str[10]="Sandip";
struct Node *head=strIntoList(str);
printLL(head);
return 0;
}