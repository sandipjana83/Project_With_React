#include <stdio.h>
#include <stdlib.h>
struct queue{
  int size;
  int f;
  int r;
  int *arr;
};
int isFull(struct queue *q){
  if(q->r==q->size-1){
    return 1;
  }
  return 0;
}
int isEmpty(struct queue *q){
  if(q->f== q->r){
    return 1;
  }
  return 0;
}
void enqueue(struct queue *q,int val){
  if(isFull(q)){
    printf("full");
  }
  else{
    q->r=q->r+1;
    q->arr[q->r]=val;
  }
}
int dequeue(struct queue *q){
  int a;
  if(isEmpty(q)){
    printf("empty");
    return -1;
  }
  
  else{
    q->f=q->f+1;
    a=q->arr[q->f];
    return a;
  }
  
}
int main(){
struct queue q;
q.size=10;
q.f=q.r=-1;
q.arr=(int *)malloc(q.size *sizeof(int));
enqueue(&q,12);
enqueue(&q,10);
printf("%d\n",isEmpty(&q));
printf("%d\n",dequeue(&q));
//dequeue(&q);
printf("%d\n",isEmpty(&q));
return 0;
}