#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int max_sum(vector<int>&num){
  int maxsum=INT_MIN,curr_sum=0;
  for(int i=0;i<num.size();i++){
    curr_sum+=num[i];
  
  maxsum=max(curr_sum,maxsum);
  if(curr_sum<0){
    curr_sum=0;
  }
}
  return maxsum;

}
int main(){
vector<int>arr={6,-2,-10,2,5};
cout<<max_sum(arr);

return 0;
}