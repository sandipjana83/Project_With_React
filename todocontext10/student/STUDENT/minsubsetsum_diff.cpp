#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

bool t[100][100];
void subset_sum(vector<int>arr,int sum){
  int n=arr.size();
  for(int i=0;i<=n;i++){
    t[i][0]=true;
  }
  for (int j = 1; j <=sum; j++)
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
}


int minsubsetsum_diff(vector<int>arr){
  int range=0;
  vector<int>v;
  int n=arr.size();
  for(int val:arr){
    range+=val;
  }
  subset_sum(arr,range);
  for(int i=0;i<=range/2;i++){
    if(t[n][i]){
      v.push_back(i);
    }
  }
  int mn=INT_MAX;
  for(int i=0;i<v.size();i++){
    mn=min(mn,range-2*v[i]);
  }
  return mn;
}
int main(){
vector<int>arr={1,6,11,5};
cout<<minsubsetsum_diff(arr)<<endl;
return 0;
}