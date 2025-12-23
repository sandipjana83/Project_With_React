#include <iostream>


using namespace std;

int main(){
int n,dig;
cout<<"enter a number:";
cin>>n;
int i=1;
int sum=0;
while(n!=0){
  dig=n%2;
  n/=2;
  sum+=dig*i;
  
  i*=10;

  

}
cout<<sum;
return 0;
}