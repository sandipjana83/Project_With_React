#include <iostream>
using namespace std;

void selection_sort(int arr[],int n){
  for (int i=0;i<n-1;i++){
    int smallestidx=i;
    for(int j=i+1;j<n;j++){
      if(arr[j]<arr[smallestidx]){
        smallestidx=j;
      }
    }
    swap(arr[i],arr[smallestidx]);
  }
}

int main(){
  int nums[]={4,3,1,17,8,11};
  int size=sizeof(nums)/sizeof(nums[0]);
  selection_sort(nums,size);
  for(int val=0;val<size;val++){
    cout<<nums[val]<<endl;
  }

return 0;
}