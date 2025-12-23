#include <iostream>
#include <vector>
using namespace std;

int t[100][100];
int countSubsetSum(vector<int>&arr,int sum){
  int n=arr.size();
  for (int i = 0;i <=n;i++)
  {
    t[i][0]=1;
  }
  for(int j=1;j<=sum;j++){
    t[0][j]=0;
  }
  for(int i=1;i<=n;i++){
    for(int j=1;j<=sum;j++){
      if(arr[i-1]<=j)
        t[i][j]=t[i-1][j]+t[i-1][j-arr[i-1]];
      else
        t[i][j]=t[i-1][j];
    }
  }
  return t[n][sum];
}

int countSubset_With_diff(vector<int> &arr,int diff){
  int s=0;
  for (int i:arr)
    s +=i;
  int s1= (diff + s)/2;
  return countSubsetSum(arr,s1);
}
int main(){
vector<int>vec={1,6,11,5};
cout<<countSubset_With_diff(vec,1)<<endl;
return 0;
}