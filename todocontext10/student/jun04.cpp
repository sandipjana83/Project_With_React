#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

void three_sum(vector<int>&arr){
  int n=arr.size();


  
  set<vector<int>>uniquetriplets;
  for(int i=0;i<n;i++){
    int tar=-arr[i];
    set<int>s;
    for(int j=i+1;j<n;j++){
      int third=tar-arr[j];
      if(s.find(third) != s.end()){
        vector<int>trip={arr[i],arr[j],third};
        sort(trip.begin(),trip.end());
        uniquetriplets.insert(trip);
      }
      s.insert(arr[j]);
    }

  }
  vector<vector<int>>ans(uniquetriplets.begin(),uniquetriplets.end());
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      cout<<ans[i][j]<<endl;
    }
  }

  

}
  

int main(){
  vector<int>vec={-1,0,1,2,-1,-4};
  three_sum(vec);
 
  return 0;
}