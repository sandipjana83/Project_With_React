#include <iostream>
#include <vector>
#include<unordered_map>
using namespace std;

void two_sum(vector<int>&arr,int tar){
  unordered_map<int,int>m;
  vector<int>ans;
  for(int i=0;i<arr.size();i++){
    int first=arr[i];
    int sec=tar-first;

    if(m.find(sec) !=m.end()){
      ans.push_back(arr[i]);
      ans.push_back(arr[m[sec]]);
      break;
    }
    m[first]=i;
  }
  for(int val:ans){
    cout<<val<<endl;
  }
  
}
int main(){
  vector<int>vec={5,2,11,7,15};
  int target=9;
  two_sum(vec,target);
  return 0;
}
