#include <iostream>
using namespace std;

int fact(int );

int fact(int n){
  int i;
  long int fact;
  for(i=0;i<n;i++)
  {
    fact*=i;
  }
  return fact;

}

int main(){
  int num,r;
  cout<<"enter the value of n:";
  cin>>num;
  cout<<"enter the value of r:";
  cin>>r;
  cout<<"the value of nCr="<<fact(num)/(fact(r)*fact(num-r));


return 0;
}