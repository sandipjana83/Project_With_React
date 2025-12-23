#include <stdio.h>
#include <stdlib.h>

struct students{
  float weight;
  float height;
  struct students *next;
};
void insert(struct students **head,float height,float weight){
  struct students *ptr=(struct students *)malloc(sizeof(struct students));
  ptr->height=height;
  ptr->weight=weight;
  ptr->next=NULL;
  if(*head==NULL){
    *head=ptr;
    return;
  }
  else{
    struct students *p=*head;
    while(p->next !=NULL){
      p=p->next;
    }
    p->next=ptr;
  }
}
float maxRatio(struct students *head){
  struct students* temp=head;
  float max_ratio=0;
  while(temp !=NULL){
    if(temp->height !=0){
      float ratio=temp->weight/temp->height;
      if(ratio>max_ratio){
        max_ratio=ratio;
      }
    }
    temp=temp->next;
  }
  return max_ratio;
}
void display(struct students *head){
  while(head !=NULL){
    printf("height=%.2f weight=%.2f\n",head->height,head->weight);
    head=head->next;

  }
}
int main(){
struct students *head=NULL;
int stu;
float height,weight;
printf("How many studnts:");
scanf("%d",&stu);
for(int i=0;i<stu;i++){
  printf("Enter height and weight of student %d : ",i+1);
  scanf("%f %f",&height,&weight);
  insert(&head,height,weight);
}
display(head);
printf("Maximum ratio: %f",maxRatio(head));
return 0;
}