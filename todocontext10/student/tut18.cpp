#include <iostream>
using namespace std;

int main(){

int nums[]={2,5,1,1,2,3};
int size=sizeof(nums)/sizeof(nums[0]);
int feq[size];


for (int i=0;i<size;i++){
    

    int count=1;
    if(feq[i]==1)
      continue;
    

  for(int j=0;j<size;j++){
    if(nums[i]==nums[j] && i!=j){
      
      count++;
      feq[j]=1;
      
      
     

     }
  }
  cout<<nums[i]<< "occurs" <<count<<endl;
  
    
  
 }
 return 0;
 }
// #include <iostream>
// using namespace std;

// void printUniqueValues(int arr[], int size) {
//     cout << "Unique values: ";
//     for (int i = 0; i < size; i++) {
//         bool isUnique = true;
//         for (int j = 0; j < size; j++) {
//             if (i != j && arr[i] == arr[j]) {
//                 isUnique = false;
//                 break;
//             }
//         }
//         if (isUnique) {
//             cout << arr[i] << " ";
//         }
//     }
//     cout << endl;
// }

// int main() {
//     int arr[] = {1, 2, 2, 3, 4, 4, 5};
//     int size = sizeof(arr) / sizeof(arr[0]);

//     printUniqueValues(arr, size);
//     return 0;
// }
