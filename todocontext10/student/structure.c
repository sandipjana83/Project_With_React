#include <stdio.h>
#include <string.h>

struct employee{
    int code;
    float salary;
    char name[10];
};
void show (struct employee e);

void show (struct employee e){
    printf("code is %d \n salary is %f \n name is %s",e.code,e.salary,e.name);
}
int main(){


struct employee e1;
e1.code=45;
strcpy(e1.name,"sandip");
e1.salary=23.4;
show(e1);
return 0;




}
