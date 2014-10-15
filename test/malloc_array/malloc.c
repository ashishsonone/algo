#include <stdio.h>
#include <stdlib.h>

int main(){
    int size = 100;
    int * a = calloc(1, size * sizeof(int));
    printf("...%d\n", a[0]);
}
