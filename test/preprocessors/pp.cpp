#include <iostream>
#include <cstdio>

using namespace std;

#define HASHING_FN 32

#if HASHING_FN == 1
    #define WIDTH 8
    void hash(int * sha){
        for(int i=0; i<WIDTH; i++){
            sha[i] = i*i;
        }
    }
#elif HASHING_FN == 2
    #define WIDTH 16
    void hash(int * sha){
        for(int i=0; i<WIDTH; i++){
            sha[i] = i;
        }
    }
#else
    #define WIDTH 1
    void hash(int * sha){
        for(int i=0; i<WIDTH; i++){
            sha[i] = -1;
        }
    }
#endif

typedef struct entry_t{
    int index;
    int hash[WIDTH];
} entry_t;

#if HASHING_FN == 1
#elif HASHING_FN == 2
#else
#endif

void print(entry_t e){
    printf("[%d] : ", e.index);
    for(int i=0; i <WIDTH; i++){
        printf("%d ", e.hash[i]);
    }
    printf("\n");
}

int main(){
    entry_t e;
    hash(e.hash);
    e.index = 12;
    print(e);
}
