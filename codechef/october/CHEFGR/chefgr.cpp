#include <cstdio>

int main(){
    int T;
    scanf("%d", &T);
    for(int i=0; i<T; i++){
        int N, M;
        scanf("%d", &N);
        scanf("%d", &M);
        int sum = 0, max = -1, h;
        for(int k=0; k<N; k++){
            scanf("%d", &h);
            if(h > max) max = h;
            sum += h;
        }

        int sumtot = sum + M;
        int poss = true;
        if(sumtot % N != 0){ //height cant be equal
            poss = false;
        }
        else{
            int avg = sumtot / N;
            if(max > avg) poss = false;
        }

        if(poss) printf("Yes\n");
        else printf("No\n");
    }
}
