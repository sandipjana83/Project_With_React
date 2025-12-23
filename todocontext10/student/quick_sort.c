#include <stdio.h>

int partition(int num[],int low,int high){
  int idx=low-1,j,pivot=num[high];
  for(j=low;j<high;j++){
    if(num[j]<=pivot){
      idx++;
      int temp=num[idx];
      num[idx]=num[j];
      num[j]=temp;
    }
   }
  idx++;
  int temp=num[idx];
  num[idx]=num[high];
  num[high]=temp;
  return idx;
}
void quick_sort(int arr[],int st,int end){
  if(st<end){
    int pivIdx=partition(arr,st,end);
    quick_sort(arr,st,pivIdx-1);
    quick_sort(arr,pivIdx+1,end);
  }
}
int main(){
int arr[5]={8,3,7,12,4};
quick_sort(arr,0,4);
for(int i=0;i<5;i++){
  printf("%d\t",arr[i]);
}
return 0;
}