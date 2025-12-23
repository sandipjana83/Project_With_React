// #include <iostream>
// using namespace std;

// int main(){
// char ch;
// cout<<"enter a character:";
// cin>>ch;
// if(ch>='A' && ch<='Z'){
//   cout<<"character is uppercase"<<endl;

// }
// else if(ch>='a' && ch<='z'){
//   cout<<"character is lowercase"<<endl;
// }
// return 0;
// }
#include <iostream>
using namespace std;

int main(){
int s=0; 
int arr[6]={1,5,1,2,2};
for(int i=0;i<5;i++){
  s^=arr[i];

}
cout<<s;
return 0;
}