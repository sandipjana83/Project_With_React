#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;
int t[100][1000];
int knapsack(int wt[],int val[],int w,int n){
  //int t[100][1000];
  
  if(n==0 || w==0){
    return 0;
  }
  if(t[n][w] !=-1){
    return t[n][w];
  }
  if(wt[n-1] <=w){
    t[n][w]= max(val[n-1]+knapsack(wt,val,w-wt[n-1],n-1),knapsack(wt,val,w,n-1));
  }
  else if(wt[n-1]>w){
    t[n][w]= knapsack(wt,val,w,n-1);
  }
  return t[n][w];
}

int main(){
  memset(t,-1,sizeof(t));
  int n=4;
  int wt[4]={1,3,4,5};
  int val[4]={3,4,5,7};
  int w=7;
  cout<<knapsack(wt,val,w,n)<<endl;
return 0;
}