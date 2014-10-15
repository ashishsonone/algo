#include <stdio.h>
typedef struct
{
/* 0 */  char Data1;
    //3-Bytes Added here.
/* 4 */  int Data2;
/* 8 */  unsigned short Data3;
/*10 */  char Data4;
    //1-byte Added here.
/*12  ends here*/

}SampleStruct;

int main(){
    printf("Size of struct %d, sum of indies is %d\n", sizeof(SampleStruct), sizeof(char)+sizeof(int)+sizeof(unsigned short)+sizeof(char));
}
