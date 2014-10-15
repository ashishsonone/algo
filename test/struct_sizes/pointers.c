#include <iostream>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <string.h>
#include <sys/time.h>
#include <sys/types.h>
#include <stdbool.h>
using namespace std;

struct CacheItem {
    uint64_t it_addr;
    uint64_t it_age;
    uint8_t *it_data;
};

struct PageCache{
    CacheItem * page;
    unsigned int page_size;
    unsigned int page_no;
};


int main(){
    PageCache * cache;
    cache = (PageCache*) malloc(sizeof(*cache));
    cout <<"size of pointer to PageCache i.e cache "  << sizeof(*cache) << endl;
    cout <<"size of data pointed to by cache variable i.e size of PageCache struct "  << sizeof(*cache) << endl;
}
