#include <iostream>
using namespace std;

struct Node{
  public:
  int data;
  Node *next;
  
  Node(int val){
    data=val;
    next=NULL;
  }
};
class List{
private:
  Node *head;
  Node *tail;
public:
  List(){
    head=tail=NULL;
  }
void push_front(int val){
  Node *ptr=new Node(val);
  ptr->data=val;
  if(head==NULL){
    head=tail=ptr;
    return;
  }
  ptr->next=head;
  head=ptr;
  
}
void push_back(int val){
  Node *ptr=new Node(val);
  ptr->data=val;
  Node *p=head;
  while(p->next !=NULL){
    p=p->next;
  }
  p->next=ptr;
  ptr->next=NULL;

}
void pop_front(){
  Node *p=head;
  Node *q=head->next;
  head=q;
  delete(p);
}
void pop_back(){
  Node *p=head;
 
  while(p->next !=tail){
    p=p->next;

  }
  p->next=NULL;
  delete(tail);
  tail=p;

}

void print_ll(){
  Node *temp=head;
  while(temp!=NULL){
    cout<<temp->data<<"->";
    temp=temp->next;
  }
  cout<<endl;
}

};
int main(){
List ll;
ll.push_front(5);
ll.push_back(7);
ll.push_back(12);
ll.push_back(17);


ll.print_ll();
ll.pop_back();
ll.print_ll();

return 0;
}