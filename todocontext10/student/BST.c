#include <stdio.h>
#include <stdlib.h>
struct Node{
  int data;
  struct Node *left;
  struct Node *right;
};
struct Node *createnode(int val){
  struct Node *ptr;
  ptr=(struct Node *)malloc(sizeof(struct Node));
  ptr->data=val;
  ptr->left=NULL;
  ptr->right=NULL;
  return ptr;
}
void Inorder(struct Node *root){
  if(root != NULL){
    Inorder(root->left);
    printf("%d ",root->data);
    Inorder(root->right);
  }
}
struct Node *search(struct Node *root,int key){
  if(root==NULL){
    return NULL;
  }
  if(root->data==key){
    return root;
  }
  else if(key<root->data){
    return search(root->left,key);
  }
  else{
    return search(root->right,key);
  }
}
struct Node *searchitr(struct Node *root,int key){
  while(root !=NULL){
  if(root->data==key){
    return root;
  }
  else if(key<root->data){
    root=root->left;
  }
  else{
    root=root->right;
  }
}
return NULL;
}
void insert(struct Node *root,int key){
  struct Node *prev=NULL;
  while(root !=NULL){
    prev=root;
    if(key== root->data){
      printf("cannot insert");
      return;
    }
    else if(key<root->data){
      root=root->left;
    }
    else{
      root=root->right;
    }
  }
  struct Node *new=creatnode(key);
  if(key<prev->data){
    prev->left=new;
  }
  else{
    prev->right=new;
  }
}
int main(){
struct Node *p=creatnode(5);
struct Node *p1=creatnode(3);
struct Node *p2=creatnode(6);
// struct Node *p3=creatnode(0);
struct Node *p4=creatnode(1);
struct Node *p5=creatnode(4);
//struct Node *p6=creatnode(3);
p->left=p1;
p->right=p2;
p1->left=p4;
p1->right=p5;
//Inorder(p);
insert(p,7);
Inorder(p);
return 0;
}