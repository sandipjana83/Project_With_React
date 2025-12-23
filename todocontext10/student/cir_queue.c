#include <stdio.h>
#include <stdlib.h>

struct cirqueue{
  int size;
  int f;
  int r;
  int *arr;
};
int isFull(struct cirqueue *q){
  if((q->r+1)%q->size==q->f){
    return 1;
  }
  return 0;
}
int isEmpty(struct cirqueue *q){
  if(q->r==q->f){
    return 1;
  }
  return 0;
}
void enqueue(struct cirqueue *q,int val){
  if(isFull(q)){
    printf("Queue overflow");
  }
  else{
    q->r=(q->r+1)%q->size;
    q->arr[q->r]=val;
  }
}
int dequeue(struct cirqueue *q){
  int val;
  if(isEmpty(q)){
    printf("Queue Empty");
    return -1;
  }
  else{
    q->f=(q->f+1)%q->size;
    val=q->arr[q->f];
  }
  return val;
}
int main(){
struct cirqueue q;
q.size=7;
q.f=q.r=0;

return 0;
}