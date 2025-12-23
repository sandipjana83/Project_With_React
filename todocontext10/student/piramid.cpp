#include <iostream>
using namespace std;

int main(){
int n=4,i,j,k;
for(i=1;i<=n;i++){
  for(j=1;j<=n-i;j++){
    cout<<" ";
  }
  for(k=1;k<=i;k++){
    cout<<k;
  }
  for(j=i-1;j>0;j--){
    cout<<j;
  }
  cout<<endl;
}
return 0;
}