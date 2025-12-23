#include <iostream>
#include <vector>
using namespace std;

void find_duplicate(vector<int>&num){
    int fast=num[0],slow=num[0];
    do{
        fast=num[num[fast]];
        slow=num[slow];
    }while(fast !=slow);
    slow=num[0];
    while(slow !=fast){
        slow=num[slow];
        fast=num[fast];
    }
    cout<< fast<<endl;
}
int main(){
vector<int>vec={1,2,3,4,3,5,2};
find_duplicate(vec);
return 0;
}