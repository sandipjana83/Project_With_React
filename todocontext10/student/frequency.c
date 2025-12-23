#include <stdio.h>
#include <string.h>
int main(){
    char str[100] ;
    int i,j;
    printf("enter a string:");
    fgets(str,sizeof(str),stdin);
    char freq[strlen(str)];
    for(i=0;i<strlen(str);i++){
        if(freq[i]==1){
            continue;
        }
        int count=1;
        for(j=i+1;j<strlen(str);j++){
            if(str[i]==str[j]){
                count++ ;
                freq[j]=1;


            }
        }
        printf(" %c occurs %d time\n",str[i],count);
    }
    
    return 0;
}