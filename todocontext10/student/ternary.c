#include <stdio.h>
 int main(){
//     int n;
//     printf("enter a number:");
//     scanf("%d",&n);
//     (n%2==0)? printf("even") : printf("odd");
//     return 0;
// }
int arr[]={7,4,2,3,11};

int st=0,end=4;
while(st<=end){
    int temp=arr[st];
    arr[st]=arr[end];
    arr[end]=temp;
    st++;
    end--;
}
for(int i=0;i<5;i++){
    printf("%d\t",arr[i]);
}
 }
