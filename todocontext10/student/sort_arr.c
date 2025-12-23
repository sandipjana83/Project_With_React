#include <stdio.h>
void dutch_flag(int arr[],int n);
// void sort(int arr[],int n){
//     int count0=0,count1=0,count2=0;
//     for(int i=0;i<n;i++){
//         if(arr[i]==0){
//             count0++;
//         }
//         else if(arr[i]==1){
//             count1++;
//         }
//         else{
//             count2++;
//         }

//     }
//     int idx=0;
//     for(int i=0;i<count0;i++){
//         arr[idx]=0;
//         idx++;
//     }
//     for(int i=0;i<count1;i++){
//         arr[idx]=1;
//         idx++;
//     }
//     for(int i=0;i<count2;i++){
//         arr[idx]=2;
//         idx++;
//     }

// }

void dutch_flag(int arr[],int n){
    int st=0,mid=0,end=n-1;
    while(mid<=end){
        if(arr[mid]==0)
            {
                int temp=arr[mid];
                arr[mid]=arr[st];
                arr[st]=temp;
                mid++;st++;
                
            }
        else if(arr[mid]==1){
                mid++;
                
            }
        else if(arr[mid]==2){
                int temp=arr[mid];
                arr[mid]=arr[end];
                arr[end]=temp;
                end--;
                
            }
           
        
    }
}
int main(){
    int arr[]={1,2,0,1,0,2,0};
    int size=sizeof(arr)/sizeof(arr[2]);
    dutch_flag(arr,size);
    for(int j=0;j<size;j++){
        printf("%d\t",arr[j]);
    }
    return 0;
}
