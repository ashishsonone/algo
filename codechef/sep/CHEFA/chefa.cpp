#include <cstdio>
#include <algorithm>

int compare(int a, int b){
    return a >= b;
}

int main(){
    int T;
    scanf("%d", &T);
    while(T--){
        int N;
        scanf("%d", &N);
        int * stones = new int[N];
        for(int i=0; i<N; i++){
            scanf("%d", &stones[i]);
        }

        long long numstones = 0;
        std::sort(stones, stones+N, compare);
        for(int i=0; i<N; i+=2){
            numstones += stones[i];
        }
        printf("%lld\n", numstones);
        delete[] stones;
    }
}
