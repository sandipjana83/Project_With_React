#include <stdio.h>
int fact(int n){
    if (n==0)
        return 0;
    else if(n==1){
        return 1;
    }
    else{
        return n*fact(n-1) ;
    }

}
int cal_peterson(int num){
    int s=0,temp=num;
    while(num>0){
        int dig=num%10;
        s +=fact(dig);
        num /=10;
    }
    return s==temp;
}
int main(){
    int a=140;
    (cal_peterson(a)==1)? printf("peterson"): printf("not peterson");
    return 0;
}