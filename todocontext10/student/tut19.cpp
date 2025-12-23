#include <iostream>
#include <vector>
using namespace std;

int lin_search(int x){
  vector <int>vec={4,2,5,2,1};
  for(int i:vec){
    if(i==x){
      return i;
    }
    return -1;

  }
}


int main(){
//vector<int>vec={4,1,2,1,2};
int target;
cout<<"enter a number:";
cin>>target;
cout<<lin_search(target);


return 0;
}