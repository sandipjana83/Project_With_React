#include <stdio.h>
#include <math.h>
void prime_factor(int n){
    while(n%2==0){
        printf("2\n");
        n /=2 ;

    }
    for(int i=3;i<=sqrt(n);i+=2){
        while(n%i==0){
            printf("%d\n",i);
            n /=i;
        }
        
    }
    if(n>2){
        printf("%d\n",n);
    }
    //printf("\n");


}
int main(){
    int num=152;
    prime_factor(num);
    return 0;
}