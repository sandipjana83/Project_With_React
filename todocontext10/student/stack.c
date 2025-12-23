#include <stdio.h>
#include <stdlib.h>

struct stack{
  int size;
  int top;
  char *arr;
};

int isEmpty(struct stack *s){
  if(s->top==-1){
    return 1;
  }
  return 0;
}

int isFull(struct stack *s){
  if(s->top==s->size-1){
    return 1;
  }
  return 0;
}

void push(struct stack *s,int val){
  if(isFull(s)){
    printf("stack overflow");
  }
  else{
    s->top=s->top+1;
    s->arr[s->top]=val;
  }
}

int pop(struct stack *s){
  int val;
  if(isEmpty(s)){
    printf("stack underflow");
    return -1;
  }
  else{
    val=s->arr[s->top];
    s->top=s->top-1;
  }
  return val;
}

int parenthesis_match(struct stack *s, char *exp){
  for(int i=0;exp[i] !='\0';i++){
    if(exp[i]=='('){
      push(s,'(');
    }
    else if(exp[i]==')'){
      if(isEmpty(s)){
        return 0;
      }
      pop(s);
    }
  }
  if(isEmpty(s)){
    return 1;
  }
  else{
    return 0;
  }
}


int main(){
struct stack sp;
sp.size=20;
sp.top=-1;
sp.arr = (char *)malloc(sp.size *sizeof(char));
char exp[20]="(10+1*(3/2-(2-2))";
printf("%d ",parenthesis_match(&sp,exp));
return 0;
}