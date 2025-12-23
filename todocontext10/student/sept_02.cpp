#include <iostream>
using namespace std;

struct Node{
  int data;
  Node *next;
  Node(int val){
    data=val;
    next=NULL;
  }
};
class linked_list{
  Node *head;
  Node *tail;
public:
  linked_list(){
    head=tail=NULL;
  }
  void pushAtfront(int val){
    Node *temp=new Node(val);
    temp->data=val;
    temp->next=head;
    head=temp;
    
  }
  void insertAtIndex(int index,int val){
    Node *ptr;
    ptr=new Node(val);
    ptr->data=val;
    Node *p=head;
    Node *q=head->next;
    int i=0;
    while(i !=index-1){
      p=p->next;
      q=q->next;
      i++;
    }
    p->next=ptr;
    ptr->next=q;
  }
  void printLL(){
    Node *temp=head;
    while(temp !=NULL){
      cout<<temp->data<<"->";
      temp=temp->next;
    }
  }
  void reverse(){
    Node *prev=NULL;
    Node *curr=head;
    Node *Next=NULL;
    while(curr !=NULL){
      Next=curr->next;
      curr->next=prev;
      prev=curr;
      curr=Next;
    }
    head=prev;
  }
};

int main(){
linked_list ll;
ll.pushAtfront(4);
ll.pushAtfront(5);
ll.pushAtfront(3);
ll.pushAtfront(10);
ll.insertAtIndex(1,6);
ll.printLL();
ll.reverse();
cout<<endl;
ll.printLL();
return 0;
}