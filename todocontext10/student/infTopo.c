#include <stdio.h>
#include <stdlib.h>

struct Node {
  char data;
  struct Node*next;
};
struct Node *top=NULL;
void push(int val){
  struct Node *newNode=(struct Node*)malloc(sizeof(struct Node));
  if(newNode==NULL){
    return;
  }
  else{
    newNode->data=val;
    newNode->next=top;
    top=newNode;
  }
}
void push_back(int val){
  struct Node *ptr=(struct Node*)malloc(sizeof(struct Node));;
  ptr->data=val;
  ptr->next=NULL;
  if(top==NULL){
    top=ptr;
    return;
  }
  struct Node *p=top;
  while(p->next !=NULL){
    p=p->next;

  } 
  p->next=ptr;
}
char pop(){
  char val;
  if(top ==NULL){
    return 0;
  }
  else{
    struct Node *temp=top;
    val=top->data;
    top=temp->next;
    free(temp);

  }
  return val;
}
char peek(){
  if(top==NULL){
    return -1;
  }
  return top->data;
}
int precedence(char ch){
  if(ch=='*' || ch=='/'){
    return 3;
  }
  else if(ch=='+' ||ch=='-'){
    return 2;
  }
  else{
    return 0;
  }
}
int isOperator(char ch){
  if(ch== '+' ||ch=='-' ||ch=='*'|| ch=='/'){
    return 1;
  }
  else{
    return 0;
  }
}

void infixTopostfix(char infix[]){
  int i=0, j=0;
  char postfix[10];
  while(infix[i] !='\0'){
    char val=infix[i];
    if(!isOperator(val)){
      postfix[j]=val;
      i++;j++;
    }
    else
    {
      if(precedence(val)>precedence(peek())){
        push(val);
        i++;
      }
      else{
        postfix[j]=pop();
        j++;
      }

    }
  }
  while(top  !=NULL){
    postfix[j]=pop();
    j++;
  }
  postfix[j]='\0';
  for(int i=0;postfix[i]!='\0';i++){
    printf("%c ",postfix[i]);
  }
}
int main(){
char str[10]="x+y*z-k";
infixTopostfix(str);
return 0;
}