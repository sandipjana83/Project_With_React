#include <iostream>
using namespace std;

int t[100][100];
int count_subset(int arr[],int n,int sum){
  for(int i=0;i<=n;i++){
    t[i][0]=1;
  }
  for(int j=1;j<=sum;j++){
    t[0][j]=0;
  }
  for(int i=1;i<=n;i++){
    for(int j=1;j<=sum;j++){
      if(arr[i-1]<=j){
        t[i][j]=t[i-1][j] + t[i-1][j-arr[i-1]];
      }
      else{
        t[i][j]=t[i-1][j];
      }
    }
  }
  return t[n][sum];
}
int main(){
  int arr[6]={2,3,5,6,8,10};
  cout<<count_subset(arr,6,9)<<endl;
return 0;
}