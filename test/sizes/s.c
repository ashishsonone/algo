#include <stdio.h>
void f(int a[][2]){
    printf("size arg array a %d\n", sizeof(a));
}
int main(){
    int a[3][2];
    printf("size array a %d\n", sizeof(a));
    f(a);
}
