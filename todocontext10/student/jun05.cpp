#include <iostream>
#include <vector>
#include<set>
using namespace std;

int three_sum03(vector<int>&nums){
  int n=nums.size();
  vector<vector<int>>ans;
  for(int i=0;i<n;i++){
    int j=i+1,k=n-1;
    while(j<k){
      int sum=nums[i]+nums[j]+nums[k];
      if(sum<0){
        j++;
      }
      else if(sum>0){
        k--;
      }
      else{
        ans.push_back({nums[i],nums[j],nums[k]});
        j++;k--;
        while(j<k && nums[j]==nums[j-1])
            j++;
      }
    }
  }
  for (const auto& row : ans) {
    for (int value : row) {
        cout << value << " ";
    }
    cout << endl;
}

  
}
int main(){
  vector<int>vec={-1,0,1,2,-1,-4};
  three_sum03(vec);

return 0;
}