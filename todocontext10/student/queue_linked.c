#include <stdio.h>
#include <stdlib.h>
struct Node {
  int data;
  struct Node *next;
};
struct Node *f=NULL;
struct Node *r=NULL;
void printll(){
  
  while(f !=NULL){
    printf("%d ",f->data);
    f=f->next;
  }
}
void enqueue(int val){
  struct Node *n=(struct Node*)malloc(sizeof(struct Node));
  if(n== NULL){
    printf("queue overflow");
  }
  else{
    n->data=val;
    n->next=NULL;
    if(f==NULL){
      f=r=n;
    }
    else{
      r->next=n;
      r=n;
    }
  }
}
int dequeue(){
  int val;
  struct Node *ptr=f;
  if(f==NULL){
    printf("queue is empty\n");
    return -1;
  }
  else{
    f=f->next;
    val=ptr->data;
    free(ptr);
  }
  return val;
  
}
int main(){
enqueue(12);
enqueue(15);

printf("\n");
printf("dequeue element: %d\n",dequeue());
// printf("dequeue element: %d\n",dequeue());
// printf("dequeue element: %d\n",dequeue());
enqueue(45);
printll();
return 0;
}