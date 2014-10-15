#include <stdio.h>
int main(){
    char command[1000];
    sprintf(command,"(dd if=/dev/zero of=Sim_disk bs=%dx%dx%db count=1) 2> /dev/zero",1,100,20);
    printf("%s", command);
}
