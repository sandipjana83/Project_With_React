#include <iostream>

using namespace std;

int main(){
    // int n;
    // cout<<"enter a nuumber:"<<endl;
    // cin>>n;
    // if(n%2==0){
    //     cout<<"number is even"<<endl;
    // }
    // else{
    //     cout<<"number is odd"<<endl;
    // }
    int n1,n2;
    cout<<"enter two numbers:";
    cin>>n1>>n2;
    char ch;
    cout<<"enter an operator:";
    cin>>ch;
    switch(ch){
        case '+':
            cout<<"the result ="<<n1+n2<<endl;
            break;
        case '-':
            cout<<"the result="<<n1-n2<<endl;
            break;
        case '*':
            cout<<"the result ="<<n1*n2<<endl;
            break;
        case '/':

            cout<<"the result is="<<(float) n1/n2;
            break;


    }
    return 0;
}