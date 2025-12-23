#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

void repeating_value(vector<vector<int>>arr){
  vector<int>ans;
  unordered_set<int>s;
  int m=arr.size(),n=arr[0].size();
  int a,b,actual_sum=0;
  for(int i=0;i<m;i++){
    for(int j=0;j<n;j++){
      actual_sum+=arr[i][j];
      if(s.find(arr[i][j])!=s.end()){
        a=arr[i][j];
        ans.push_back(a);
                
      }
      s.insert(arr[i][j]);

      
      
    }
  }
  int expected_sum=(n*n)*(n*n+1)/2;
  b=expected_sum+a-actual_sum;
  ans.push_back(b);
  for(int val:ans){
    cout<<val<<endl;
  }
  
  

}

int main(){
  vector<vector<int>>vec={{9,1,7},{8,9,2},{3,4,6}};
  repeating_value(vec);


return 0;
}