#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;
void twoSum(vector<int>&nums,int tar){
  unordered_map<int,int>m;
  vector<int>ans;
  for(int i=0;i<nums.size();i++){
    int first=nums[i];
    int sec=tar-first;
    if(m.find(sec) !=m.end()){
      ans.push_back(i);
      ans.push_back(m[sec]);
      break;
    }
    m[first]=i;
  }
  for(int val:ans){
    cout<<val<<endl;
  }
}

int main(){
vector<int>vec={2,7,3,11,20};
int tar=27;
twoSum(vec,tar);
return 0;
}