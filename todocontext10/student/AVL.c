#include <stdio.h>
#include <stdlib.h>
struct Node{
  int data;
  struct Node *left;
  struct Node *right;
  int height;
};
int getHeight(struct Node *n){
  if(n==NULL){
    return 0;
  }
  return n->height;
}
struct Node *createNode(int val){
  struct Node *ptr=(struct Node*)malloc(sizeof(struct Node ));
  ptr->data=val;
  ptr->left=NULL;
  ptr->right=NULL;
  ptr->height=1;
  return ptr;
}
int getBalanceFactor(struct Node *n){
  if(n==NULL){
    return 0;
  }
  return getBalanceFactor(n->left)-getBalanceFactor(n->right);
}
int maxVal(int a, int b) {
    return (a > b) ? a : b;
}
struct Node *rightRotate(struct Node *y){
  struct Node *x=y->left;
  struct Node *T2=x->right;
  x->right=y;
  y->left=T2;
  y->height=maxVal(getHeight(y->left),getHeight(y->right))+1;
  x->height=maxVal(getHeight(x->left),getHeight(x->right))+1;
  return x;
}
struct Node *leftRotate(struct Node *x){
  struct Node *y=x->right;
  struct Node *T2=y->left;
  y->left=x;
  x->right=T2;
  y->height=maxVal(getHeight(y->left),getHeight(y->right))+1;
  x->height=maxVal(getHeight(x->left),getHeight(x->right))+1;
  return y;
}
struct Node* insert(struct Node* node, int data) {
    // 1. Normal BST insertion
    if (node == NULL)
        return createNode(data);

    if (data < node->data)
        node->left = insert(node->left, data);
    else if (data > node->data)
        node->right = insert(node->right, data);
    else // duplicate keys not allowed
        return node;

    // 2. Update height of this ancestor node
    node->height = 1 + max(height(node->left), height(node->right));

    // 3. Get balance factor
    int balance = getBalance(node);

    // 4. Balance the tree using rotations

    // Case 1 - Left Left
    if (balance > 1 && data < node->left->data)
        return rightRotate(node);

    // Case 2 - Right Right
    if (balance < -1 && data > node->right->data)
        return leftRotate(node);

    // Case 3 - Left Right
    if (balance > 1 && data > node->left->data) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    // Case 4 - Right Left
    if (balance < -1 && data < node->right->data) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    // Return unchanged node pointer
    return node;
}

int main(){
struct Node *p=createNode(4);
struct Node *p1=createNode(1);
struct Node *p2=createNode(6);
struct Node *p3=createNode(5);
struct Node *p4=createNode(2);
p->left=p1;
p->right=p2;
p1->left=p3;
p1->right=p4;
printf("%d",getHeight(p));
return 0;
}