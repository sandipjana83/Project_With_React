#include <iostream>
#include <vector>
using namespace std;


int pair_sum(vector<int>vec,int tar){
  int n=vec.size();
  for(int i=0;i<n;i++){
    for(int j=i+1;j<n;j++){
      if(vec[i]+vec[j]==tar){
        cout<<"pair found at index "<<i<<" and "<<j<<endl;
        return 1; // Pair found
      }
    }
  }
}

int main(){
  vector<int> vec = {1, 2, 3, 4, 5};
  int target = 6;
  
  if(pair_sum(vec, target)) {
    cout << "Pair exists with the given sum." << endl;
  } else {
    cout << "No pair found with the given sum." << endl;
  }

return 0;
}