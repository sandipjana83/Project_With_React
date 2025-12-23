#include <stdio.h>
int main(){
    int arr[]={18,3,6,8,42},i;
    int n=sizeof(arr)/sizeof(arr[0]);
    // int max=arr[0],min=arr[n-1];
    // for(i=1;i<n;i++){
    //     if(arr[i]>max){
    //         max=arr[i];
    //     }
    // }
    // for(int j=n-2;j>=0;j--){
    //     if(arr[j]<min){
    //         min=arr[j];
    //     }
    // }
    // printf("%d  %d",max,min);
    int first=arr[0];
    int second=arr[0];
    for(int i=0;i<n;i++){
        if(arr[i]>first){
            second=first;
            first=arr[i];
        }
        else if(arr[i]>second && arr[i]!=first){
            second=arr[i];
        }
    }
    printf("%d\n",first);
    printf("%d",second);
    return 0;
    

    
}