#include <iostream>
#include <vector>
using namespace std;

int main(){
int nums[]={0,2,7,4,12};
int target=9;
vector <int> vec;
for(int i=0;i<5;i++){
  //for(int j=0;i<5;i++)
  for(int j=i+1;j<5;j++){
    //if(nums[i]+nums[j]==target && i!=j)
    if(nums[i]+nums[j]==target){
      vec.push_back(i);
      vec.push_back(j);
      break;


    }
  }
}
for(int val:vec){
  cout<<val<<endl;
}
return 0;
}