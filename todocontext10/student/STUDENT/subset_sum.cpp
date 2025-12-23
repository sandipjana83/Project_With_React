#include <iostream>
using namespace std;

bool t[100][100];
bool subset_sum(int arr[],int n, int sum){
  for(int i=0;i<n;i++){
    t[i][0]=true;
  }
  for (int j = 0; j <sum; j++)
  {
    t[0][j]=false;
  }
  
  for (int i = 1; i <=n; i++)
  { for(int j=1;j<=sum;j++){
      if (arr[i-1]<=j)
      {
        t[i][j]=(t[i-1][j-arr[i-1]]) ||(t[i-1][j]);
      }
      else{
        t[i][j]= t[i-1][j];
      }
      
  }
    
  }
  return t[n][sum];
}
bool sum_partition(int arr[],int n){
  int sum=0;
  for(int i=0;i<n;i++){
    sum+=arr[i];
  }
  if(sum %2 !=0){
    return false;
  }
  else{
    subset_sum(arr,n,sum/2);
  }
}
int main(){
int arr[4]={1,6,11,5};
cout<<sum_partition(arr,4)<<endl;
return 0;
}