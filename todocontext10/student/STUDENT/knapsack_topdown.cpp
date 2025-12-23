#include <iostream>
#include <algorithm>
using namespace std;

int t[100][100];

int knapsack_topDown(int wt[],int val[],int n,int w){
  for(int i=0;i<n+1;i++){
    for(int j=0;j<w+1;j++){
      if(i==0 || j==0)
        t[i][j]=0;
      else if(wt[i-1]<= j){
        t[i][j]=max(val[i-1]+t[i-1][j-wt[i-1]], t[i-1][j]);
      }
      else{
        t[i][j]=t[i-1][j];
      }
    }
  }
  return t[n][w];
}
int main(){
int n=4;
int w=7;
int wt[4]={1,3,4,5};
int val[4]={3,4,5,7};
//int t[5][8];
cout<<knapsack_topDown(wt,val,n,w)<<endl;
return 0;
}