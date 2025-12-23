#include <iostream>
#include <vector>
using namespace std;

int find_duplicate(vector<int>arr){
    int slow=arr[0],fast=arr[0];
    do{
        slow=arr[slow];
        fast=arr[arr[fast]];

    }while (slow != fast);
    
    slow=arr[0];
    while(slow != fast){
        slow=arr[slow];
        fast=arr[fast];

    }
    return slow;
} 
int main(){
vector<int>vec={3,1,3,4,2};
cout<<find_duplicate(vec)<<endl;
return 0;
}