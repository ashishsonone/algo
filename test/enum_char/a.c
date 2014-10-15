#include <stdio.h>
typedef enum {
    read = 1,
    write = 2,
    exec = 4
}access_method;

int main(){
    printf("size of read %d, size of write %d, size of exec %d\n", sizeof(read), sizeof(write), sizeof(exec));
    char x = read | write | exec;
    printf("size of x : %d, value : %d\n",sizeof(x), x);
}
