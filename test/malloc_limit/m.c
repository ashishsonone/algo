#include <stdlib.h>
#include <stdio.h>

#define SIZE 1000*1000*1000

int main(){
    int i;
    char *x;
    for(i=0; i <100;i++) {
        x = malloc(SIZE);
    }
    printf("size of x : %d", sizeof(x));
}
