#include <stdio.h>
int c = 2;

int f(){
    static int e=4;
    e+=1;
    printf("%d\n",e);
}

int main(){
    printf("%d\n",c);
    f();
    f();
    f();
}
