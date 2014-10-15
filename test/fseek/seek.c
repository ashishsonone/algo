#include <stdio.h>
#include <string.h>
#define BLOCKSIZE 5

int main(){
    FILE *fp = fopen("Sim_disk", "rb+");
    if(fp == NULL){
        printf("Couldn't open file");
        return -1;
    }
    int blockno = 1;
    int offset = 3;
    
    int pos = blockno * BLOCKSIZE + offset;
    fseek(fp, pos, SEEK_SET);
    char towrite[100] = "Hello There!" ;
    printf("to write : %s\n" , towrite);

    fwrite(towrite, strlen(towrite), 1, fp);
    fclose(fp);


    int no_bytes = 9;
    int block_offset = 4;


    int rem_bytes = no_bytes - (BLOCKSIZE - block_offset); //removing bytes consumed in first block

    int left_rem = (BLOCKSIZE-block_offset)?1:0;
    int mid_no_blocks = rem_bytes/BLOCKSIZE;
    int right_rem = (rem_bytes%BLOCKSIZE)?1:0;
    printf("no_bytes %d, block_offset %d, rem_bytes %d,  left_rem %d, mid_no_blocks %d, right_rem %d\n", no_bytes, block_offset, rem_bytes, left_rem, mid_no_blocks, right_rem);
    printf("Total block span %d\n", left_rem+mid_no_blocks+ right_rem);
}
