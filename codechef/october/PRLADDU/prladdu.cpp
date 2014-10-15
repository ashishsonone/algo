#include <cstdio>
#define abs(x) ((x) >= 0 ? (x) : -(x))

#define gc getchar_unlocked

void scanint(int &x)
{
    register int c = gc();
    x = 0;
    int neg = 0;
    for(;((c<48 || c>57) && c != '-');c = gc());
    if(c=='-') {neg=1;c=gc();}
    for(;c>47 && c<58;c = gc()) {x = (x<<1) + (x<<3) + c - 48;}
    if(neg) x=-x;
}

int currd, currv, N;
int nextd(int * D){
    for(int i=currd; i<N; i++){
        if(D[i] < 0){
            return i;
        }
    }
    return -1;
}
int nextv(int * D){
    for(int i=currv; i<N; i++){
        if(D[i] > 0){
            return i;
        }
    }
    return -1;
}
int main(){
    int T;
    scanint(T);
    for(int i=0; i<T; i++){
        scanint(N);
        int D[N];
        for(int k=0; k<N; k++){
            scanint(D[k]);
        }
        currd = 0;
        currv = 0;
        long long distance = 0, jump;

        while(true){
            currd = nextd(D);
            currv = nextv(D);
            
            if(currd < 0) break;

            jump = abs(currv - currd);
            if(D[currv] <= -D[currd]){
                distance += D[currv] * jump;
                //printf("add %d\n", D[currv] * jump);
                D[currd] += D[currv];
                D[currv] = 0;
            }
            else{
                distance += -D[currd] * jump;
                //printf("add %d\n", -D[currd] * jump);
                D[currv] += D[currd]; //Dinos is -ve
                D[currd] = 0;
            }
        }
        printf("%llu\n", distance);
    }
}
