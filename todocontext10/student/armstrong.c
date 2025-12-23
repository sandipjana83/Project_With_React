#include <stdio.h>
#include <math.h>
int digit(int num){
  int s=0;
  while(num>0){
    s++;
    num=num/10;
  }
  return s;
}
int armstrong(int temp){
  int n=digit(temp),num=temp;
  int rev=0;
  while(num>0){
    int dig=num%10;
    rev+=pow(dig,n);
    num=num/10;
  }
  return rev;
}
int main(){
int n=153;
int arm=armstrong(n);
(n ==arm)? printf("the number is armstrong"):printf("the number is not armstrong");

return 0;
}