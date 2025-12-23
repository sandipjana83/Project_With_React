#include <stdio.h>
#include <stdlib.h>
struct Node{
  int data;
  struct Node *left;
  struct Node *right;
};
struct Node *creatNode(int val){
  struct Node *ptr;
  ptr=(struct Node*)malloc(sizeof(struct Node));
  ptr->data=val;
  ptr->left=NULL;
  ptr->right=NULL;
  return ptr;

}
void preorder(struct Node *root){
  if(root!=NULL){
    printf("%d ",root->data);
    preorder(root->left);
    preorder(root->right);
  }
}
void inorder(struct Node *root){
  if(root !=NULL){
    inorder(root->left);
    printf("%d ",root->data);
    inorder(root->right);

  }
}
void postOrder(struct Node *root){
  if(root!=NULL){
    postOrder(root->left);
    postOrder(root->right);
    printf("%d ",root->data);
  }
}
int sumNode(struct Node *root){

  if(root==NULL){
   return 0;
  }
  int leftval=sumNode(root->left);
  int rightval=sumNode(root->right);
  return leftval+rightval+root->data;
}

int main(){
// struct Node *p;
// p=(struct Node *) malloc(sizeof(struct Node));
// p->left=NULL;
// p->right=NULL;

// struct Node *p1;
// p1=(struct Node *) malloc(sizeof(struct Node));
// p1->left=NULL;
// p1->right=NULL;

// struct Node *p2;
// p2=(struct Node *) malloc(sizeof(struct Node));
// p2->left=NULL;
// p2->right=NULL;
struct Node *p=creatNode(4);
struct Node *p1=creatNode(1);
struct Node *p2=creatNode(6);
struct Node *p3=creatNode(5);
struct Node *p4=creatNode(2);
p->left=p1;
p->right=p2;
p1->left=p3;
p1->right=p4;

preorder(p);
 printf("\n");
// postOrder(p);
// printf("\n");
// inorder(p);
sumNode(p);
return 0;
}