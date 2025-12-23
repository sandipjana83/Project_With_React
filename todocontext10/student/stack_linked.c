#include <stdio.h>
#include <stdlib.h>

struct Node {
  int data;
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
int pop(){
  int val;
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
int peek(){
  if(top==NULL){
    return -1;
  }
  return top->data;
}
int isOperator(char ch){
  if(ch== '+' ||ch=='-' ||ch=='*'|| ch=='/'){
    return 1;
  }
  else{
    return 0;
  }
}
int parenthesis_check(char str[]){
  for (int i=0;str[i] !='\0';i++){
    if(str[i]=='(' || str[i]=='{' || str[i]=='['){
      push(str[i]);
    }
    else if(str[i]==')'||str[i]=='}'||str[i]==']'){
      if(top==NULL){
        return 0;
      }
      else{
        pop();
      }
    }
  }
  if(top==NULL){
    return 1;
  }
  else{
  return 0;
  }
}
void decTobinary(int n){
  while(n >0){
    push(n%2);
    n/=2;
  }
  while(top!=NULL){
    printf("%d ",pop());
  }
  printf("\n");
}
void display(){
  struct Node *temp=top;
  while(temp != NULL){
    printf("%c ",temp->data);
    temp=temp->next;
  }
}
int evalutePostfix(char postfix[]){
  for(int i=0;postfix[i]!='\0';i++){
    char val=postfix[i];
    if(!isOperator(val)){
      
      push(val-'0');
    }
    else{
      int val2=pop();
      int val1=pop();
      switch (val)
      {
      case '+':
        push(val1+val2);
        break;
      case '-':
        push(val1-val2);
        break;
      case '*':
        push(val1*val2);
        break;
      case '/':
        push(val1/val2);
        break;
      default:
        break;
      }
    }
  }
  return pop();
}
int main(){
//char st[6]="({[})";
//printf("%d",parenthesis_check(st));
//printf("\n");
//display();
char postfix[10]="23*54*+9-";
printf("%d",evalutePostfix(postfix));
return 0;
}